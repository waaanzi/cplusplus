/*
leetcode20. ��Ч������
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��

��Ч�ַ��������㣺
�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
ע����ַ����ɱ���Ϊ����Ч�ַ�����

ʾ�� 1:
����: "()"
���: true

ʾ�� 2:
����: "()[]{}"
���: true

ʾ�� 3:
����: "(]"
���: false

ʾ�� 4:
����: "([)]"
���: false

ʾ�� 5:
����: "{[]}"
���: true

˼·����ջ����������ַ���ÿ���ַ�������ջ��Ԫ��ƥ�䣬���ջ������ѹջ������ջΪ�����ַ�����Ч��
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