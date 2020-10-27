#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

int main() {
  {
    // system_clock 来自系统范围实时时钟的壁钟时间
    // 与本地系统时间有关
    // 是唯一有能力映射时间点到C-style时间的C++时钟

// 是否为稳定时钟
cout << "system_clock::is_steady: " << std::boolalpha << system_clock::is_steady << endl;
{
  auto start = system_clock::now();

  int i = 0;
  while (i < 10000)
    i++;

  duration<double> time = system_clock::now() - start;
  cout << "time: " << time.count() << endl;
}
{
  auto t = system_clock::to_time_t(system_clock::now());
  cout << asctime(gmtime(&t)) << endl;
  cout << asctime(localtime(&t)) << endl;

  duration<double> time =
      system_clock::now() - system_clock::from_time_t(t);
  cout << "time: " << time.count() << endl;
}
  }
  {
    // steady_clock 决不调整的单调时钟
cout << "steady_clock::is_steady: " << std::boolalpha << steady_clock::is_steady << endl;
{
  auto start = steady_clock::now();

  int i = 0;
  while (i < 10000)
    i++;

  duration<double> time = steady_clock::now() - start;
  cout << "time: " << time.count() << endl;
}
  }
  {
    // high_resolution_clock
    // high_resolution_clock 在不同标准库实现之间实现不一致，而应该避免使用它。
    // 通常它只是 std::chrono::steady_clock 或 std::chrono::system_clock 的别名，但实际是哪个取决于库或配置。
cout << "high_resolution_clock::is_steady: " << std::boolalpha
     << high_resolution_clock::is_steady << endl;
{
  auto start = high_resolution_clock::now();

  int i = 0;
  while (i < 10000)
    i++;

  duration<double> time = high_resolution_clock::now() - start;
  cout << "time: " << time.count() << endl;
}
  }

  cin.get();

  return 0;
}