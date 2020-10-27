#include <iostream>
#include <type_traits>

#include<typeinfo>

using namespace std;

class A {
};

class base {
 public:
  virtual void test() {
    cout << "base test" << endl;
  }
  virtual ~base() {}
};

class derived1 : public base {
  virtual void test() {
    cout << "derived1 test" << endl;
  }
};

void print(const base* p) {
  cout << "typeid(p) " << typeid(p).name() << endl;
  cout << "typeid(*p) " << typeid(*p).name() << endl;
}

typedef void(*funcptr)();

int main() {

  // 类型名
  cout << "typeid(int) " << typeid(int).name() << endl;
  cout << "typeid(A) " << typeid(A).name() << endl;
  cout << endl;

  // 具体的对象
  int i;
  A a;
  cout << "typeid(i) " << typeid(i).name() << endl;
  cout << "typeid(a) " << typeid(a).name() << endl;
  cout << endl;

  // 不含虚函数类的指针、解引用、引用
  A* pa = &a;
  cout << "typeid(pa) " << typeid(pa).name() << endl;
  cout << "typeid(*pa) " << typeid(*pa).name() << endl;
  cout << "typeid(&a) " << typeid(&a).name() << endl;
  cout << endl;

  // 含虚函数的指针、解引用
  base b;
  derived1 d1;
  print(&b);
  print(&d1);
  cout << endl;

  // typeinfo  搞不出来
  cout << "sizeof d1" << sizeof(d1);

  char* p = (char*)&d1;

  auto& ti = typeid(d1);
  auto t2 = &ti;
  auto tiz = sizeof(typeid(d1));
  int** vtbl = (int**)*(int**)p;
  cout << "vtbl[-1] " << vtbl[-1] << endl;
  //cout << "typeinfo " << t2->name() << endl;

  auto t1 = (type_info*)*((char*)vtbl-4);
  auto t22 = (type_info*)(vtbl[-1]);

  //cout << t->name() << endl;

  funcptr ptr;
  ptr = (funcptr)(vtbl[0]);
  ptr();


  system("pause");
  return 0;
}