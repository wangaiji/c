#include"stdio.h" 
#include"math.h" 
int f(int a)
{
	char s[20];
	int i=0;
	while(a)
	{
		s[i++]=a%10+'0';
		a=a/10;
		if(s[i-1]>'6') 
		return 0;
	}
	while(i<6)
	s[i++]='0';
	s[i]='\0';
	for(i=1;i<6;i++)
	{
		if(s[i]==s[i+1]&&s[i]==s[i-1])
		return 0;
		if(fabs(s[i]-s[i-1]>4))
		return 0;
	}
	return 1;		
}
int main()
{
	int n,x,y,i;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d",&x,&y);
		for(i=x;i<=y;i++)
		if(f(i)==1) printf("%06d\n",i);	
		printf("\n");	
        } 
}
