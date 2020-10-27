/*
leetcode 整数反转
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:
输入: 123
输出: 321

示例 2:
输入: -123
输出: -321

示例 3:
输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 −1]。
请根据这个假设，如果反转后整数溢出那么就返回 0。
*/

#include <limits>
#include <cstdint>
class Solution {
 public:
  int reverse(int x) {
    int res = 0;
    int64_t max = std::numeric_limits<int32_t>::max();
    int64_t min = std::numeric_limits<int32_t>::min();

    while(x){
      int pop = x % 10;

      // 判断溢出
      if (res > max/10 || (res == max/10 && (pop > max%10))){
        return 0;
      }
      if (res < min/10 || (res == min/10 && (pop < min%10))) {
        return 0;
      }

      res = res * 10 + pop;
      x = x / 10;
    }

    return res;
  }
};

#include <iostream>
int main() {
  int32_t x = -2147483412;
  std::cout << "x: " << std::showpos << x << std::endl;
  Solution s;
  int32_t result = s.reverse(x);
   std::cout << "result: " << std::showpos << result << std::endl;

   std::cin.get();
   return 0;
}