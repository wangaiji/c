#include"stdio.h"
#include"string.h" 
int main() 
{
	int a,b,i,n,j=1;
	while(scanf("%d %d",&a,&b)==2)
	{
		int x=0,y=0;
		for(i=a;i<=b;i++)
		{
			char c[1000000]={'0'};
			n=0;
			int m=i;
			while(m!=0)
			{
				c[n++]=m%10+'0';
				m=m/10;
			}
			if(strstr(c,"125")) y++;
			if(strchr(c,'1')&&strchr(c,'2')&&strchr(c,'5'))
			x++;
		}
		printf("Case %d:%d %d\n",j++,x,y);
		
	}
}
