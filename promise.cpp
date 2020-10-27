#include <algorithm>  // sort
#include <future>     // future promise
#include <iostream>   // cout cin endl
#include <iterator>   // istream_iterator back_inserter
#include <sstream>    // istringstream
#include <thread>     // thread
#include <vector>     // vector
#include <numeric>    // accumulate

void accumulate(std::vector<int>::iterator first,
                std::vector<int>::iterator last,
                std::promise<int> accumulate_promise) {
  int sum = std::accumulate(first, last, 0);
  accumulate_promise.set_value(sum);  // 原子地存储 num 到共享状态，并令状态就绪
}

int main() {
  std::istringstream iss_numbers{"3 4 1 42 23 -23 93 2 -289 93"};
  std::vector<int> numbers;

  {
    // set_value 1
    std::promise<void> numbers_promise;
    std::future<void> numbers_future = numbers_promise.get_future();
   
    std::thread t([&] {
      std::copy(std::istream_iterator<int>{iss_numbers},
                std::istream_iterator<int>{}, std::back_inserter(numbers));
      numbers_promise.set_value(); // 使状态就绪
    });
   
    numbers_future.wait();
    std::sort(numbers.begin(), numbers.end());
   
    for (int num : numbers)
      std::cout << num << ' ';
    std::cout << std::endl;
   
    t.join();
  }

  {
    // set_value 2
    std::promise<int> accumulate_promise;
    std::future<int> accumulate_future = accumulate_promise.get_future();
    std::thread t(accumulate, numbers.begin(), numbers.end(),
                            std::move(accumulate_promise));

    std::cout << "result=" << accumulate_future.get() << '\n';
    t.join(); 
  }
  {
// set_value_at_thread_exit
using namespace std::chrono_literals;
std::promise<int> p;
std::future<int> f = p.get_future();
std::thread([&p] {
  std::this_thread::sleep_for(1s);
  p.set_value_at_thread_exit(9);
}).detach();

std::cout << "Waiting..." << std::flush;
f.wait();
std::cout << "Done!\nResult is: " << f.get() << std::endl;
  }
  {
// set_exception
std::promise<int> p;
std::future<int> f = p.get_future();

std::thread t([&p] {
  try {
    throw std::runtime_error("Example");
  } catch (...) {
    try {
      // store anything thrown in the promise
      p.set_exception(std::current_exception());
    } catch (...) {
    }  // set_exception() may throw too
  }
});

try {
  std::cout << f.get();
} catch (const std::exception& e) {
  std::cout << "Exception from the thread: " << e.what() << std::endl;
}
t.join();
  }
  {
    // set_exception_at_thread_exit
  }

  std::cin.get();
  return 0;
}