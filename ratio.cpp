#include <iostream>
#include <type_traits>  // is_same
#include <ratio>

int main() {

  // 类型判断及type成员
  std::cout << std::boolalpha << std::is_same<std::ratio<10,20>, std::ratio<100,200>>() << std::endl;
  std::cout << typeid(std::ratio<10, 20>::type).name() << std::endl;
  std::cout << typeid(std::ratio<100, 200>::type).name() << std::endl;

  // 静态数据成员
  std::cout << std::ratio<100, 200>::num << std::endl;
  std::cout << std::ratio<100, 200>::den << std::endl;

  // 算术运算
  using r = std::ratio_add<std::ratio<10,20>, std::ratio<100,200>>;
  std::cout << r::num << std::endl;
  std::cout << r::den << std::endl;

  // 逻辑运算
  std::cout << std::ratio_equal<std::ratio<10,20>, std::ratio<100,200>>::value << std::endl;

  std::cin.get();
  return 0;
}