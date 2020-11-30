/*
leetcode5. ������Ӵ�
����һ���ַ��� s���ҵ� s ����Ļ����Ӵ�������Լ��� s ����󳤶�Ϊ 1000��

ʾ�� 1��
����: "babad"
���: "bab"
ע��: "aba" Ҳ��һ����Ч�𰸡�

ʾ�� 2��
����: "cbbd"
���: "bb"
*/

#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  // ��̬�滮
  string longestPalindrome(string s) {
    int n = s.size();

    vector<vector<int>> pd(n, vector<int>(n));  // int pd[n][n]

    string res;

    for (int i = 0; i < n; ++i) {
      for (int start = 0; start < n; ++start) {
        int end = start + i;
        if (end > n - 1) {
          continue;
        }
        if (i == 0) {
          pd[start][end] = 1;
        } else if (i == 1) {
          pd[start][end] = (s[start] == s[end]);
        } else {
          pd[start][end] = ((s[start] == s[end]) && pd[start + 1][end - 1]);
        }

        if (pd[start][end] && (i + 1 /*end - start + 1*/) > res.size()) {
          res = s.substr(start, i + 1);
        }
      }
    }

    return res;
  }

  // ������չ��
  // �������ĵ����໥Ϊ������ˣ����Ŀ��Դ���������չ��������ֻ�� 2n -
  //    1 �����������ģ�һ��Ԫ��Ϊ���ĵ������ n ��������Ԫ��Ϊ���ĵ������ n - 1 ����
  string longestPalindrome2(string s) {
    int n = s.size();

    if (n == 0 || n == 1) {
      return s;
    }

    int start = 0;
    int maxlen = 0;

    for (int i = 0; i < n; ++i) {
      int len1 = expend(s, i, i);
      int len2 = expend(s, i, i + 1);

      int cur_maxlen = len1 > len2 ? len1 : len2;
      if (cur_maxlen > maxlen) {
        maxlen = cur_maxlen;
        start = i - (cur_maxlen - 1) / 2;
      }
    }

    return s.substr(start, maxlen);
  }

 private:
  int expend(const string& s, int left, int right) {
    while ((left >= 0) && (right < s.size()) && (s[left] == s[right])) {
      --left;
      ++right;
    }

    return right - left - 1; // (right -1) - (left + 1) + 1
  }
};

#include <iostream>
int main() {
  string str = "babad";
  Solution s;
  cout << s.longestPalindrome2(str) << endl;

  cin.get();

  return 0;
}