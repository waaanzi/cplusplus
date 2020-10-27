/*
头文件 <mutex>
class mutex; (C++11 起)
mutex 类是能用于保护共享数据免受从多个线程同时访问的同步原语。
mutex 提供排他性非递归所有权语义：
调用方线程从它成功调用 lock 或 try_lock 开始，到它调用 unlock 为止占有 mutex 。
线程占有 mutex 时，所有其他线程若试图要求 mutex 的所有权，则将阻塞（对于 lock 的调用）或收到 false 返回值（对于 try_lock ）.
调用方线程在调用 lock 或 try_lock 前必须不占有 mutex 。
若 mutex 在仍为任何线程所占有时即被销毁，或在占有 mutex 时线程终止，则行为未定义。
mutex 类满足互斥 (Mutex) 和标准布局类型 (StandardLayoutType) 的全部要求。

std::mutex 既不可复制亦不可移动。

lock   锁定互斥，若互斥不可用则阻塞
try_lock  尝试锁定互斥，若互斥不可用则返回false
unlock  解锁互斥

*/

#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>

int g_num = 0;  // 为 g_num_mutex 所保护
std::mutex g_num_mutex;

void slow_increment(int id) {
  for (int i = 0; i < 3; ++i) {
    g_num_mutex.lock();
    ++g_num;
    std::cout << id << " => " << g_num << '\n';
    g_num_mutex.unlock();

    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

std::chrono::milliseconds interval(100);
std::mutex mutex;
// 两个线程都能修改 'job_shared',
// mutex 将保护此变量
int job_shared = 0;

// 只有一个线程能修改 'job_exclusive', 不需要保护
int job_exclusive = 0;

// 此线程能修改 'job_shared' 和 'job_exclusive'
void job_1() {
  std::this_thread::sleep_for(interval);
  while (true) {
    if (mutex.try_lock()) {
      std::cout << "job shared (" << job_shared << ")\n";
      mutex.unlock();
      return;
    } else {
      ++job_exclusive;
      std::cout << "job exclusive (" << job_exclusive << ")\n";
      std::this_thread::sleep_for(interval);
    }
  }
}

// 此线程只能修改 'job_shared'
void job_2() {
  mutex.lock();
  std::this_thread::sleep_for(5 * interval);
  ++job_shared;
  mutex.unlock();
}

int main() {

  // lock unlock
  {
    std::thread t1(slow_increment, 0);
    std::thread t2(slow_increment, 1);
    t1.join();
    t2.join();
  }

  // try_lock
  {
    std::thread thread_1(job_1);
    std::thread thread_2(job_2);

    thread_1.join();
    thread_2.join();
  }
  getchar();
  return 0;
}

