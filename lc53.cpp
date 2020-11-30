/*
leetcode53. ��������
����һ���������� nums���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�

ʾ��:
����: [-2,1,-3,4,-1,2,1,-5,4]
���: 6
����: ���������� [4,-1,2,1] �ĺ����Ϊ 6��
*/

int maxSubArray(int* nums, int numsSize) {
  int max_ending_here = nums[0];
  int max_so_for = nums[0];
  for (int i = 1; i < numsSize; ++i) {
    max_ending_here = (max_ending_here + nums[i]) > nums[i]
                          ? (max_ending_here + nums[i])
                          : nums[i];
    max_so_for = max_ending_here > max_so_for ? max_ending_here : max_so_for;
  }

  return max_so_for;
}

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int max_ending_here = nums[0];
    int max_so_for = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      max_ending_here = std::max(max_ending_here + nums[i], nums[i]);
      max_so_for = std::max(max_ending_here, max_so_for);
    }

    return max_so_for;
  }
};

#include <iostream>

int main() {
  {
    // C
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(nums) / sizeof(nums[0]);
    cout << maxSubArray(nums, n) << endl;
  }
  {
    // C++
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution s;
    cout << s.maxSubArray(nums) << endl;
  }

  cin.get();
  return 0;
}