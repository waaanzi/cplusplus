#include <functional>  // tie
#include <iostream>    // cout cin
#include <tuple>       // tuple

template <int Index, int Size, typename ...Args>
class PrintTuple{
 public:
  static void print(std::ostream& os, const std::tuple<Args...>& t) {
    os << std::get<Index>(t) << ((Index + 1 == Size) ? " " : ", ");
    PrintTuple<Index + 1, Size, Args...>::print(os, t);
  }
};

template <int Size, typename... Args>
class PrintTuple<Size, Size, Args...> {
 public:
  static void print(std::ostream& os, const std::tuple<Args...>& t) {
  }
};

template <typename ...Args>
std::ostream& operator<<(std::ostream& os, const std::tuple<Args...>& t) {
  os << "[";
  PrintTuple<0, sizeof...(Args), Args...>::print(os, t);
  os << "]";
  return os;
}

int main() {
  {
    // 取值
    std::tuple<int, double> t{1, 1.1};
    std::cout << "std::get<0>(t): " << std::get<0>(t) << std::endl;
    std::cout << "std::get<1>(t): " << std::get<1>(t) << std::endl;
  }
  {
    // 辅助函数
    // tie ignore
    int i = 0;
    double d = 0;
    std::tuple<int, double> t{1, 2.2};
    std::tie(i, d) = t;
    std::tie(std::ignore, i) = t;
    std::cout << "i: " << i << " d: " << d << std::endl;

    // make_tuple ref
    auto m = std::make_tuple(3, 4);
    int i1 = 0;
    double d1 = 0;
    auto m1 = std::make_tuple(std::ref(i1), d1);
    std::get<1>(m1) = 100; // i1 = 100

    // tuple_element
    using Type = std::tuple_element<0, decltype(m)>::type;  // int
    Type e = 100;

    // tuple_cat
    auto c = std::tuple_cat(t, m);

    // tuple_size
    std::cout << "std::tuple_size<decltype(c)>::value: "
              << std::tuple_size<decltype(c)>::value << std::endl;
  }
  {
    // 打印
    auto m = std::make_tuple(1, 2, "hello");
    std::cout << "m: " << m;
  }
  std::cin.get();
}