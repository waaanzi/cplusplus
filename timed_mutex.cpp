#include <mutex>
#include <iostream>
#include <sstream>
#include <vector>
#include <thread>
#include <chrono>

/*
头文件 <mutex>
class timed_mutex; (C++11 起)

template< class Rep, class Period >
bool try_lock_for( const std::chrono::duration<Rep,Period>& timeout_duration );(C++11 起)

template< class Clock, class Duration >
bool try_lock_until( const std::chrono::time_point<Clock,Duration>& timeout_time);(C++11 起)
*/

std::mutex cout_mutex;
std::timed_mutex mutex;
std::timed_mutex test_mutex;

using namespace std::chrono;
using namespace std::chrono_literals;

void job(int id) {
  std::ostringstream stream;
  for (int i = 0; i < 3; ++i) {
    if (mutex.try_lock_for(100ms)) {
      stream << "success ";
      std::this_thread::sleep_for(100ms);
      mutex.unlock();
    } else {
      stream << "failed ";
    }
    std::this_thread::sleep_for(100ms);
  }

  std::lock_guard<std::mutex> lock(cout_mutex);
  std::cout << "[" << id << "] " << stream.str() << std::endl;
}

void f() {
  auto now = steady_clock::now();
  if (test_mutex.try_lock_until(now + 10s)) {
    std::cout << "get lock." << std::endl;
  } else {
    std::cout << "try_lock_util timeout." << std::endl;
  }  
}

int main() {
  {
  // try_lock_for
  std::vector<std::thread> threads;
  for (int i = 0; i < 4; ++i) {
    threads.emplace_back(job, i);
  }

  for (auto& i : threads) {
    i.join();
  }
  }

 {
  // try_lock_until
  auto start = steady_clock::now();
  std::lock_guard<std::timed_mutex> l(test_mutex);
  std::thread t(f);
  t.join();
  auto end = steady_clock::now();
  std::cout << "time use: " << duration_cast<milliseconds>(end-start).count() 
            << "ms." << std::endl;
  }

  std::cin.get();
  return 0;
}