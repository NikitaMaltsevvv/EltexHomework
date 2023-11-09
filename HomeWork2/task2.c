#include <stdio.h>
#define N 5

int main(void) {
  int arr[N];

  for (int i = 0; i < N; i++)
    arr[i] = i + 1;

  for (int i = N - 1; i >= 0; i--) {
    printf("%d", arr[i]);
    if (i != 0)
      putc(' ', stdout);
  }

  return 0;
}
