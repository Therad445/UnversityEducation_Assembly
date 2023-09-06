#define _USE_MATH_DEFINES
#include <cmath>
#include <bitset>
#include <climits>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

using namespace std;

void print16(void *p) {
  unsigned short *p1 = reinterpret_cast<unsigned short *>(p);
  signed short *p2 = reinterpret_cast<signed short *>(p);

  cout << hex << *p1 << setw(20) << bitset<16>(*p1) << dec << setw(20) << *p1;
  cout << hex << setw(20) << *p2 << setw(20) << bitset<16>(*p2) << dec << setw(20) << *p2 << endl;
}

void print32(void *p) {
  unsigned int *p1 = reinterpret_cast<unsigned int *>(p);
  signed int *p2 = reinterpret_cast<signed int *>(p);
  float *p3 = reinterpret_cast<float *>(p);
  int view_size = 34;

  cout << hex << *p1 << setw(view_size) << bitset<16>(*p1) << dec << setw(view_size) << *p1;
  cout << hex << setw(view_size) << *p2 << setw(view_size) << bitset<16>(*p2) << dec << setw(view_size) << *p2;
  cout << fixed << setw(view_size) << *p3 << setw(view_size) << scientific << setw(view_size)
        << *p3 << endl;
}

void signexpand(short p) {
  signed int p1 = static_cast<signed int>(p);

  printf("%d\t", p1);
  cout << bitset<32>(p1) << endl;
}

void unsignexpand(short p) {
  unsigned int p1 = static_cast<unsigned int>(p);

  printf("%d\t", p1);
  cout << bitset<32>(p1) << endl;
}

void task3(short m, short n) {
  signed short r1 = m * 2;
  unsigned short r2 = m * 2;
  signed short r3 = n * 2;
  unsigned short r4 = n * 2;

  signed short r5 = m / 2;
  unsigned short r6 = m / 2;
  signed short r7 = n / 2;
  unsigned short r8 = n / 2;

  unsigned short r9 = m % 16;
  unsigned short r10 = n % 16;

  unsigned short r11 = m - m % 16;
  unsigned short r12 = n - n % 16;
  print16(&m);
  print16(&n);

  printf("------dot-------\n");
  print16(&r1);
  print16(&r2);
  print16(&r3);
  print16(&r4);
  printf("------frac------\n");
  print16(&r5);
  print16(&r6);
  print16(&r7);
  print16(&r8);
  printf("------ocr-------\n");
  print16(&r9);
  print16(&r10);
  print16(&r11);
  print16(&r12);
}

void task4(void *p) {
  signed short *p1 = reinterpret_cast<signed short int *>(p);
  unsigned short *p2 = reinterpret_cast<unsigned short int *>(p);

  signed short r1 = *p1 << 1;
  signed short r2 = *p2 << 1;
  signed short r3 = *p1 >> 1;
  signed short r4 = *p2 >> 1;
  signed short r5 = *p2 & 15;
  signed short r6 = *p2 & -16;
  
  print16(&r1);
  print16(&r2);
  print16(&r3);
  print16(&r4);
  print16(&r5);
  print16(&r6);
}

void task5(void *p, int D) {
  unsigned int value = *reinterpret_cast<unsigned int *>(p);
  unsigned int buf = 0;
  while (buf < value) {
    buf += D;
  }
  unsigned short int left = buf - D;
  unsigned short int right = buf;
  print16(&left);
  print16(&right);
}

void task6(void *p) {
  int *p1 = reinterpret_cast<int *>(p);

    cout << *p1 << endl;
  (*p1)++;
  printf("Increment %d\n", (*p1) - 1);
  print32(p1);

  (*p1)--;
  (*p1)--;
  printf("Decrement %d\n", (*p1) + 1);
  print32(p1);
}

void task7(void *p) {
  int *p1 = reinterpret_cast<int *>(p);
  int sr = 0x7fffffff;
  int res = (*p1) & sr;

  float *p2 = reinterpret_cast<float *>(&res);
  printf("%f\n", *p2);
}

void task8(int N) {
  float result = 0.0;

  printf("Forward: \n");
  for (int i = 1; i <= N; i++) {
    result += 1.0 / i;
  }

  printf("Result = %f\n", result);
  result = 0.0;

  printf("Reverse: \n");
  for (int i = N; i > 0; i--) {
    result += 1.0 / i;
  }

  printf("Result = %f\n", result);
}

void task9(float eps) {
  int N = ((eps + 1 + sqrt((eps + 1)*(eps + 1) + 4*eps))/(2*eps)) + 1;
  float result = 0;
  for (int i = N - 1; i > 2; i--) {
    result += pow(-1, i) * ((i + 1.0) / (i * i - i));
  }

  printf("%f\n", result);
}

float task10(float eps, int s) {

  int N_eps = pow(eps, -s);
  float result = 0.0;
  cout << "N_eps = " << N_eps << endl;
  for (int i = N_eps; i > 0; i--) {
    result += 1.0 / pow(i, s);
  }
  return result;
}

int main() {

  signed short m = 155;
  unsigned short n = -299;

//   printf("task 1\n");
  
//   short max_signed = 32767;
//   unsigned short max_unsigned = 65535;
//   short min_signed = -32768;
//   unsigned short min_unsigned = 0;
//   short x16 = 0xAA11BB22;
//   short y16 = 7;
//   short z16 = -7;
//   print16(&max_signed);
//   print16(&max_unsigned);
//   print16(&min_signed);
//   print16(&min_unsigned);
//   print16(&x16);
//   print16(&y16);
//   print16(&z16);

//   long max_signed32 = 2147483647;
//   unsigned long max_unsigned32 = 4294967295;
//   long min_signed32 = -2147483648;
//   unsigned long min_unsigned32 = 0;
//   long x32 = 0xAA11BB22;
//   long y32 = 7;
//   long z32 = -7;
//   print32(&max_signed32);
//   print32(&max_unsigned32);
//   print32(&min_signed32);
//   print32(&min_unsigned32);
//   print32(&x32);
//   print32(&y32);
//   print32(&z32);

  printf("\ntask 2\n");

  print16(&m);
  signexpand(m);

  print16(&n);
  unsignexpand(n);

  printf("\ntask 3\n");
  
  task3(m, n);

  printf("\ntask 4\n");
  
  print16(&m);
  print16(&n);
  task4(&m);
  task4(&n);

  printf("\ntask 5\n");
  
  task5(&m, 32);

  printf("\ntask 6\n");

  float a = 0;
  float b = 1;
  float c = 12345689;
  float d = 123456891;
  unsigned int t1 = 4294967295;
  signed int t2 = -2147483648;
  signed int t3 = 2147483647;
  printf("-a, b, c, d---\n");
  task6(&a);
  task6(&b);
  task6(&c);
  task6(&d);
  printf("------m, n----\n");
  task6(&m);
  task6(&n);
  printf("------max-----\n");
  task6(&t1);
  task6(&t2);
  task6(&t3);

  printf("\ntask 7\n");

  float number = -453.235;
  void *pn = &number;
  task7(pn);

  printf("\ntask 8\n");

//   printf("\n---N = 10^3---\n");
//   task8(1000);
//   printf("\n---N = 10^6---\n");
//   task8(1000000);
//   printf("\n---N = 10^9---\n");
//   task8(1000000000);

  printf("\ntask 9\n");
  task9(0.0001);

  printf("\ntask 10\n");

  printf("%f ~= %f", task10(0.001, 2), pow(M_PI, 2)/6);

  return 0;
}