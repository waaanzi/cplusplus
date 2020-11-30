/*
leetcode20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:
输入: "()"
输出: true

示例 2:
输入: "()[]{}"
输出: true

示例 3:
输入: "(]"
输出: false

示例 4:
输入: "([)]"
输出: false

示例 5:
输入: "{[]}"
输出: true

思路：用栈辅助，针对字符串每个字符，若与栈顶元素匹配，则出栈；否则压栈。最终栈为空则字符串有效。
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    if (s.empty()) {
      return true;
    }

    stack<char> sk;
    for (auto& c : s) {
      switch (c) {
        case '(': {
          sk.push(c);
          break;
        }
        case ')': {
          if (!sk.empty()) {
            auto top = sk.top();
            if ('(' == top) {
              sk.pop();
              break;
            }
          }
          return false;
        }
        case '[': {
          sk.push(c);
          break;
        }
        case ']': {
          if (!sk.empty()) {
            auto top = sk.top();
            if ('[' == top) {
              sk.pop();
              break;
            }
          }
          sk.push(c);
          break;
        }
        case '{': {
          sk.push(c);
          break;
        }
        case '}': {
          if (!sk.empty()) {
            auto top = sk.top();
            if ('{' == top) {
              sk.pop();
              break;
            }
          }
          sk.push(c);
          break;
        }
        default:
          break;
      }
    }

    if (sk.empty()) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  Solution s;
  string str = "{[()]}";
  cout << "string \"" << str << "\" is valid : " << boolalpha << s.isValid(str)
       << endl;

  str = "()[]{}";
  cout << "string \"" << str << "\" is valid : " << boolalpha << s.isValid(str)
       << endl;

  str = "([)]";
  cout << "string \"" << str << "\" is valid : " << boolalpha << s.isValid(str)
       << endl;

  cin.get();
  return 0;
}