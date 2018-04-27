#include"stdio.h"
#include"string.h"
int main()
{
	int N,i,j;
	char a[40],b[40],c[40];
	scanf("%d",&N);
	while(N--)
	{
		char c[40]={0};
		j=0;
		getchar();
		scanf("%s %s",a,b);
		for(i=strlen(b)-1;i>=0;i--)
		{
		if(b[i]<='9'&&b[i]>='0') continue;
		else c[j++]=b[i];
	    }
		for(i=strlen(a)-1;i>=0;i--)
		{
			if(a[i]<='9'&&a[i]>='0') continue;
		    else c[j++]=a[i];
		}
		printf("%s\n",c);
	}
	
}
