#include <stdio.h>
#define N 10

int main(void) {
  int arr[N];

  for (int i = 0; i < N; i++) arr[i] = i + 1;

  for (int *parr = arr; parr - arr < N; parr++) printf("%d ", *parr);

  return 0;
}