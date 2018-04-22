#include"stdio.h"
#include"string.h"
int main()
{
	int T,i,j;
	char s[10],b[10];
	scanf("%d",&T);
	while(T--)
	{
		char b[10]={'O','O','T','T','F','F','S','S','E','N'};
		scanf("%s",s);
		for(i=strlen(s)-1;i>=0;i--)
		{
			printf("%c",b[s[i]-48]);
		}
		printf("\n");
	}
}
