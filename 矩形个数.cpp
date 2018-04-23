#include"stdio.h"
#include"math.h"
int main()
{
	float L,D,R,n;
	int t,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%f%f%f",&L,&D,&R);
		n=L/sqrt(4*R*R-D*D);
		if(R<=D/2) printf("impossible\n");
		else
		{
			if(n==(int)n) k=(int)n;
			else k=(int)n+1;
			printf("%d\n",k);
		}
	}
} 
