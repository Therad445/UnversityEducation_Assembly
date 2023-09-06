#include <iostream>
#include <string.h>

using namespace std;

char *inputstr1() {

  int length = 1024;
  char buf[length], x;
  int len = 0;

  for (;;) {
    if (len >= length) {
      cout << "Buffer overflow" << endl;
      break;
    }

    scanf("%c", &x);
    if (x == '\n' || x == ' ') {
      buf[len] = '\0';
      len += 1;
      break;
    }

    buf[len] = x;
    len += 1;
  }
  char *newstr = (char *)malloc(len);
  strcpy(newstr, buf);

  //возвращаем указатель на строку
  return newstr;
}

char *inputstr() {

  int length = 1024;
  char buf[length], x;
  int len = 0;

  for (;;) {
    if (len >= length) {
      cout << "Buffer overflow" << endl;
      break;
    }

    scanf("%c", &x);
    if (x == '\n') {
      buf[len] = '\0';
      len += 1;
      break;
    }

    buf[len] = x;
    len += 1;
  }

  char *newstr = (char *)malloc(len);
  strcpy(newstr, buf);

  //возвращаем указатель на строку
  return newstr;
}

int main() {

  char *s1 = inputstr1();
  char *s2 = inputstr();
  char *s3 = inputstr();

  cout << "***" << s1 << "***" << endl;
  cout << "***" << s2 << "***" << endl;
  cout << "***" << s3 << "***" << endl;

  delete[] s1;
  delete[] s2;
  delete[] s3;
}