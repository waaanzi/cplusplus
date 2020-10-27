#include <chrono>
#include <condition_variable>
#include <iostream>
#include <vector>
#include <atomic>

std::vector<std::function<void(int)>> task_vc;
std::mutex task_mutex;

std::mutex cv_mutex;
std::condition_variable cv;

std::mutex cout_mutex;

std::atomic<int> exit_flag = 0;

using namespace std::chrono_literals;

void ProcessLoop( int num) {
  while (!exit_flag) {
    {
      std::lock_guard<std::mutex> guard(task_mutex);
      if (task_vc.size() > 0) {
        auto task = task_vc.front();
        task_vc.erase(task_vc.begin());
        task(num);
      }
    }

    {
      {
        std::lock_guard<std::mutex> guard(cout_mutex);
        std::cout << "thread " << num
                  << " : wait for 100ms." << std::endl;
      }

      std::unique_lock<std::mutex> lock(cv_mutex);
      cv.wait_for(lock, 100ms);
    }
  }
}

int main() {
  std::vector<std::thread> td_vc;
  for (int i = 0; i < 4; i++) {
    td_vc.push_back(std::thread(ProcessLoop, i));
  }
 
  for (int i = 0; i < 10; i++) {
    std::lock_guard<std::mutex> guard(task_mutex);
    task_vc.push_back([](int num) {
      std::lock_guard<std::mutex> guard(cout_mutex);
      std::cout << "thread " << num << " : hello" << std::endl;
    });
 
    std::unique_lock<std::mutex> lock(cv_mutex);
    cv.notify_one();
  }
 
  std::this_thread::sleep_for(500ms);
  exit_flag.exchange(1);

  std::cin.get();
  return 0;
}