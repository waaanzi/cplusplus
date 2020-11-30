/*
leetcode70. 爬楼梯
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
注意：给定 n 是一个正整数。

示例 1：
输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶

示例 2：
输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶
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