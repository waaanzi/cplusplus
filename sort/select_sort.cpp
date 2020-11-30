#include <iostream>

using namespace std;

void print(int a[], int num, int index) {
  cout << " index = " << index << " : ";
  for (int i = 0; i < num; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}

/*
简单选择排序（Simple Selection Sort）
在要排序的一组数中，选出最小（或者最大）的一个数与第1个位置的数交换；
然后在剩下的数当中再找最小（或者最大）的与第2个位置的数交换，
依次类推，直到第n-1个元素（倒数第二个数）和第n个元素（最后一个数）比较为止
*/

// 比a[i]小的最小元素下标
int select_min(int a[], int n, int i){
  int j = i;
  for (int k = i + 1; k < n; ++k) {
    if (a[j] > a[k]) {
      j = k;
    }
  }
  return j;
}

void select_sort(int a[], int n) {
  for (int i = 0; i < n; ++i) {
    int min = select_min(a, n, i);
    if (i != min) {
      int temp = a[i];
      a[i] = a[min];
      a[min] = temp;
    }

    print(a, n, i + 1);
  }
}


int main() {
  int a[] = {7, 6, 5, 4, 3, 2, 1};
  select_sort(a, sizeof(a) / sizeof(a[0]));
  cin.get();
  return 0;
}