/*
leetcode4. Ѱ�����������������λ��
����������СΪ m �� n �����򣨴�С�������� nums1 �� nums2�������ҳ������������������������λ����

ʾ�� 1��
���룺nums1 = [1,3], nums2 = [2]
�����2.00000
���ͣ��ϲ����� = [1,2,3] ����λ�� 2

ʾ�� 2��
���룺nums1 = [1,2], nums2 = [3,4]
�����2.50000
���ͣ��ϲ����� = [1,2,3,4] ����λ�� (2 + 3) / 2 = 2.5

ʾ�� 3��
���룺nums1 = [0,0], nums2 = [0,0]
�����0.00000

ʾ�� 4��
���룺nums1 = [], nums2 = [1]
�����1.00000

ʾ�� 5��
���룺nums1 = [2], nums2 = []
�����2.00000
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