#include<stdio.h>

int power(int x, int n) {
	if (0 == n) {
		return 1;
	}
	//为了避免造成两个递归调用栈，用tmp记录一次递归返回值，再进行递归调用。 
	int tmp = power(x, n>>1);
	if (n & 1) {
		return tmp * tmp * x;
	}
	return tmp * tmp;
}
int main () {
	int res;
	int n = 15;
	res = power(2, n);
	printf("%d", res);
	return 0;
}
