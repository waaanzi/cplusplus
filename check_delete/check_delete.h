#include <iostream>
// #include "A.h"
template<typename T>
inline void check_delete(T* t) {
  typedef char type_must_be_complete[sizeof(T) ? 1 : -1];
  (void) sizeof(type_must_be_complete);
  ::delete t;
};