#include"stdio.h"
#include"math.h"
int main()
{
	int T,M,i,r,t;
	char s[10];
	float sum,m;
	scanf("%d",&T);
	while(T--)
	{
		r=0;sum=0;
		scanf("%d",&M);
		for(i=1;i<=M;i++)
		{
			getchar();
			scanf("%s",s);
			if(s[0]=='I') r++;
			if(s[0]=='S')
			{
				scanf("%d",&t);
				m=pow(20,r);
				sum+=t/m; 	
			}
			if(s[0]=='O') r--;
		} 
		printf("%.f\n",sum*60); 
		  
	}
}
