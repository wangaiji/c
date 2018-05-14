#include<stdio.h>  
int main()  
{  
    int a,n,flag,i,max,min,j;  
    int arr[10000],c[10000];  
    while(scanf("%d",&a)!=EOF)  
    {  
        n=a/3;  
        flag=1;  
        i=0;  
        while(n--)  
        {   
            for(j=0;j<3;++j)  
            {  
                scanf("%d",arr+j);  
            }  
            if(flag%2!=0)  
            {  
                max=arr[0];  
                if(max<arr[1])  
                    max=arr[1];  
                if(max<arr[2])  
                    max=arr[2];  
                c[++i]=max;  
                flag+=1;  
            }  
            else if(flag%2==0)  
            {  
                min=arr[0];  
                if(min>arr[1])  
                    min=arr[1];  
                if(min>arr[2])  
                    min=arr[2];  
                c[++i]=min;  
                ++flag;  
            }  
        }  
        max=c[1];  
        for(j=2;j<=i;++j)  
        {  
            if(max<c[j])  
                max=c[j];  
        }  
        printf("%d\n",max);  
    }  
    return 0;   
}          
