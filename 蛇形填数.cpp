#include"stdio.h" 
int main()
{
	int n,i,j,a[100][100],m=1,k,x;
	scanf("%d",&n);
	if(n%2==0) k=n/2;
	else k=n/2+1;
	for(x=0;x<k;x++)
  {
	for(i=x;i<n-x;i++)
	{
	  a[i][n-1-x]=m;
      m++;
    }
    for(j=n-2-x;j>=x;j--)
    {
    	a[n-1-x][j]=m;
    	m++;
	}
	for(i=n-2-x;i>=x;i--)
	{
		a[i][x]=m;
		m++;
	}
	for(j=1+x;j<n-1-x;j++)
	{
		a[x][j]=m;
		m++;
	}
  }
  for(i=0;i<n;i++) 
  {
	for(j=0;j<n;j++)
    printf("%d ",a[i][j]);
    printf("\n");
  }
    
	
}
