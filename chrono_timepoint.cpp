#include <iostream>
#include <chrono>
#include <string>

/**
头文件<chrono>
// time_point
template<class Clock, class Duration = typename Clock::duration> 
class time_point; (C++11 起)

// 构造函数
time_point(); (C++11 起)(C++14 前)(1)
constexpr time_point(); (C++14 起)(1)
explicit time_point( const duration& d ); (C++11 起)(C++14 前)(2)
constexpr explicit time_point( const duration& d ); (C++14 起)(2)
template< class Duration2 >
time_point( const time_point<Clock,Duration2>& t ); (C++11 起)(C++14 前)(3)
template< class Duration2 >
constexpr time_point( const time_point<Clock,Duration2>& t );(C++14 起)(3)

// operator+ operator-
template <class C, class D1, class R2, class P2>
time_point<C, typename common_type<D1, duration<R2, P2>>::type>
operator+(const time_point<C, D1>& pt, const duration<R2, P2>& d);
(since C++ 11)(until C++ 14)(1)
template <class C, class D1, class R2, class P2>
constexpr time_point<C, common_type_t<D1, duration<R2, P2>>> 
operator+(const time_point<C, D1>& pt, const duration<R2, P2>& d);
(since C++ 14)(1)
template <class R1, class P1, class C, class D2>
time_point<C, typename common_type<duration<R1, P1>, D2>::type>
operator+(const duration<R1, P1>& d, const time_point<C, D2>& pt);
(since C++ 11)(until C++ 14)(2)
template <class R1, class P1, class C, class D2>
constexpr time_point<C, common_type_t<duration<R1, P1>, D2>> 
operator+(const duration<R1, P1>& d, const time_point<C, D2>& pt);
(since C++ 14)(2)
template <class C, class D1, class R2, class P2>
time_point<C, typename common_type<D1, duration<R2, P2>>::type>
operator-(const time_point<C, D1>& pt, const duration<R2, P2>& d);
(since C++ 11)(until C++ 14)(3)
template <class C, class D1, class R2, class P2>
constexpr time_point<C, common_type_t<D1, duration<R2, P2>>> 
operator-(const time_point<C, D1>& pt, const duration<R2, P2>& d);
(since C++ 14)(3)
template <class C, class D1, class D2>
typename common_type<D1, D2>::type operator-(
const time_point<C, D1>& pt_lhs, const time_point<C, D2>& pt_rhs);
(since C++ 11)(until C++ 14)(4)
template <class C, class D1, class D2>
constexpr common_type_t<D1, D2> operator-(
const time_point<C, D1>& pt_lhs, const time_point<C, D2>& pt_rhs);
(since C++ 14)(4)

**/

using namespace std;
using Clock = chrono::high_resolution_clock;
using TimePoint = chrono::time_point<Clock>;

void print_ms(const TimePoint& point) {
  using Ms = chrono::milliseconds;
  const Clock::duration since_epoch = point.time_since_epoch();
  cout << chrono::duration_cast<Ms>(since_epoch).count() << " ms\n";
}

template <typename TimePoint>
string to_string(const TimePoint& time_point) {
  return to_string(time_point.time_since_epoch().count());
}

int main() {
  {
    // 构造函数
const TimePoint default_value = TimePoint();  // (1)
print_ms(default_value);

const Clock::duration duration_4_seconds = chrono::seconds(4);
const TimePoint time_point_4_seconds(duration_4_seconds);  // (2)
print_ms(time_point_4_seconds);
const TimePoint time_point_now = Clock::now();  // (3)
print_ms(time_point_now);
  }
  {
    // time_since_epoch
const auto p0 = chrono::time_point<chrono::system_clock>{};
const auto p1 = chrono::system_clock::now();
const auto p2 = p1 - chrono::hours(24);

time_t epoch_time = chrono::system_clock::to_time_t(p0);
cout << "epoch: " << ctime(&epoch_time);
time_t today_time = chrono::system_clock::to_time_t(p1);
cout << "today: " << ctime(&today_time);

cout << "hours since epoch: "
     << chrono::duration_cast<chrono::hours>(p1.time_since_epoch()).count()
     << endl;
cout << "yesterday, hours since epoch: "
     << chrono::duration_cast<chrono::hours>(p2.time_since_epoch()).count()
     << endl;
  }
  {
    // operator+= -=
const Clock::duration duration_4_seconds = chrono::seconds(4);
TimePoint time_point_4_seconds(duration_4_seconds);
time_point_4_seconds += duration_4_seconds;
print_ms(time_point_4_seconds);
  }
  {
    // operator++ ++(int) -- --(int) (C++20)
  } 
  {
    // min max
print_ms(TimePoint::min());
print_ms(TimePoint::max());
  }
  {
    // operator+ operator-
const Clock::duration duration_4_seconds = chrono::seconds(4);
TimePoint time_point_4_seconds(duration_4_seconds);
time_point_4_seconds = time_point_4_seconds + duration_4_seconds;
print_ms(time_point_4_seconds);
time_point_4_seconds = time_point_4_seconds - duration_4_seconds;
print_ms(time_point_4_seconds);
const Clock::duration milliseconds = chrono::milliseconds(10);
time_point_4_seconds = time_point_4_seconds - milliseconds;
print_ms(time_point_4_seconds);
  }
  {
    // operator==,!=,<,<=,>,>=,<=>
  } 
  {
  // time_point_cast
const Clock::duration duration_4_seconds = chrono::seconds(4);
TimePoint time_point_4_seconds(duration_4_seconds);
print_ms(chrono::time_point_cast<chrono::milliseconds>(time_point_4_seconds));
  }
  {
    // floor ceil round
    // floor  converts a time_point to another, rounding down
    // ceil   converts a time_point to another, rounding up
    // round  converts a time_point to another, rounding to nearest, ties to even
using namespace literals::chrono_literals;
using Sec = chrono::seconds;

cout << "Time point\t"
             "Cast\t"
             "Floor\t"
             "Round\t"
             "Ceil\n";
cout << "(ms)\t\t"
             "(s)\t"
             "(s)\t"
             "(s)\t"
             "(s)\n";
for (const auto value_ms : {5432ms, 5678ms}) {
  chrono::time_point<chrono::system_clock,
                          chrono::milliseconds>
      time_point_ms(value_ms);

  cout << to_string(time_point_ms) << "\t\t"
       << to_string(chrono::time_point_cast<Sec>(time_point_ms))
       << "\t" << to_string(chrono::floor<Sec>(time_point_ms))
       << "\t" << to_string(chrono::round<Sec>(time_point_ms))
       << "\t" << to_string(chrono::ceil<Sec>(time_point_ms))
       << "\n";
}
  }
  {
    // common_type(chrono::time_point)
cout << typeid(common_type<chrono::time_point<Clock, chrono::seconds>,
  chrono::time_point<Clock, chrono::milliseconds>>::type).name() << endl;
  }


  cin.get();
  return 0;
}