#include"stdio.h"
int f(int x)
{
	int i,sum=0;
	for(i=1;i<x;i++)
	{
		if(x%i==0)
		sum+=i;
	}
	return sum;
}
int main()
{
	int x;
	for(x=0;x<10000;x++)
	{
		if(f(f(x))==x&&x<f(x))
		printf("(%d,%d)",x,f(x));
	}
}
