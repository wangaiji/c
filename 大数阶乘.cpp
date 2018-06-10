#include"stdio.h" 
#include"string.h"
void print_factorial(int n)
{
	if(n<0)
	{
		printf("error\n");
		return;
	}
	else if(n==0)
	{
		printf("%d\n",1);
		return;
	}
	int a[100000]={1},i,j;
	int t=0,len=1,tem;//t为进位，len为位数 
	for(i=2;i<=n;i++) 
	{
		t=0;
		for(j=0;j<len;j++)
		{
			tem=a[j]*i;
			a[j]=(tem+t)%10;//每一位分离出来
			t=(tem+t)/10;
			if(t!=0&&j==len-1)
			len++;
		}
	}
	for(i=len-1;i>=0;i--) 
	{
		printf("%d ",a[i]);//输出结果 
	}
}
int main()
{
	int n;
	scanf("%d",&n);//输入几的阶乘
	print_factorial(n); 
}
