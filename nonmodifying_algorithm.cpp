// C++ 标准库，非更易型算法(nonmodifying algorithm)
/*
count
count_if
min_element
max_element
minmax_element(C++11)
find
find_if
find_if_not
search_n
search
find_end
find_first_of
adjacent_find
equal
is_permutation(C++11)
mismatch
lexicographical_compare
is_sorted(C++11)
is_sorted_until(C++11)
is_partitioned(C++11)
partition_point(C++11)
is_heap(C++11)
is_heap_until(C++11)
all_of(C++11)
any_of(C++11)
none_of(C++11)
*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

template <typename C>
void fill(C& container, int begin, int end) {
  for (auto i = begin; i <= end; i++) {
    container.emplace_back(i);
  }
}

template <typename C>
void print(const std::string& pre, C container) {
  std::cout << pre;
  std::copy(container.begin(), container.end(),
            std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
}

template <typename C>
void print1(const std::string& pre, C container) {
  std::cout << pre;
  for (auto it = container.begin(); it != container.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

bool even(int a) {
  return a % 2 == 0;
}

bool my_equal(int a, int b) {
  return a == b;
}

bool my_less(int a, int b) {
  std::cout << "my_less a:" << a << " b:" << b << " =" << (a < b) << std::endl;
  return a < b;
}

#include <chrono>
#include <ctime>

int main() {
  // 元素计数
  if (0) {
    // count count_if
    std::vector<int> vc;
    fill(vc, 1, 9);
    vc.emplace_back(9);
    vc.emplace_back(9);

    int count5 = std::count(vc.begin(), vc.end(), 5);
    int count9 = std::count(vc.begin(), vc.end(), 9);

    print1("vc: ", vc);
    std::cout << "count of 5 in vc: " << count5 << std::endl;
    std::cout << "count of 9 in vc: " << count9 << std::endl;

    int count = std::count_if(vc.begin(), vc.end(), even);
    std::cout << "count of even numbers in vc: " << count << std::endl;
  }
  // 最大值最小值
  if (0) {
    // min_element max_element min_max_element
    std::vector<int> vc;
    vc.emplace_back(1);
    fill(vc, 1, 9);
    vc.emplace_back(9);
    vc.emplace_back(9);
    print1("vc: ", vc);

    auto min = std::min_element(vc.begin(), vc.end());
    std::cout << "No." << std::distance(vc.begin(), min)
              << " is the min element." << std::endl;
    auto max = std::max_element(vc.begin(), vc.end());
    std::cout << "No." << std::distance(vc.begin(), max)
              << " is the max element." << std::endl;
    auto min_max = std::minmax_element(vc.begin(), vc.end());
    std::cout << "min_max is No." << std::distance(vc.begin(), min_max.first)
              << " and No." << std::distance(vc.begin(), min_max.second)
              << std::endl;
  }
  // 查找元素
  if (0) {
    // find find_if find_if_not(C++11)
    std::vector<int> vc;
    vc.emplace_back(1);
    fill(vc, 1, 9);
    print("vc: ", vc);

    if (1) {
      auto it = std::find(vc.begin(), vc.end(), 1);
      std::cout << "the first element equals 1 is No."
                << std::distance(vc.begin(), it) << std::endl;
      auto it1 = std::find(vc.begin(), vc.end(), 10);
      if (it1 != vc.end()) {
        std::cout << "the first element equals 10 is No."
                  << std::distance(vc.begin(), it1) << std::endl;
      } else {
        std::cout << "no element equals 10 in vc." << std::endl;
      }
    }

    if (1) {
      auto it = std::find_if(vc.begin(), vc.end(), even);
      std::cout << "the first even element is No."
                << std::distance(vc.begin(), it) << std::endl;
    }
    if (1) {
      auto it = std::find_if_not(vc.begin(), vc.end(), even);
      std::cout << "the first odd element is No."
                << std::distance(vc.begin(), it) << std::endl;
    }
    if (1) {
      // search_n 查找前n个连续匹配值
      auto it = std::search_n(vc.begin(), vc.end(), 2, 1);
      std::cout << "2  consecutive element equal 1 start at No."
                << std::distance(vc.begin(), it) << std::endl;

      // 由于不在早期的STL规范中，所以是binary predicate 而不是unary predicate
      auto it1 = std::search_n(vc.begin(), vc.end(), 2, 1, my_equal);
      std::cout << "2  consecutive element equal 1 start at No."
                << std::distance(vc.begin(), it1) << std::endl;
    }

    if (1) {
      // search 查找第一个子区间
      std::list<int> l;
      fill(l, 3, 6);
      print("list: ", l);
      auto it = std::search(vc.begin(), vc.end(), l.begin(), l.end());
      std::cout << "the 3 4 5 6 position in vc is No."
                << std::distance(vc.begin(), it) << std::endl;
      // 注意构造函数参数 searcher
      // auto it1 = std::search(vc.begin(), vc.end(),
      //                        std::boyer_moore_searcher(sub.begin(),
      //                        sub.end()));
      // std::cout << "the 3 4 5 6 position in vc is No."
      //           << std::distance(vc.begin(), it1) << std::endl;
    }

    if (1) {
      // find_end 查找最后一个子区间 （叫做search_end更合适）
      fill(vc, 3, 6);
      std::list<int> l;
      fill(l, 3, 6);
      print("vc: ", vc);
      print("list: ", l);
      auto it = std::find_end(vc.begin(), vc.end(), l.begin(), l.end());
      std::cout << "the last 3 4 5 6 position in vc is No."
                << std::distance(vc.begin(), it) << std::endl;
    }

    if (1) {
      // find_first_of 查找某些元素第一次出现位置
      std::list<int> l;
      fill(l, 3, 6);
      print("vc: ", vc);
      print("list: ", l);
      auto it = std::find_first_of(vc.begin(), vc.end(), l.begin(), l.end());
      std::cout << "the first 3 4 5 6 position in vc is No."
                << std::distance(vc.begin(), it) << std::endl;
    }
    if (1) {
      // adjacent_find 查找两个连续且相等的元素
      std::list<int> l;
      fill(l, 3, 6);
      fill(l, 6, 7);
      fill(l, 7, 8);
      print("list: ", l);
      auto it = std::adjacent_find(l.begin(), l.end());
      std::cout
          << "the first two same consecutive element position in list is No."
          << std::distance(l.begin(), it) << std::endl;
    }
  }
  // 区间的比较
  if (1) {
    if (0) {
      // equal 检查相等性
      std::vector<int> vc1;
      std::vector<int> vc2;
      std::vector<int> vc3;
      std::vector<int> vc4;
      fill(vc1, 1, 3);
      fill(vc2, 1, 4);
      fill(vc3, 1, 5);
      fill(vc4, 1, 4);
      print("vc1: ", vc1);
      print("vc2: ", vc2);
      print("vc3: ", vc3);
      print("vc4: ", vc4);
      std::cout << "vc1 and vc2 is "
                << (std::equal(vc1.begin(), vc1.end(), vc2.begin(), vc2.end())
                        ? ""
                        : "not ")
                << "equal." << std::endl;
      std::cout << "vc2 and vc3 is "
                << (std::equal(vc2.begin(), vc2.end(), vc3.begin()) ? ""
                                                                    : "not ")
                << "equal." << std::endl;
      std::cout << "vc2 and vc3 is "
                << (std::equal(vc2.begin(), vc2.end(), vc3.begin(), vc3.end())
                        ? ""
                        : "not ")
                << "equal." << std::endl;
      std::cout << "vc2 and vc4 is "
                << (std::equal(vc2.begin(), vc2.end(), vc4.begin(), my_equal)
                        ? ""
                        : "not ")
                << "equal." << std::endl;
      // std::equal(vc3.begin(), vc3.end(), vc4.begin(), my_equal); 报错
    }

    if (0) {
      // is_permutation 测试不定序的相等性
      std::vector<int> vc1{3, 2, 1};
      std::vector<int> vc2;
      std::vector<int> vc3;
      std::vector<int> vc4{4, 2, 1, 3};
      fill(vc2, 1, 4);
      fill(vc3, 1, 5);
      print("vc1: ", vc1);
      print("vc2: ", vc2);
      print("vc3: ", vc3);
      print("vc4: ", vc4);
      std::cout << "vc1 and vc2 is "
                << (std::is_permutation(vc1.begin(), vc1.end(), vc2.begin(),
                                        vc2.end())
                        ? ""
                        : "not ")
                << "equal." << std::endl;
      std::cout << "vc2 and vc3 is "
                << (std::is_permutation(vc2.begin(), vc2.end(), vc3.begin())
                        ? ""
                        : "not ")
                << "equal." << std::endl;
      std::cout << "vc2 and vc3 is "
                << (std::is_permutation(vc2.begin(), vc2.end(), vc3.begin(),
                                        vc3.end())
                        ? ""
                        : "not ")
                << "equal." << std::endl;
      std::cout << "vc3 and vc4 is "
                << (std::is_permutation(vc2.begin(), vc2.end(), vc4.begin(),
                                        my_equal)
                        ? ""
                        : "not ")
                << "equal." << std::endl;
      //  std::cout << "vc3 and vc4 is "
      //            << (std::is_permutation(vc3.begin(), vc3.end(), vc4.begin(),
      //            my_equal) ? "" : "not ") << "equal." << std::endl; 报错
    }
    if (0) {
      // mismatch 查找第一处不同
      std::vector<int> vc1{3, 2, 1};
      std::vector<int> vc2;
      std::vector<int> vc3;
      std::vector<int> vc4{4, 2, 1, 3};
      fill(vc2, 1, 4);
      fill(vc3, 1, 5);
      print("vc1: ", vc1);
      print("vc2: ", vc2);
      print("vc3: ", vc3);
      print("vc4: ", vc4);

      auto pair1 = std::mismatch(vc1.begin(), vc1.end(), vc2.begin());
      std::cout << "vc1 and vc2 mismatch: No."
                << std::distance(vc1.begin(), pair1.first) << " : No."
                << std::distance(vc2.begin(), pair1.second) << std::endl;

      auto pair11 =
          std::mismatch(vc1.begin(), vc1.end(), vc2.begin(), my_equal);
      std::cout << "vc1 and vc2 mismatch: No."
                << std::distance(vc1.begin(), pair11.first) << " : No."
                << std::distance(vc2.begin(), pair11.second) << std::endl;

      auto pair2 =
          std::mismatch(vc2.begin(), vc2.end(), vc3.begin(), vc3.end());
      std::cout << "vc2 and vc3 mismatch: No."
                << std::distance(vc2.begin(), pair2.first) << " : No."
                << std::distance(vc3.begin(), pair2.second) << std::endl;

      auto pair22 = std::mismatch(vc2.begin(), vc2.end(), vc3.begin(),
                                  vc3.end(), my_equal);
      std::cout << "vc2 and vc3 mismatch: No."
                << std::distance(vc2.begin(), pair22.first) << " : No."
                << std::distance(vc3.begin(), pair22.second) << std::endl;

      auto pair3 = std::mismatch(vc3.begin(), vc3.end(), vc4.begin(), vc4.end(),
                                 my_equal);
      std::cout << "vc3 and vc4 mismatch: No."
                << std::distance(vc3.begin(), pair3.first) << " : No."
                << std::distance(vc4.begin(), pair3.second) << std::endl;

      auto pair4 = std::mismatch(vc3.begin(), vc3.end(), vc2.begin(), vc2.end(),
                                 my_equal);
      std::cout << "vc3 and vc2 mismatch: No."
                << std::distance(vc3.begin(), pair4.first) << " : No."
                << std::distance(vc2.begin(), pair4.second) << std::endl;
    }
    if (0) {
      // lexicographical_compare 检验“小于”
      std::vector<int> vc1{3, 2, 1};
      std::vector<int> vc2;
      std::vector<int> vc3;
      std::vector<int> vc4{4, 2, 1, 3};
      fill(vc2, 1, 4);
      fill(vc3, 1, 5);
      print("vc1: ", vc1);
      print("vc2: ", vc2);
      print("vc3: ", vc3);
      print("vc4: ", vc4);

      std::cout << "vc1 lexicographical "
                << (std::lexicographical_compare(vc1.begin(), vc1.end(),
                                                 vc2.begin(), vc2.end())
                        ? ""
                        : "not ")
                << "less than vc2 ." << std::endl;
      std::cout << "vc2 lexicographical "
                << (std::lexicographical_compare(vc2.begin(), vc2.end(),
                                                 vc3.begin(), vc3.end(),
                                                 std::greater<int>())
                        ? ""
                        : "not ")
                << "less than vc3 ." << std::endl;
      std::cout << "vc3 lexicographical "
                << (std::lexicographical_compare(vc3.begin(), vc3.end(),
                                                 vc2.begin(), vc2.end(),
                                                 std::greater<int>())
                        ? ""
                        : "not ")
                << "less than vc2 ." << std::endl;
      std::cout << "vc3 lexicographical "
                << (std::lexicographical_compare(vc3.begin(), vc3.end(),
                                                 vc4.begin(), vc4.end(),
                                                 std::greater<int>())
                        ? ""
                        : "not ")
                << "less than vc4 ." << std::endl;
    }
  }
  // 区间是否排序或者局部排序
  if (0) {
    // is_sorted(C++11) 区间是否排序
    std::vector<int> vc1{3, 2, 1};
    std::vector<int> vc2;
    fill(vc2, 1, 3);
    std::vector<int> vc3;
    fill(vc3, 1, 3);
    fill(vc3, 1, 3);
    print("vc1: ", vc1);
    print("vc2: ", vc2);
    print("vc3: ", vc3);
    std::cout << "vc1 is "
              << (std::is_sorted(vc1.begin(), vc1.end()) ? "" : "not ")
              << "sorted" << std::endl;
    std::cout << "vc2 is "
              << (std::is_sorted(vc2.begin(), vc2.end()) ? "" : "not ")
              << "sorted" << std::endl;
    std::cout << "vc3 is "
              << (std::is_sorted(vc3.begin(), vc3.end()) ? "" : "not ")
              << "sorted" << std::endl;

    // is_sorted_until(C++11) 返回区间第一个破坏排序的元素
    auto it1 = std::is_sorted_until(vc1.begin(), vc1.end());
    std::cout << "until No." << std::distance(vc1.begin(), it1)
              << " vc1 is sorted" << std::endl;
    auto it2 = std::is_sorted_until(vc2.begin(), vc2.end());
    std::cout << "until No." << std::distance(vc2.begin(), it2)
              << " vc2 is sorted" << std::endl;
    auto it3 = std::is_sorted_until(vc3.begin(), vc3.end());
    std::cout << "until No." << std::distance(vc3.begin(), it3)
              << " vc3 is sorted" << std::endl;
  }

  // 检验是否被分割
  if (0) {
    std::vector<int> vc1{1, 3, 5, 2, 4, 6};
    std::vector<int> vc2{2, 4, 6, 1, 3, 5};
    std::vector<int> vc3;
    std::vector<int> vc4{2, 4, 6, 8};
    ;
    fill(vc3, 1, 6);

    print("vc1: ", vc1);
    print("vc2: ", vc2);
    print("vc3: ", vc3);
    print("vc3: ", vc4);
    // std::is_partitioned
    std::cout << "vc1 is "
              << (std::is_partitioned(vc1.begin(), vc1.end(), even) ? ""
                                                                    : "not ")
              << "partitioned" << std::endl;
    std::cout << "vc2 is "
              << (std::is_partitioned(vc2.begin(), vc2.end(), even) ? ""
                                                                    : "not ")
              << "partitioned" << std::endl;
    std::cout << "vc3 is "
              << (std::is_partitioned(vc3.begin(), vc3.end(), even) ? ""
                                                                    : "not ")
              << "partitioned" << std::endl;
    std::cout << "vc4 is "
              << (std::is_partitioned(vc4.begin(), vc4.end(), even) ? ""
                                                                    : "not ")
              << "partitioned" << std::endl;
    // std::partition_point
    auto it1 = std::partition_point(vc1.begin(), vc1.end(), even);
    std::cout << "vc1: the No." << std::distance(vc1.begin(), it1)
              << " is partition_point " << std::endl;
    auto it2 = std::partition_point(vc2.begin(), vc2.end(), even);
    std::cout << "vc2: the No." << std::distance(vc2.begin(), it2)
              << " is partition_point" << std::endl;
    auto it3 = std::partition_point(vc3.begin(), vc3.end(), even);
    std::cout << "vc3: the No." << std::distance(vc3.begin(), it3)
              << " is partition_point" << std::endl;
    auto it4 = std::partition_point(vc4.begin(), vc4.end(), even);
    std::cout << "vc4: the No." << std::distance(vc4.begin(), it4)
              << " is partition_point " << std::endl;
  }

  // 区间元素是否构成大堆
  if (0) {
    // is_heap(C++11) 区间元素是否构成大堆
    std::vector<int> vc1{3, 2, 1};
    std::vector<int> vc2;
    fill(vc2, 1, 3);
    std::vector<int> vc3{3, 2, 1, 3, 2, 1};
    print("vc1: ", vc1);
    print("vc2: ", vc2);
    print("vc3: ", vc3);
    std::cout << "vc1 is "
              << (std::is_heap(vc1.begin(), vc1.end(), my_less) ? "" : "not ")
              << "heap" << std::endl;
    std::cout << "vc2 is "
              << (std::is_heap(vc2.begin(), vc2.end()) ? "" : "not ") << "heap"
              << std::endl;
    std::cout << "vc2 is "
              << (std::is_heap(vc2.begin(), vc2.end(), std::greater<int>())
                      ? ""
                      : "not ")
              << "heap" << std::endl;
    std::cout << "vc3 is "
              << (std::is_heap(vc3.begin(), vc3.end()) ? "" : "not ") << "heap"
              << std::endl;

    // is_heap_until(C++11) 查找能成为最大堆的最大子范围
    auto it1 = std::is_heap_until(vc1.begin(), vc1.end());
    std::cout << "until No." << std::distance(vc1.begin(), it1)
              << " vc1 is heap" << std::endl;
    auto it2 = std::is_heap_until(vc2.begin(), vc2.end());
    std::cout << "until No." << std::distance(vc2.begin(), it2)
              << " vc2 is heap" << std::endl;
    auto it3 = std::is_heap_until(vc3.begin(), vc3.end());
    std::cout << "until No." << std::distance(vc3.begin(), it3)
              << " vc3 is heap" << std::endl;
  }

  // 区间元素是否构成大堆
  if (0) {
    // is_heap(C++11) 区间元素是否构成大堆
    std::vector<int> vc1{3, 2, 1};
    std::vector<int> vc2;
    fill(vc2, 1, 3);
    std::vector<int> vc3{3, 2, 1, 3, 2, 1};
    print("vc1: ", vc1);
    print("vc2: ", vc2);
    print("vc3: ", vc3);
    std::cout << "vc1 is "
              << (std::is_heap(vc1.begin(), vc1.end(), my_less) ? "" : "not ")
              << "heap" << std::endl;
    std::cout << "vc2 is "
              << (std::is_heap(vc2.begin(), vc2.end()) ? "" : "not ") << "heap"
              << std::endl;
    std::cout << "vc2 is "
              << (std::is_heap(vc2.begin(), vc2.end(), std::greater<int>())
                      ? ""
                      : "not ")
              << "heap" << std::endl;
    std::cout << "vc3 is "
              << (std::is_heap(vc3.begin(), vc3.end()) ? "" : "not ") << "heap"
              << std::endl;

    // is_heap_until(C++11) 查找能成为最大堆的最大子范围
    auto it1 = std::is_heap_until(vc1.begin(), vc1.end());
    std::cout << "until No." << std::distance(vc1.begin(), it1)
              << " vc1 is heap" << std::endl;
    auto it2 = std::is_heap_until(vc2.begin(), vc2.end());
    std::cout << "until No." << std::distance(vc2.begin(), it2)
              << " vc2 is heap" << std::endl;
    auto it3 = std::is_heap_until(vc3.begin(), vc3.end());
    std::cout << "until No." << std::distance(vc3.begin(), it3)
              << " vc3 is heap" << std::endl;
  }

  // 检查区间元素
  if (1) {
    std::vector<int> vc1{1, 2, 3};
    std::vector<int> vc2{1, 3, 5};
    std::vector<int> vc3{2, 4, 6};
    std::vector<int> vc4;
    print("vc1: ", vc1);
    print("vc2: ", vc2);
    print("vc3: ", vc3);
    print("vc4: ", vc4);
    // std::all_of
    std::cout << " all_of  vc1 is "
              << (std::all_of(vc1.begin(), vc1.end(), even) ? "" : "not ")
              << "even" << std::endl;
    std::cout << " all_of  vc2 is "
              << (std::all_of(vc2.begin(), vc2.end(), even) ? "" : "not ")
              << "even" << std::endl;
    std::cout << " all_of  vc3 is "
              << (std::all_of(vc3.begin(), vc3.end(), even) ? "" : "not ")
              << "even" << std::endl;
    std::cout << " all_of  vc4 is "
              << (std::all_of(vc4.begin(), vc4.end(), even) ? "" : "not ")
              << "even" << std::endl
              << std::endl;

    // std::any_of
    std::cout << " any_of  vc1 is "
              << (std::any_of(vc1.begin(), vc1.end(), even) ? "" : "not ")
              << "even" << std::endl;
    std::cout << " any_of  vc2 is "
              << (std::any_of(vc2.begin(), vc2.end(), even) ? "" : "not ")
              << "even" << std::endl;
    std::cout << " any_of  vc3 is "
              << (std::any_of(vc3.begin(), vc3.end(), even) ? "" : "not ")
              << "even" << std::endl;
    std::cout << " any_of  vc4 is "
              << (std::any_of(vc4.begin(), vc4.end(), even) ? "" : "not ")
              << "even" << std::endl
              << std::endl;

    // none_of
    std::cout << " none_of vc1 is "
              << (std::none_of(vc1.begin(), vc1.end(), even) ? "" : "not ")
              << "even" << std::endl;
    std::cout << " none_of vc2 is "
              << (std::none_of(vc2.begin(), vc2.end(), even) ? "" : "not ")
              << "even" << std::endl;
    std::cout << " none_of vc3 is "
              << (std::none_of(vc3.begin(), vc3.end(), even) ? "" : "not ")
              << "even" << std::endl;
    std::cout << " none_of vc4 is "
              << (std::none_of(vc4.begin(), vc4.end(), even) ? "" : "not ")
              << "even" << std::endl
              << std::endl;
  }
  std::cin.get();
  return 0;
}
