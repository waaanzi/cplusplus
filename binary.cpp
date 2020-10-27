#include <cstdint>
#include <iostream>
#include <limits>
#include <bitset>

int main() {
  char max = std::numeric_limits<char>::max();
  char min = std::numeric_limits<char>::min();

  std::cout << "char max : " << int(max) << " " << std::bitset<8>(max) << std::endl;
  std::cout << "char min : " << int(min) << " " << std::bitset<8>(min) << std::endl;

  std::cout << "0 : " << std::bitset<8>(0) << std::endl;
  std::cout << "-1 : " << std::bitset<8>(-1) << std::endl;

  std::cin.get();
  return 0;
}