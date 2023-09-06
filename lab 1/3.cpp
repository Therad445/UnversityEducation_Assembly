#include <iostream>

using namespace std;

int main()
{
    printf("%zu\n", sizeof(void*));
    printf("%zu\n", sizeof(char));
    printf("%zu\n", sizeof(signed char));
    printf("%zu\n", sizeof(unsigned char));
    printf("%zu\n", sizeof(char*));
    printf("%zu\n", sizeof(wchar_t));
    printf("%zu\n", sizeof(wchar_t*));
    printf("%zu\n", sizeof(short));
    printf("%zu\n", sizeof(unsigned short));
    printf("%zu\n", sizeof(short*));
    printf("%zu\n", sizeof(int));
    printf("%zu\n", sizeof(unsigned int));
    printf("%zu\n", sizeof(int*));
    printf("%zu\n", sizeof(long));
    printf("%zu\n", sizeof(unsigned long));
    printf("%zu\n", sizeof(long long));
    printf("%zu\n", sizeof(unsigned long long));
    printf("%zu\n", sizeof(float));
    printf("%zu\n", sizeof(double));
    printf("%zu\n", sizeof(long double));
    printf("%zu\n", sizeof(double*));
    printf("%zu\n", sizeof(size_t));
    printf("%zu\n", sizeof(ptrdiff_t));
    return 0;
}
