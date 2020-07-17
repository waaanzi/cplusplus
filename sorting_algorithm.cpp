#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>

/*
排序算法(sorting algorithm)
sort
stable_sort
partial_sort
patial_sort_copy
nth_element
make_heap
push_heap
pop_heap
sort_heap
*/

using namespace std;

template <typename C>
void print(const std::string& pre, C container) {
  std::cout << pre;
  std::copy(container.begin(), container.end(),
            std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
}

int main() {
  if (1) {
    // std::sort 排序
    std::vector<int> vc{1, 7, 3, 5, 2, 4, 6};
    print("before sort vc: ", vc);
    std::sort(vc.begin(), vc.end());
    print(" after sort vc: ", vc);
  }
  if (1) {
    // std::sort 排序
    std::vector<int> vc{1, 7, 3, 5, 2, 4, 6};
    print("before sort vc: ", vc);
    std::sort(vc.begin(), vc.end(), greater<int>());
    print(" after sort vc: ", vc);
  }
  if (1) {
    // std::stable_sort 稳定排序
    vector<pair<int, string>> mp{{1, "a"}, {3, "b"}, {2, "c"}, {1, "d"}};
    cout << "before stable_sort mp:" << endl;
    for (auto& item : mp) {
      cout << "   first: " << item.first << " second: " << item.second << endl;
    }
    std::stable_sort(
        mp.begin(), mp.end(),
        [](const pair<int, string>& f, const pair<int, string>& s) {
          return f.first < s.first;
        });
    cout << "after stable_sort mp:" << endl;
    for (auto& item : mp) {
      cout << "   first: " << item.first << " second: " << item.second << endl;
    }
  }
  if (1) {
    // std::partial_sort 部分排序
    std::vector<int> vc{1, 7, 3, 5, 2, 4, 6};
    print("before partial_sort vc: ", vc);
    std::partial_sort(vc.begin(), vc.begin() + 4, vc.end());
    print(" after partial_sort vc: ", vc);
  }
  if (1) {
    // std::partial_sort_copy 部分排序
    std::vector<int> vc{1, 7, 3, 5, 2, 4, 6};
    std::vector<int> vc1(3);
    print("before partial_sort_copy vc: ", vc);
    print("before partial_sort_copy vc: ", vc1);
    std::partial_sort_copy(vc.begin(), vc.end(), vc1.begin(), vc1.end());
    print(" after partial_sort_copy vc: ", vc);
    print(" after partial_sort_copy vc: ", vc1);
  }
  if (1) {
    // 注意copy范围
    // std::partial_sort_copy 对范围内的元素进行复制并部分排序
    std::vector<int> vc{1, 7, 3, 5, 2, 4, 6};
    std::vector<int> vc1(8);
    print("before partial_sort_copy vc: ", vc);
    print("before partial_sort_copy vc: ", vc1);
    std::partial_sort_copy(vc.begin(), vc.end(), vc1.begin(), vc1.end());
    print(" after partial_sort_copy vc: ", vc);
    print(" after partial_sort_copy vc: ", vc1);
  }
  if (1) {
    // std::nth_element 给定的范围部分排序，确保其按给定元素划分
    std::vector<int> vc{1, 7, 3, 5, 2, 4, 6};
    print("before nth_element vc: ", vc);
    std::nth_element(vc.begin(), vc.begin() + 4, vc.end());
    print(" after nth_element vc: ", vc);
  }
  if (1) {
    // std::make_heap 从一个元素范围创建出一个最大堆
    std::vector<int> vc{1, 7, 3, 5, 2, 4, 6};
    print("before make_heap vc: ", vc);
    std::make_heap(vc.begin(), vc.end());
    print(" after make_heap vc: ", vc);

    // std::push_heap 将一个元素加入到一个最大堆
    vc.emplace_back(8);
    std::push_heap(vc.begin(), vc.end());
    print(" after push_heap vc: ", vc);

    // std::pop_heap 从最大堆中移除最大元素
    std::pop_heap(vc.begin(), vc.end());
    print(" after pop_heap vc: ", vc);
    int e = vc.back();
    vc.pop_back();

    // std::sort_heap 将一个最大堆变成一个按升序排序的元素范围
    std::sort_heap(vc.begin(), vc.end());
    print(" after sort_heap vc: ", vc);
  }

  {
    int a = 1;
    const int* pa = &a;
    int* b = nullptr;
    // const int** pb  = &b;
  }

  cin.get();

  return 0;
}