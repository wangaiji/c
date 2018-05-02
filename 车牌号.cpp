#include<stdio.h>
#include<string.h>
#define N 10
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    while(n--)
	{
       int m;
       scanf("%d",&m);
       char a[N],min[N];
       scanf("%s",a);
       strcpy(min,a);
       for(int i=1;i<m;i++)
	   {
          scanf("%s",a);
          if(strcmp(a,min)<0)
          {
            strcpy(min,a);
          }
       }
       puts(min);
       printf(" ");
    }
}
