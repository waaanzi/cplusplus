/*
leetcode26. ɾ�����������е��ظ���
����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�
��Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ����������ɡ�

ʾ�� 1:
�������� nums = [1,1,2],
����Ӧ�÷����µĳ��� 2, ����ԭ���� nums ��ǰ����Ԫ�ر��޸�Ϊ 1, 2��
�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�

ʾ�� 2:
���� nums = [0,0,1,1,1,2,2,3,3,4],
����Ӧ�÷����µĳ��� 5, ����ԭ���� nums ��ǰ���Ԫ�ر��޸�Ϊ 0, 1, 2, 3, 4��
�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
*/

#include <vector>
using namespace std;

class Solution {
 public:
  // C++
  int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    auto it = nums.begin();
    int val = *it;
    ++it;
    while(it != nums.end()){
      if (*it == val) {
        // erase����ֵָ��ɾ��Ԫ�ص���һλ��
        it = nums.erase(it);
      }else{
        val = *it;
        ++it;
      }
    }

    return nums.size();
  }

  // C
  // ����ָ��
  int removeDuplicates(int* nums, int numsSize) {
    if (0 == numsSize) {
      return 0;
    }

    int i = 0;
    for(int j = 1; j < numsSize; ++j){
      if (nums[j] != nums[i]){
        ++i;
        nums[i] = nums[j];
      }
    }

    return i + 1;
  }
};

#include <iostream>

void print(const vector<int>& nums) {
  cout << "nums : ";
  for(auto& i : nums) {
    cout << i << " ";
  }
  cout << std::endl;
}

int main() {
  std::vector<int> vc = {2, 2, 3, 4, 5, 5, 6, 7};
  print(vc);

  Solution s;
  s.removeDuplicates(vc);
  print(vc);

  std::cin.get();
  return 0;
}