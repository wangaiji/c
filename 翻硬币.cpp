#include"stdio.h"
#include"string.h"
int main()
{
	int i,n=0;
	char a[1000],b[1000];
	gets(a);
	gets(b);
 	for(i=0;i<strlen(b);i++)
  	{
	   	if(a[i]!=b[i])
	   	{
	   	 	n++;
			if(b[i+1]=='o') b[i+1]='*';
			else b[i+1]='o';	
   		}
	}
        printf("%d",n);
}
