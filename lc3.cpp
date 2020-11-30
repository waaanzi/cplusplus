/*
leetcode3. 无重复字符的最长子串
给定一个字符串，请你找出其中不含有重复字符的最长子串的长度。

示例 1:
输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
*/

#include <string.h>
int lengthOfLongestSubstring(char* s) {
  int len = strlen(s);
  if (!len) {
    return 0;
  }

  int cur_max_len = 1;
  int max_len = 1;
  for (int i = 1; i < len; ++i){
    int j = i - 1;
    while(j >= i - cur_max_len && s[j] != s[i]){
      --j;
    }
    if (j < (i - cur_max_len)) {
      cur_max_len = cur_max_len + 1;
    } else {
      cur_max_len = i - j;
      continue;
    }

    max_len = max_len > cur_max_len ? max_len : cur_max_len;

  }

  return max_len;
}

#include <string>
using namespace std;
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.empty()) {
      return 0;
    }

    int cur_max_len = 1;
    int max_len = 1;
    for (int i = 1; i < s.size(); ++i) {
      auto idx = s.substr(i - cur_max_len, cur_max_len).find_last_of(s[i]);
      if (idx == string::npos) {
        cur_max_len = cur_max_len + 1;
      } else {
        cur_max_len = cur_max_len - idx;
        continue;
      }

      max_len = max_len > cur_max_len ? max_len : cur_max_len;
    }

    return max_len;
  }
};

#include <iostream>
using namespace std;

int main(){
  {
    char* s = "pwwkew";
    cout << s << " : " << lengthOfLongestSubstring(s) << endl;
  }

  {
    string str = "pwwkew";
    Solution s;
    cout << str << " : " << s.lengthOfLongestSubstring(str) << endl;
  }

  cin.get();
  return 0;
}