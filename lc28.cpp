/*
leetcode28. ʵ�� strStr()
ʵ�� strStr() ������

����һ�� haystack �ַ�����һ�� needle �ַ������� haystack �ַ������ҳ� needle
�ַ������ֵĵ�һ��λ�� (��0��ʼ)����������ڣ��򷵻�  -1��

ʾ�� 1:
����: haystack = "hello", needle = "ll"
���: 2

ʾ�� 2:
����: haystack = "aaaaa", needle = "bba"
���: -1

˵��:
�� needle �ǿ��ַ���ʱ������Ӧ������ʲôֵ�أ�����һ���������кܺõ����⡣
���ڱ�����ԣ��� needle �ǿ��ַ���ʱ����Ӧ������ 0 ������C���Ե� strstr() �Լ�
Java�� indexOf() ���������
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