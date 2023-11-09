#include <stdio.h>

void print_binary(unsigned char num);

int main(void) {
  unsigned char num;
  if (scanf("%hhu", &num) != 1) return -1;

  print_binary(num);

  return 0;
}

void print_binary(unsigned char num) {
  for (int i = sizeof(unsigned char) * 8 - 1; i >= 0; i--)
    printf("%d", (num >> i) & 1);
}