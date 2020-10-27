#include <chrono>
#include <iostream>
#include <string>

/*
 template<class Rep, class Period = std::ratio<1>> class duration; (since
 C++11)
*/

 template <class DurationT>
 void print(const std::string pre, const DurationT& d) {
  std::cout << "(" << pre << ")";
  std::cout << ".count(): " << d.count() << std::endl;
}

 int main() {
  if (1) {
    std::cout
        << typeid(std::chrono::duration<uint8_t,
        std::ratio<1>>::zero()).name();
    std::cout
        << typeid(std::chrono::duration<uint8_t,
        std::ratio<1>>::min()).name();
    std::cout
        << typeid(std::chrono::duration<uint8_t,
        std::ratio<1>>::max()).name();
  }
  {
    // operator+(unary) operator-(unary)
    std::chrono::duration<int, std::ratio<1, 2>> d1{10};
    print("d1", d1);
    std::chrono::duration<int, std::ratio<1, 2>> d2 = +d1;
    print("d2", d2);
    d2 = -d1;
    print("d2", d2);
  }
  {
    // operator++ operator-- (递增、递减tick数)
    std::chrono::duration<int, std::ratio<1, 2>> d1{10};
    print("d1", d1);
    print("d1++", d1++);
    print("d1--", d1--);
    print("++d1", ++d1);
    print("--d1", --d1);
  }
  {
    // compound assignment (复合赋值)
    std::chrono::duration<int, std::ratio<1, 2>> d1{1};
    print("d1", d1);
    std::chrono::duration<int, std::ratio<1, 3>> d2{1};
    std::chrono::duration<int, std::ratio<1>> d3{1};
    // d1 += d2; 不存在从d2 Period 到 d1 Period的隐式转换
    d1 += d3;
    print("d1", d1);
  }
  {
    // 加减乘除 取模
    std::chrono::duration<int, std::ratio<1, 2>> d1{1};
    print("d1", d1);
    std::chrono::duration<int, std::ratio<1, 3>> d2{1};
    print("d1+d2", d1 + d2);
    std::cout << "typeid(decltype(d1+d2)).name(): " << std::endl
              << typeid(decltype(d1 + d2)).name() << std::endl;
    print("d1-d2", d1 - d2);
    print("2*d1", 2 * d1);
    print("d2*2", d2 * 2);
    std::cout << "d1/d2 : " << d1 / d2 << std::endl;
    print("d1/2", d1 / 2);
    print("d1%d2", d1 % d2);
    print("d1%2", d1 % 2);
  }
  {
    // 关系运算
    std::chrono::duration<int, std::ratio<1, 2>> d1{1};
    std::chrono::duration<int, std::ratio<1, 3>> d2{1};
    std::cout << "d1==d2 : " << (d1 == d2) << std::endl;
  }
  {
    // duration_cast floor ceil round abs
    std::chrono::duration<int, std::ratio<1, 3>> d1{1};
    auto d2 = std::chrono::duration_cast<
        std::chrono::duration<int, std::ratio<1, 10>>>(d1);
    print("d2", d2);
    auto d3 =
        std::chrono::floor<std::chrono::duration<int, std::ratio<1, 10>>>(d1);
    print("d3", d3);
    auto d4 =
        std::chrono::ceil<std::chrono::duration<int, std::ratio<1, 10>>>(d1);
    print("d4", d4);
    auto d5 =
        std::chrono::round<std::chrono::duration<int, std::ratio<1, 10>>>(d1);
    print("d5", d5);
    auto d5_1 =
        std::chrono::round<std::chrono::duration<int, std::ratio<1, 5>>>(d5);
    print("d5_1", d5_1);  // round就近取整，偶数优先
    std::chrono::duration<int, std::ratio<1, 3>> d6{-1};
    auto d7 = std::chrono::abs(d6);
    print("d7", d7);
  }
  {
      // operator<< from_stream
  } {
    std::chrono::nanoseconds(1);
    std::chrono::microseconds(2);
    std::chrono::milliseconds(3);
    std::chrono::seconds(4);
    std::chrono::minutes(5);
    std::chrono::hours(6);
    // std::chrono::days
    // std::chrono::weeks
    // std::chrono::months
    // std::chrono::years

    // std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  {
    // std::common_type
    std::chrono::seconds d1(1);
    std::chrono::minutes d2(1);
    typedef std::common_type<std::chrono::seconds, std::chrono::minutes>::type
        type;
    std::cout << typeid(type).name() << std::endl;
    type d3(d2);
    print("d3", d3);
  }
  {
    // treat_as_floating_point
    std::chrono::seconds d1(1);
    auto v = std::chrono::treat_as_floating_point<
        std::chrono::milliseconds::rep>::value;
  }
  {
    // duration_values
    std::cout <<
    std::chrono::duration_values<std::chrono::seconds::rep>::zero()
              << std::endl;
    std::cout <<
    std::chrono::duration_values<std::chrono::seconds::rep>::min()
              << std::endl;
    std::cout <<
    std::chrono::duration_values<std::chrono::seconds::rep>::max()
              << std::endl;
  }
  {
      // std::formatter
  } {
    // literals
    using namespace std::chrono_literals;
    print("10h", 10h);
  }

  std::cin.get();
  return 0;
}