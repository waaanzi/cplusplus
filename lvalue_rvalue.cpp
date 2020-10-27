
#include <iostream>
#include <type_traits>

using namespace std;

/*

在C++11中所有的值必属于左值、右值两者之一
左值 lvalue   left-value(location-value)
右值 rvalue  right-value(read-value)

C++98
左值（lvalue），可以放在赋值运算符=左边的变量或者表达式，有名字，可以取地址
右值（rvalue），临时变量值（非引用返回的函数返回值、表达式等）或者不跟对象关联的字面量值(注意：字符串字面值是左值，唯一例外)，没有名字，不能取地址
C++11
对右值进行了扩充，右值分为纯右值（prvalue，Pure Rvalue）和将亡值（xvalue，eXpiring Value）
纯右值就是C++98中的右值概念；
将亡值则是C++11新增的跟右值引用相关的表达式，这样表达式通常是将要被移动的对象
*/

/*
左值引用&
右值引用&&

它实现了转移语义 (Move Sementics) 和精确传递 (Perfect Forwarding)。它的主要目的有两个方面：
1. 消除两个对象交互时不必要的对象拷贝，节省运算存储资源，提高效率。
2. 能够更简洁明确地定义泛型函数。

移动构造
移动拷贝

std::move
std::forward
*/

class MyString {
 public:
  MyString() {
    data_ = NULL;
    length_ = 0;
    cout << "default constructor " << endl;
  }
  MyString(char* data, int length) {
    data_ = new char[length];
    length_ = length;
    memcpy(data_, data, length_);
    cout << "constructor " << endl;
  }
  MyString(const MyString& str) {
    data_ = new char[str.length_];
    length_ = str.length_;
    memcpy(data_, str.data_, length_);
    cout << "copy constructor " << endl;
  }
  MyString& operator=(const MyString& str) {
    if (this != &str) {
      data_ = new char[str.length_];
      length_ = str.length_;
      memcpy(data_, str.data_, length_);
    }

    cout << "copy assignment " << endl;
    return *this;
  }
  ~MyString() {
    if (NULL != data_) {
      delete[] data_;
      data_ = NULL;
    }

    cout << "destructor" << endl;
  }
  MyString(MyString&& str) {
    data_ = new char[str.length_];
    length_ = str.length_;
    memcpy(data_, str.data_, length_);
    str.data_ = NULL;
    str.length_ = 0;
    cout << "move constructor " << endl;
  }
  MyString& operator=(MyString&& str) {
    if (this != &str) {
      data_ = new char[str.length_];
      length_ = str.length_;
      memcpy(data_, str.data_, length_);
      str.data_ = NULL;
      str.length_ = 0;
    }

    cout << "move assignment " << endl;
    return *this;
  }

 private:
  char* data_;
  int length_;
};


MyString func() {
  cout << "call func " << endl;
  MyString str("world", 6);
  return std::move(str);
}

void out(int& t) {
  cout << "out T&" << endl;
}

void out(int&& t) {
  cout << "out T&&" << endl;
}

template<typename T>
void forward(T&& t) {
  out(t);
  out(std::forward<T>(t));
  out(std::move(t));
}



void test_pointer() {
  int a;
  const int c_a = 1;

  int* p;
  p = &a;
  //p = &c_a; // error

  const int* p1;
  p1 = &a;
  p1 = &c_a;

  p1 = p;


  int** p2;
  const int** p3;

  p2 = &p;
  // p2 = &p1;  // error

  // p3 = &p;  // error
  p3 = &p1;

  // p3 = p2;  // error
}

int main(int argc, char* argv[]) {
  // 字符串常量是左值
  cout << &("abc") << endl;
  cout << endl;

  // 判断引用、左值引用、右值引用
  int a = 1;
  int& b = a;
  int&& c = 1;

  cout << "a is_reference: " << is_reference<decltype(a)>::value << endl;
  cout << "a is_lvalue_reference: " << is_lvalue_reference<decltype(a)>::value << endl;
  cout << "a is_rvalue_reference: " << is_rvalue_reference<decltype(a)>::value << endl;
  cout << endl;
  cout << "b is_reference: " << is_reference<decltype(b)>::value << endl;
  cout << "b is_lvalue_reference: " << is_lvalue_reference<decltype(b)>::value << endl;
  cout << "b is_rvalue_reference: " << is_rvalue_reference<decltype(b)>::value << endl;
  cout << endl;
  cout << "c is_reference: " << is_reference<decltype(c)>::value << endl;
  cout << "c is_lvalue_reference: " << is_lvalue_reference<decltype(c)>::value << endl;
  cout << "c is_rvalue_reference: " << is_rvalue_reference<decltype(c)>::value << endl;
  cout << endl;

  // std::move

  cout << "a is_lvalue_reference: " << is_lvalue_reference<decltype(a)>::value << endl;
  cout << "a is_rvalue_reference: " << is_rvalue_reference<decltype(a)>::value << endl;
  cout << "move(a) is_lvalue_reference: " << is_lvalue_reference<decltype(move(a))>::value << endl;
  cout << "move(a) is_rvalue_reference: " << is_rvalue_reference<decltype(move(a))>::value << endl;
  // 用途
  // 减少拷贝
  cout << "output1---------------------------" << endl;
  MyString str("hello", 6);
  MyString str1 = std::move(str);
  MyString str2(std::move(str));
  cout << "output2---------------------------" << endl;
  MyString str3;
  str3 = std::move(str);
  cout << "output3---------------------------" << endl;
  str = func();
  cout << "end---------------------------" << endl;

  // 完美转发
  cout << endl;
  cout << endl;
  cout << "forward---------------------------" << endl;
  cout << "lvalue: " << endl;
  int x = 2;
  forward(x);
  cout << endl;
  cout << endl;
  cout << "lvalue refer: " << endl;
  int& y = x;
  forward(y);
  cout << endl;
  cout << endl;
  cout << "rvalue: " << endl;
  forward(1);
  cout << endl;
  cout << endl;
  cout << "rvalue refer: " << endl;
  forward(std::move(x));

  // auto
  int a1 = 1;
  int& a2 = a1;
  const int c_a3 = 10;
  int a4[4];
  const int* const p = &c_a3;

  auto d1 = a1;
  auto d2 = a2;
  auto d3 = c_a3;
  auto d4 = a4;

  cout << "typeid(d1).name: " << typeid(d1).name() << endl;
  cout << "typeid(d2).name: " << typeid(d2).name() << endl;
  cout << "typeid(d3).name: " << typeid(d3).name() << endl;
  cout << "typeid(d4).name: " << typeid(d4).name() << endl;

  d1 = 2;
  cout << "a1: " << a1 << endl;
  d2 = 3;
  cout << "a1: " << a1 << endl;
  d3 = 11;
  cout << "c_a3: " << c_a3 << endl;

  auto& d5 = a1;
  auto& d6 = a2;
  auto& d7 = c_a3;
  auto& d8 = a4;

  cout << "typeid(d8).name: " << typeid(d8).name() << endl;

  d5 = 4;
  cout << "a1: " << a1 << endl;
  d6 = 5;
  cout << "a1: " << a1 << endl;
  //d7 = 12;
  //cout << "c_a3: " << c_a3 << endl;

  //const int* const p = &c_a3;
  //auto p1 = p;
  //auto& p2 = p;


  std::string ss = "hi";
  cout << "ss.size()" << ss.size() << endl;
  cout << "ss.length()" << ss.length() << endl;


  // test_pointer
  test_pointer();

  system("pause");
  return 0;
}
