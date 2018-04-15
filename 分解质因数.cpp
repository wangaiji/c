#include <stdio.h>
int main()
{
int n, i;
scanf("%d", &n);

for (i=2; i<=n;i++)
{ if (n%i==0)
{  
    n = n/i;
    printf("%d*", i);
    i--;
    } 
}

return 0;
}
