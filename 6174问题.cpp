#include"stdio.h"
int main()
{
	int n,a,b,t,c,m,x,i,j;
	int d[4];
	scanf("%d",&n);
	while(n--)
	{
		c=0;x=0;
		scanf("%d",&m);
		if(m==6174) {printf("1\n");continue;}
		while(c!=6174)
		{
		d[3]=m%10;
		d[2]=(m/10)%10;
		d[1]=(m/100)%10;
		d[0]=(m/1000)%10; 
		for(i=0;i<3;i++)
		  for(j=i+1;j<4;j++)
		  if(d[i]<d[j]) 
		  {
		  	t=d[i];
		  	d[i]=d[j];
		  	d[j]=t;
		  }
		a=1000*d[0]+100*d[1]+10*d[2]+d[3];
		b=1000*d[3]+100*d[2]+10*d[1]+d[0];
		c=a-b;x++;m=c;
    	}
    	printf("%d\n",x+1);
	}
}
