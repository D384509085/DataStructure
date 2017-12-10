#include<stdio.h>

int power(int x, int n) {
	printf("%d\n", x);
	if (0 == n)
		return 1;
	if (n%3 == 0) {
		return power(x*x*x, n/3);
	}
	if (n%3 == 1) {
		return power(x*x*x, n/3) * x;
	}
	if (n%3 == 2) {
		return power(x*x*x, n/3) * x * x;
	}
	return 0;
}
int main() {
	int n = 15;
	int x = 2;
	int res = power(x, n);
	printf("%d", res);
	return 0;
}
