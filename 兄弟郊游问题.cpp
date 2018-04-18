#include"stdio.h"
int main()
{
	int N;
	float s,M,X,Y,Z,m;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%f %f %f %f",&M,&X,&Y,&Z);
		m=M*X/(Y-X);
		s=Z*m;
		printf("%.2f\n",s);
	}
}
