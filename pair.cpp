#include <iostream>
#include <utility>
#include <string>
#include <tuple>
// 定义于头文件<utility> 
// template <class T1, class T2>
// struct pair;

// std::tuple_size<std::pair> 获得pair的大小(类模板特化) 
// std::tuple_element<std::pair> 获得pair中元素的类型(类模板特化)

class A {
 public:
  A(std::tuple<int, float>) {
    std::cout << "A(std::tuple<int, float>)" << std::endl;
  }

  template <typename... Args>
  A(Args... args) {
    std::cout << "A(Args... args)" << std::endl;
  }

  A(int, float) { std::cout << "A(int, float)" << std::endl; }
};
int main() {
  std::pair<int, double> p1;
  std::cout << "p1.first : " << p1.first  << " p1.second : " << p1.second  << std::endl;
  std::cout << "std::get<0>(p1) : " << std::get<0>(p1)  << " std::get<1>(p1) : " << std::get<1>(p1)  << std::endl;

  std::pair<int, const char*> p2(1, "hi");
  std::pair<int, std::string> p3(2, "hell0");
  std::pair<int, std::string> p4(3, "hey");
  std::cout << "p3.first : " << p3.first  << " p3.second : " << p3.second  << std::endl;
  p3 = p2;
  std::cout << "p3.first : " << p3.first  << " p3.second : " << p3.second  << std::endl;
  p3.swap(p4);
  std::cout << "p3.first : " << p3.first  << " p3.second : " << p3.second  << std::endl;

  std::pair<int, std::string> p5(std::piecewise_construct,
                                 std::make_tuple(1),
                                 std::forward_as_tuple(10, 'a'));
  std::cout << "p5.first : " << p5.first  << " p5.second : " << p5.second  << std::endl;

  std::cout << "p5 size : " << std::tuple_size<decltype(p5)>::value << std::endl;
  
  std::tuple_element<0, decltype(p5)>::type; // int

  {
    std::cout << std::endl;
    std::cout << std::endl;
  std::tuple<int, float> t(1, 2.2);
  std::pair<int, A> p1(10, t);
  std::pair<int, A> p2(std::piecewise_construct, std::make_tuple(100), t);
  }

  std::cin.get();
  return 0;
}