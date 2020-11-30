/*
leetcode69. x ��ƽ����
ʵ�� int sqrt(int x) ������
���㲢���� x ��ƽ���������� x �ǷǸ�������
���ڷ������������������ֻ���������Ĳ��֣�С�����ֽ�����ȥ��

ʾ�� 1:
����: 4
���: 2
ʾ�� 2:

����: 8
���: 2
˵��: 8 ��ƽ������ 2.82842..., ���ڷ���������������С�����ֽ�����ȥ��
*/
int mySqrt(int x) {
  if (0 == x) {
    return 0;
  }

  int i = 1;
  while ((i <= x) && (i <= x / i)) {
    ++i;
  }
  return i - 1;
}

int mySqrt1(int x) {
  if (0 == x) {
    return 0;
  }

  int res = 1;

  int left = 1;
  int right = x;
  while (left <= right) {
    long mid = left + (right - left) / 2;
    if (mid <= x / mid) {
      left = mid + 1;
      res = mid;
    } else {
      right = mid - 1;
    }
  }

  return res;
}

class Solution {
 public:
  int mySqrt(int x) {
    if (0 == x) {
      return 0;
    }

    int res = 1;

    int left = 1;
    int right = x;
    while (left <= right) {
      long mid = left + (right - left) / 2;
      if (mid <= x / mid) {
        left = mid + 1;
        res = mid;
      } else {
        right = mid - 1;
      }
    }

    return res;
  }
};

#include <iostream>
using namespace std;

int main() {
  cout << mySqrt(8) << endl;
  {
    Solution s;
    cout << s.mySqrt(9);
  }

  std::cin.get();
  return 0;
}