#include"stdio.h"
#include"string.h"
int main() 
{
    char a1[1000],a2[1000],b[1000],c[100][100];
    int n,q,s1,s2,i,j,len1,len2,m=0,x,y;
    scanf("%d",&n);
    x=n;
    while(n--)
    {
    	scanf("%s %s",a1,a2);
	len1=strlen(a1);
	len2=strlen(a2);
	q=(len1>len2)?len1:len2;
	for(i=0;i<50;i++)  a1[50-1-i]=a1[len1-1-i];
	for(i=0;i<50-len1;i++)  a1[i]='0';
	for(i=0;i<50;i++)  a2[50-1-i]=a2[len2-1-i];
	for(i=0;i<50-len2;i++)  a2[i]='0';
	for(i=0;i<50;i++) b[i]='0';
 	for(j=0;j<50;j++)
	   c[m][j]='0';
	s1=0;//½øÎ» 
	for(i=0;i<q;i++)
	{
		b[50-1-i]=((a1[50-1-i]-'0')+(a2[50-1-i]-'0')+s1)%10+'0';
		s1=((a1[50-1-i]-'0')+(a2[50-1-i]-'0')+s1)/10;
	}
	b[50-1-q]=s1+'0';
	
	
	for(i=0;b[i]=='0';i++);
	for(j=i;j<50;j++)
	{
		printf("%c",b[j]);
	}
	printf("\n"); 
	
	s2=0;//½èÎ» 
	for(i=0;i<q;i++)
	{
		if(((a1[50-1-i]-'0')-(a2[50-1-i]-'0')-s2)>=0)
		{
			c[m][50-1-i]=((a1[50-1-i]-'0')-(a2[50-1-i]-'0')-s2)+'0';
			s2=0;
		}
		else
		{
		    	c[m][50-1-i]=(10+(a1[50-1-i]-'0')-(a2[50-1-i]-'0')-s2)+'0';
  			s2=1;	
		}
	}
	m=m+1;
    }
    for(y=0;y<x;y++)
    {
        for(i=0;c[y][i]=='0'&&i<50;i++);
	if(i==50)
	{
	  printf("0\n");
	  continue;
        }
	for(j=i;j<50;j++)
	{
		printf("%c",c[y][j]);
	}
    	printf("\n");
    }
}
