/*
leetcode58. 最后一个单词的长度
给定一个仅包含大小写字母和空格 ' ' 的字符串
s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
如果不存在最后一个单词，请返回 0 。
说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。

示例:
输入: "Hello World"
输出: 5
*/

#include <string.h>
int lengthOfLastWord(char* s) {
  int len = 0;
  for (int i = strlen(s)-1; i >= 0; --i){
    if (s[i] != ' '){
      ++len;
    }else {
      if (len) {
        break;
      }
    } 
  }

  return len;
}

#include <string>
using namespace std;

class Solution {
 public:
  int lengthOfLastWord(string s) {
    int len = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
      if (s[i] != ' ') {
        ++len;
      } else {
        if (len) {
          break;
        }
      }
    }
    return len;
  }
};

#include <iostream>
int main() {
  {
    char* s = "Hello World";
    cout << lengthOfLastWord(s) << endl;
  }
  {
    string s = "Hello World";
    Solution so;
    cout << so.lengthOfLastWord(s) << endl;
  }
  cin.get();
  return 0;
}