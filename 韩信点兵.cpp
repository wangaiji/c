#include"stdio.h"
int main()
{
	int a,b,c,i,flag=0;
	scanf("%d %d %d",&a,&b,&c);
	for(i=10;i<=100;i++)
	if(i%3==a&&i%5==b&&i%7==c)
    {flag=1;printf("%d\n",i);break;}
    if(flag==0) printf("No answer\n");
}
