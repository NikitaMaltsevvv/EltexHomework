#include <stdio.h>
#define N 100

char* findStr(char*, char*);

int main(void) {
  char str[N];
  for (int i = 0; i < N; i++) {
    if (scanf("%c", &str[i]) != 1) return -1;
    if (str[i] == '\n') {
      str[i] = '\0';
      break;
    }
  }

  char substr[N];
  for (int i = 0; i < N; i++) {
    if (scanf("%c", &substr[i]) != 1) return -1;
    if (substr[i] == '\n') {
      substr[i] = '\0';
      break;
    }
  }

  for (int i = 0; i < N; i++) {
    if (str[i] == '\0') break;
    printf("\nSymbol \'%c\' - address = %p", str[i], &str[i]);
  }

  char* pStr = findStr(str, substr);

  if (pStr)
    printf("\n\nAddress of substr in str - %p", pStr);
  else
    printf("\n\nAddress of substr in str - NULL");

  return 0;
}

char* findStr(char* str, char* substr) {
  char* result = NULL;
  for (int i = 0; (i < N) && (str[i] != '\0'); i++) {
    if (str[i] == *substr) {
      for (int j = 0; j < N; j++) {
        if (substr[j] == '\0')
          result = &str[i];
        else if ((str[i + j] != substr[j]) ||
                 (str[i + j] == '\0' && substr[j] != '\0'))
          break;
      }
      if (!result) break;
    }
  }
  return result;
}