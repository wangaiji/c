#include"stdio.h" 
#include"string.h" 
int main()
{
	int a[100],b[100],i=0,j,n,m;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	while(scanf("%d %d",&n,&m),n!=0&&m!=0) 
	{
		if(b[n])
		b[n]+=m;
		else
		{
			a[i++]=n;
			b[n]=m;
		}	
	}
	for(j=0;j<i;j++)
	printf("%d %d\n",a[j],b[a[j]]);
}
