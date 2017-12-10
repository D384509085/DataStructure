#include<stdio.h>
//**************************************
static int max3 (int x, int y, int z);
static int cro_mid_seq (int *a, int n);
static int max_seq_sum (int *a, int n);

//**************************************
static int max3 (int x, int y, int z)
{
	if (x > y)
	{
		if (x > z)
		{
			return x;
		}
	}
	else
	{
		if (y > z)
		{
			return y;
		}
	}
	return z;
}

static int cro_mid_seq (int *a, int n)
{
	int m1 = 0, m2 = 0;
	int tmp = 0;
	for (int i = n/2; i < n; i ++)
	{
		tmp += a[i];
		if (tmp > m2)
		{
			m2 = tmp;
		}
	}
	tmp = 0;
	for (int i = n/2 - 1; i >= 0; i --)
	{
		tmp += a[i];
		if (tmp > m1)
		{
			m1 = tmp;
		}
	}
	return m1 + m2;
}
static int max_seq_sum (int *a, int n)
{
	if (n == 1)
	{
		return a[0];
	}
	int left_max = max_seq_sum (a, n/2);
	int right_max = max_seq_sum (&(a[n/2]), n - n/2);
	int cross_max = cro_mid_seq (a, n);
	int max = max3 (left_max, right_max, cross_max);
	return max;
}

int main() 
{
    int a[1000];
    int n;
    int pri;
    printf ("数组长度\n");
    scanf ("%d", &n);
    printf ("输入数组\n");
    for (int i=0; i<n; i++)
    {
        scanf ("%d", &a[i]);
    }   
    int sum = max_seq_sum(a, n);
    printf ("最大子序列和%d", sum);
    return 0;
}
