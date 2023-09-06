#include <iomanip>
#include <iostream>
#include <string.h>
#include <errno.h>

using namespace std;

int main() {
  int N = 5, res = 0, i = 0;
  unsigned int *Ml = new unsigned int[N];
  char *Mlc = new char[N + 1]{}, *buf = new char[N + 1]{};

  res = scanf("%[^A-z\n]", Mlc);

  if (res != 0) {
    buf = strtok(Mlc, " ");
    while (buf != NULL && i < N) {
      Ml[i] = atoi(buf);
      printf("%d ", Ml[i]);
      buf = strtok(NULL, " ");
      i++;
    }
    printf("\nУспешно считаны %d элементов\n", i);
  }
  else {
    printf("\nНекорректный ввод\n");
  }
  delete[] Ml;
  delete[] Mlc;
  delete[] buf;
  return 0;
}