#include <stdio.h>

void print_binary(char);

int main(void) {
  char num;
  if ((scanf("%hhi", &num) != 1) || num >= 0) return -1;

  print_binary(num);

  return 0;
}

void print_binary(char num) {
  for (int i = sizeof(char) * 8 - 1; i >= 0; i--) printf("%d", (num >> i) & 1);
}