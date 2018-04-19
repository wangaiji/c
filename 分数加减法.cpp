#include"stdio.h"
#include"math.h"
int f(int m,int n)
{
	int r;
	r=m%n;
	while(r>0)
	{
		m=n;
		n=r;
		r=m%n;
	}
	return n;
}
int main()
{
	int a,b,c,d,x1,x2,x,y;
	char o; 
	while(scanf("%d/%d%c%d/%d",&a,&b,&o,&c,&d)!=EOF)
	{
		if(a-c==0&&b-d==0) {printf("0\n");continue;}
		if((a==0||b==0)&&(c!=0&&d!=0))
	   {
        if(c%d==0) {printf("%c%d\n",o,c/d);continue;}
        else {printf("%c%d/%d\n",o,c/f(c,d),d/f(c,d));continue;}
       }
        if((c==0||d==0)&&(a!=0&&b!=0))
		{
          if(a%b==0) {printf("%d\n",a/b);continue;}
          else {printf("%d/%d\n",a/f(a,b),b/f(a,b));continue;}
        }
		
		x2=b*d;
		if(o=='+') x1=a*d+c*b;
		else x1=a*d-c*b;
        x=x1/f(x2,fabs(x1));
		y=x2/f(x2,fabs(x1));
		printf("%d/%d\n",x,y);
	}
}
