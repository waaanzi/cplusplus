#include <iostream>

using namespace std;

void print (int a[], int num, int index) {
  cout << index << " : ";
  for (int i= 0; i < num; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}

/*
直接插入排序
先将序列的第1个记录看成是一个有序的子序列，
然后从第2个记录逐个进行插入，直至整个序列有序为止
*/
void insert_sort(int a[], int n){
  if ( n < 2) {
    return;
  }
  for(int i = 1; i < n; ++i){
    if (a[i] < a[i-1]){
      int j = i - 1; // 有序序列结尾元素下标
      int val = a[i]; // 待插入元素值
      while((j >= 0) && (a[j] > val)){
        a[j + 1] = a[j];
        --j;
      }
      a[j + 1] = val;
    }

    print(a, n, i);
  }
}

int main() {
  int a[] = {7,6,5,4,3,2,1};
  insert_sort(a, sizeof(a)/sizeof(a[0]));
  cin.get();
  return 0;
}