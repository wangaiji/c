#include"stdio.h"
  
void f(int days,int year,int month,int day) {  
    char week[7][28] = {"星期一","星期二","星期三","星期四","星期五","星期六","星期日"};  
    int monthDay[12] = {31,28,31,30,31,30,31,31,30,31,30,31};     
    int i;    
    int s = 0;  
   // int flag1 = 0;  
   // int flag2 = 0;  
    
    for(i=0;i<days;i++) {    
        day++;    
        if(day > monthDay[month-1])    
        {    
            day=1;    
            month++;    
            if(month > 12)    
            {    
                month=1;    
                year++;    
                if((year%400==0) ||(year%4==0 && year%100!=0))    
                    monthDay[1] = 29;    
                else    
                    monthDay[1] = 28;    
            }    
        }    
    }    
    /*if(month > 9)  
        flag1 = 1;  
    if(day > 9)  
        flag2 = 1;  
    if(flag1 == 1 && flag2 == 1) {  
        printf("%d年%d月%d日 ",year,month,day);  
    } else if(flag1 == 0 && flag2 == 1) {  
        printf("%d年0%d月%d日 ",year,month,day);  
    } else if(flag_1 == 1 && flag_2 == 0) {  
        printf("%d年%d月0%d日 ",year,month,day);  
    } else if(flag_1 == 0 && flag_2 == 0) {  
        printf("%d年0%d月0%d日 ",year,month,day);  
    } */
    printf("%02d年%02d月%02d日 ",year,month,day);
  
    if(year >= 1990) {  
        for(i = 1990;i < year;i++) {  
            if((i%400 == 0) || (i%4 == 0 && i%100 != 0))   
                s += 366;     
            else  
                s += 365;  
        }  
        if((year%400==0) ||(year%4==0 && year%100!=0))    
            monthDay[1] = 29;    
        else    
            monthDay[1] = 28;   
        for(i = 0;i < month - 1;i++) {  
            s += monthDay[i];  
        }  
        s += day - 1;  
        printf("%s",week[s%7]);  
    } else {  
        for(i = 1990;i > year;i--) {  
            if((i%400 == 0) || (i%4 == 0 && i%100 != 0))   
                s += 366;     
            else  
                s += 365;  
        }   
        if((year%400==0) ||(year%4==0 && year%100!=0))    
            monthDay[1] = 29;    
        else    
            monthDay[1] = 28;   
        for(i = 12;i > month;i--) {  
            s += monthDay[i - 1];  
        }  
        s += monthDay[month] - day + 1;  
        printf("%s",week[s%7]);  
    }  
}  
  
  
int main(void) {  
    int n;  
    int year;  
    int month;  
    int day;  
    int days;  
  
    scanf("%d",&n);  
    while(n--) {  
        scanf("%d-%d-%d %d",&year,&month,&day,&days);  
        f(days,year,month,day);  
        printf("\n");  
    }  
  
    return 0;  
}  

