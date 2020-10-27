#include <cmath>
#include <functional>
#include <future>
#include <iostream>
#include <thread>

// 避免对 std::pow 重载集消歧义的独有函数
int f(int x, int y) {
  return std::pow(x, y);
}

void task_lambda() {
  std::packaged_task<int(int, int)> task(
      [](int a, int b) { return std::pow(a, b); });
  std::future<int> result = task.get_future();

  task(2, 9);

  std::cout << "task_lambda:\t" << result.get() << '\n';
}

void task_bind() {
  std::packaged_task<int()> task(std::bind(f, 2, 11));
  std::future<int> result = task.get_future();

  task();

  std::cout << "task_bind:\t" << result.get() << '\n';
}

void task_thread() {
  std::packaged_task<int(int, int)> task(f);
  std::future<int> result = task.get_future();

  std::thread task_td(std::move(task), 2, 10);
  task_td.join();

  std::cout << "task_thread:\t" << result.get() << '\n';
}

int main() {
  {
    std::packaged_task<int(int, int)> task;
    std::cout << std::boolalpha << task.valid() << std::endl;
  }

  task_lambda();
  task_bind();
  task_thread();

  {
    // make_ready_at_thread_exit ;
  } 
  {
    // reset
    std::packaged_task<int(int, int)> task(
        [](int a, int b) { return std::pow(a, b); });
    std::future<int> result = task.get_future();
    task(2, 9);
    std::cout << "2^9 = " << result.get() << '\n';

    task.reset();
    result = task.get_future();
    std::thread task_td(std::move(task), 2, 10);
    task_td.join();
    std::cout << "2^10 = " << result.get() << '\n';
  }

  std::cin.get();
  return 0;
}