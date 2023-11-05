#include <stdio.h>

void print_binary(int);

int main(void) {
  int num;
  char bit;

  printf("Enter number: ");
  if (scanf("%d", &num) != 1) return -1;

  print_binary(num);

  printf("\nEnter value of bit: ");
  if (scanf("%hhi", &bit) != 1) return -1;

  if (bit)
    num |= 0x4;
  else
    num &= 0xFB;

  printf("Changed number = %d\n", num);
  print_binary(num);

  return 0;
}

void print_binary(int num) {
  for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
    printf("%d", (num >> i) & 1);
  }
}