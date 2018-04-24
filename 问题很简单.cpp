#include"stdio.h"
#include"math.h"
int main()
{
	long int N,i,j;
	int T,s;
	scanf("%d",&T);
	while(T--)
	{
		s=0;
		scanf("%ld",&N);
		for(i=1;(i+1)*(i+1)<=N+1;i++)
		if((N+1)%(i+1)==0) s++;
	
		printf("%d\n",s);
	}
}
