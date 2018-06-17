#include "stdio.h"
#include <string.h>
 void find(char a[],char b[])
 {
    int len1,len2,i=0,j=0;
    char *str1,*str2;
    str1=a;str2=b;
    len1=strlen(str1);
    len2=strlen(str2);
    while(i<len1&&j<len2)
    {
        if(str1[i]==str2[j])
        {
            i++;j++;
        }
        else
        {
        i=i-j+1;j=0;
        }
     
    }
    if(j>=len2) printf( "%d\n",(i-j+1));
    else printf("no found");
 
}
int main()
{
    char a[100],b[100];
    int i=0;
    char c;
    while((c=getchar())!=' ')
    {
        a[i++]=c;
    }
    a[i]='\0';
    i=0;
    while((c=getchar())!='\n')
    {
        b[i++]=c;
    }
      b[i]='\0';
    find(a,b);
}
