#include<stdio.h>  
  
void fun(int x,int y) {  
    int i;  
    int j;  
    int tmp = 0;  
    int res = 0;  
    int flag = 1;  
  
    for(i = 2; i <= 10000; i++) {   
        tmp = res = x - (i+(i-1)) + i*(i-1);  
        for(j = i+2; j <= 10000; j++) {      
            res = tmp - (j + (j-1)) + j * (j-1);      
            if(res == y) {      
               printf("(%d,%d)",i - 1,j - 1);    
               flag = 0;  
            }  
        }  
    }  
    if(flag == 1){  
        printf("NONE");  
    }  
    printf("\n");  
}  
  
int main(void) {  
    int n;  
    int X;  
    int Y;  
      
    scanf("%d",&n);  
    while(n--) {  
        scanf("%d %d",&X,&Y);  
        fun(X,Y);    
    }  
    return 0;  
}  
