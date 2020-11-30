/*
leetcode88. 合并两个有序数组
给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1
成为一个有序数组。

说明：
初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 

示例：
输入：
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
输出：[1,2,2,3,5,6]
 
*/

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
  // nums1为空场景
  if (0 == m) {
    while(--n >= 0) {
      nums1[n] = nums2[n];
    }
    return;
  }

  int k = m + n - 1;
  for(int i = m - 1, j = n -1; j >= 0 && k >= i;){
    // 注意nums1元素全部后移的场景
    if ((i >= 0) && (nums1[i] > nums2[j])){
      nums1[k] = nums1[i];
      --i;
    }else {
      nums1[k] = nums2[j];
      --j;
    }
    --k;
  }
}


#include <vector>
using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {}
};

#include <iostream>

template <typename C>
void print(C c, int size, char* s) {
  cout << s << ": ";
  for (int i = 0; i < size; ++i) {
    cout << c[i] << " ";
  }
  cout << endl;
}

int main() {
  {
    int vc1[] = {0}; int vc2[] = {1}; int m = 0, n=1;
    print(vc1, m, "vc1 before");
    
    print(vc2, n, "vc2");
    merge(vc1, m+n, m, vc2, n, n);

    print(vc1, m+n, "vc1 after");
  }
  {
    int vc1[] = {2,0};
    int vc2[] = {1};
    int m = 1, n = 1;
    print(vc1, m, "vc1 before");

    print(vc2, n, "vc2");
    merge(vc1, m + n, m, vc2, n, n);

    print(vc1, m + n, "vc1 after");
  }

  std::cin.get();
  return 0;
}

