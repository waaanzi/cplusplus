#include <iostream>
#include <type_traits>  // is_same
#include <ratio>

int main() {

  // �����жϼ�type��Ա
  std::cout << std::boolalpha << std::is_same<std::ratio<10,20>, std::ratio<100,200>>() << std::endl;
  std::cout << typeid(std::ratio<10, 20>::type).name() << std::endl;
  std::cout << typeid(std::ratio<100, 200>::type).name() << std::endl;

  // ��̬���ݳ�Ա
  std::cout << std::ratio<100, 200>::num << std::endl;
  std::cout << std::ratio<100, 200>::den << std::endl;

  // ��������
  using r = std::ratio_add<std::ratio<10,20>, std::ratio<100,200>>;
  std::cout << r::num << std::endl;
  std::cout << r::den << std::endl;

  // �߼�����
  std::cout << std::ratio_equal<std::ratio<10,20>, std::ratio<100,200>>::value << std::endl;

  std::cin.get();
  return 0;
}