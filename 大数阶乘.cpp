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
	int t=0,len=1,tem;//tΪ��λ��lenΪλ�� 
	for(i=2;i<=n;i++) 
	{
		t=0;
		for(j=0;j<len;j++)
		{
			tem=a[j]*i;
			a[j]=(tem+t)%10;//ÿһλ�������
			t=(tem+t)/10;
			if(t!=0&&j==len-1)
			len++;
		}
	}
	for(i=len-1;i>=0;i--) 
	{
		printf("%d ",a[i]);//������ 
	}
}
int main()
{
	int n;
	scanf("%d",&n);//���뼸�Ľ׳�
	print_factorial(n); 
}
