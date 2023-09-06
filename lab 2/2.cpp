
#include <bitset>
#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <iomanip>


void printPointer(void *p){
    char *p1 = reinterpret_cast<char *>(p);
    unsigned short *p2 = reinterpret_cast<unsigned short *>(p);
    double *p3 = reinterpret_cast<double *>(p);
    printf("%p  %c  %d  %f\n",p,  *p1, *p2, *p3);
    printf("%s","###########################\n");
    printf("%c\n\n", *(p1 + 1));
    printf("%d\n\n",*(p2 + 1));
    printf("%f\n\n",*(p3 + 1));
    printf("%s","end ...\n");

}

int main()
{

    printf("task 2\n");
    long long z2_longlong = 0x8877665544332211;
    char z2_char[] = "abcdefgh0123456789";
    printPointer(&z2_longlong);
    printPointer(&z2_char);

    return 0;
}