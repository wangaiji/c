#include"stdio.h"
int main()
{
	int a1,b1,c1,a2,b2,c2,a,b,c,d,e,f,x,y,z;
	scanf("%d:%d:%d",&a1,&b1,&c1);
	scanf("%d:%d:%d",&a2,&b2,&c2);
	c=c1+c2;b=b1+b2;a=a1+a2;
	if(c>60)
	{
		c=c1+c2-60;
		b=b+1; 
	}
	if(b>60)
	{
		b=b-60;
		a=a+1;
	}
	if(a1<a2)
	a1=a1+24;
	d=a1-a2;e=b1-b2;f=c1-c2;
	if(f<0) 
	{
	 	f=60+f;
		e=e-1;
        }
        if(e<0)
        {
        	e=60+e;
        	d=d-1;
	}
	if(a>24) a=a-24;
 	printf("%02d:%02d:%02d\n",a,b,c);
	printf("%02d:%02d:%02d\n",d,e,f);
	x=a/2,y=b/2,z=c/2; 
	if(a%2!=0)
	y+=30;
	if(b%2!=0)
	z+=30;
	printf("%02d:%02d:%02d",x,y,z);
	if(c%2!=0)
	printf("'50");	
}
