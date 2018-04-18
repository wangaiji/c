#include"stdio.h"
int main()
{
	int N,M;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&M);
		if(M<=100&&M>=90)
		printf("A\n");
		else if(M<=89&&M>=80)
		printf("B\n");
		else if(M<=79&&M>=70)
		printf("C\n");
		else if(M<=69&&M>=60)
		printf("D\n");
		else if(M<=59&&M>=0)
		printf("E\n");
	}
}
