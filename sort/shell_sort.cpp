#include <iostream>

using namespace std;

void print(int a[], int num, int dk, int index) {
  cout << "dk = " << dk << " index = " <<  index << " : ";
  for (int i = 0; i < num; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}

/*ϣ�������ֽ���С��������
�Ƚ�����������ļ�¼���зָ��Ϊ���������зֱ����ֱ�Ӳ�������
�����������еļ�¼����������ʱ���ٶ�ȫ���¼��������ֱ�Ӳ�������
*/
void shell_insert_sort(int a[], int n, int dk) {
  if (n < 2) {
    return;
  }

  int index = 1;
  for (int i = dk; i < n; ++i) {
    if (a[i] < a[i - dk]) {
      int j = i - dk;   // �������н�βԪ���±�
      int val = a[i];  // ������Ԫ��ֵ
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