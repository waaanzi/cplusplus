// C++ 标准库，移除型算法(removing algorithm)
/*
remove
remove_if
remove_copy
remove_copy_if
unique
unique_copy
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
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

template <typename It1, typename It2>
void print2(const std::string& pre, const It1& beg, const It2& end) {
  std::cout << pre;
  std::copy(beg, end, std::ostream_iterator<int>(std::cout, " "));
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

int plus1(int a) {
  return a + 10;
}

int plus2(int a, int b) {
  return a + b;
}

bool my_equal(int a, int b) {
  return a == b;
}

int main() {
  if (1) {
    // 通过以满足不移除的元素出现在范围起始的方式，迁移（以移动赋值的方式）范围中的元素进行移除。
    // 保持剩余元素的相对顺序，且不更改容器的物理大小。
    if (1) {
      // std::remove 移除满足特定判别标准的元素
      std::vector<int> vc;
      fill(vc, 1, 9);
      print("before remove vc: ", vc);
      auto it = std::remove(vc.begin(), vc.end(), 1);
      print("after remove vc: ", vc);
      print2("after remove vc: ", vc.begin(), it);
    }
    if (1) {
      // std::remove_if 移除满足特定判别标准的元素
      std::vector<int> vc;
      fill(vc, 1, 9);
      print("before remove_if vc: ", vc);
      auto it = std::remove_if(vc.begin(), vc.end(), even);
      print("after remove_if vc: ", vc);
      print2("after remove_if vc: ", vc.begin(), it);
    }
    if (1) {
      // std::remove_copy
      // 复制一个范围的元素，忽略满足特定判别标准的元素。源与目标范围不能重叠。
      std::vector<int> vc1;
      fill(vc1, 1, 9);
      std::vector<int> vc2;
      print("before remove_copy vc1: ", vc1);
      print("before remove_copy vc2: ", vc2);
      auto it =
          std::remove_copy(vc1.begin(), vc1.end(), std::back_inserter(vc2), 1);
      print("after remove_copy vc1: ", vc1);
      print("after remove_copy vc2: ", vc2);
    }
    if (1) {
      // std::remove_copy_if
      // 复制一个范围的元素，忽略满足特定判别标准的元素。源与目标范围不能重叠。
      std::vector<int> vc1;
      fill(vc1, 1, 9);
      std::vector<int> vc2;
      print("before remove_copy_if vc1: ", vc1);
      print("before remove_copy_if vc2: ", vc2);
      auto it = std::remove_copy_if(vc1.begin(), vc1.end(),
                                    std::back_inserter(vc2), even);
      print("after remove_copy_if vc1: ", vc1);
      print("after remove_copy_if vc2: ", vc2);
    }
    if (1) {
      // std::unique 移除范围内的连续重复元素
      // 通过用覆写要被擦除的元素的方式迁移范围中的元素进行移除。保持剩余元素的相对顺序，且不更改容器的物理大小
      std::vector<int> vc{1, 2, 2, 2, 3, 3, 4, 5, 6, 7, 8, 9};
      print("before unique vc: ", vc);
      auto it = std::unique(vc.begin(), vc.end());
      print("after unique vc: ", vc);
      print2("after unique vc: ", vc.begin(), it);
    }
    if (1) {
      // std::unique
      std::vector<int> vc{1, 2, 2, 2, 3, 3, 4, 5, 6, 7, 8, 9};
      print("before unique vc: ", vc);
      auto it = std::unique(vc.begin(), vc.end(), my_equal);
      print("after unique vc: ", vc);
      print2("after unique vc: ", vc.begin(), it);
    }
    if (1) {
      // std::unique_copy 创建某范围的不含连续重复元素的副本
      std::vector<int> vc1{1, 2, 2, 2, 3, 3, 4, 5, 6, 7, 8, 9};
      std::vector<int> vc2;
      print("before unique_copy vc1: ", vc1);
      print("before unique_copy vc2: ", vc2);
      auto it =
          std::unique_copy(vc1.begin(), vc1.end(), std::back_inserter(vc2));
      print("after unique_copy vc1: ", vc1);
      print("after unique_copy vc2: ", vc2);
    }
    if (1) {
      // std::unique_copy
      std::vector<int> vc1{1, 2, 2, 2, 3, 3, 4, 5, 6, 7, 8, 9};
      std::vector<int> vc2;
      print("before unique_copy vc1: ", vc1);
      print("before unique_copy vc2: ", vc2);
      auto it = std::unique_copy(vc1.begin(), vc1.end(),
                                 std::back_inserter(vc2), my_equal);
      print("after unique_copy vc1: ", vc1);
      print("after unique_copy vc2: ", vc2);
    }
  }

  std::cin.get();
  return 0;
}