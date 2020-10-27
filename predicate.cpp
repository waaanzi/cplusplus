#include <iostream>
#include <vector>
#include <algorithm> // find_if sort

int main() 
{
  std::vector<int> vc {1,2,3,4,5};

  auto it = std::find_if(vc.begin(), vc.end(), [](int i) {return i == 3;});
  std::sort(vc.begin(), vc.end(), [](int a, int b) {return a < b;});

  return 0;
}