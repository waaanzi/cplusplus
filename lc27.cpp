/*
leetcode27. 移除元素
给你一个数组 nums 和一个值 val，你需要原地移除所有数值等于val的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。



示例 1:
给定 nums = [3,2,2,3], val = 3,
函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
你不需要考虑数组中超出新长度后面的元素。

示例 2:
给定 nums = [0,1,2,2,3,0,4,2], val = 2,
函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
注意这五个元素可为任意顺序。
你不需要考虑数组中超出新长度后面的元素。
*/

#include <vector>
using namespace std;


int removeElement(int* nums, int numsSize, int val) {
  int i = 0;
  for(int j = 0; j < numsSize; ++j){
    if (nums[j] != val){
      nums[i] = nums[j];
      ++i;
    }
  }
  return i;
}

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    auto it = nums.begin();
    while(it != nums.end()) {
      if (*it == val) {
        it = nums.erase(it);
      }else{
        ++it;
      }
    }
    return nums.size();
  }
};

#include <iostream>

void print(const vector<int>& nums) {
  cout << "nums : ";
  for (auto& i : nums) {
    cout << i << " ";
  }
  cout << std::endl;
}

void print(int* nums, int numsSize) {
  cout << "nums : ";
  for (int j = 0; j < numsSize; ++j) {
    cout << nums[j] << " ";
  }
  cout << std::endl;
}

int main() {
  {
    // C
    int nums[] = {2, 2, 3, 4, 5, 5, 6, 7};
    int n = sizeof(nums) / sizeof(nums[0]);
    print(nums, n);
    removeElement(nums, n, 5);
    print(nums, n);
  }
  {
    // C++
    std::vector<int> vc = {2, 2, 3, 4, 5, 5, 6, 7};
    print(vc);
    Solution s;
    s.removeElement(vc, 5);
    print(vc);
  }
  std::cin.get();
  return 0;
}
