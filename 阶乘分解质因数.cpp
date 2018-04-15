#include"stdio.h" 
int main()
{
	int s,n,m,sum;
	scanf("%d",&s);
	while(s--)
	{
		sum=0;
		scanf("%d %d",&n,&m);
		while(n/m)
		{
			sum+=n/m;
			n=n/m;
		}
		printf("%d\n",sum);
	}
}
