#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

int main() {
  {
    // system_clock ����ϵͳ��Χʵʱʱ�ӵı���ʱ��
    // �뱾��ϵͳʱ���й�
    // ��Ψһ������ӳ��ʱ��㵽C-styleʱ���C++ʱ��

// �Ƿ�Ϊ�ȶ�ʱ��
cout << "system_clock::is_steady: " << std::boolalpha << system_clock::is_steady << endl;
{
  auto start = system_clock::now();

  int i = 0;
  while (i < 10000)
    i++;

  duration<double> time = system_clock::now() - start;
  cout << "time: " << time.count() << endl;
}
{
  auto t = system_clock::to_time_t(system_clock::now());
  cout << asctime(gmtime(&t)) << endl;
  cout << asctime(localtime(&t)) << endl;

  duration<double> time =
      system_clock::now() - system_clock::from_time_t(t);
  cout << "time: " << time.count() << endl;
}
  }
  {
    // steady_clock ���������ĵ���ʱ��
cout << "steady_clock::is_steady: " << std::boolalpha << steady_clock::is_steady << endl;
{
  auto start = steady_clock::now();

  int i = 0;
  while (i < 10000)
    i++;

  duration<double> time = steady_clock::now() - start;
  cout << "time: " << time.count() << endl;
}
  }
  {
    // high_resolution_clock
    // high_resolution_clock �ڲ�ͬ��׼��ʵ��֮��ʵ�ֲ�һ�£���Ӧ�ñ���ʹ������
    // ͨ����ֻ�� std::chrono::steady_clock �� std::chrono::system_clock �ı�������ʵ�����ĸ�ȡ���ڿ�����á�
cout << "high_resolution_clock::is_steady: " << std::boolalpha
     << high_resolution_clock::is_steady << endl;
{
  auto start = high_resolution_clock::now();

  int i = 0;
  while (i < 10000)
    i++;

  duration<double> time = high_resolution_clock::now() - start;
  cout << "time: " << time.count() << endl;
}
  }

  cin.get();

  return 0;
}