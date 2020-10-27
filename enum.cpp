#include <iostream>

// 无作用域枚举
// 枚举项（enumerator）值是不确定的整型类型（称为该枚举的底层类型（underlying type））
enum class Type : uint8_t{
  kText = 1,
};

enum class Msg {
  kText = 2,
};

int main() {

  int type = Type::kText;
  {
    int type11 = (int)Type::kText;
    int type12 = static_cast<int>(Type::kText);
  }

  std::cin.get();

  return 0;
}