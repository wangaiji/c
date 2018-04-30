#include"stdio.h" 
#include"string.h"
int main()
{
	int n,i;
	char a[1000],b[1000];
	scanf("%d",&n);
	while(n--) 
	{
		char b[1000]={0};
		int x=0,y=0,z=0;
		scanf("%s",a);
		for(i=0;i<strlen(a);i++)
		{
		if(a[i]=='R') x++;
		if(a[i]=='W') y++;
		if(a[i]=='B') z++;
	    }
		for(i=0;i<x;i++)
		b[i]='R';
		for(i=x;i<x+y;i++)
		b[i]='W';
		for(i=x+y;i<x+y+z;i++)
		b[i]='B';
		printf("%s",b);
	}
}
