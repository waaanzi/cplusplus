/*
std::thread
头文件<thread>
类thread标识单个执行线程，线程允许多个函数并发执行。
在默认构造、移动、detach或join后，std::thread对象会处在不表示任何线程的状态。detach之后，执行线程可能不关联到任何thread对象
成员类 std::thread::id ，是轻量的频繁复制类，作为std::thread对象的唯一标识符工作。

观察器：
joinable 检查thread对象是否标识活跃的执行线程。当get_id() !=std::thread::id()返回true,所以默认构造的thread不可合并。
get_id 返回标识与*this关联的线程的std::thread::id类型值。若无关联的线程，则返回默认构造的std::thread::id。
native_handle 返回实现定义的底层线程句柄
hardware_concurrency 静态，返回实现所支持的并发线程数。应该只把值当做提示。
操作：
join 阻塞当前线程，直至*this所标识的线程完成其执行。*this所标识的线程的完成同步与从join()的成功返回
detach 从thread对象分离执行的线程，允许执行独立地持续。一旦线程退出，则释放所有分配的资源。调用detach后，*this不再占有任何线程。
swap 互换2个thread对象的底层句柄。
非成员函数：
std::swap（std::thread）
*/

#include <iostream>     // std::cout
#include <thread>       // std::thread
#include <chrono>
#include <utility>      // std::move
// #include <algorithm>    // std::swap
#include <functional>   // std::ref
#include <vector>       // vector
#include <ctime>        // clock_t clock()
#include <mutex>        // std::mutex
#include <atomic>
#include <condition_variable>

using namespace std;
std::mutex mmmm;
std::condition_variable_any var;

void func1(int n) {
  cout << "func1" << endl;
  n += 10;

  std::unique_lock<std::mutex> lock(mmmm);
  var.wait_for(lock, std::chrono::milliseconds(5000));
  // this_thread::sleep_for(chrono::milliseconds(5000));
  cout << "func22" << endl;
}

void func2(int& n) {
  cout << "func2" << endl;
  n += 20;
  this_thread::sleep_for(chrono::milliseconds(10));
}

void show() {
  cout << "show hello world" << endl;
}


const int N = 1000000;
int num = 0;
void count() {
  for (int i = 0; i < N; i++) {
    num++;
  }
}

mutex m;
void count_mutex() {
  for (int i = 0; i < N; i++) {
    m.lock();
    num++;
    m.unlock();
  }
}

std::atomic_int num1 = 0;
void count_atomic_int() {
  for (int i = 0; i < N; i++) {
    num1++;
  }
}

