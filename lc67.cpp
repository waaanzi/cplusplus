/*
leetcode67. ���������
���������������ַ������������ǵĺͣ��ö����Ʊ�ʾ����
����Ϊ �ǿ� �ַ�����ֻ�������� 1 �� 0��

ʾ�� 1:
����: a = "11", b = "1"
���: "100"

ʾ�� 2:
����: a = "1010", b = "1011"
���: "10101"

��ʾ��
ÿ���ַ��������ַ� '0' �� '1' ��ɡ�
1 <= a.length, b.length <= 10^4
�ַ���������� "0" ���Ͷ�����ǰ���㡣
*/

#include <string.h>
#include <malloc.h>
char* addBinary(char* a, char* b) {
  int a_len = strlen(a);
  int b_len = strlen(b);
  int len = a_len > b_len ? a_len : b_len;
  char* s = (char*)malloc(sizeof(char) * (len + 1));
  s[len] = '\0';

  int carry = 0; // ��λ
  int a_idx = a_len - 1; // ���һ���ַ��±���ǰ����
  int b_idx = b_len - 1;
  int s_idx = len - 1;
  while(a_idx >= 0 || b_idx >= 0){
    int aidx_num = a_idx < 0 ? 0 : a[a_idx] - '0';
    int bidx_num = b_idx < 0 ? 0 : b[b_idx] - '0';
    s[s_idx--] = (aidx_num + bidx_num + carry) % 2 + '0';
    carry = (aidx_num + bidx_num + carry) / 2;

    --a_idx;
    --b_idx;
  }

  if (carry) {
    char* res = (char*)malloc(sizeof(char) * (len + 1 + 1));
    res[0] = carry + '0';
    memcpy(res + 1, s, len + 1);
    free(s);
    return res;
  }else{
    return s;
  }
}

#include <string>
using namespace std;

class Solution {
 public:
  string addBinary(string a, string b) {
    string res;
    int carry = 0;
   
    auto a_it = a.rbegin();
    auto b_it = b.rbegin();
    while(a_it < a.rend() || b_it < b.rend()){
      int a_num = a_it >= a.rend() ? 0 : *a_it - '0';
      int b_num = b_it >= b.rend() ? 0 : *b_it - '0';
      res.insert(res.begin(), (a_num + b_num + carry) % 2 + '0');
      carry = (a_num + b_num + carry) / 2;

      ++a_it;
      ++b_it;
    }
    if (carry){
      res.insert(res.begin(), carry + '0');
    }

    return res;
  }
};

#include <iostream>
int main() {
  {
    char* a = "1010";
    char* b = "1011";
    char* s = addBinary(a, b);
    cout << s << endl;
    free(s);
  }
  {
    string a = "1010";
    string b = "1011";
    Solution s;
    cout << s.addBinary(a, b);
  }
  cin.get();
  return 0;
}