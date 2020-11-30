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
ֱ�Ӳ�������
�Ƚ����еĵ�1����¼������һ������������У�
Ȼ��ӵ�2����¼������в��룬ֱ��������������Ϊֹ
*/
void insert_sort(int a[], int n){
  if ( n < 2) {
    return;
  }
  for(int i = 1; i < n; ++i){
    if (a[i] < a[i-1]){
      int j = i - 1; // �������н�βԪ���±�
      int val = a[i]; // ������Ԫ��ֵ
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