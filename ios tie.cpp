#include <iostream>
#include <fstream>

/*
*  c++ ios::tie demo
*/

using std::cin;

int main()
{
  // http://www.cplusplus.com/reference/ios/ios/tie/

  std::ofstream ofs;
  ofs.open("test.txt");
  // 绑定流是一个输出流对象，它在这个流对象中的每个i/o操作之前刷新。
  cin.tie(&ofs);
  char c;
  while (cin >> c)
  {
    ofs << c;
  }
  ofs.close();
  system("pause");
}