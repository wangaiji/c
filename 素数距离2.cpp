#include"stdio.h" 
#include"math.h"
int main()
{
	int m,n,k;
	long a[100000],i,j;
	scanf("%d",&n);
	while(n--)
	{
		k=0;a[0]=2;
		scanf("%d",&m);
		if(m==1) { printf("2 1\n");continue;}
		for(i=3;i<=1000000;i++)
		{
		   for(j=2;j<=sqrt(i);j++)
		   if(i%j==0) break;
		   if(j>sqrt(i)) a[k++]=i;
		}
	    for(i=0;i<k;i++)
		{ 
		  if(m==a[i]) printf("%d 0\n",m);
	      if(m>a[i]&&m<a[i+1]) 
		  {
			if(m-a[i]<=a[i+1]-m) printf("%d %d\n",a[i],m-a[i]);
			else printf("%d %d\n",a[i+1],a[i+1]-m);
		  }
	    } 
	}
}
