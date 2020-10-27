/*
leetcode9. 回文数
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:
输入: 121
输出: true

示例 2:
输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

示例 3:
输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。

*/

/*
1. 负数 结尾为0的正整数均不是回文数。
2. 正数反转等于本身则为回文数，但反转可能溢出。所以考虑反转一半进行判断。
假设数字x有n位， 反转部分得到的数字为reverse_num
   最开始，reverse_num = 0， x > reverse_num;
   n为奇数时，
     当反转（n/2 + 1）位时，x < reverse_num必成立， 此时 （x == reverse_num /
10） 则为回文数 n为偶数时，2种情况： 当反转 n/2 位时，若 x != reverse_num，
则不是回文数； 当反转 n/2 位时，若 x == reverse_num， 则是回文数；
*/
class Solution {
 public:
  bool isPalindrome(int x) {
    if ((x < 0) || ((x != 0) && (x % 10 == 0))) {
      return false;
    }

    int reverse_num = 0;
    while (x > reverse_num) {
      reverse_num = reverse_num * 10 + x % 10;
      x = x / 10;
    }

    return (x == reverse_num) || (x == reverse_num / 10);
  }
};

#include <iostream>
int main() {
  Solution s;
  std::cout << "123 isPalindrome: " << std::boolalpha << s.isPalindrome(123)
            << std::endl;
  std::cout << "31 isPalindrome: " << std::boolalpha << s.isPalindrome(31)
            << std::endl;
  std::cout << "1 isPalindrome: " << std::boolalpha << s.isPalindrome(1)
            << std::endl;
  std::cout << "11 isPalindrome : " << std::boolalpha << s.isPalindrome(11) << std::endl;
  std::cout << "1221 isPalindrome: "
            << std::boolalpha
            << s.isPalindrome(1221)
            << std::endl;
  std::cin.get();
  return 0;
}
