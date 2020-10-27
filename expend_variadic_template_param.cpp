#include <iostream>
#include <functional>

template<typename T>
void print(const T& t, int& size) {
  --size;
  std::cout << t << " ";
  if (0 == size) {
    std::cout << "over!" << std::endl;
  }
}

template <typename ... Args>
void unpacker(Args...args) {}

template <typename ... Args>
void print_all(Args&& ...args) {
  {
    int size = sizeof...(args);
    std::cout << std::endl;

    std::cout << "method 1: " << std::endl;
    int dummy[] { 0, (print<Args>(std::forward<Args>(args), size), 0)... };
  }
  {
    int size = sizeof...(args);
    std::cout << std::endl;

    std::cout << "method 2: " << std::endl;
    unpacker((print<Args>(std::forward<Args>(args), size), 0)...);
  }
  {
    int size = sizeof...(args);
    std::cout << std::endl;

    std::cout << "method 3: " << std::endl;
    std::initializer_list<int> {(print<Args>(std::forward<Args>(args), size), 0)...};
  }
  {
    int size = sizeof...(args);
    std::cout << std::endl;

    std::cout << "method 4: " << std::endl;
    auto f = [](...) {};
    f((print<Args>(std::forward<Args>(args), size), 0)...);
  }
  {
    int size = sizeof...(args);
    std::cout << std::endl;

    std::cout << "method 5: " << std::endl;
    struct dummy {
      dummy(std::initializer_list<int>) {}
    };
    dummy{ (print<Args>(std::forward<Args>(args), size), 0)... };
  }
}

int main() {
  print_all(1, 2, 3, "hello world");
  std::cin.get();
  return 0;
}