#include"stdio.h" 
int main()
{
	int n,k,m,sum;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d %d",&n,&k);
		sum=n;
		while(n>=k)
		{
			sum+=n/k;
			n=n%k+n/k;
		}
		printf("%d\n",sum);
		
	}
	
}
