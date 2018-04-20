#include<stdio.h>
int main()
{
    int i,m,j,sum1,sum2,n,t=0;
    scanf("%d",&n);
    while(n--)
 {
     t++;
     sum1=0;
     sum2=0;
     scanf("%d",&m);
     for(i=1;i<=m;i++)
   {
     for(j=1;j<=i+1;j++)
    {
     sum1=sum1+j;
    }
     sum2=sum2+i*sum1;
     sum1=0;
   }
     printf("%d %d %d\n",t,m,sum2);
 }
     return 0;
}
