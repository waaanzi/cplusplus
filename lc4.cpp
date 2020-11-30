/*
leetcode4. 寻找两个正序数组的中位数
给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数。

示例 1：
输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2

示例 2：
输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5

示例 3：
输入：nums1 = [0,0], nums2 = [0,0]
输出：0.00000

示例 4：
输入：nums1 = [], nums2 = [1]
输出：1.00000

示例 5：
输入：nums1 = [2], nums2 = []
输出：2.00000
*/

double findMedianSortedArrays(int* nums1,
                              int nums1Size,
                              int* nums2,
                              int nums2Size) {
  int target = (nums1Size + nums2Size) / 2 + 1;
  bool need_another = (nums1Size + nums2Size) % 2 == 0;
  int i = 0;
  int j = 0;

  int pre_min = 0;
  while (i < nums1Size || j < nums2Size){
    int min = 0;

    if (i < nums1Size && j < nums2Size){
      if (nums1[i] < nums2[j]) {
        min = nums1[i];
        ++i;
      }else{
        min = nums2[j];
        ++j;
      }
    } else if (i < nums1Size){
      min = nums1[i];
      ++i;
    }else {
      min = nums2[j];
      ++j;
    }

    if (i + j == target){
      if (need_another) {
        return (double)(pre_min + min) / 2;
      } else {
        return min;
      }
    }

    pre_min = min;
  }

  return 0;
}

#include <algorithm>
#include <vector>
using namespace std;
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    std::vector<int> vc;
    std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(),
               std::back_inserter(vc));
    if (vc.size() % 2) {
      return vc[vc.size() / 2];
    } else {
      return (double)(vc[vc.size() / 2] + vc[(vc.size() - 1) / 2]) / 2;
    }
  }
};

#include <iostream>

int main() {
  {
    int nums1[] = {1, 3};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2[] = {2};
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    cout << findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size) << endl;
  }
  {
  vector<int> nums1{1, 2};
  vector<int> nums2{3, 4};
  Solution s;
  cout << s.findMedianSortedArrays(nums1, nums2) << endl;
  }
  cin.get();
  return 0;
}