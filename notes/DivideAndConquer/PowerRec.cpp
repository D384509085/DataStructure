#include<stdio.h>
#include<time.h>

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
	for (int n = 1; n < 10000; n++) {
		float start = clock();
		mcount = count;
		for (int j = 0; j <1000; j++) {
			power(1, n);
		}
		eachCount = count - mcount;
		float end = clock();
		printf("算%d次幂需要进行%d次乘法运算,需要时间:%f\n", n, eachCount, end-start);
	}
	
	return 0;
}










//
