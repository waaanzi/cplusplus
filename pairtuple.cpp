#include <utility> // defined std::pair
#include <tuple>  // defined std::tuple
#include <iostream>
#include <string>

using std::cout;

int main()
{
  // pair 创建及初始化
  std::pair<int, double> point1;
  point1.first = 1;
  point1.second = 2.2;

  auto point = std::make_pair(1, 2.2);
  // pair 访问方式
  cout << "point.first: " << point.first << std::endl;
  cout << "point.second:  " << point.second << std::endl;
  cout << "std::get<0>(point):  " << std::get<0>(point) << std::endl;
  cout << "std::get<1>(point):  " << std::get<1>(point) << std::endl;

  // tuple
  auto t = std::make_tuple(1, "jack", 89.5);
  cout << " std::get<0>(t)  " << std::get<0>(t) << std::endl;
  cout << " std::get<1>(t)  " << std::get<1>(t) << std::endl;
  cout << " std::get<2>(t)  " << std::get<2>(t) << std::endl;

  int num;
  std::string name;
  double score;
  std::tie(num, name, score) = t;

  cout << "num: " << num << std::endl;
  cout << "name:  " << name << std::endl;
  cout << "score: " << score << std::endl;

  auto t1 = std::tie(num, name, score);
  cout << " std::get<0>(t1)  " << std::get<0>(t1) << std::endl;
  cout << " std::get<1>(t1)  " << std::get<1>(t1) << std::endl;
  cout << " std::get<2>(t1)  " << std::get<2>(t1) << std::endl;

  system("pause");
}