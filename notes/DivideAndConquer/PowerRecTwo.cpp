#include<stdio.h>

int power(int x, int n) {
	if (0 == n) {
		return 1;
	}
	//Ϊ�˱�����������ݹ����ջ����tmp��¼һ�εݹ鷵��ֵ���ٽ��еݹ���á� 
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
