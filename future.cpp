#include <iostream>
#include <future>
#include <thread>
 
int main() {
  // 来自 packaged_task 的 future
  std::packaged_task<int()> task([]() { return 7; });  // 包装函数
  std::future<int> f1 = task.get_future();             // 获取 future
  std::thread(std::move(task)).detach();               // 在线程上运行

  // 来自 async() 的 future
  std::future<int> f2 = std::async(std::launch::async, []() { return 8; });

  // 来自 promise 的 future
  std::promise<int> p;
  std::future<int> f3 = p.get_future();
  std::thread([&p] { p.set_value_at_thread_exit(9); }).detach();

  std::cout << "valid: " << f1.valid() << ' ' << f2.valid() << ' ' << f3.valid() << std::endl;
  f1.wait();
  f2.wait();
  f3.wait();
  std::cout << "Results are: " << f1.get() << ' ' << f2.get() << ' ' << f3.get() << std::endl;
  std::cout << "after get, valid: " << f1.valid() << ' ' << f2.valid() << ' ' << f3.valid() << std::endl;

  std::future<int> f4 = std::async(std::launch::async, []() { return 8; }); 
  std::cout << "f4 valid()= " << f4.valid() << std::endl;
  auto fs = f4.share();
  std::cout << "after share, f4 valid()= " << f4.valid() << std::endl;


  std::future<int> f5;
  auto fs1 = f5.share(); // NULL

  {
std::shared_future<int> fs = std::async([]() { return 8; });
std::cout << "Results: " << fs.get() << ' ' << fs.get() << std::endl;

auto fs1 = std::async([]() { return 8; }).share();
std::cout << "Results: " << fs1.get() << ' ' << fs1.get() << std::endl;
  }


  std::cin.get();
  return 0;
}