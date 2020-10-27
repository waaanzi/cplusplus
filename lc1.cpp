#include <iostream>
#include <unordered_map>

/*
给定一个整数数列，找出其中和为特定值的那两个数。

你可以假设每个输入都只会有一种答案，同样的元素不能被重用。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/

using namespace std;
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
      auto it = map.find(target - nums[i]);
      if (it != map.end()) {
        result.push_back(it->second);
        result.push_back(i);
        break;
      } else {
        map[nums[i]] = i;
      }
    }
    return result;
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 3, 5};
  int target = 6;

  do {
    std::cout << "nums: ";
    for (auto i : nums) {
      std::cout << i << " ";
    }
    std::cout << ", target:" << target << std::endl;
  } while (false);

  Solution s;
  auto result = s.twoSum(nums, target);
  if (!result.empty()) {
    std::cout << "result: ";
    for (auto i : result) {
      std::cout << i << " ";
    }
  } else {
    std::cout << "not found." << std::endl;
  }

  std::cin.get();
  return 0;
}