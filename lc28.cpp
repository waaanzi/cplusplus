/*
leetcode28. 实现 strStr()
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle
字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:
输入: haystack = "hello", needle = "ll"
输出: 2

示例 2:
输入: haystack = "aaaaa", needle = "bba"
输出: -1

说明:
当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及
Java的 indexOf() 定义相符。
*/

#include <string.h>
int strStr(char* haystack, char* needle) {
  if (needle == "") {
    return 0;
  }

  int haystack_len = strlen(haystack);
  int needle_len= strlen(needle);
  char* temp = needle;
  for (int i = 0; i <= haystack_len - needle_len; ++i){
    int j = i;
    int k = 0;
    while((k < needle_len) && (haystack[j] == needle[k])){
      ++j;
      ++k;
    }

    if (k == needle_len){
      return i;
    }
  }

  return -1;
}

#include <string>
using namespace std;
class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle.empty()) {
      return 0;
    }
    auto it = haystack.find(needle);
    if (it == string::npos) {
      return -1;
    } else {
      return it;
    }
  }
};

#include <iostream>

int main() {
  {
    // C
    char* haystack = "hello";
    char* needle = "lo";
    cout << strStr(haystack, needle) << endl;
  }
  {
    // C++ 
    string haystack = "hello";
    string needle = "ll";
    Solution s;
    cout << s.strStr(haystack, needle);
  }
  cin.get();
  return 0;
}