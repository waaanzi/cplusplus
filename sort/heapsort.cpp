#include <iostream>

using namespace std;

void print(int a[], int num) {
  for (int i = 0; i < num; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}

/*
初始时把要排序的n个数的序列看作是一棵顺序存储的二叉树（一维数组存储二叉树），调整它们的存储序，使之成为一个堆，
将堆顶元素输出，得到n 个元素中最小(或最大)的元素，这时堆的根节点的数最小（或者最大）。
然后对前面(n-1)个元素重新调整使之成为堆，输出堆顶元素，得到n 个元素中次小(或次大)的元素。
依此类推，直到只有两个节点的堆，并对它们作交换，最后得到有n个节点的有序序列。称这个过程为堆排序。
*/

// s节点不符合堆时的调整处理
void adjust_heap(int a[], int n, int s){
  int temp = a[s];
  int child = 2*s + 1; // s节点左子
  while(child < n){
    // s节点右子存在，且右子更大
    if ((child + 1 < n -1) && (a[child] < a[child + 1])){
      child +=1;
    }

    // 更大子节点移到s节点
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

// 建大堆
void build_heap(int a[], int n) {
  if (n < 2){
    return;
  }

  int last_f = 0; // 最后一个有子节点的父节点
  if (n % 2 == 0){
    last_f = (n - 1) /2; // n为偶数，最后一个节点为左子节点
  } else {
    last_f = (n - 3) /2; // n为奇数，最后一个节点为右子节点
  }

  for (int i = last_f; i >=0; --i){
    adjust_heap(a, n, last_f);
  }
}

void heap_sort(int a[], int n) {
  // 建最大堆
  build_heap(a, n);
  for (int i = n - 1; i >=0; --i) {
    // 堆顶节点(a[0])与i节点交换值
    int temp = a[i];
    a[i] = a[0];
    a[0] = temp;

    // 将前i个节点重新调整为最大堆
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