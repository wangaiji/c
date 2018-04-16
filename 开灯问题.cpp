#include"stdio.h"
int main()
{
	int n,k,i,j;
	int a[1000];
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++)
	a[i]=0;
	for(j=1;j<=k;j++)
	  for(i=1;i<=n;i++)
		if(i%j==0) a[i]=!a[i];
	for(i=1;i<=n;i++)
	if(a[i]) printf("%d ",i);
	
	
}
