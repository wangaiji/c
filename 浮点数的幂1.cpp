#include"stdio.h" 
#include"string.h"
int len=1; 
void multiply(int a[],int n,int num)
{
	int i,j,t1,tem;//t1Ϊ��λ
	for(i=1;i<=n;i++) 
	{
		t1=0;
		for(j=0;j<len;j++) 
		{
			tem=a[j]*num;
			a[j]=(tem+t1)%10;
			t1=(tem+t1)/10;
			if(t1!=0&&j==len-1)
			len++;
		}
	}//���Ŵ�� 
}
int main()
{
	char R[10];
	int n,num,t,i,j,l;//tΪС�����λ�� 
	while(scanf("%s%d",R,&n)!=EOF)
	{
		int a[150]={1};
		num=0,t=0;
		for(i=0;i<strlen(R);i++)
		{
			if(R[i]=='.')
			{
				t=(strlen(R)-1-i)*n;
			}
			else
			{
				num=num*10+R[i]-48;
			}
		}
		multiply(a,n,num);
		if(len<=t)//����a��λ��С��С��λ�� 
		{
			printf(".");
			for(i=0;i<t-len;i++)
			printf("0");
			for(i=len-1;i>=0;i--)
			printf("%d",a[i]);
		}
		else
		{
			j=0;
			while(a[j]==0&&j<t)//ȥ��ĩβû�õ��� 
			{
				j++;
			}
			l=len;
			for(i=len-1;i>=j;i--)
			{
				if(a[i]==0)
				l--;
				if(a[i]!=0)
				break;
			}
			for(i=l-1;i>=j;i--)
			{
				if(i+1==t)
				printf(".");
				printf("%d",a[i]);
			}
		}
		printf("\n");
	} 
}
