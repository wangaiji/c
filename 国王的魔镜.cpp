#include"stdio.h"
#include"string.h" 
int main()
{
	int N,l,i,q;
	char a[100],t[100];
	scanf("%d",&N);
	while(N--)
	{
		getchar();
		scanf("%s",a);
		do{
		l=strlen(a);
		if(l%2) break;
        for(i=0; i<l/2; i++)
        t[i]=a[l-1-i];
        t[i]='\0';
        a[l/2]='\0';
        q=strcmp(a,t);
        }while(q==0);
        printf("%d\n",l);
	}
	
}
