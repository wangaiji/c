#include"stdio.h"
int main()
{
	int N,i,j,sum,flag=0;
	while(scanf("%d",&N)!=EOF)
	{
             for(i=1;i<=100;i++)
	    {
		sum=0;
		for(j=i;j<=100;j++)
		{
			sum+=j;
			if(sum==N)
			{
	                    printf("%d %d\n",i,j);
	                    flag=1;
                        }
		}
		if(flag==1) break;
	    }
       }
}
