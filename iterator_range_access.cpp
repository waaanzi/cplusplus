#include <initializer_list>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>

template <typename T>
void print(const std::string& pre, const T& it_begin, const T& it_end) {
  std::cout << pre << ":  ";
  auto it = it_begin;
  while (it != it_end) {
    std::cout << *it << " ";
    ++it;
  }
  std::cout << std::endl;
}

int main() {
  int sz[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  // C++11
  print("sz1", std::begin(sz), std::end(sz));

  // c++14
  print("sz2", std::cbegin(sz), std::cend(sz));
  print("sz3", std::rbegin(sz), std::rend(sz));
  print("sz4", std::crbegin(sz), std::crend(sz));

  std::vector<int> vc{1, 2, 3, 4, 5, 6, 7, 8, 9};
  print("vc", std::begin(vc), std::end(vc));

  std::initializer_list<int> lt{1, 2, 3, 4, 5, 6, 7, 8, 9};
  print("lt", std::begin(lt), std::end(lt));

  // rbegin rend
  {
    std::vector<int> vc{1, 2, 3, 4, 5, 6, 7, 8, 9};

    print("it: ", vc.begin(), vc.end());
    print("reverse it: ", vc.rbegin(), vc.rend());

    auto begin = vc.begin();
    auto end = vc.end();
    auto rbegin = vc.rbegin();
    auto rend = vc.rend();

    auto it = std::find(vc.begin(), vc.end(), 5);
    std::cout << "*it: " << *it << std::endl;
    auto rit = std::reverse_iterator<decltype(it)>(it);
    std::cout << "*rit: " << *rit << std::endl;
    auto rit_base = rit.base();
    std::cout << "*rit_base: " << *rit_base << std::endl;
    for (auto it = vc.begin(); it != vc.end(); ++it) {
    }
  }

  // shared_ptr reset
  {
    auto p = std::make_shared<int>(5);
    p.reset();
    if (p) {
      std::cout << "11 ";
    }else {
      std::cout << "22 ";
    }
  }

  class Op{
   public:
    Op(int n):num_(n) {}
    bool operator()(int) {
      return ++count_ == num_;
    }

   private:
     int num_;
     int count_=0;
  };

  // remove_if
  {

    std::vector<int> vc{1, 2, 3, 4, 5, 6, 7, 8, 9};
     print("vc: ", vc.begin(), vc.end());
     int count = 0;
     // auto it = std::remove_if(vc.begin(), vc.end(), [count](int a) mutable {
     // return ++count == 3;
     // });

     auto it = std::remove_if(vc.begin(), vc.end(), Op(3));

     vc.erase(it, vc.end());
     print("vc: ", vc.begin(), vc.end());
  }

  std::cin.get();
  return 0;
}