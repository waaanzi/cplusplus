#include <fstream>

int main()
{
    int error = 0;
    std::ofstream file("‪C:\\Users\\zhangli01\\Documents\\1.txt", std::ofstream::out);
    if (file)
    {
        file << "aaa";
        file.close();
    }
    system("pause");

    return 0;
}