#include"stdio.h"
#include"math.h"
int main()
{
	int n,m,i,j,a,b;
	scanf("%d",&n);
	while(n--)
	{
		
		scanf("%d",&m);
	    if(m==1) {printf("2 1\n");continue;}
		for(i=2;i<=sqrt(m);i++)
		if(m%i==0) break;
		
		if(i>sqrt(m)) {printf("%d 0\n",m);continue;}
		for(j=m-1;j>=2;j--)
		{
			for(i=2;i<=sqrt(j);i++)
			if(j%i==0) break;
			if(i>sqrt(j)) { a=j;break;}	
		}
		for(j=m+1;;j++)
		{
			for(i=2;i<=sqrt(j);i++)
			if(j%i==0) break;
			if(i>sqrt(j)) { b=j;break;}
		}
		if(m-a<=b-m) printf("%d %d\n",a,m-a);
		else  printf("%d %d\n",b,b-m);
	}
}
