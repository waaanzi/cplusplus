#include <iostream>

using namespace std;

void print(int a[], int num) {
  for (int i = 0; i < num; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}

/*
��ʼʱ��Ҫ�����n���������п�����һ��˳��洢�Ķ�������һά����洢�����������������ǵĴ洢��ʹ֮��Ϊһ���ѣ�
���Ѷ�Ԫ��������õ�n ��Ԫ������С(�����)��Ԫ�أ���ʱ�ѵĸ��ڵ������С��������󣩡�
Ȼ���ǰ��(n-1)��Ԫ�����µ���ʹ֮��Ϊ�ѣ�����Ѷ�Ԫ�أ��õ�n ��Ԫ���д�С(��δ�)��Ԫ�ء�
�������ƣ�ֱ��ֻ�������ڵ�Ķѣ��������������������õ���n���ڵ���������С����������Ϊ������
*/

// s�ڵ㲻���϶�ʱ�ĵ�������
void adjust_heap(int a[], int n, int s){
  int temp = a[s];
  int child = 2*s + 1; // s�ڵ�����
  while(child < n){
    // s�ڵ����Ӵ��ڣ������Ӹ���
    if ((child + 1 < n -1) && (a[child] < a[child + 1])){
      child +=1;
    }

    // �����ӽڵ��Ƶ�s�ڵ�
    if (a[s] < a[child]) {
      a[s] = a[child];
      s = child;
      child = 2 * s + 1;
    }else {
      break;
    }
    a[s] = temp;
  }
}

// �����
void build_heap(int a[], int n) {
  if (n < 2){
    return;
  }

  int last_f = 0; // ���һ�����ӽڵ�ĸ��ڵ�
  if (n % 2 == 0){
    last_f = (n - 1) /2; // nΪż�������һ���ڵ�Ϊ���ӽڵ�
  } else {
    last_f = (n - 3) /2; // nΪ���������һ���ڵ�Ϊ���ӽڵ�
  }

  for (int i = last_f; i >=0; --i){
    adjust_heap(a, n, last_f);
  }
}

void heap_sort(int a[], int n) {
  // ������
  build_heap(a, n);
  for (int i = n - 1; i >=0; --i) {
    // �Ѷ��ڵ�(a[0])��i�ڵ㽻��ֵ
    int temp = a[i];
    a[i] = a[0];
    a[0] = temp;

    // ��ǰi���ڵ����µ���Ϊ����
    adjust_heap(a, i, 0);

    print(a, n);
  }
}

int main() {
  int a[] = {7, 6, 5, 4, 3, 2, 1};
  int n = sizeof(a) / sizeof(a[0]);
  print(a, n);
  heap_sort(a, n);
  print(a, n);
  cin.get();
  return 0;
}