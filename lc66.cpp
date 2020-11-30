/*
leetcode66. 加一
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。


示例 1：
输入：digits = [1,2,3]
输出：[1,2,4]
解释：输入数组表示数字 123。

示例 2：
输入：digits = [4,3,2,1]
输出：[4,3,2,2]
解释：输入数组表示数字 4321。

示例 3：
输入：digits = [0]
输出：[1]

提示：
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

  // 只有全9才会比digitsSize多一位
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