int main() {

  int n = 1;
  auto time = std::time(0);
  thread t2(func1, n);
  // std::unique_lock<std::mutex> lock(mmmm);
  std::this_thread::sleep_for(chrono::milliseconds(1000));
  var.notify_one();
  t2.join();

  auto time1 = std::time(0)- time;
  int i = 0;; 

  //{
  //  // 1 thread构造及初始化
  //  int n = 1;
  //  thread t1; // t1处在不表示任何线程的状态
  //  thread t2(func1, n);
  //  t2.join();
  //  cout << "after func1 n: " << n << endl;
  //  thread t3(func2, ref(n));
  //  t3.join();
  //  cout << "after func2 n: " << n << endl;

  //  // thread不可复制构造或可复制复制
  //  // thread t4(t3); // error
  //  // thread t5 = t3; // error

  //  thread t6(func1, n);
  //  thread t7(move(t6)); // thread可移动构造
  //  t7.join();

  //  std::vector<thread> vc;
  //  vc.push_back(thread(show)); // thread存放在vector中
  //  vc[0].join();

  //  shared_ptr<thread> p(new thread(show)); // share_ptr和thread结合
  //  p->join();
  //}
  //cout << endl;
  //cout << endl;
  //{
  //  // 2 join detach
  //  thread t1(show);
  //  cout << endl;
  //  cout.setf(ios_base::boolalpha); // bool输出为true/false
  //  cout << "t1 joinable: " << t1.joinable() << endl;
  //  t1.join();
  //  cout << "t1 joinable after join: " << t1.joinable() << endl;

  //  thread t2(show);
  //  cout << endl;
  //  cout << "t2 joinable: " << t2.joinable() << endl;
  //  t2.detach();
  //  cout << "t2 joinable after detach: " << t2.joinable() << endl;

  //}
  //cout << endl;
  //cout << endl;
  //{
  //  // 3 hardware_concurrency
  //  auto n = thread::hardware_concurrency(); // cpu核数
  //  cout << "thread::hardware_concurrency(): " << n << endl;
  //}
  //cout << endl;
  //cout << endl;
  //{
  //  // 4 thread 原子变量与线程安全
  //  {
  //    clock_t start = clock();
  //    thread t1(count);
  //    thread t2(count);
  //    t1.join();
  //    t2.join();
  //    clock_t end = clock();
  //    cout << "after count num: " << num << " , use " << end - start << "ms" << endl;
  //  }
  //  {
  //    num = 0;
  //    // 互斥量 方式1
  //    clock_t start = clock();
  //    thread t1(count_mutex);
  //    thread t2(count_mutex);
  //    t1.join();
  //    t2.join();
  //    clock_t end = clock();
  //    cout << "method1 after count_mutex num: " << num << " , use " << end - start << "ms" << endl;
  //  }
  //  {
  //    num = 0;
  //    // 互斥量 方式2
  //    clock_t start = clock();
  //    thread t1(count_mutex);
  //    t1.join();
  //    thread t2(count_mutex);
  //    t2.join();
  //    clock_t end = clock();
  //    cout << "method2 after count_mutex num: " << num << " , use " << end - start << "ms" << endl;
  //  }
  //  {
  //    // 原子变量 方式1
  //    clock_t start = clock();
  //    thread t1(count_atomic_int);
  //    thread t2(count_atomic_int);
  //    t1.join();
  //    t2.join();
  //    clock_t end = clock();
  //    cout << "method1 after count_atomic_int num1: " << num1 << " , use " << end - start << "ms" << endl;
  //  }
  //  {
  //    num1 = 0;
  //    // 原子变量 方式2
  //    clock_t start = clock();
  //    thread t1(count_atomic_int);
  //    t1.join();
  //    thread t2(count_atomic_int);
  //    t2.join();
  //    clock_t end = clock();
  //    cout << "method2 after count_atomic_int num1: " << num1 << " , use " << end - start << "ms" << endl;
  //  }
  //}
  //{
  //  // 5 lambda
  //  auto lam = [] {cout << "hello world" << endl; };
  //  thread t1(lam);
  //  t1.join();
  //  thread t2(lam);
  //  t2.join();
  //}
  //cout << endl;
  //cout << endl;
  //{
  //  // 6 时间等待
  //  thread t1([]() {
  //    this_thread::sleep_for(chrono::seconds(3));
  //    this_thread::yield();
  //    cout << "u can u up" << endl;
  //  });
  //  t1.join();
  //}
  //cout << endl;
  //cout << endl;
  //{
  //  // 7 可变参数
  //  thread t1(printf, "%s%d", "hi", 999);
  //  t1.join();
  //}
  //cout << endl;
  //cout << endl;
  //{
  //  // 8 线程交换
  //  thread t1([] {/*cout << "thread1"; cout << endl; */});
  //  thread t2([] {/*cout << "thread2"; cout << endl; */});
  //  cout << "thread1 id: " << t1.get_id() << endl;
  //  cout << "thread2 id: " << t2.get_id() << endl;
  //  std::swap(t1, t2);
  //  cout << "after swap:" << endl;
  //  cout << "thread1 id: " << t1.get_id() << endl;
  //  cout << "thread2 id: " << t2.get_id() << endl;
  //  t1.join();
  //  t2.join();
  //}
  //cout << endl;
  //cout << endl;
  //{
  //  // 9 线程移动
  //  thread t1([] {cout << "thread1"; cout << endl; });
  //  cout << "thread1 id: " << t1.get_id() << endl;
  //  thread t2 = move(t1);
  //  cout << "thread2 id: " << t2.get_id() << endl;
  //  t2.join();
  //}
  system("pause");
  return 0;
}