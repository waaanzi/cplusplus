#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>

/*
�����㷨(sorting algorithm)
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
    // std::sort ����
    std::vector<int> vc{1, 7, 3, 5, 2, 4, 6};
    print("before sort vc: ", vc);
    std::sort(vc.begin(), vc.end());
    print(" after sort vc: ", vc);
  }
  if (1) {
    // std::sort ����
    std::vector<int> vc{1, 7, 3, 5, 2, 4, 6};
    print("before sort vc: ", vc);
    std::sort(vc.begin(), vc.end(), greater<int>());
    print(" after sort vc: ", vc);
  }
  if (1) {
    // std::stable_sort �ȶ�����
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
    // std::partial_sort ��������
    std::vector<int> vc{1, 7, 3, 5, 2, 4, 6};
    print("before partial_sort vc: ", vc);
    std::partial_sort(vc.begin(), vc.begin() + 4, vc.end());
    print(" after partial_sort vc: ", vc);
  }
  if (1) {
    // std::partial_sort_copy ��������
    std::vector<int> vc{1, 7, 3, 5, 2, 4, 6};
    std::vector<int> vc1(3);
    print("before partial_sort_copy vc: ", vc);
    print("before partial_sort_copy vc: ", vc1);
    std::partial_sort_copy(vc.begin(), vc.end(), vc1.begin(), vc1.end());
    print(" after partial_sort_copy vc: ", vc);
    print(" after partial_sort_copy vc: ", vc1);
  }
  if (1) {
    // ע��copy��Χ
    // std::partial_sort_copy �Է�Χ�ڵ�Ԫ�ؽ��и��Ʋ���������
    std::vector<int> vc{1, 7, 3, 5, 2, 4, 6};
    std::vector<int> vc1(8);
    print("before partial_sort_copy vc: ", vc);
    print("before partial_sort_copy vc: ", vc1);
    std::partial_sort_copy(vc.begin(), vc.end(), vc1.begin(), vc1.end());
    print(" after partial_sort_copy vc: ", vc);
    print(" after partial_sort_copy vc: ", vc1);
  }
  if (1) {
    // std::nth_element �����ķ�Χ��������ȷ���䰴����Ԫ�ػ���
    std::vector<int> vc{1, 7, 3, 5, 2, 4, 6};
    print("before nth_element vc: ", vc);
    std::nth_element(vc.begin(), vc.begin() + 4, vc.end());
    print(" after nth_element vc: ", vc);
  }
  if (1) {
    // std::make_heap ��һ��Ԫ�ط�Χ������һ������
    std::vector<int> vc{1, 7, 3, 5, 2, 4, 6};
    print("before make_heap vc: ", vc);
    std::make_heap(vc.begin(), vc.end());
    print(" after make_heap vc: ", vc);

    // std::push_heap ��һ��Ԫ�ؼ��뵽һ������
    vc.emplace_back(8);
    std::push_heap(vc.begin(), vc.end());
    print(" after push_heap vc: ", vc);

    // std::pop_heap ���������Ƴ����Ԫ��
    std::pop_heap(vc.begin(), vc.end());
    print(" after pop_heap vc: ", vc);
    int e = vc.back();
    vc.pop_back();

    // std::sort_heap ��һ�����ѱ��һ�������������Ԫ�ط�Χ
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