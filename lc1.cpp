#include <iostream>
#include <unordered_map>

/*
����һ���������У��ҳ����к�Ϊ�ض�ֵ������������

����Լ���ÿ�����붼ֻ����һ�ִ𰸣�ͬ����Ԫ�ز��ܱ����á�

ʾ��:

���� nums = [2, 7, 11, 15], target = 9

��Ϊ nums[0] + nums[1] = 2 + 7 = 9
���Է��� [0, 1]
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