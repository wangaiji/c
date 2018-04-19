#include<stdio.h>
#include<math.h> 
int main() 
{
	int n;
	float x1,y1,x2,y2;
	float x;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
		x=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		printf("%.2f\n",x);
	}
}
