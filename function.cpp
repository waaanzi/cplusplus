#include <iostream>
#include <functional>

// 类
struct Demo {
  void print(int a, int b) {
    std::cout << "Demo " << a << " " << b << " " << a_ << std::endl;
  };
  int a_ = 1;

  void ttt() {
    auto tt = std::bind(&Demo::print_private, this);
    tt();
  }

 private:
  void print_private() {
    std::cout << "print_private" << std::endl;
  }
  int a_private_ = 100;
};

// 普通函数
int add(int& a, int& b) {
  a++;
  b++;
  std::cout << "add " << a << " " << b << std::endl;
  return a + b;
}

// 仿函数
struct PrintDemo {
  void operator()(int i) const {
    std::cout << "PrintDemo " << i << std::endl;
  }
};

int main() {
  using namespace std::placeholders;

  {
    int a = 1;
    int b = 2;
    // 1、存储普通函数
    std::function<int(int&, int&)> f = add; // 方式1
    // std::function<int(int&, int&)> f = std::bind(add, _1, _2); // 方式2

    f(a, b); // output： add 2 3
  }

  {
    // 2、绑定lambda
    std::function<void()> f = []() {
      std::cout << "hello" << std::endl;
    };
  }

  {
    Demo demo;
    // 3、存储成员函数
    std::function<void(Demo&, int, int)> f1 = &Demo::print; // 方式1
    // std::function<void(int, int)> f1 = std::bind(&Demo::print, &demo, _1, 10); // 方式2

    // 4、存储成员变量
    std::function<int(Demo&)> f2 = &Demo::a_; // 方式1
    // std::function<int(Demo&, int)> f2 = std::bind(&Demo::a_, _1); // 方式2

    f1(demo, 10, 20); // output: Demo 10 20 1
    std::cout << f2(demo); // output: 1

    // {
    //   // 私有成员函数
    //   std::function<void(int, int)> f1 = std::bind(&Demo::print_private, demo); // 方式1
    //   f1(10, 20); // output: Demo 10 20 1
    // }
    demo.ttt();
  }
  {
    // 5、存储仿函数
    std::function<void(int)> f = PrintDemo();
    f(100); // output: PrintDemo 100
  }
  system("pause");
  return 0;
}
