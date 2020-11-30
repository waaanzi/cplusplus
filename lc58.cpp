/*
leetcode58. ���һ�����ʵĳ���
����һ����������Сд��ĸ�Ϳո� ' ' ���ַ���
s�����������һ�����ʵĳ��ȡ�����ַ����������ҹ�����ʾ����ô���һ�����ʾ��������ֵĵ��ʡ�
������������һ�����ʣ��뷵�� 0 ��
˵����һ��������ָ������ĸ��ɡ��������κοո��ַ��� ������ַ�����

ʾ��:
����: "Hello World"
���: 5
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