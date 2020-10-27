#include <iterator>
#include <algorithm>
#include <string>
#include <deque>
#include <iostream>

using namespace std;

int main() {
  deque<int> d;
  std::fill_n(std::front_inserter(d), 1, 1);
  std::fill_n(std::front_inserter(d), 1, 2);
  std::fill_n(std::front_inserter(d), 1, 3);

  std::fill_n(std::back_inserter(d), 1, 4);
  std::fill_n(std::back_inserter(d), 1, 5);
  std::fill_n(std::back_inserter(d), 1, 6);

  std::fill_n(std::inserter(d, d.begin() + 3), 1, 100);
  for(auto str : d)
    std::cout << str << "  ";
  std::cin.get();
  return 0;
}