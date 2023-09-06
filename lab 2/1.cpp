#include <iostream>

using namespace std;

void viewPointer(void *p) {
  char *p1 = reinterpret_cast<char *>(p);
  unsigned short *p2 = reinterpret_cast<unsigned short *>(p);
  double *p3 = reinterpret_cast<double *>(p);
  printf("%p %p %p %p\n", p, p1, p2, p3);
  printf("%p %p %p\n\n", p1 + 1, p2 + 1, p3 + 1);
}

int main()
{
    char c = 'f'; 
    char* pChar = &c;
    viewPointer(pChar);
    double a = 5;
    double* pDouble = &a;
    viewPointer(pDouble);
    int b = 5;
    int* pInt = &b;
    viewPointer(pInt);
    
    
    return 0;
}
