#include"stdio.h"
#include"string.h"
int main()
{
	int n,i,j,count=1;
	char s[15][25],t[25],a[15][25];
	while(scanf("%d",&n),n)
	{
	  getchar();
	  for(i=0;i<n;i++)
	  {
		scanf("%s",&s[i]);
	  }
	  for(i=0;i<n;i++)
	    for(j=0;j<n-i-1;j++)
	    {
	    	if(strlen(s[j])>strlen(s[j+1]))
	    	{
	    		strcpy(t,s[j]);
	    		strcpy(s[j],s[j+1]);
	    		strcpy(s[j+1],t);
			}
		}
	  for(i=0;i<n;i++)
	  {
	  	if(i%2==0)
	  	strcpy(a[i/2],s[i]);
	  	else
	  	strcpy(a[n-1-(i-1)/2],s[i]);
	  }
	  printf("SET %d\n",count);
	  for(i=0;i<n;i++)
	  printf("%s\n",a[i]);
	  count++;
    }
}
