#include <vector>
#include <iostream>
#include <map>
#include <memory>

struct Base {
  int a;
  virtual void f() const { std::cout << "I am base!\n"; }
  virtual ~Base() {}
};

struct Derived : Base {
  void f() const override { std::cout << "I am derived!\n"; }
  ~Derived() {}
};

int main() {

  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  auto begin1 = v.begin();
  auto end1 = v.end();
  
  auto temp = begin1 + 1;
  auto temp1 = v.erase(temp);
  
  auto end2 = v.end();

  std::map<int, int> mp;
  mp[1] = 1;
  auto& i = mp[2];
  i = 2;
  // std::cout << mp[2];
  
  char buff[1024];
  uint64_t a = 123456789;
  snprintf(buff, sizeof(buff), "%d", a);
  std::cout << "buff : " << buff;

  {
    // std::find
   // std::vector<int> vec = { 1,2,3,4,5,6,7 };
   // auto it = std::find(vec.begin(), vec.end(), 1);
   // if (vec.end() != it)
   // {
   //   std::cout << "find it!" << std::endl;
   // }
  }

  std::cin.get();

  return 0;
}