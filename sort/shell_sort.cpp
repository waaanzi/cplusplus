#include <iostream>

using namespace std;

void print(int a[], int num, int dk, int index) {
  cout << "dk = " << dk << " index = " <<  index << " : ";
  for (int i = 0; i < num; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}

/*希尔排序又叫缩小增量排序
先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，
待整个序列中的记录“基本有序”时，再对全体记录进行依次直接插入排序。
*/
void shell_insert_sort(int a[], int n, int dk) {
  if (n < 2) {
    return;
  }

  int index = 1;
  for (int i = dk; i < n; ++i) {
    if (a[i] < a[i - dk]) {
      int j = i - dk;   // 有序序列结尾元素下标
      int val = a[i];  // 待插入元素值
      while ((j >= 0) && (a[j] > val)) {
        a[j + dk] = a[j];
        j -= dk;
      }
      a[j + dk] = val;
    }

    print(a, n, dk, index);
    ++index;
  }
}

void shell_sort(int a[], int n){
  int dk = n /2;
  while(dk >=1){
    shell_insert_sort(a, n, dk);
    dk = dk /2;
  }  
}

int main() {
  int a[] = {7, 6, 5, 4, 3, 2, 1};
  shell_sort(a, sizeof(a) / sizeof(a[0]));
  cin.get();
  return 0;
}