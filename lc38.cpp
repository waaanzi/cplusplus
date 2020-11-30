/*
leetcode38. �������
����һ�������� n �����������еĵ� n �
��������С���һ���������У������� 1 ��ʼ�������е�ÿһ��Ƕ�ǰһ���������
����Խ����������ɵݹ鹫ʽ����������ַ������У�

countAndSay(1) = "1"
countAndSay(n) �Ƕ� countAndSay(n-1) ��������Ȼ��ת������һ�������ַ�����
ǰ�������£�

1   1
2   11
3   21
4   1211
5   111221
��һ�������� 1
����ǰһ�������� 1 �� �� һ �� 1 �������� "11"
����ǰһ�������� 11 �� �� �� �� 1 �� ������ "21"
����ǰһ�������� 21 �� �� һ �� 2 + һ �� 1 �� ������ "1211"
����ǰһ�������� 1211 �� �� һ �� 1 + һ �� 2 + �� �� 1 �� ������ "111221"
Ҫ����һ�������ַ���������Ҫ���ַ����ָ�Ϊ��С�������飬ÿ���鶼�����������
��ͬ�ַ���ɡ�Ȼ�����ÿ���飬�������ַ���������Ȼ�������ַ����γ�һ�������顣
Ҫ������ת��Ϊ�����ַ������Ƚ�ÿ���е��ַ������������滻���ٽ���������������������

ʾ�� 1��
���룺n = 1
�����"1"
���ͣ�����һ������������

ʾ�� 2��
���룺n = 4
�����"1211"
���ͣ�
countAndSay(1) = "1"
countAndSay(2) = �� "1" = һ �� 1 = "11"
countAndSay(3) = �� "11" = �� �� 1 = "21"
countAndSay(4) = �� "21" = һ �� 2 + һ �� 1 = "12" + "11" = "1211"

��ʾ��
1 <= n <= 30
*/


#include <string.h>
#include <stdio.h>
#include <malloc.h>
// ���������ͷ���Դ
char* countAndSay(int n) {
  if (1 == n) {
    char* temp = (char*) malloc(2);
    memcpy(temp, "1", 2);
    return temp;
  }

  char* s = countAndSay(n - 1);
  char* res = (char*)malloc(strlen(s) * 2 + 1);
  int res_index = 0;

  char val = s[0];
  int count = 1;

  int len = strlen(s);
  for(int i = 1; i < len; ++i) {
    if (s[i] == val){    
      ++count;
    }else{
      res[res_index++] =  (char)('0' + count);
      res[res_index++] =  val; 

      val = s[i];
      count = 1;
    }

  }

  // ����������������һ���ַ�����û�д���
  res[res_index++] = (char)('0' + count);
  res[res_index++] = val; 
  res[res_index] = '\0';

  free(s);

  return res;
}

#include <string>
using namespace std;
class Solution {
 public:
  string countAndSay(int n) {
    if (1 == n) {
      return "1";
    }

    string s = countAndSay(n - 1);
    string temp;

    auto it = s.begin();
    char val = *it;
    int count = 0;

    while(it != s.end()) {
      if (*it == val) {
        ++count;
      }else{
        temp += (char)('0' + count);
        temp += val;

        val = *it;
        count = 1;
      }
      ++it;
    }

    temp += (char)('0' + count);
    temp += val;

    return temp;
  }
};

#include <iostream>
int main() {
  {
    // C
    int n = 10;
    char* s = countAndSay(n);
    cout << s << endl;
    free(s);
  }
  {
    // C++
    Solution s;
    cout << s.countAndSay(10) << endl;
  }
  cin.get();
  return 0;
}