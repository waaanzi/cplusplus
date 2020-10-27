#include <iterator>  
#include <algorithm> // copy
#include <iostream>
#include <vector>
#include <list> 
#include <string>
/*
// std::inserter Container c 需支持insert
template< class Container >
std::insert_iterator<Container> inserter( Container& c, typename
Container::iterator i ); (until C++20) 
template< class Container > constexpr
std::insert_iterator<Container> inserter( Container& c,
ranges::iterator_t<Container> i );(since C++20) 

// std::front_inserter Container c 需支持push_front
template< class Container >
std::front_insert_iterator<Container> front_inserter( Container& c ); (until C++20)
template< class Container >
constexpr std::front_insert_iterator<Container> front_inserter( Container& c ); (since C++20)

// std::back_inserter Container c 需支持push_back
template< class Container >
std::back_insert_iterator<Container> back_inserter( Container& c ); (until C++20)
template< class Container >
constexpr std::back_insert_iterator<Container> back_inserter( Container& c ); (since C++20)

// std::make_reverse_iterator
template <class Iter>
std::reverse_iterator<Iter> make_reverse_iterator( Iter i ); (since C++14) (until C++17)
template <class Iter>
constexpr std::reverse_iterator<Iter> make_reverse_iterator( Iter i ); (since C++17)

// std::make_move_iterator
template< class Iter >
std::move_iterator<Iter> make_move_iterator( const Iter& i ); (since C++11) (until C++14)
template< class Iter >
std::move_iterator<Iter> make_move_iterator( Iter i ); (since C++14) (until C++17)
template< class Iter >
constexpr std::move_iterator<Iter> make_move_iterator( Iter i ); (since C++17)
*/

template<typename T>
void print(const T& vc, const std::string& pre="") 
{
  std::cout << pre;
  for (auto i : vc) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

int main() {

  std::vector<int> vc{1,2,3,4,5};
  {
    // std::inserter
    // std::vector<int> vc1(vc.size()); // vector有个设置大小的构造函数
    std::vector<int> vc1;
    std::copy(vc.begin(), vc.end(), std::inserter(vc1, vc1.begin()));

    print(vc1, "vc1: ");
  }

  {
    // std::front_inserter
    std::list<int> vc2;
    std::copy(vc.begin(), vc.end(), std::front_inserter(vc2));

    print(vc2, "vc2: ");
  }

  {
    // std::back_inserter
    std::vector<int> vc3;
    std::copy(vc.begin(), vc.end(), std::back_inserter(vc3));

    print(vc3, "vc3: ");
  }

  {
    // std::make_reverse_iterator
    std::vector<int> vc4;
    std::copy(std::make_reverse_iterator(vc.end()), 
      std::make_reverse_iterator(vc.begin()), std::back_inserter(vc4));

    print(vc4, "vc4: ");
  }

  {
    // std::make_move_iterator
    std::cout << std::endl << "std::make_move_iterator Demo: " << std::endl;
    std::vector<std::string> vs {"one", "two", "three"};
    print(vs, "vs: ");
    std::vector<std::string> vc5(std::make_move_iterator(vs.begin()), std::make_move_iterator(vs.end()));
    print(vc5, "vc5: ");
    print(vs, "vs: ");
  }
  std::cin.get();
  return 0;
}