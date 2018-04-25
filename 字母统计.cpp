#include"stdio.h" 
#include"string.h"
int main()
{
	int T,i,a[26],max,j;
	char s[1010];
	scanf("%d",&T);
	while(T--)
	{
		int a[26]={0};
		getchar();
		scanf("%s",s);
		for(i=0;i<strlen(s);i++)
		{
			a[s[i]-97]++;
		}
		max=a[0];
		for(i=1;i<26;i++)
		if(a[i]>max) {max=a[i];j=i;}
		printf("%c\n",j+'a');
	}
	
	
}
