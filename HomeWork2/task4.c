#include <stdio.h>
#define N 5

void changeState(int *vecR, int *vecC);

int main(void) {
  int arr[N][N] = {0};

  int row = 0, col = 0, vecR = 0, vecC = 1;
  for (int i = 1; i <= N * N; i++) {
    arr[row][col] = i;

    if (((row + vecR > N - 1) || (row + vecR < 0)) ||
        ((col + vecC > N - 1) || (col + vecC < 0)) ||
        (arr[row + vecR][col + vecC] != 0))
      changeState(&vecR, &vecC);

    row += vecR;
    col += vecC;
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

void changeState(int *vecR, int *vecC) {
  if ((*vecC == 1) && (*vecR == 0)) {
    *vecC = 0;
    *vecR = 1;
  } else if ((*vecC == 0) && (*vecR == 1)) {
    *vecC = -1;
    *vecR = 0;
  } else if ((*vecC == -1) && (*vecR == 0)) {
    *vecC = 0;
    *vecR = -1;
  } else if ((*vecC == 0) && (*vecR == -1)) {
    *vecC = 1;
    *vecR = 0;
  }
}