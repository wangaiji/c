#include<stdio.h>
#include<string.h>
#define M 100
#define N 100
int main(void)
{
	char str[M],substr[N];
	int i,j,k,a=0;
	printf("�����ַ���str��");
	gets(str); 
	printf("�������Ӵ�substr:");
	gets(substr);
	for(i=0;str[i];i++)
	for(j=i,k=0;substr[k]==str[j];k++,j++)
	if(substr[k+1]=='\0')
	{
		a++;
		break;
	}
    printf("%d",a);
} 
