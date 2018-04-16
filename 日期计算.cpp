#include"stdio.h" 
int main()
{
	int N,y,m,d,day,i;
	scanf("%d",&N);
	while(N--)
	{
		day=0;
		int a[12]={31,29,31,30,31,30,31,31,30,31,30,31};
		int b[12]={31,28,31,30,31,30,31,31,30,31,30,31};
		scanf("%d %d %d",&y,&m,&d);
		if((y%4==0)&&(y%100!=0)||(y%400==0))
		{
			for(i=0;i<m-1;i++)
			day=day+a[i];
		}
		else
		{
			for(i=0;i<m-1;i++)
			day=day+b[i];
		}
		printf("%d\n",day+d);
	}
}
