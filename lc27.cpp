/*
leetcode27. �Ƴ�Ԫ��
����һ������ nums ��һ��ֵ val������Ҫԭ���Ƴ�������ֵ����val��Ԫ�أ��������Ƴ���������³��ȡ�
��Ҫʹ�ö��������ռ䣬������ʹ�� O(1) ����ռ䲢ԭ���޸��������顣
Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�



ʾ�� 1:
���� nums = [3,2,2,3], val = 3,
����Ӧ�÷����µĳ��� 2, ���� nums �е�ǰ����Ԫ�ؾ�Ϊ 2��
�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�

ʾ�� 2:
���� nums = [0,1,2,2,3,0,4,2], val = 2,
����Ӧ�÷����µĳ��� 5, ���� nums �е�ǰ���Ԫ��Ϊ 0, 1, 3, 0, 4��
ע�������Ԫ�ؿ�Ϊ����˳��
�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
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
