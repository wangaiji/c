#include"stdio.h"
int main()
{
	char x;
	int y;
	int T,i,a;
	scanf("%d",&T);
	while(T--)
	{
		
		scanf("%s%d",&x,&y);
		if(x>='A'&&x<='Z')
		a=x-'A'+1;
		else if(x>='a'&&x<='z')
		a='a'-x-1;
		printf("%d\n",a+y);
		
	}
	
}
