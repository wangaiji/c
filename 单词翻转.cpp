#include"stdio.h"
#include"string.h"
int main()
{
	char c[100],a[100][100];
	int i,j=0,x=0;
	gets(c);
	for(i=0;i<strlen(c);i++)
	{
		if(c[i]!=' ')
		{
			a[x][j++]=c[i];
		}
		else
		{
			x++;
			j=0;	
		}
		
	}
	for(i=x;i>=0;i--)
	{
		printf("%s ",a[i]);
	}
}
