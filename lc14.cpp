/*
leetcode14. �����ǰ׺
��дһ�������������ַ��������е������ǰ׺��
��������ڹ���ǰ׺�����ؿ��ַ��� ""��

ʾ�� 1:
����: ["flower","flow","flight"]
���: "fl"

ʾ�� 2:
����: ["dog","racecar","car"]
���: ""
����: ���벻���ڹ���ǰ׺��

˵��:
��������ֻ����Сд��ĸ a-z ��

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
   ���������������ǰ׺
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
  ���ҳ��������ֵ�����С�������ַ����������ǰ׺��Ϊ�������ַ����Ĺ���ǰ׺
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
  8ms��9.3MB
  1.Ϊ�գ�res = ""����Ϊ�գ�res = strs[0];
  2.��ʼ����
  3.s.find(res) != 0������ǰ׺����ʼ��ȥres�����һ���ַ�
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
