/*
leetcode3. ���ظ��ַ�����Ӵ�
����һ���ַ����������ҳ����в������ظ��ַ�����Ӵ��ĳ��ȡ�

ʾ�� 1:
����: "abcabcbb"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��

ʾ�� 2:
����: "bbbbb"
���: 1
����: ��Ϊ���ظ��ַ�����Ӵ��� "b"�������䳤��Ϊ 1��

ʾ�� 3:
����: "pwwkew"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ��� "wke"�������䳤��Ϊ 3��
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