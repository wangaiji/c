#include<stdio.h>  
#include<string.h>  
#define MAX 1000010  
int s1[MAX],s2[MAX]; //����ӿ�ʼ��ÿһ��������ĸ���   
char ch[20];  
void int_string(int x) // ת�����ǵ��õ�   
{  
    int i=0;  
    while(x)  
    {  
        ch[i++] = x % 10 + '0';  
        x /= 10;  
    }  
    ch[i]='\0'; //�ַ���������־   
}  
  
int judge()  
{  
    if(strstr(ch,"125"))  
        return 2;  
    if(strchr(ch,'1')&&strchr(ch,'2')&&strchr(ch,'5'))  
        return 1;  
    return 0;  
}  
  
int main()  
{  
    int i,j,k;        //���   
    for(i=125;i<MAX;++i)  
    {  
        int_string(i);  
        k=judge();  
        if(k==2)  //����" 521 "   
        {  
            s1[i]=s1[i-1]+1;  
            s2[i]=s2[i-1]+1;  
        }  
        else if(k==1)  //"���� '5' ' 2' '1' "   
        {  
            s1[i]=s1[i-1]+1;  
            s2[i]=s2[i-1];  
        }  
        else  
        {  
            s1[i]=s1[i-1];  
            s2[i]=s2[i-1];  
        }  
    }  
    int a,b,temp=1;  
    while(scanf("%d%d",&a,&b)==2)  
    {  
        printf("Case %d:%d %d\n", temp++, s1[b]-s1[a-1],s2[b]-s2[a-1]);  
    }  
    return 0;  
}  
