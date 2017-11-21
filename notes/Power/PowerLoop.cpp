#include<stdio.h> 

int main () {
	int n = 15;
	int x = 2;
	int result = 1;
	while (n != 0) {
		//ÈônÎªÆæÊı 
		if (n & 1) {
			result *= x;
		}
		x = x * x;
		n = n >> 1;
	}
	printf("%d\n", result);


	return 0;
}
