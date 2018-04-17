#include"stdio.h"
#include"math.h" 
int main()
{
	int M,w,n,t;
	scanf("%d",&M);
	while(M--)
	{
		n=0;
		scanf("%d",&w);
        t=w;
		while(t>10)
		{
		t=t/10;
		n++;
	    }
	    printf("%.f\n",w-t*pow(10.0,n));
	}
}
