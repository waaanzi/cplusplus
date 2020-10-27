/*
https://en.cppreference.com/w/cpp/thread/unique_lock
头文件<mutex>

template<class Mutex>
class unique_lock; (since C++11)

The class unique_lock is a general-purpose mutex ownership wrapper allowing deferred locking,
time-constrained attempts at locking, recursive locking, transfer of lock ownership, and use with condition variables.
类unique_lock是通用互斥包装器，允许延迟锁定、锁定的有时限尝试、递归锁定、所有权转移和与条件变量一同使用。

The class unique_lock is movable, but not copyable -- it meets the requirements of MoveConstructible and MoveAssignable
but not of CopyConstructible or CopyAssignable.
类unique_lock可移动，但不可复制——它满足可移动构造 (MoveConstructible) 和可移动赋值 (MoveAssignable)
但不满足可复制构造(CopyConstructible)或可复制赋值 (CopyAssignable)。

The class unique_lock meets the BasicLockable requirements. If Mutex meets the Lockable requirements,
unique_lock also meets the Lockable requirements (ex.: can be used in std::lock); if Mutex meets the TimedLockable requirements,
unique_lock also meets the TimedLockable requirements.
类unique_lock满足基础可锁(BasicLockable)要求。若 Mutex 满足可锁(Lockable)要求，则unique_lock亦满足可锁(Lockable)要求（例如：能用于std::lock）；
若Mutex满足定时可锁 (TimedLockable) 要求，则unique_lock亦满足定时可锁(TimedLockable) 要求。

构造函数
unique_lock() noexcept;(1)  (since C++11)
unique_lock( unique_lock&& other ) noexcept;(2) (since C++11)
explicit unique_lock( mutex_type& m );(3) (since C++11)
unique_lock( mutex_type& m, std::defer_lock_t t ) noexcept;(4)  (since C++11)
unique_lock( mutex_type& m, std::try_to_lock_t t );(5)  (since C++11)
unique_lock( mutex_type& m, std::adopt_lock_t t );(6) (since C++11)
template< class Rep, class Period >
unique_lock( mutex_type& m,const std::chrono::duration<Rep,Period>& timeout_duration );(7)  (since C++11)
template< class Clock, class Duration >
unique_lock( mutex_type& m,const std::chrono::time_point<Clock,Duration>& timeout_time );(8)  (since C++11)

方法
lock 锁定关联互斥
try_lock  尝试锁定关联互斥，若互斥不可用则返回
try_lock_for 试图锁定关联的定时可锁 (TimedLockable) 互斥，若互斥在给定时长中不可用则返回
try_lock_until 尝试锁定关联可定时锁 (TimedLockable) 互斥，若抵达指定时间点互斥仍不可用则返回
unlock 解锁关联互斥

operator =：赋值操作符，允许移动赋值，禁止拷贝赋值；

swap 与另一 std::unique_lock 交换状态
release 将关联互斥解关联而不解锁它
mutex 返回指向关联互斥的指针
owns_lock 测试锁是否占有其关联互斥
operator bool 测试锁是否占有其关联互斥

todo 方法都写demo
*/

#include <mutex>
#include <thread>
#include <chrono>
#include <vector>
#include <iostream>

struct Box {
  explicit Box(int num) : num_things{ num } {}

  int num_things;
  std::mutex m;
};

void transfer(Box& from, Box& to, int num) {
  // 仍未实际取锁
  std::unique_lock<std::mutex> lock1(from.m, std::defer_lock);
  std::unique_lock<std::mutex> lock2(to.m, std::defer_lock);

  // 锁两个unique_lock而不死锁
  std::lock(lock1, lock2);

  from.num_things -= num;
  to.num_things += num;

  // 'from.m'与 'to.m'互斥解锁于'unique_lock'析构函数
}

std::mutex mtx;           // mutex for critical section
void print_star() {
  std::unique_lock<std::mutex> lck(mtx, std::defer_lock);
  // print '*' if successfully locked, 'x' otherwise:
  if (lck.try_lock())
    std::cout << '*';
  else
    std::cout << 'x';
}

std::timed_mutex mtx1;
void fireworks() {
  std::unique_lock<std::timed_mutex> lck(mtx1, std::defer_lock);
  // waiting to get a lock: each thread prints "-" every 200ms:
  while (!lck.try_lock_for(std::chrono::milliseconds(200))) {
    std::cout << "-";
  }
  // got a lock! - wait for 1s, then this thread prints "*"
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  std::cout << "*\n";
}

std::mutex mtx2;
int count = 0;
void print_count_and_unlock(std::mutex* p_mtx) {
  std::cout << "count: " << count << '\n';
  p_mtx->unlock();
}

void task() {
  std::unique_lock<std::mutex> lck(mtx2);
  ++count;
  print_count_and_unlock(lck.release());
}

int main() {

  {
    // lock | unlock demo

    int counter = 0;
    std::mutex counter_mutex;
    std::vector<std::thread> threads;

    auto worker_task = [&](int id) {
      std::unique_lock<std::mutex> lock(counter_mutex);
      ++counter;
      std::cout << id << ", initial counter: " << counter << '\n';
      lock.unlock();

      // don't hold the lock while we simulate an expensive operation
      std::this_thread::sleep_for(std::chrono::seconds(1));

      lock.lock();
      ++counter;
      std::cout << id << ", final counter: " << counter << '\n';
    };

    for (int i = 0; i < 10; ++i) threads.emplace_back(worker_task, i);

    for (auto& thread : threads) thread.join();
  }

  std::cout << std::endl;
  std::cout << std::endl;

  {
    // unique_lock( mutex_type& m, std::defer_lock_t t ) demo

    Box acc1(100);
    Box acc2(50);

    std::thread t1(transfer, std::ref(acc1), std::ref(acc2), 10);
    std::thread t2(transfer, std::ref(acc2), std::ref(acc1), 5);

    t1.join();
    t2.join();

    std::cout << "acc1.num_things: " << acc1.num_things << std::endl;
    std::cout << "acc2.num_things: " << acc2.num_things << std::endl;
  }

  std::cout << std::endl;
  std::cout << std::endl;

  {
    // try_lock demo

    std::vector<std::thread> threads;
    for (int i = 0; i < 1000; ++i)
      threads.emplace_back(print_star);

    for (auto& x : threads) x.join();
  }

  std::cout << std::endl;
  std::cout << std::endl;

  {
    // try_lock_for demo
    std::thread threads[10];
    // spawn 10 threads:
    for (int i = 0; i < 10; ++i)
      threads[i] = std::thread(fireworks);

    for (auto& th : threads) th.join();
  }

  std::cout << std::endl;
  std::cout << std::endl;

  {
    // release demo
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i)
      threads.emplace_back(task);

    for (auto& x : threads) x.join();
  }

  getchar();
  return 0;
}