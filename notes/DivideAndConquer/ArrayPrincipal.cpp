#include<stdio.h>

int principal (int *a, int start, int end)
{
	if (1 == end - start) 
	{
	    return a[start];	
	}
	int mid = (start + end) / 2;
	int left = principal(a, start, mid);
	int right = principal(a, mid, end);
	int countLeft = 0;
	int countRight = 0;
	for (int i = start; i < end; i++) 
	{
		if (a[i] == left)
			countLeft++;
		if (a[i] == right)
			countRight++;
	}
	if (countLeft > (end - start) / 2 && left != -1)
		return left;
	else if (countRight > (end - start) / 2 && right != -1)
		return right;
	else 
		return -1;
	
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
    int arrayPrincipal = principal(a, 0, n);
    printf ("数组主元是%d", arrayPrincipal);
    return 0;
}
