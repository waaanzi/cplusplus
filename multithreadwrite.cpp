#include <thread>
#include <vector>
#include <memory>
#include <iostream>

void func(std::shared_ptr<std::vector<int>> vec) {
  int i = 1;
  while (i < 100000)
    vec->push_back(1);
}

void func1(std::shared_ptr<std::vector<int>> vec, int i) {
  while (--i >= 0)
    vec->at(i) = 99;
}

void func3(std::function<void()> f) {
  f();
}

void func2(uint64_t& time) {
  time = 999;
  // auto f = [](uint64_t& time) {
  //   time += 1000;
  // };
  // auto handler = std::bind(f, std::ref(time));
  // func3(handler);
}

int main() {
  //  {
  //    auto vec = std::make_shared<std::vector<int>>();
  //    std::thread t1(func, vec);
  //    std::thread t2(func, vec);
  //    t1.join();
  //    t2.join();
  //  }

  // {
  //   // vector的at返回引用
  //
  //   auto vec = std::make_shared<std::vector<int>>(5, 1);
  //   for (int i = 0; i < 5; ++i) {
  //     std::cout << vec->at(i) << std::endl;
  //   }
  //   std::thread t1(func1, vec, 5);
  //   t1.join();
  //   for (int i = 0; i < 5; ++i) {
  //     std::cout << vec->at(i) << std::endl;
  //   }
  // }

  // 测试在lambda传递过程中，引用参数是否起作用,？不起作用，无论是thread还是bind,都要用std::ref包一下
  {
    auto vec_sp = std::make_shared<std::vector<uint64_t>>(5, 1);
    for (int i = 0; i < 5; ++i) {
      std::cout << vec_sp->at(i) << std::endl;
    }
    // std::thread t1(func2, std::ref(vec_sp->at(3)));
    uint64_t a = 10;
    std::thread t1(func2, std::ref(a));
    std::cout << "a:  " << a << std::endl;
    for (int i = 0; i < 5; ++i) {
      std::cout << vec_sp->at(i) << std::endl;
    }
  }
  getchar();
  return 0;
}