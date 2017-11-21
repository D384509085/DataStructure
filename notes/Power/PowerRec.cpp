#include<stdio.h>
 
int count = 0;

int power (int x, int n) {
	if (0 == n) {
		return (1);
	}
	if (1 == n) {
		return x;
	}
	count++;
	if (n & 1) {
		count++;
		return power(x*x, n>>1)*x;
	}
	else {
		return power(x*x, n>>1);
	}
}

int main () {
	int result; 
	int mcount;
	int eachCount;
	for (int n = 1; n < 100; n++) {
		mcount = count;
		power(1, n);
		eachCount = count - mcount;
		printf("��%d������Ҫ����%d�γ˷�����\n", n, eachCount);
	}
	return 0;
}
