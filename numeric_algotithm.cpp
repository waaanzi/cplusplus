#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <string>
#include <vector>

/*
数值算法(numeric algorithm) <numeric>
accumulate
inner_product
adjacent_difference
partial_sum
*/

using namespace std;

template <typename C>
void print(const std::string& pre, C container) {
  std::cout << pre;
  std::copy(container.begin(), container.end(),
            std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
}

template <typename C>
void fill(C& container, int begin, int end) {
  for (auto i = begin; i <= end; i++) {
    container.emplace_back(i);
  }
}

bool even(int a) {
  return a % 2 == 0;
}

int main() {
  if (1) {
    // std::accumulate 对一个范围内的元素求和
    std::vector<int> vc;
    fill(vc, 1, 6);
    print("vc: ", vc);
    std::cout << "accumulate vc: " << std::accumulate(vc.begin(), vc.end(), 0)
              << std::endl;
  }
  if (1) {
    // std::inner_product 计算两个范围的元素的内积
    std::vector<int> vc1;
    fill(vc1, 2, 4);
    std::vector<int> vc2;
    fill(vc2, 3, 5);
    print("vc1: ", vc1);
    print("vc2: ", vc2);
    std::cout << "inner_product vc1 and vc2: "
              << std::inner_product(vc1.begin(), vc1.end(), vc2.begin(), 0)
              << std::endl;
  }
  if (1) {
    // std::adjacent_difference 计算范围内各相邻元素之间的差
    std::vector<int> vc{1, 3, 5, 7};
    print("vc: ", vc);
    std::adjacent_difference(vc.begin(), vc.end(), vc.begin());
    std::cout << "adjacent_difference vc: " << std::endl;
    print("vc: ", vc);
  }
  if (1) {
    // std::partial_sum 计算范围内元素的部分和
    std::vector<int> vc{1, 3, 5, 7};
    print("vc: ", vc);
    std::partial_sum(vc.begin(), vc.end(), vc.begin());
    std::cout << "partial_sum vc: " << std::endl;
    print("vc: ", vc);
  }

  cin.get();

  return 0;
}