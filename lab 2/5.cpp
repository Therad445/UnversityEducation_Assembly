#include <iostream>

using namespace std;

void printDump(void *p, int N) {
    for (int i = 0; i < N; i++)
      printf("%X ", *(((unsigned char *) p) + i));

    printf("\n");
}

int main()
{
    setlocale(LC_ALL, "Ru");
    printf("task 7\n");
    int x = 5;
    printDump(&x, 10);
    char pChar[] = "gfhfhf";
    printDump(pChar, 10);
    double y = 2.28;
    printDump(&y, 10);
    printf("task 8\n");
    char c1[] = "jzyx\0";
    char c2[] = "ёяюэ\0";
    wchar_t wc1[] = L"jzyx\0";
    wchar_t wc2[] = L"ёяюэ\0";
    printf("char jzyx: ");
    printDump(c1, sizeof(c1));
    printf("char ёяюэ: ");
    printDump(c2, sizeof(c2));
    printf("wchar_t jzyx: ");
    printDump(wc1, sizeof(wc1));
    printf("wchar_t ёяюэ: ");
    printDump(wc2, sizeof(wc2));

    return 0;
}
