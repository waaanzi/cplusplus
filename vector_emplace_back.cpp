#include <iostream>
#include <vector>

class A {
 public:
  A() {
    std::cout << "constructor" << std::endl;
  }

  A(int n) {
    std::cout << "constructor int" << std::endl;
  }
  A(const A& a) {
    std::cout << "copy constructor" << std::endl;
  }
  A(A&& a) { std::cout << "move constructor" << std::endl; }
  ~A() {
    std::cout << "destructor" << std::endl;
  }
};

int main() {
  A a;
  {
    std::vector<A> vc;
    vc.reserve(10); // 排除扩容干扰
    std::cout << std::endl;
    std::cout << "push_back:" << std::endl;
    vc.push_back(1);
    vc.push_back(std::move(A(1)));
    vc.push_back(a);
  }

  {
    std::vector<A> vc1;
    vc1.reserve(10);
    std::cout << std::endl;
    std::cout << "emplace_back:" << std::endl;
    vc1.emplace_back(1);
    vc1.emplace_back(a);
  }

  {
  A a;
  std::vector<A> vc;
  vc.push_back(std::move(a));
  }
  {
    A a;
    std::vector<A> vc;
    vc.emplace_back(std::move(a));
  }

  std::cin.get();
  return 0;
}