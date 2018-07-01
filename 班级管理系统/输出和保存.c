#include "record.h" 
#define TITLE "******************班级管理系统*******************"
#define NAME "选择输出方式："
#define NR(x) (sizeof(x)/sizeof(x[0]+0))
void Show4_1()
{
	printf("                                 ******************学生信息管理系统*************************\n");
	printf("                                                   选择输出方式：\n");
	printf("                                                  1.按总成绩从高到低输出\n");
	printf("                                                  2.按学号顺序输出\n");
	printf("                                                  3.按语文成绩从高到低输出\n");
	printf("                                                  4.按数学成绩从高到低输出\n");
	printf("                                                  5.按英语成绩从高到低输出\n");
	printf("                                                  6.返回上一层\n");
	printf("                                                  0.退出\n");
	printf("                                                 请输入相应的数字\n"); 
	printf("                                 ***********************************************************\n");
}
//显示菜单 
void showmenu2(HANDLE hOut ,char **menu2, int size , int index) ;
//获取用户输入 
int  get_userinput(int *index , int size) ;
char *menu2[] = 
{
	"1.按总成绩从高到低输出",
	"2.按学号顺序输出",
	"3.按语文成绩从高到低输出",
	"4.按数学成绩从高到低输出",
	"5.按英语成绩从高到低输出",
	"6.返回上一层",
	"0.退出",
};
/*
void output(struct student *head)//输出 
{
	char flag; 
	while(1)
	{
		system("cls");
		Show4_1();
		fflush(stdin);
		scanf("%c",&flag);
		switch(flag)
		{
			case '1':Sort(head,flag);print(head);break;//按平均分输出 
			case '2':Sort(head,flag);print(head);break;//按学号输出 
			case '3':Sort(head,flag);print(head);break; //语文 
			case '4':Sort(head,flag);print(head);break; //数学 
			case '5':Sort(head,flag);print(head);break; //英语 
			case '6':return;
			case '0':exit(0); 
			default :printf("输入有误请重新输入\n");break; 
		}
		printf("按任意键进行下一步操作\n");
		getch();
	} 
}*/
//定义结构体
CONSOLE_CURSOR_INFO cci; 
//定义默认的坐标位置  	
COORD pos2 = {0,0};
//显示菜单 
void showmenu2(HANDLE hOut ,char **menu2 , int size , int index) ;
//获取用户输入 
int  get_userinput(int *index , int size) ;

void output(struct student *head)//输出 
{
   // system("cls");
    int i;
    int ret ;
    int index = 0 ;
    HANDLE hOut;
    SetConsoleTitleA(TITLE);
    //获取当前的句柄---设置为标准输出句柄 
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //获取光标信息
    GetConsoleCursorInfo(hOut, &cci); 
	//设置光标大小   
    cci.dwSize = 1; 
	//设置光标不可见 FALSE   
    cci.bVisible =  0; 
    //设置(应用)光标信息
    SetConsoleCursorInfo(hOut, &cci); 
  //  system("cls");  
    while(1)
    {
    	system("cls");
    	showmenu2(hOut , menu2, NR(menu2) , index);
	ret = get_userinput(&index , NR(menu2));
	if(ret == ESC)
	break ;
	if(ret == ENTER)
	{
	       switch(index)
	       {
  		        case 0:Sort(head,'1');print(head);break;//按平均分输出 
			case 1:Sort(head,'2');print(head);break;//按学号输出 
			case 2:Sort(head,'3');print(head);break; //语文 
			case 3:Sort(head,'4');print(head);break; //数学 
			case 4:Sort(head,'5');print(head);break; //英语 
			case 5:return;break;
			case 6:exit(0); break;  	
	       }
	       	printf("按任意键进行下一步操作\n");
		getch();
	}
	
    }
}

void showmenu2(HANDLE hOut ,char **menu2 , int size , int index)
{
	int i ; 	
	//设置显示的文本的颜色 
	SetConsoleTextAttribute(hOut, FOREGROUND_RED|FOREGROUND_GREEN|0x8); 
	//初始化控制台显示的X,Y轴的坐标 
	pos2.X = 32;
	pos2.Y = 3 ;
	//设置显示到控制台终端的具体位置 
	SetConsoleCursorPosition(hOut,pos2);    
	//调用printf在控制台对应的位置上输出 
	printf("%s",TITLE);
	pos2.X = 50;
	pos2.Y = 4 ;
	SetConsoleCursorPosition(hOut,pos2);   
	printf("%s",NAME);
	for(i = 0 ; i < size ; i++)
	{
		//如果i==index表示在当前选项的位置，默认初始化显示是第一项，显示为红色，
		//当按下上下按键选择的时候，光标会移动，也就看到了列表选择的现象 
		if(i == index)
		{
			//红色 
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | 0x8); 
			pos2.X = 50;
    		pos2.Y = 5+i;
    		//设置光标坐标
    		SetConsoleCursorPosition(hOut,pos2);    
    		printf("%s",menu2[i]);
		}
		//否则显示为白色 
		else
		{
			//白色 
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
			pos2.X = 50;
    		pos2.Y = 5+i;
    		//设置光标坐标
    		SetConsoleCursorPosition(hOut,pos2);    //设置光标坐标
    		printf("%s",menu2[i]);
		}
	}
	printf("\n");
	SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY); 
	printf("                                *************************************************\n");
	//刷新标准输出缓冲区 
	fflush(stdout);
}

