#include <stdio.h>

int main(void) {
  unsigned char num, count = 0;
  if (scanf("%hhu", &num) != 1) return -1;

  for (int i = 0; i < 8; i++, num <<= 1) (num & 0x80) ? count++ : count;
  printf("Count of one = %hhu", count);

  return 0;
}