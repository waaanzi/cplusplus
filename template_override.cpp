#include "template_override.h"
#include <thread>


template<> void base::hey<int>(int t) {
  std::cout << "Specialization hey int" << std::endl;
}

A a;



#include <vector>
#include <list>

class N {
 public:
  N() {
    std::cout << "N create" << std::endl;
  }
  ~N() {
    std::cout << "N delete" << std::endl;
  }
};

int main() {
  //base d;
  //d.hello(1.1);
  //d.hello(10);

  // auto a = std::make_shared<A>();
  // a.f1();

  //std::thread t(&A::f1, a);
  //t.join();

  // a.f1();

  std::cout << "std::vector:" << std::endl << std::endl;
  {
    std::vector<N> v;
    N n;
    for (int i = 0; i < 5; i++) {
      v.push_back(n);
    }
  }
  std::cout << std::endl;
  std::cout << "std::list:" << std::endl << std::endl;
  {
    std::list<N> l;
    N n;
    for (int i = 0; i < 5; i++) {
      l.push_back(n);
    }
  }

  while (true);
  getchar();
  return 0;

}