#include"stdio.h" 
int main()
{
	int N,M,n;
	scanf("%d",&N);
	while(N--)
	{
		n=0;
		scanf("%d",&M);
		while(M)
	  {
		if(M%2==1)
		{
			n++;
		}
		M=M/2;
	  }
		printf("%d\n",n);
	}
}
