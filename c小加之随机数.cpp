#include<stdio.h>
int main()
{
   int i,j,t;
   int n;
   scanf("%d",&n);
   while(n--)
  { 
    int q=0;
    scanf("%d",&q);
    int a[q],b[q];
    for(i=0;i<q;i++)
    scanf("%d",&a[i]);
    for(i=0;i<q-1;i++)
    for(j=0;j<q-1-i;j++)
    {
     if(a[j]>a[j+1])
     {
       t=a[j];
       a[j]=a[j+1];
       a[j+1]=t;
     }
    } 
    int count=0; 
    for(i=0;i<q;i++)
    {
      if(a[i]!=a[i+1])
     {
       b[count]=a[i];
       count++;
     }
    }
    printf("%d\n",count);
    for(i=0;i<count;i++)
    printf("%d ",b[i]);
    printf("\n");
  }
  return 0;
}
