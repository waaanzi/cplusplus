#include <ctime>
#include <thread> // this_thread https://blog.csdn.net/luoshabugui/article/details/86588578
#include <chrono> // chrono
#include <iomanip> // put_time
#include <iostream>
/*
Time manipulation
difftime  double difftime( std::time_t time_end, std::time_t time_beg );
time std::time_t time( std::time_t* arg );
clock std::clock_t clock(); 获得elapsed CPU time，单位是1/CLOCKS_PER_SEC秒
timespec_get(C++17)

Format conversions
asctime char* asctime( const std::tm* time_ptr );
ctime
strftime
wcsftime
gmtime
localtime
mktime

Constants
CLOCKS_PER_SEC

types
struct tm 日历时间类型
time_t 数值类型的 typedef， 表现timepoint
clock_t 数值类型的 typedef, 表现elapsed CPU time
timespec(C++17) 
*/
int main() 
{
  {
    // std::time
    auto time = std::time(0);
    std::cout << "time: "<< time << std::endl;
  }
  {
    // std::difftime
    auto start = std::time(0);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    auto end = std::time(0);
    std::cout << "std:difftime: " << std::difftime(end, start) << std::endl;
  }
  {
    // clock
    auto clock = std::clock();
    std::cout << "clock: " << clock << std::endl;
  }
  {
    // asctime tm转换为一个标准日历时间字符串 Www Mmm dd hh:mm:ss yyyy\n
    auto time = std::time(0);
    std::cout << "std::asctime: " << std::asctime(std::localtime(&time)) << std::endl;
  }
  {
    // ctime char* ctime( const std::time_t* time );
    // 如同通过调用 std::asctime(std::localtime(time)) 
    auto time = std::time(0);
    std::cout << "std::ctime: " << std::ctime(&time) << std::endl;
  }
  {
    // strftime std::size_t strftime( char* str, std::size_t count, const char* format, const std::tm* time );
    auto time = std::time(0);
    char str[200];
    std::strftime(str, sizeof(str), "%A %c", std::localtime(&time));
    std::cout << "std::strftime: " << str << std::endl;
  }
  {
    // gmtime std::tm* gmtime( const std::time_t* time );
    // localtime std::tm* localtime( const std::time_t *time );
    auto time = std::time(0);
    std::cout << "std:gmtime: " << std::put_time(std::gmtime(&time), "%c %A") << std::endl;
    std::cout << "std:localtime: " << std::put_time(std::localtime(&time), "%c %A") << std::endl;
  }
  {
    // mktime std::time_t mktime( std::tm* time );
     auto time = std::time(0);
     auto tm = *std::localtime(&time);
     tm.tm_mon += 2;
     std::mktime(&tm);
     auto time1 = std::mktime(&tm);
     std::cout << "std:mktime: " << std::put_time(std::localtime(&time1), "%c %A") << std::endl;
  }
  {
    // CLOCKS_PER_SEC
    std::cout << "CLOCKS_PER_SEC: " << CLOCKS_PER_SEC << std::endl;
  }


  std::tm tm_;
  std::time_t t;
  std::clock_t c;

  std::cin.get();
  return 0;
}