#include"stdio.h"
int m;
int sum(int day)
{
	if(day==m)
	return 1;
	else
	return 2*sum(day+1)+2;
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		printf("%d\n",sum(0));
	}
}
