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
��ѡ������Simple Selection Sort��
��Ҫ�����һ�����У�ѡ����С��������󣩵�һ�������1��λ�õ���������
Ȼ����ʣ�µ�������������С��������󣩵����2��λ�õ���������
�������ƣ�ֱ����n-1��Ԫ�أ������ڶ��������͵�n��Ԫ�أ����һ�������Ƚ�Ϊֹ
*/

// ��a[i]С����СԪ���±�
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