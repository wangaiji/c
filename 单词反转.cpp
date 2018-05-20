#include"stdio.h" 
#include"string.h"
int main()
{
	char s[100],a[100],t;
	int i,j=0,x,m=0,n;
	gets(s);
	for(i=0;i<=strlen(s);i++)
	{
		if(s[i]!=' '&&i!=strlen(s))
		a[j++]=s[i];
		else if(s[i]==' '||i==strlen(s))
		{	
		  a[j++]=' ';
		  x=i-1;
		  for(n=m;n<=(m+x)/2;n++)
		  {
		  	t=a[n];
		  	a[n]=a[m+x-n];
		  	a[m+x-n]=t;
		  }  
		  m=i+1;
                }
	}
	puts(a);
}
