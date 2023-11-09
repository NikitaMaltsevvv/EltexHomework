#include <stdio.h>
#define N 3

int main(void) {
  int arr[N][N];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if ((i + j) < 2)
        arr[i][j] = 0;
      else
        arr[i][j] = 1;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d", arr[i][j]);
      if (j != N - 1)
        putc(' ', stdout);
    }
    putc('\n', stdout);
  }

  return 0;
}