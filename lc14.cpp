/*
leetcode14. 最长公共前缀
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。

示例 1:
输入: ["flower","flow","flight"]
输出: "fl"

示例 2:
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。

说明:
所有输入只包含小写字母 a-z 。

*/

/*
*/
#include <string>
#include <vector>

#include <algorithm>
using namespace std;

class Solution {
 public:
   /*
   12ms, 94.MB
   遍历，两两计算最长前缀
   */
  string longestCommonPrefix1(vector<string>& strs) {
    if (0 == strs.size()) {
      return string();
    }
    string res = strs[0];
    for(int i = 1; i < strs.size(); ++i){
      res = getPrefix(strs[i], res);
      if (res.empty()) {
        break;
      }
    }
    return res;
  }

  /*
  4ms, 9.1MB
  先找出数组中字典序最小和最大的字符串，最长公共前缀即为这两个字符串的公共前缀
  */
  string longestCommonPrefix2(vector<string>& strs) {
    if (0 == strs.size()) {
      return string();
    }
    auto p = minmax_element(strs.begin(), strs.end());
    for (int i = 0; i < p.first->size(); ++i) {
      if (p.first->at(i) != p.second->at(i)){
        return p.first->substr(0, i);
      }
    }
    return *p.first;
  }

  /*
  8ms，9.3MB
  1.为空，res = ""，不为空，res = strs[0];
  2.开始遍历
  3.s.find(res) != 0不是其前缀，开始减去res的最后一个字符
  */
  string longestCommonPrefix3(vector<string>& strs) {
    string res = strs.empty() ? "" : strs[0];
    for (auto& s : strs) {
      while (s.find(res) != 0) {
        res = res.substr(0, res.length() - 1);
      }
    }
    return res;
  }

  private:
  string getPrefix(const string& str1, const string& str2) {
    int len = std::min(str1.size(), str2.size());
    int i = 0;
    while (i < len) {
      if (str1[i] != str2[i]){
        break;
      }
      ++i;
    }

    if (i){
      return str1.substr(0, i);
    } else {
      return string();
    }   
  }
};

#include <iostream>
int main() {
  Solution s;
  vector<string> vc {"flower","flow","flight"};
  std::cout << "vc: "  << std::endl;
  for (auto& s : vc) {
    std::cout << s  << std::endl;
  }
  std::cout << "longestCommonPrefix : " << s.longestCommonPrefix3(vc) << std::endl;
  std::cin.get();
  return 0;
}
