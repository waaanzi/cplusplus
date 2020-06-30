// C++ 标准库，变序型算法(mutating algorithm)
/*
reverse
reverse_copy
rotate
rotate_copy
next_permutation
prev_permutation
shuffle(C++11)
random_shuffle
partition
stable_partition
partition_copy
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <random>  // std::random_device
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
    // std::reverse 逆转范围中的元素顺序
    std::vector<int> vc;
    fill(vc, 1, 9);
    print("before reverse vc: ", vc);
    std::reverse(vc.begin(), vc.end());
    print(" after reverse vc: ", vc);
  }
  if (1) {
    // std::reverse_copy 创建一个范围的逆向副本
    std::vector<int> vc1;
    fill(vc1, 1, 9);
    std::vector<int> vc2;
    print("before reverse_copy vc1: ", vc1);
    print("before reverse_copy vc2: ", vc2);
    std::reverse_copy(vc1.begin(), vc1.end(), std::back_inserter(vc2));
    print(" after reverse_copy vc1: ", vc1);
    print(" after reverse_copy vc2: ", vc2);
  }
  if (1) {
    // std::rotate 旋转范围中的元素顺序
    std::vector<int> vc;
    fill(vc, 1, 9);
    print("before rotate vc: ", vc);
    std::rotate(vc.begin(), vc.begin() + 3, vc.end());
    print(" after rotate vc: ", vc);
  }
  if (1) {
    // std::rotate_copy 复制并旋转元素范围
    std::vector<int> vc1;
    fill(vc1, 1, 9);
    std::vector<int> vc2;
    print("before rotate_copy vc1: ", vc1);
    print("before rotate_copy vc2: ", vc2);
    std::rotate_copy(vc1.begin(), vc1.begin() + 3, vc1.end(),
                     std::back_inserter(vc2));
    print(" after rotate_copy vc1: ", vc1);
    print(" after rotate_copy vc2: ", vc2);
  }
  if (1) {
    // std::next_permutation 产生某个元素范围的按字典顺序的下一个较大的排列
    std::vector<int> vc;
    fill(vc, 1, 3);
    print("before next_permutation vc: ", vc);
    while (std::next_permutation(vc.begin(), vc.end())) {
      print(" after next_permutation vc: ", vc);
    }
  }
  if (1) {
    // std::prev_permutation 产生某个元素范围的按字典顺序的下一个较小的排列
    std::vector<int> vc{3, 2, 1};
    print("before prev_permutation vc: ", vc);
    while (std::prev_permutation(vc.begin(), vc.end())) {
      print(" after prev_permutation vc: ", vc);
    }
  }
  if (1) {
    // std::shuffle(C++11) 随机重排范围中的元素
    std::vector<int> vc;
    fill(vc, 1, 9);
    print("before shuffle vc: ", vc);
    std::shuffle(vc.begin(), vc.end(), std::random_device());
    print(" after shuffle vc: ", vc);
  }
  if (1) {
    // std::random_shuffle(C++14弃用C++17移除) 随机重排范围中的元素
    std::vector<int> vc;
    fill(vc, 1, 9);
    print("before random_shuffle vc: ", vc);
    std::random_shuffle(vc.begin(), vc.end());
    print(" after random_shuffle vc: ", vc);
  }
  if (1) {
    // std::partition 将范围中的元素分为两组
    std::vector<int> vc;
    fill(vc, 1, 9);
    print("before partition vc: ", vc);
    std::partition(vc.begin(), vc.end(), even);
    print(" after partition vc: ", vc);
  }
  if (1) {
    // std::stable_partition 将元素分为两组，同时保留其相对顺序
    std::vector<int> vc;
    fill(vc, 1, 9);
    print("before stable_partition vc: ", vc);
    std::stable_partition(vc.begin(), vc.end(), even);
    print(" after stable_partition vc: ", vc);
  }
  if (1) {
    // std::partition_copy 复制并将范围中的元素分为两组
    std::vector<int> vc;
    fill(vc, 1, 9);
    std::vector<int> vc_true;
    std::vector<int> vc_false;
    print("before partition_copy vc: ", vc);
    print("before partition_copy vc_true: ", vc_true);
    print("before partition_copy vc_false: ", vc_false);
    std::partition_copy(vc.begin(), vc.end(), std::back_inserter(vc_true),
                        std::back_inserter(vc_false), even);
    print(" after partition_copy vc: ", vc);
    print(" after partition_copy vc_true: ", vc_true);
    print(" after partition_copy vc_false: ", vc_false);
  }

  std::cin.get();
  return 0;
}