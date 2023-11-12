#include <stdio.h>
#define N 5

int main(void) {
  int arr[N];

  for (int i = 0; i < N; i++) arr[i] = i + 1;

  for (int i = 0; i < N - 1 - i; i++) {
    int temp = arr[i];
    arr[i] = arr[N - 1 - i];
    arr[N - 1 - i] = temp;
  }

  for (int i = 0; i < N; i++) {
    printf("%d", arr[i]);
    if (i != N - 1) putc(' ', stdout);
  }

  return 0;
}
