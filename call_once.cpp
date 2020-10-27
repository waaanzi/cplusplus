/*
std::call_once
std::once_flag

定义于头文件 <mutex>
template< class Callable, class... Args >
void call_once( std::once_flag& flag, Callable&& f, Args&&... args ); (C++11 起)
准确执行一次可调用 (Callable) 对象 f ，即使同时从多个线程调用。

细节为：
If, by the time call_once is called, flag indicates that f was already called, call_once returns right away (such a call to call_once is known as passive).
Otherwise, call_once invokes ​std​::​forward<Callable>(f) with the arguments std​::​forward<Args>(args)... (as if by std::invoke).
Unlike the std::thread constructor or std::async, the arguments are not moved or copied because they don't need to be transferred to another thread of execution. (such a call to call_once is known as active).
    If that invocation throws an exception, it is propagated to the caller of call_once,
and the flag is not flipped so that another call will be attempted (such call to call_once is known as exceptional).
    If that invocation returns normally (such call to call_once is known as returning),
the flag is flipped, and all other calls to call_once with the same flag are guaranteed to be passive.

All active calls on the same flag form a single total order consisting of zero or more exceptional calls,
followed by one returning call. The end of each active call synchronizes-with the next active call in that order.

The return from the returning call synchronizes-with the returns from all passive calls on the same flag:
this means that all concurrent calls to call_once are guaranteed to observe any side-effects made by the active call,
with no additional synchronization.

若在调用call_once的时刻， flag指示已经调用了f，则call_once立即返回（称这种对call_once的调用为消极）。
否则，call_once 以参数 std​::​forward<Args>(args)... 调用std​::​forward<Callable>(f)（如同用 std::invoke）。不同于std::thread构造函数或std::async，
不移动或复制参数，因为不需要转移它们到另一执行线程（称这种对 call_once 的调用为积极）。
若该调用抛异常，则传播异常给call_once的调用方，并且不翻转flag ，以令其他调用将得到尝试（这种对call_once的调用被称为异常）。
若该调用正常返回（这种对call_once的调用被称为返回），则翻转 flag ，并保证以同一 flag 对call_once的其他调用为消极。
同一flag上的所有积极调用组成单独全序，它们由零或多个异常调用后随一个返回调用组成。该顺序中，每个积极调用的结尾同步于下个积极调用。

从返回调用的返回同步于同一 flag 上的所有消极调用：这表示保证所有对call_once的同时调用都观察到积极调用所做的任何副效应，而无需额外同步。

注意：
std::once_flag

定义于头文件 <mutex>
class once_flag; (C++11 起)
类 std::once_flag 是 std::call_once 的辅助类。
std::once_flag 既不可复制亦不可移动。
once_flag的生命周期必须要比使用它的线程的生命周期要长
*/


#include <iostream>
#include <thread>
#include <mutex>

std::once_flag flag1, flag2;

void simple_do_once() {
  std::call_once(flag1, []() {
    std::cout << "Simple example: called once\n";
  });
}

void may_throw_function(bool do_throw) {
  if (do_throw) {
    std::cout << "throw: call_once will retry\n"; // this may appear more than once
    throw std::exception();
  }
  std::cout << "Didn't throw, call_once will not attempt again\n"; // guaranteed once
}

void do_once(bool do_throw) {
  try {
    std::call_once(flag2, may_throw_function, do_throw);
  } catch (...) {
  }
}

int main() {
  std::thread st1(simple_do_once);
  std::thread st2(simple_do_once);
  std::thread st3(simple_do_once);
  std::thread st4(simple_do_once);
  st1.join();
  st2.join();
  st3.join();
  st4.join();

  std::thread t1(do_once, true);
  std::thread t2(do_once, true);
  std::thread t3(do_once, false);
  std::thread t4(do_once, true);
  t1.join();
  t2.join();
  t3.join();
  t4.join();

  getchar();
}