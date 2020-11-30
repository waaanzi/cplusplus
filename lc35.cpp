/*
leetcode35. 搜索插入位置
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引.
如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
你可以假设数组中无重复元素。

示例1:
输入: [1,3,5,6], 5
输出: 2

示例2:
输入: [1,3,5,6], 2
输出: 1

示例3:
输入: [1,3,5,6], 7
输出: 4

示例4:
输入: [1,3,5,6], 0
输出: 0
*/

int searchInsert(int* nums, int numsSize, int target) {
  int i = 0;
  while ((i < numsSize) && (nums[i] < target)){
    ++i;
  }
  return i;
}

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    auto it = nums.begin();
    while((it != nums.end()) && (*it < target)){
      ++it;
    }
    return it - nums.begin();
  }
};

#include <iostream>
int main() {
  {
    // C
    int nums[] = {1, 3, 5, 6};
    int target = 5;
    cout << searchInsert(nums, 4, 5) << endl;
  }
  {
    // C++
    std::vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    Solution s;
    cout << s.searchInsert(nums, target);
  }
  cin.get();
  return 0;
}