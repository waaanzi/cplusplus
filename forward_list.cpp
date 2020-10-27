#include <forward_list>
#include <iostream>
#include <string>

template<typename C>
void print(const std::string& pre, const C& c) 
{
  std::cout << std::endl;
  std::cout << pre << std::endl;
  for(auto item : c) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}

class A 
{
 public:
  explicit A(int a = 0) {}
  explicit A(int a, int b) {}
};

int main() 
{
  std::forward_list<int> c1 {1,2,3,4,5,6,7};
  print("original c1£º", c1);
  // iterator
  {
    //std::forward_list<int> c;
    //std::cout << "empty forward_list begin==before_begin: " << (c.begin() == c.before_begin()); 
  }

  // insert_after
  {
    c1.insert_after(c1.before_begin(), 10);
    print("1 insert_after c1£º", c1);
    c1.insert_after(c1.begin(), 3, 30);
    print("2 insert_after c1£º", c1);

    std::forward_list<int> temp_c {100,200,300};
    c1.insert_after(c1.before_begin(), temp_c.begin(), temp_c.end());
    print("3 insert_after c1£º", c1);
  }
  // emplace_after
  {
    std::forward_list<A> temp_c;
    A a1;
    temp_c.insert_after(temp_c.before_begin(), a1);
    temp_c.emplace_after(temp_c.before_begin(), 1);
    temp_c.emplace_front(2,2);

    std::cout << "temp_c size:" << std::distance(temp_c.begin(), temp_c.end()) << std::endl;
  }
  // erase_after
  {
    print("c1£º", c1);
    auto it = std::next(c1.begin(), 9);
    c1.erase_after(c1.begin(), it);
    print("1 erase_after c1£º", c1);
    c1.erase_after(it);
    print("2 erase_after c1£º", c1);
  }
  // splice_after
  {
    print("c1£º", c1);
    std::forward_list<int> temp_c {1000,2000,3000};
    print("original temp_c£º", temp_c);
    c1.splice_after(c1.before_begin(), temp_c);
    print("splice_after temp_c£º", temp_c);
    print("splice_after c1£º", c1);

    std::forward_list<int> temp1_c {7000,8000,9000};
    print("original temp1_c£º", temp1_c);
    c1.splice_after(c1.before_begin(), temp1_c, temp1_c.begin());
    print("splice_after temp1_c£º", temp1_c);
    print("splice_after c1£º", c1);

    c1.splice_after(c1.before_begin(), temp1_c, temp1_c.begin(), temp1_c.end());
    print("splice_after temp1_c£º", temp1_c);
    print("splice_after c1£º", c1);

  }


  std::cin.get();
  return 0;
}