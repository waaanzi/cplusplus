#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>

/*
已排序区间算法(sorted-range algorithm)
binary_search
includes
lower_bound
upper_bound
equal_range
merge
set_union
set_intersection
set_difference
set_symmetric_difference
inplace_merge
partition_point
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
    // std::binary_search 查找元素是否存在于某范围中
    std::vector<int> vc;
    fill(vc, 1, 6);
    print("vc: ", vc);
    std::cout << "find 6 in vc: " << std::boolalpha
              << std::binary_search(vc.begin(), vc.end(), 6) << std::endl;
    std::cout << "find 7 in vc: " << std::boolalpha
              << std::binary_search(vc.begin(), vc.end(), 7) << std::endl;
  }
  if (1) {
    // std::includes 范围是否包含另一范围
    std::vector<int> vc;
    fill(vc, 1, 6);
    std::vector<int> vc1;
    fill(vc1, 2, 4);
    std::vector<int> vc2;
    fill(vc2, 3, 7);
    print("vc: ", vc);
    print("vc1: ", vc1);
    print("vc2: ", vc2);
    std::cout << "vc1 in vc: " << std::boolalpha
              << std::includes(vc.begin(), vc.end(), vc1.begin(), vc1.end())
              << std::endl;
    std::cout << "vc2 in vc: " << std::boolalpha
              << std::includes(vc.begin(), vc.end(), vc2.begin(), vc2.end())
              << std::endl;
  }
  if (1) {
    // std::lower_bound 返回指向第一个不小于给定值的元素的迭代器
    std::vector<int> vc{1, 3, 5, 7};
    print("vc: ", vc);
    std::cout << "lower_bound 5 in vc: "
              << *std::lower_bound(vc.begin(), vc.end(), 5) << std::endl;
  }
  if (1) {
    // std::upper_bound 返回指向第一个大于给定值的元素的迭代器
    std::vector<int> vc{1, 3, 5, 7};
    print("vc: ", vc);
    std::cout << "upper_bound 5 in vc: "
              << *std::upper_bound(vc.begin(), vc.end(), 5) << std::endl;
  }
  if (1) {
    // std::equal_range 返回匹配特定键值的元素范围
    std::vector<int> vc{1, 3, 5, 7};
    print("vc: ", vc);
    auto p = std::equal_range(vc.begin(), vc.end(), 5);
    std::cout << "equal_range 5 in vc first pos: "
              << std::distance(vc.begin(), p.first) << std::endl;
    std::cout << "equal_range 5 in vc end pos: "
              << std::distance(vc.begin(), p.second) << std::endl;
  }
  if (1) {
    // std::merge 归并两个已排序区间到一个已排序区间
    std::vector<int> vc1{1, 3, 5, 7};
    print("vc1: ", vc1);
    std::vector<int> vc2{2, 4, 6, 8};
    print("vc2: ", vc2);
    std::vector<int> vc3;
    print("vc3: ", vc3);
    auto p = std::merge(vc1.begin(), vc1.end(), vc2.begin(), vc2.end(),
                        std::back_inserter(vc3));
    std::cout << "merge vc1 and vc2 to vc3: " << std::endl;
    print("vc3: ", vc3);
  }
  if (1) {
    // std::set_union 计算并集
    std::vector<int> vc1{1, 3, 5, 7};
    print("vc1: ", vc1);
    std::vector<int> vc2{2, 4, 6, 8};
    print("vc2: ", vc2);
    std::vector<int> vc3;
    print("vc3: ", vc3);
    auto p = std::set_union(vc1.begin(), vc1.end(), vc2.begin(), vc2.end(),
                            std::back_inserter(vc3));
    std::cout << "set_union vc1 and vc2 to vc3: " << std::endl;
    print("vc3: ", vc3);
  }
  if (1) {
    // std::set_intersection 计算交集
    std::vector<int> vc1{1, 2, 3, 5, 7};
    print("vc1: ", vc1);
    std::vector<int> vc2{2, 4, 6, 8};
    print("vc2: ", vc2);
    std::vector<int> vc3;
    print("vc3: ", vc3);
    auto p = std::set_intersection(vc1.begin(), vc1.end(), vc2.begin(),
                                   vc2.end(), std::back_inserter(vc3));
    std::cout << "set_intersection vc1 and vc2 to vc3: " << std::endl;
    print("vc3: ", vc3);
  }
  if (1) {
    // std::set_difference 计算差集
    std::vector<int> vc1{1, 2, 3, 5, 7};
    print("vc1: ", vc1);
    std::vector<int> vc2{2, 4, 6, 8};
    print("vc2: ", vc2);
    std::vector<int> vc3;
    print("vc3: ", vc3);
    auto p = std::set_difference(vc1.begin(), vc1.end(), vc2.begin(), vc2.end(),
                                 std::back_inserter(vc3));
    std::cout << "set_difference vc1 and vc2 to vc3: " << std::endl;
    print("vc3: ", vc3);
  }
  if (1) {
    // std::set_symmetric_difference 计算对称差
    std::vector<int> vc1{1, 2, 3, 5, 7};
    print("vc1: ", vc1);
    std::vector<int> vc2{2, 4, 6, 8};
    print("vc2: ", vc2);
    std::vector<int> vc3;
    print("vc3: ", vc3);
    auto p = std::set_symmetric_difference(vc1.begin(), vc1.end(), vc2.begin(),
                                           vc2.end(), std::back_inserter(vc3));
    std::cout << "set_symmetric_difference vc1 and vc2 to vc3: " << std::endl;
    print("vc3: ", vc3);
  }
  if (1) {
    // std::inplace_merge 归并两个相继已排序区间到一个排序区间（稳定排序）
    std::vector<std::pair<int, string>> vc{
        {1, "tom"}, {3, "lee"}, {1, "john"}, {5, "kate"}};
    for (auto item : vc) {
      std::cout << "{" << item.first << ", " << item.second << "}" << std::endl;
    }
    std::inplace_merge(vc.begin(), vc.begin() + 2, vc.end());
    std::cout << "after inplace_merge: " << std::endl;
    for (auto item : vc) {
      std::cout << "{" << item.first << ", " << item.second << "}" << std::endl;
    }
  }
  if (1) {
    // std::partition_point 定位已划分范围的划分点
    std::vector<int> vc;
    fill(vc, 1, 6);
    print("vc: ", vc);
    std::partition(vc.begin(), vc.end(), even);
    print("vc: ", vc);
    auto it = std::partition_point(vc.begin(), vc.end(), even);
    std::cout << "partition_point vc of noteven: "
              << std::distance(vc.begin(), it) << std::endl;
  }

  cin.get();

  return 0;
}