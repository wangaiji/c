#include<stdio.h>
int main(void)
{
	char a[30],b[30];
	int i,n=1;
	while(scanf("%s %s",a,b)!=EOF)
	{
		getchar();
		printf("Case %d: ",n++);
		if(a[1]=='#')
		{
			if(a[0]=='G') {a[0]='A';a[1]='b';}
			else { a[0]=a[0]+1;a[1]='b';}
			printf("%s %s\n",a,b);
		}
		else if(a[1]=='b')
		{
			if(a[0]=='A') {a[0]='G';a[1]='#';}
			else { a[0]=a[0]-1;a[1]='#';}
			printf("%s %s\n",a,b);
		}
		else printf("UNIQUE\n");
		
	}
}

