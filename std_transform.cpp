#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <iterator>
#include <functional>

std::map<int, int> mp{
  {1, 11},
  {2, 22},
  {3, 33},
  {4, 44}
};

int main() {
  std::vector<int> vc;
  std::transform(mp.begin(), mp.end(), std::back_inserter(vc),
                 std::bind(&std::map<int, int>::value_type::second, std::placeholders::_1));

  for (auto i : vc) {
    std::cout << i << std::endl; // output: 11 22 33 44
  }

  std::cin.get();
  return 0;
}