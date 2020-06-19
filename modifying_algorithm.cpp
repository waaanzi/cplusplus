// C++ 标准库，更易型算法(modifying algorithm)
/*
copy
copy_if(C++11)
copy_n(C++11)
copy_backward
move(C++11)
move_backward(C++11)
transform
merge
swap_ranges
fill
fill_n
generate
generate_n
iota(C++11)
replace
replace_if
replace_copy
replace_copy_if
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

int main() {
  if (0) {
    if (1) {
      // std::copy 将某一范围的元素复制到一个新的位置

      std::list<int> l;
      std::vector<int> vc;
      fill(vc, 1, 9);

      print("before copy list: ", l);
      std::copy(vc.begin(), vc.end(), std::back_inserter(l));
      print("after copy list: ", l);
    }

    if (1) {
      // std::copy_if(C++11) 将某一范围的满足条件的元素复制到一个新的位置
      std::list<int> l;
      std::vector<int> vc;
      fill(vc, 1, 9);

      print("before copy_if list: ", l);
      std::copy_if(vc.begin(), vc.end(), std::back_inserter(l), even);
      print("after copy_if list: ", l);
    }

    if (1) {
      // std::copy_n(C++11) 将一定数目的元素复制到一个新的位置
      std::list<int> l;
      std::vector<int> vc;
      fill(vc, 1, 9);

      print("before copy_n list: ", l);
      std::copy_n(vc.begin(), 5, std::back_inserter(l));
      print("after copy_n list: ", l);
    }

    if (1) {
      // std::copy_backyard(C++11) 按从后往前的顺序复制一个范围内的元素
      std::list<int> l(10);
      std::vector<int> vc;
      fill(vc, 1, 9);

      print("before copy_backyard list: ", l);
      std::copy_backward(vc.begin(), vc.end(), l.end());
      print("after copy_backyard list: ", l);
    }
  }

  if (0) {
    if (1) {
      // std::move(C++11)
      std::list<int> l(10);
      std::vector<int> vc;
      fill(vc, 1, 9);

      print("before move vc(src): ", vc);
      print("before move list(dst): ", l);
      std::move(vc.begin(), vc.end(), l.begin());
      print("after move vc(src): ", vc);
      print("after move list(dst): ", l);
    }

    if (1) {
      // std::move(C++11)
      std::list<std::string> l(10);
      std::vector<std::string> vc{"hello", "big", "world"};

      print1("before move vc(src): ", vc);
      print1("before move list(dst): ", l);
      std::move(vc.begin(), vc.end(), l.begin());
      print1("after move vc(src): ", vc);
      print1("after move list(dst): ", l);
    }

    if (1) {
      // std::move_backward(C++11)
      std::list<int> l(10);
      std::vector<int> vc;
      fill(vc, 1, 9);

      print("before move_backward vc(src): ", vc);
      print("before move_backward list(dst): ", l);
      std::move_backward(vc.begin(), vc.end(), l.end());
      print("after move_backward vc(src): ", vc);
      print("after move_backward list(dst): ", l);
    }
  }
  if (0) {
    if (1) {
      // std::transform
      std::list<int> l(10);
      std::vector<int> vc;
      fill(vc, 1, 9);

      print("before transform vc(src): ", vc);
      print("before transform list(dst): ", l);
      std::transform(vc.begin(), vc.end(), l.begin(), plus1);
      print("after transform vc(src): ", vc);
      print("after transform list(dst): ", l);
    }
    if (1) {
      // std::transform
      std::list<int> l(10);
      std::vector<int> vc1;
      fill(vc1, 1, 9);
      std::vector<int> vc2;
      fill(vc2, 1, 9);

      print("before transform vc1(src): ", vc1);
      print("before transform vc2(src): ", vc2);
      print("before transform list(dst): ", l);
      std::transform(vc1.begin(), vc1.end(), vc2.begin(), l.begin(), plus2);
      print("after transform vc1(src): ", vc1);
      print("after transform vc2(src): ", vc2);
      print("after transform list(dst): ", l);
    }
  }

  if (0) {
    // std::merge
    if (1) {
      std::list<int> l;
      std::vector<int> vc1;
      fill(vc1, 1, 9);
      std::vector<int> vc2;
      fill(vc2, 1, 9);

      print("before merge vc1(src): ", vc1);
      print("before merge vc2(src): ", vc2);
      print("before merge list(dst): ", l);
      std::merge(vc1.begin(), vc1.end(), vc2.begin(), vc2.end(),
                 std::back_inserter(l));
      print("after merge vc1(src): ", vc1);
      print("after merge vc2(src): ", vc2);
      print("after merge list(dst): ", l);
    }

    if (1) {
      std::list<int> l;
      std::vector<int> vc1;
      fill(vc1, 1, 9);
      std::vector<int> vc2;
      fill(vc2, 1, 9);

      print("before merge vc1(src): ", vc1);
      print("before merge vc2(src): ", vc2);
      print("before merge list(dst): ", l);
      std::merge(vc1.begin(), vc1.end(), vc2.begin(), vc2.end(),
                 std::back_inserter(l), std::less<int>());
      print("after merge vc1(src): ", vc1);
      print("after merge vc2(src): ", vc2);
      print("after merge list(dst): ", l);
    }
  }

  if (0) {
    // std::swap_ranges
    std::vector<int> vc1;
    fill(vc1, 1, 9);
    std::vector<int> vc2;
    fill(vc2, 11, 19);
    print("before swap_ranges vc1: ", vc1);
    print("before swap_ranges vc2: ", vc2);
    std::swap_ranges(vc1.begin() + 3, vc1.end() - 2, vc2.begin() + 3);
    print("after swap_ranges vc1: ", vc1);
    print("after swap_ranges vc2: ", vc2);
  }
  if (0) {
    if (1) {
      // std::fill 将一个给定值复制赋值给一个范围内的每个元素
      std::vector<int> vc(10);
      std::fill(vc.begin(), vc.end(), 9);
      print("after fill vc: ", vc);
    }
    if (1) {
      // std::fill_n 将一个给定值复制赋值给一个范围内的 N 个元素
      std::vector<int> vc(10);
      std::fill_n(vc.begin(), 5, 9);
      print("after fill_n vc: ", vc);
    }
  }
  if (0) {
    if (1) {
      // std::generate 将相继的函数调用结果赋值给一个范围中的每个元素
      std::vector<int> vc(10);
      int i = 100;
      std::generate(vc.begin(), vc.end(), [&i]() { return ++i; });
      print("after generate vc: ", vc);
    }
    if (1) {
      // std::generate_n 将相继的函数调用结果赋值给一个范围中的 n 个元素
      std::vector<int> vc(10);
      int i = 100;
      std::generate_n(vc.begin(), 5, [&i]() { return ++i; });
      print("after generate_n vc: ", vc);
    }
  }
  if (0) {
    // std::iota(C++11) 用从起始值开始连续递增的值填充一个范围
    std::vector<int> vc(10);
    std::iota(vc.begin(), vc.end(), 100);  // #include <numeric>
    print("after iota vc: ", vc);
  }
  if (1) {
    if (1) {
      // std::replace 替换区间中特定值元素为另一个值
      std::vector<int> vc;
      fill(vc, 1, 9);
      print("before replace vc: ", vc);
      std::replace(vc.begin(), vc.end(), 5, 500);
      print("after replace vc: ", vc);
    }
    if (1) {
      // std::replace_if 替换区间中满足特定判别标准的元素为另一个值
      std::vector<int> vc;
      fill(vc, 1, 9);
      print("before replace_if vc: ", vc);
      std::replace_if(vc.begin(), vc.end(), even, 500);
      print("after replace_if vc: ", vc);
    }
    if (1) {
      // std::replace_copy
      // 复制一个范围内的元素，并将满足特定判别标准的元素替换为另一个值
      std::vector<int> vc1;
      fill(vc1, 1, 9);
      std::vector<int> vc2;
      print("before replace_copy vc1: ", vc1);
      print("before replace_copy vc2: ", vc2);
      std::replace_copy(vc1.begin(), vc1.end(), std::back_inserter(vc2), 5,
                        500);
      print("after replace_copy vc1: ", vc1);
      print("after replace_copy vc2: ", vc2);
    }
    if (1) {
      // std::replace_copy_if
      // 复制一个范围内的元素，并将满足特定判别标准的元素替换为另一个值
      std::vector<int> vc1;
      fill(vc1, 1, 9);
      std::vector<int> vc2;
      print("before replace_copy_if vc1: ", vc1);
      print("before replace_copy_if vc2: ", vc2);
      std::replace_copy_if(vc1.begin(), vc1.end(), std::back_inserter(vc2),
                           even, 500);
      print("after replace_copy_if vc1: ", vc1);
      print("after replace_copy_if vc2: ", vc2);
    }
  }

  std::cin.get();
  return 0;
}