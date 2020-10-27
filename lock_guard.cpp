/*
定义于头文件 <mutex>
template< class Mutex >
class lock_guard;
类 lock_guard 是互斥封装器，为在作用域块期间占有互斥提供了一种方便的RAII风格机制。
创建lock_guard对象时，它试图接收给定互斥的所有权。控制离开创建lock_guard对象的作用域时，销毁lock_guard并释放互斥。
lock_guard 类不可复制。
*/

#include <thread>
#include <mutex>
#include <iostream>
#include <vector>

std::mutex g_mutex;  // 保护 vc
std::vector<int> vc;

void func() {

  std::lock_guard<std::mutex> lock(g_mutex);

  for(int i = 0; i < 100; ++i) 
  {
    vc.emplace_back(i);
  }

 std::cout << std::this_thread::get_id()  << std::endl;

  // g_mutex 在锁离开作用域时自动释放
}

int main() {
  std::cout << "main: " << vc.size() << '\n';

  std::thread t1(func);
  std::thread t2(func);

  t1.join();
  t2.join();

  std::cout << "main: " << vc.size() << '\n';

  getchar();
  return 0;
}