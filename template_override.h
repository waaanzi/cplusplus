#include <iostream>
#include <functional>

class base {
 public:
  template <typename T>
  void hello(T t) {
    std::cout << "base hello" << std::endl;
    hey(t);
  }

  template <typename T>
  void hey(T t) {
    std::cout << "base hey" << std::endl;
  }
};


#include <thread>


void show() {
  // std::cout << "show" << std::endl;
}

class A {

 public:
  void f1() {

    //m_ = [&]() {
    //  //f2();
    //  //std::cout << "m" << std::endl;

    //};

    std::thread t(show);
    // t.detach();
    //t.join();

  }

  void f2() {
    std::cout << "f2" << std::endl;
  }

  ~A() {
    std::cout << "~A" << std::endl;
  }

  std::function<void()> m_;

  std::function<void()> bm_;

};
