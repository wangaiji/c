#include<stdio.h>
int ss(int a) 
{
   if(a==1)
   return 0;
   for(int i=2; i<a; i++)
   if(a%i==0)
   return 0;
   return 1;
}

int main() 
{
   int n, i, j;
   scanf("%d", &n);
   while(n--) 
   {
     int a;
     scanf("%d", &a);

     if(ss(a))
     printf("%d\n", a);

     else{
     for(i=a;i>=1;i--)
     if(ss(i))
     break;

     for(j=a;;j++)
     if(ss(j))
     break;

     printf("%d\n",(j-a)<=(a-i)?j:i);
     }
   }
}
