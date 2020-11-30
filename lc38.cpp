/*
leetcode38. 外观数列
给定一个正整数 n ，输出外观数列的第 n 项。
「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。
你可以将其视作是由递归公式定义的数字字符串序列：

countAndSay(1) = "1"
countAndSay(n) 是对 countAndSay(n-1) 的描述，然后转换成另一个数字字符串。
前五项如下：

1   1
2   11
3   21
4   1211
5   111221
第一项是数字 1
描述前一项，这个数是 1 即 “ 一 个 1 ”，记作 "11"
描述前一项，这个数是 11 即 “ 二 个 1 ” ，记作 "21"
描述前一项，这个数是 21 即 “ 一 个 2 + 一 个 1 ” ，记作 "1211"
描述前一项，这个数是 1211 即 “ 一 个 1 + 一 个 2 + 二 个 1 ” ，记作 "111221"
要描述一个数字字符串，首先要将字符串分割为最小数量的组，每个组都由连续的最多
相同字符组成。然后对于每个组，先描述字符的数量，然后描述字符，形成一个描述组。
要将描述转换为数字字符串，先将每组中的字符数量用数字替换，再将所有描述组连接起来。

示例 1：
输入：n = 1
输出："1"
解释：这是一个基本样例。

示例 2：
输入：n = 4
输出："1211"
解释：
countAndSay(1) = "1"
countAndSay(2) = 读 "1" = 一 个 1 = "11"
countAndSay(3) = 读 "11" = 二 个 1 = "21"
countAndSay(4) = 读 "21" = 一 个 2 + 一 个 1 = "12" + "11" = "1211"

提示：
1 <= n <= 30
*/


#include <string.h>
#include <stdio.h>
#include <malloc.h>
// 调用者需释放资源
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

  // 不管哪种情况，最后一个字符都还没有处理
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