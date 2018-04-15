#include"stdio.h" 
int main()
{
	int N,X,c,d,g,i,s[100],max,sum,j;
	char a[100][100],e,f;
	scanf("%d",&N);
	while(N--)
	{
		sum=0;
		scanf("%d",&X);
		getchar(); 
	    for(i=0;i<X;i++)
	  {
	  	scanf("%s %d %d %c %c %d",a[i],&c,&d,&e,&f,&g);
		s[i]=0;
		if(c>80&&g>=1)  s[i]+=8000;
		if(c>85&&d>80)  s[i]+=4000;
		if(c>90)        s[i]+=2000;
		if(c>85&&f=='Y') s[i]+=1000;
		if(d>80&&e=='Y') s[i]+=850;
	  }
	   max=s[0];
	   for(i=1;i<X;i++)
      {
		if(s[i]>max) {max=s[i];j=i;}
		  }
	   for(i=0;i<X;i++)
	   sum+=s[i];
	   printf("%s\n",a[j]);
	   printf("%d\n",max);
	   printf("%d\n",sum);
   }
}
