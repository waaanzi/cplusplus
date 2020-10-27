#include <iostream>

class Demo {
 public:
  template<typename T>
  void f(T&& t) {
    std::cout << "Demo:f " << std::endl;
  }
};

template <typename T>
class Demo_T {
 public:
  void f(T* t) {
    t->f<int>(1);
  }
};

int main() {
  //Demo_T<Demo> dt;
  //Demo d;
  //dt.f(&d);
  const Demo t;
  t.f<int>(1);
  std::cin.get();
  return 0;
}