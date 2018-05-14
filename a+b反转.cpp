#include<stdio.h>
int main()
{
    int i,j,a,b,n,m;
    while(1)
    {
        scanf("%d%d",&m,&n);
        if(m==0 && n==0)
        {
            break;
        }
        i=0;
        while(m!=0)
        {
            a=m%10;
            i=i*10+a;
            m=m/10;
        }
        j=0;
        while(n!=0)
        {
            b=n%10;
            j=j*10+b;
            n=n/10;
        }
        printf("%d\n",i+j);
    }
    return 0;
} 
