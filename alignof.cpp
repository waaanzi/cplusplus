
#include <iostream>

using namespace std;

struct s1
{
	char s;
	int i;
};

struct s2
{
	int i;
	double d;
};

struct s3
{
	char s;
	double d;
	int i;
};


struct s11
{
	alignas(16) char s;
	int i;
};

struct s12
{
	alignas(16) char s;
	int i;
};


int main(int argc, char* argv[])
{
	// sizeof
	cout << "-------------------sizeof---------------------" << endl;
	cout << "-------basic type" << endl;
	cout << "sizeof(char)	" << sizeof(char) << endl;
	cout << "sizeof(int)	" << sizeof(int) << endl;
	cout << "sizeof(double)	" << sizeof(double) << endl;

	cout << endl;
	cout << "-------struct" << endl;
	cout << "sizeof(s1)	" << sizeof(s1) << endl;
	cout << "sizeof(s2)	" << sizeof(s2) << endl;
	cout << "sizeof(s3)	" << sizeof(s3) << endl;

	cout << endl;
	cout << endl;

	// alignof
	cout << "-------------------alignof---------------------" << endl;
	// 基本对齐值
	cout << "alignof(std::max_align_t)	" << alignof(std::max_align_t) << endl;
	cout << endl;
	cout << "-------basic type" << endl;
	cout << "alignof(char)		" << alignof(char) << endl;
	cout << "alignof(int)		" << alignof(int) << endl;
	cout << "alignof(double)		" << alignof(double) << endl;

	cout << endl;
	cout << "-------struct" << endl;
	cout << "alignof(s1)		" << alignof(s1) << endl;
	cout << "alignof(s2)		" << alignof(s2) << endl;
	cout << "alignof(s3)		" << alignof(s3) << endl;

	cout << endl;
	cout << endl;

	// alignas
	cout << "-------------------alignas---------------------" << endl;
	cout << "alignof(s1)		" << alignof(s1) << endl;
	cout << "alignof(s11)		" << alignof(s11) << endl;
	cout << "alignof(s12)		" << alignof(s12) << endl;
	cout << "sizeof(s1)	" << sizeof(s1) << endl;
	cout << "sizeof(s11)	" << sizeof(s11) << endl;
	cout << "sizeof(s12)	" << sizeof(s12) << endl;

	cout << endl;
	cout << endl;

	// 函数
	// std::alignment_of
	// std::aligned_storage
	// std::max_align_t
	// std::align
	cout << "-------------------alignas---------------------" << endl;

	system("pause");
	return 0;
}