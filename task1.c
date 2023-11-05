#include <stdio.h>

int main(void)
{
	unsigned char num;
	if (scanf("%hhu", &num) != 1) return -1;

	for (int i = 0; i < 8; i++, num <<= 1) printf("%c", (num & 0x80) ? '1' : '0');

	return 0;
}