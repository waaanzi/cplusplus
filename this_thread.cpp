#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>   // std::time_t, std::tm, std::localtime, std::mktime
#include <iomanip> // std::put_time

/*
std::this_thread 是一个命名空间，包含一系列访问当前线程的函数
get_id noexcept 获得线程id
yield noexcept 当前线程放弃执行，给实现重新调度的机会，允许其他线程运行，该线程回到准备状态，重新分配资源。
  调用该方法后，可能执行其他线程，也可能还是执行该线程。

sleep_for 阻塞线程到指定时间段之后
template <class Rep, class Period>
void sleep_for (const chrono::duration<Rep,Period>& rel_time);

sleep_until 阻塞线程到指定时间点
template <class Clock, class Duration>
void sleep_until (const chrono::time_point<Clock,Duration>& abs_time);
*/

void showThreadId(int num) {
  std::cout << "thread" << num << " id: " << std::this_thread::get_id() << std::endl;
}

void little_sleep(std::chrono::microseconds us) {
  auto start = std::chrono::high_resolution_clock::now();
  auto end = start + us;
  do {
    std::this_thread::yield();
  } while (std::chrono::high_resolution_clock::now() < end);
}

template <typename T>
std::shared_ptr<T> tt() {
  return std::make_shared<T>();
}

int main() {
  {
    // this_thread::get_id
    std::cout << "main thread id: " << std::this_thread::get_id() << std::endl;
    std::thread t1(showThreadId, 1);
    t1.join();
    std::thread t2(showThreadId, 2);
    t2.join();
  }
  std::cout << std::endl;
  std::cout << std::endl;
  {
    // this_thread::yield
    auto start = std::chrono::high_resolution_clock::now();

    little_sleep(std::chrono::microseconds(100));

    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    std::cout << "waited for "
              << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count()
              << " microseconds\n";
  }
  std::cout << std::endl;
  std::cout << std::endl;
  {
    // this_thread::sleep_for
    std::cout << "countdown:\n";
    for (int i = 10; i > 0; --i) {
      std::cout << i << std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "Lift off!\n";
  }
  std::cout << std::endl;
  std::cout << std::endl;
  {
    // this_thread::sleep_until
    using std::chrono::system_clock;
    std::time_t tt = system_clock::to_time_t(system_clock::now());

    struct std::tm* ptm = std::localtime(&tt);
    std::cout << "Current time: " << std::put_time(ptm, "%X") << '\n';

    std::cout << "Waiting for the next minute to begin...\n";
    ++ptm->tm_min;
    ptm->tm_sec = 0;
    std::this_thread::sleep_until(system_clock::from_time_t(mktime(ptm)));

    std::cout << std::put_time(ptm, "%X") << " reached!\n";
  }

  system("pause");
  return 0;
}