///*
//外部模板
//
//外部模板的使用实际依赖于C++98中一个已有的特性——显示实例化
//template <typename T> void fun(T){}
//显式实例化： template void fun<int>(int);
//外部模板： extern template void fun<int>(int);
//可以减少编译时间。
//注意：
//如果外部模板声明出现于某个编译单元中，那么与之对应的显式实例化必须出现于另一个编译单元中或者同一个编译单元的后续代码中；
//外部模板不能用于一个静态函数（没有外部链接属性），但可以用于类静态成员函数。
//*/
//
//#include <iostream>
//#include "extern_template.h"
//
//int main() {
//  f1(1);
//  f();
//  B<int>::f_m(1);
//
//  getchar();
//  return 0;
//}


#include <iostream>
#include <algorithm>  // for_each
#include <vector>

using namespace std;

bool even(int n){
  if (n%2 ==0) {
    cout << n << " is even " << endl;
    return true;
  }
  return false;
}

// range-for loop
int main() {

{
    // 容器
    cout << "vc: ";
    std::vector<int> vc {1,2,3};
    for (auto i : vc) {
      cout << i << " ";
    }
    cout << endl;
}
{
  // C-Style 数组
  cout << "sz: ";
  int sz[] = {1, 2, 3};
  for (auto i : sz) {
    cout << i << " ";
  }
  cout << endl;
}

{
  // initialize list
  cout << "list: ";
  for (auto i : {1, 2, 3}) {
    cout << i << " ";
  }
  cout << endl;
}

// for_each
{
  std::vector<int> vc{1, 2, 3};
  for_each(vc.begin(), vc.end(), even);
  cout << endl;
}

// for_each_n (C++17)
{
  std::vector<int> vc{1, 2, 3};
  for_each_n(vc.begin(), 2, even);
  cout << endl;
}

cin.get();
return 0;
}