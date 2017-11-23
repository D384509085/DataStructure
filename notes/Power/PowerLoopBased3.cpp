#include<stdio.h>

int main () {
	int n = 15;
	int x = 2;
	int res = 1;
	while (n != 0) {
		switch (n % 3) {
			case 2: res *= x;
			case 1: res *= x;
		}
		n = n / 3;
		x = x * x * x;
	}
	printf("%d", res);
	return 0;
}
