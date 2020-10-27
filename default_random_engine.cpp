/*
随机数

std::default_random_engine

std::uniform_int_distribution
*/

#include <random>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <string>
#include <map>

int main() {

  int i = 20;
  std::default_random_engine engine;
  while (--i > 0) {
    /*(time(0))*/;
    std::uniform_int_distribution<int> distribution(1, 100);
    std::cout << distribution(engine) << std::endl;
  }

  i = 10;

  srand(time(0));
  while (--i > 0) {
    std::cout << rand() % 10 << std::endl;
  }

  getchar();
  return 0;
}