#include"stdio.h"
int main()
{
	int a,b,c,m,n,p,q,r,x,y;
	scanf("%d%d%d",&a,&b,&c);
	m=a;
	n=b;
	p=c;
	r=a%b;
	while(r>0)
	{
		a=b;
		b=r;
		r=a%b;
	}
	x=m*n/b;
	q=x;
	r=x%c;
	while(r>0)
	{
		x=c;
		c=r;
		r=x%c;
	}
	y=p*q/c;
	printf("%d",y);
	
}
