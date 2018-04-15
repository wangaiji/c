#include"stdio.h" 
#include "string.h"
int main()
{
	int N,X,c,d,g,i,s,max,sum,ans;
	char a[100],e,f;
	char str[100];
	scanf("%d",&N);
	while(N--)
	{
		ans = 0;
		sum = 0;
		scanf("%d",&X);
	    for(i=0;i<X;i++)
	  {
	  	s = 0;
	  	scanf("%s %d %d %c %c %d",a,&c,&d,&e,&f,&g);
		if(c>80&&g>=1)  s+=8000;
		if(c>85&&d>80)  s+=4000;
		if(c>90)        s+=2000;
		if(c>85&&f=='Y') s+=1000;
		if(d>80&&e=='Y') s+=850;	
	    if(ans<s){
	  	strcpy(str,a);
	  	ans  = s;
	    }	 
	    sum+=s;
	  }
    printf("%s\n",str);  
    printf("%d\n",ans);  
    printf("%d\n",sum); 
   }
}
