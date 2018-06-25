#include"stdio.h"
#define N 20
struct node
{
	int num;
	char name[100];
	char author[100];
	char place[100];
	int year;
	int month;
	int day;
	double price;
};
int main()
{
	struct node thing[N];
	struct node t;
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&thing[i].num);
		scanf("%s", thing[i].name);
		scanf("%s", thing[i].author);
		scanf("%s", thing[i].place);
		scanf("%d",&thing[i].year);
		scanf("-%d", &thing[i].month);
		scanf("-%d ", &thing[i].day);
		scanf("%lf",&thing[i].price);
		scanf("\n");
	}
	
	for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++)
            {
            	if(thing[i].price>thing[j].price)
            	{
            		t=thing[i];
            		thing[i]=thing[j];
            		thing[j]=t;
	        }
	    }
        printf("编号 书名 作者 出版社 出版日期 价格\n");
        for(i=0;i<n;i++)
	{
	        printf("%d ", thing[i].num);
		printf("%s ", thing[i].name);
		printf("%s ", thing[i].author);
		printf("%s ", thing[i].place);
		printf("%d年", thing[i].year);
		printf("%d月", thing[i].month);
		printf("%d日 ", thing[i].day);
		printf("%.2lf", thing[i].price);
		printf("\n");
	}
}
