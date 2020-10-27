#include <iostream>
#include <iterator>
#include <vector>

int main() {
  {
    // ¼¸¸ö¸¨Öúº¯Êý
    std::vector<int> vc {0,1,2,3,4,5,6,7,8,9};

    std::cout << "vc: " << std::endl;
    for(auto i : vc) {
      std:: cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "it = vc.begin()" << std::endl;
    auto it = vc.begin();
    std::cout << "*it: " << *it << std::endl;
    
    // std::next
    std::cout << std::endl;
    std::cout << "it = std::next(it, 7)" << std::endl;
    it = std::next(it, 7);
    std::cout << "*it: " << *it << std::endl;
    std::cout << "it = std::next(it, -1)" << std::endl;
    it = std::next(it, -1);
    std::cout << "*it: " << *it << std::endl;

    // std::prev
    std::cout << std::endl;
    std::cout << "it = std::prev(it, 1)" << std::endl;
    it = std::prev(it, 1);
    std::cout << "*it: " << *it << std::endl;
    std::cout << "it = std::prev(it, -1)" << std::endl;
    it = std::prev(it, -1);
    std::cout << "*it: " << *it << std::endl;


    // std::distance
    std::cout << std::endl;
    std::cout << "std::distance(it, vc.end()): " << std::distance(it, vc.end()) << std::endl;
    std::cout << "std::distance(it, vc.begin()): " << std::distance(it, vc.begin()) << std::endl;


    // std::advance
    std::cout << std::endl;
    std::cout << "*it: " << *it << std::endl;
    std::cout << "std::advance(it, 1)" << std::endl;
    std::advance(it, 1);
    std::cout << "*it: " << *it << std::endl;
    std::cout << "std::advance(it, -1)" << std::endl;
    std::advance(it, -1);
    std::cout << "*it: " << *it << std::endl;
  }
  

  std::cin.get();
  return 0;
}