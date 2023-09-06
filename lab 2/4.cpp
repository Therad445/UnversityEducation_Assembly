#include <bitset>
#include <iostream>
#include <stdio.h>
#include <stdint.h>


void print32(void *p) {
  unsigned long p3 = *reinterpret_cast<unsigned long *>(p);
  long p6 = *reinterpret_cast<long *>(p);

  std::string b3 = std::bitset<sizeof(p3) * 8>(p3).to_string();
  std::string b6 = std::bitset<sizeof(p6) * 8>(p6).to_string();

  printf("%x %s %u\n", p3, b3.c_str(), p3);
  printf("%x %s %d\n", p6, b6.c_str(), p6);
  printf("%.6f %e\n", p3, p3);
  printf("%.6f %e\n\n", p6, p6);
}

void print64(void *p) {
  unsigned long long p3 = *reinterpret_cast<unsigned long long *>(p);
  long long p6 = *reinterpret_cast<long long *>(p);

  std::string b3 = std::bitset<sizeof(p3) * 8>(p3).to_string();
  std::string b6 = std::bitset<sizeof(p6) * 8>(p6).to_string();

  printf("%x %s %u\n", p3, b3.c_str(), p3);
  printf("%x %s %d\n", p6, b6.c_str(), p6);
  printf("%.6f %e\n", p3, p3);
  printf("%.6f %e\n\n", p6, p6);
}


int main() {
  char z1_char = 'a';
  double z1_double = 4.5;
  int z1_int = 9;

  printf("task 4\n");
  printf("print32\n");
  long max_signed32 = 2147483647;
  unsigned long max_unsigned32 = 4294967295;
  long min_signed32 = -2147483648;
  unsigned long min_unsigned32 = 0;
  long x32 = 0xAA11BB22;
  long y32 = 7;
  long z32 = -7;
  print32(&max_signed32);
  print32(&max_unsigned32);
  print32(&min_signed32);
  print32(&min_unsigned32);
  print32(&x32);
  print32(&y32);
  print32(&z32);

  // https://learn.microsoft.com/en-us/cpp/c-language/cpp-integer-limits?view=msvc-170
  printf("print64\n");
  long long max_signed64 = 9223372036854775807;
  unsigned long long max_unsigned64 = 0xffffffffffffffff;
  long long min_signed64 = -9223372036854775808;
  unsigned long long min_unsigned64 = 0;
  long long x64 = 0xAA11BB22;
  long long y64 = 7;
  long long z64 = -7;
  print64(&max_signed64);
  print64(&max_unsigned64);
  print64(&min_signed64);
  print64(&min_unsigned64);
  print64(&x64);
  print64(&y64);
  print64(&z64);


}