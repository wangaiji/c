#include"stdio.h" 
#include"string.h"
int main()
{
	int a[1000]={1},a1[1000]={0},i,j,t,tem,len=1,len1,m,s;
	char b[1000],c[1000];
	gets(b);
	for(i=1;i<=100;i++)//计算3^100 
	{
		t=0;
		for(j=0;j<len;j++)
		{
			tem=a[j]*3;
			a[j]=(tem+t)%10;//每一位分离出来 
			t=(tem+t)/10;//t为进位 
			if(t!=0&&j==len-1)
			len++;
 		} 
		
	}//逆着存的 
	j=0; 
	for(i=len-1;i>=0;i--)
	a1[j++]=a[i];
	for(i=0;i<len;i++)
	printf("%d",a1[i]);
	printf("\n");
	len1=strlen(b);
	m=(len>len1)?len:len1;
	for(i=0;i<50;i++) a1[50-1-i]=a1[len-1-i];
	for(i=0;i<50-len;i++) a1[i]=0;
	for(i=0;i<50;i++) b[50-1-i]=b[len1-1-i]; 
	for(i=0;i<50-len1;i++) b[i]='0';
	for(i=0;i<50;i++) c[i]='0';
	s=0;//进位
	for(i=0;i<m;i++) 
	{
		c[50-1-i]=(a1[50-1-i]+(b[50-1-i]-'0')+s)%10+'0';
		s=(a1[50-1-i]+(b[50-1-i]-'0')+s)/10;
	} 
	c[50-1-m]=s+'0';
	printf("%s",c);
	
	
	
	
}
