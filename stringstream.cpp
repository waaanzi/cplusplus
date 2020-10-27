#include <iostream>
#include <iomanip>
#include <sstream>

int main() {
  {
    std::cout << std::endl;
    std::cout << 1 << std::endl;

    std::stringstream sm;
    sm << 12345;
    sm << "@163.com";
    std::cout << "sm.str(): " << sm.str() << std::endl;
  }
  {
    std::cout << std::endl;
    std::cout << 2 << std::endl;

    std::stringstream sm;
    sm << "54321@163.com";
    int i  = 0;
    sm >> i;
    std::cout << "i: " << i << std::endl;
  }
  {
    std::cout << std::endl;
    std::cout << 3 << std::endl;

    std::stringstream sm;
    sm << std::setfill('0') << std::setw(4) << 1;
    std::cout << "sm.str(): " << sm.str() << std::endl;
    sm.str("");
    sm << "0x" << std::hex << 123456;
    std::cout << "sm.str(): " << sm.str() << std::endl;
  }

  std::cin.get();

  return 0;
}