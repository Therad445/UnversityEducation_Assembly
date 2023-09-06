#include <bitset>
#include <iostream>
#include <stdio.h>
#include <stdint.h>



void print16(void *p) {
  unsigned short p3 = *reinterpret_cast<unsigned short *>(p);
  short p6 = *reinterpret_cast<short *>(p);

  std::string b3 = std::bitset<sizeof(p3) * 8>(p3).to_string();
  std::string b6 = std::bitset<sizeof(p6) * 8>(p6).to_string();

  printf("%x %s %u\n", p3, b3.c_str(), p3);
  printf("%x %s %d\n\n", p6, b6.c_str(), p6);
}



int main() {
  char z1_char = 'a';
  double z1_double = 4.5;
  int z1_int = 9;


  printf("task 3\n");
  short max_signed = 32767;
  unsigned short max_unsigned = 65535;
  short min_signed = -32768;
  unsigned short min_unsigned = 0;
  short x = 0xAA11BB22;
  short y = 7;
  short z = -7;
  print16(&max_signed);
  print16(&max_unsigned);
  print16(&min_signed);
  print16(&min_unsigned);
  print16(&y);
  print16(&z);


}