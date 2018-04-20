#include"stdio.h" 
#include"string.h"
int main()
{
	char c[1001];
	int i,n,l;
	while(scanf("%d",&n)!=EOF)
	{
		gets(c);
		l=strlen(c);
		for(i=0;i<l;)
		{
			if(c[i]=='y'&&c[i+1]=='o'&&c[i+2]=='u')
			{
				printf("%s","we");
				i=i+3;
			}
			printf("%c",c[i]);
			i++;
		}
		printf("\n");
	}
}
