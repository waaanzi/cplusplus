#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

void print(const std::string& text, const std::vector<int>& vc) {
  std::cout << text << std::endl;
  auto it = vc.begin();
  while (it != vc.end())
  {
    std::cout << *it << " ";
    ++it;
  }
  std::cout << std::endl;
}

struct info {
  int a;
  std::string s;
};

#include<functional>
#include<thread>
int main() {

 //  std::vector<int> vc = { 9, 7,6 ,9, 8, 2, 5, 6, 2,1 };
 //  print("origin vc:", vc);
 //  std::sort(vc.begin(), vc.end());
 //  print("after sort vc:", vc);
 //  auto index_it = std::unique(vc.begin(), vc.end());
 //  print("after sort + unique vc:", vc);
 //  vc.erase(index_it, vc.end());
 //  print("after sort + unique + erase vc:", vc);

  {
    auto f = [&](int& n) {n = 10; };
    int a =1;
    auto h = std::bind(f, std::ref(a));
    h();
    std::cout << "a: " << a << std::endl;
  }

  {
    auto f = [&](info& n) {
      n.a = 10; };
    info a;
    a.a = 1;
    auto h = std::bind(f, std::ref(a));
    h();
    std::cout << "a.a: " << a.a << std::endl;
  }

  {
    auto f = [&](std::map<int, int>& n) {
      n[1] = 1; };
    std::map<int, int> a;
    auto h = std::bind(f, std::ref(a));
    std::thread t(h);
    std::cout << "a.size: " << a.size() << std::endl;
  }

  
  std::cin.get();
  return 0;
}