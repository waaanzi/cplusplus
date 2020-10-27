#include <iostream>

template <typename T>
class A
{
public:
  template <typename U>
  A(const U& a) {
    std::cout << "template constructor" << std::endl;
  }
  A() {
    std::cout << "default constructor" << std::endl;
  }
};

int main() {
  A<int> i;        // default constructor
  A<int> ii(i);    // implicitly generated copy constructor
  A<double> d(i);  // template constructor

  std::cin.get();
  return 0;
}