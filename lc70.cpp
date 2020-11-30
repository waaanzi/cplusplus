/*
leetcode70. ��¥��
������������¥�ݡ���Ҫ n ������ܵ���¥����
ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�
ע�⣺���� n ��һ����������

ʾ�� 1��
���룺 2
����� 2
���ͣ� �����ַ�����������¥����
1.  1 �� + 1 ��
2.  2 ��

ʾ�� 2��
���룺 3
����� 3
���ͣ� �����ַ�����������¥����
1.  1 �� + 1 �� + 1 ��
2.  1 �� + 2 ��
3.  2 �� + 1 ��
*/

int climbStairs_1(int n) {
  if (1 == n) {
    return 1;
  }
  if (2 == n) {
    return 2;
  }

  return climbStairs_1(n-1) + climbStairs_1(n-2);
}

int climbStairs_2(int n) {
  if (1 == n) {
    return 1;
  }
  if (2 == n) {
    return 2;
  }

  int i = 1, j = 2;
  int res = 0;
  for (int k = 3; k <= n; ++k) {
    res = i + j;
    i = j;
    j = res;
  }

  return res;
}

#include <iostream>
using namespace std;

int main() {

  int n = 3;
  cout << n << " Stairs have "  << climbStairs_2(n) << " ways to climb." << endl;
  cin.get();
  return 0;
}