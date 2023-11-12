#include <stdio.h>

void print_binary(int);

int main(void) {
  int number, temp;
  unsigned char byte;

  if ((scanf("%d", &number) != 1) || (scanf("%d", &temp) != 1) || (temp > 255))
    return -1;

  byte = (char)temp;
  char *pbyte = &number;

  print_binary(number);

  *(pbyte + 2) = byte;

  putc('\n', stdout);
  print_binary(number);

  return 0;
}

void print_binary(int num) {
  for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
    printf("%d", (num >> i) & 1);
    if ((i % 8 == 0) && (i != 31)) putc(' ', stdout);
  }
}