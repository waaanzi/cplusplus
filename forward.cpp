#include <iostream>
using namespace std;
void out(int& t) {
  cout << "out T&" << endl;
}

void out(int&& t) {
  cout << "out T&&" << endl;
}

template <typename T>
void forward(T&& t) {
  out(t);
  out(std::forward<T>(t));
  out(std::move(t));
}

int main() {
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

cout << endl;
cout << endl;
cout << "call out: " << endl;
int n = 1;
int& rn = n; 
out(1);
out(n);
out(rn);

std::cin.get();
return 0;
}