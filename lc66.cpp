/*
leetcode66. ��һ
����һ���� ���� ��ɵ� �ǿ� ��������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��
���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�
����Լ���������� 0 ֮�⣬��������������㿪ͷ��


ʾ�� 1��
���룺digits = [1,2,3]
�����[1,2,4]
���ͣ����������ʾ���� 123��

ʾ�� 2��
���룺digits = [4,3,2,1]
�����[4,3,2,2]
���ͣ����������ʾ���� 4321��

ʾ�� 3��
���룺digits = [0]
�����[1]

��ʾ��
1 <= digits.length <= 100
0 <= digits[i] <= 9
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <malloc.h>
#include <string.h>
int* plusOne(int* digits, int digitsSize, int* returnSize){
  *returnSize = digitsSize;

  // ֻ��ȫ9�Ż��digitsSize��һλ
  bool need_one_more = true;
  for (int i = 0; i < digitsSize; ++i){
    if (9 != digits[i]) {
      need_one_more = false;
      break;
    }
  }
  if (need_one_more){
    *returnSize = digitsSize + 1;
  }

  int* res = (int*)malloc(sizeof(int) * (*returnSize));
  if (need_one_more){
    res[0] = 1;
    for (int i = 1; i < *returnSize; ++i){
      res[i] = 0;
    }
    return res;
  }

  int temp = 1;
  for (int i = digitsSize - 1; i >=0; --i){
    res[i] = (digits[i] + temp) % 10;
    temp = (digits[i] + temp) / 10;
  }
  return res;
}

#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    int temp = 1;
    vector<int> res;
    for(auto it = digits.rbegin(); it != digits.rend(); ++it){
      res.emplace(res.begin(), (*it + temp) % 10);
      temp = (*it + temp) / 10;
    }
    if (temp){
      res.emplace(res.begin(), temp);
    }
    return res;
  }
};

template <typename C>
void print(C c, int size, char* s) {
  cout << s << ": ";
  for (int i = 0; i < size; ++i){
    cout << c[i] << " ";
  }
  cout << endl;
}

#include <iostream>
int main() {
  {
    int digits[] = {9};
    int n = sizeof(digits) / sizeof(digits[0]);
    print(digits, n, "digits");
    int size;
    int* output = plusOne(digits, n, &size);
    print(output, size, "output");
  }
  {
    vector<int> digits = {9};
    print(digits, digits.size(), "digits");
    Solution s;
    auto output = s.plusOne(digits);
    print(output, output.size(), "output");
  }
  cin.get();
  return 0;
}