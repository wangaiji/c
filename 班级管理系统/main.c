#include "record.h"
#define NR(x) (sizeof(x)/sizeof(x[0]+0))
#define TITLE "******************班级管理系统*******************"
void Show()
{
	HANDLE hOut;
	hOut=GetStdHandle(STD_OUTPUT_HANDLE);//获得控制台句柄 
	printf("\n\n\n");
	SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY); 
	printf("                                                    西安邮电大学\n");
	printf("                                                  学生成绩管理系统\n\n");
	printf("                                                    版本号：2.0\n"); 
	printf("\n\n\n\n\n\n");
	printf("                                                  制作人：aijinova\n");
	printf("                                                  时间：  2018年5月19号\n");
}
void Show1()
{	
        printf("                                              欢迎进入班级管理系统！\n");
	printf("                                 ******************班级管理系统*******************\n");
	printf("                                                   1.学生登录\n");
	printf("                                                   2.教师登录\n");
	printf("                                                   3.管理员登录\n");
	printf("                                                   4.注册帐号\n");
	printf("                                                   5.密码修改\n");
	printf("                                                   6.密码找回\n"); 
	printf("                                                   0.退出\n"); 
	printf("                                                 请输入相应的数字\n"); 
	printf("                                 *****************************************************\n");	
} 

/* 
int main()
{
	struct student *head; 
	char flag;
	system("cls");
	Show();
	Sleep(2000);
	while(1)
	{
		system("cls");
		Show1();
		fflush(stdin);
		scanf("%c",&flag);
		switch(flag)
		{
			case '1':Landing(flag);break;//学生
			case '2':Landing(flag);break;//老师
			case '3':Landing(flag);break;//管理员
			case '4':Sign_up();break;//注册
			case '5':Correct_password();break;//修改
			case '6':Find_password();break;//找回
			case '0':exit(0);break;//退出
			default :printf("输入有误请重新输入\n");break; 
		}	
	}
}*/

//定义要显示的菜单 
char *menu[] = 
{
	"1.学生登录", 
	"2.教师登录",
	"3.管理员登录",
	"4.注册帐号",
	"5.密码修改",
	"6.密码找回", 
	"0.退出",
};
//定义结构体
CONSOLE_CURSOR_INFO cci; 
//定义默认的坐标位置  	
extern COORD pos = {0,0};
//显示菜单 
void showmenu(HANDLE hOut ,char **menu , int size , int index) ;
//获取用户输入 
int  get_userinput(int *index , int size) ;
int main()
{
    struct student *head; 
    Show();
    Sleep(2000);
    system("cls");
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
    	showmenu(hOut , menu , NR(menu) , index);
	ret = get_userinput(&index , NR(menu));
	system("cls");
	if(ret == ESC)
	break ;
	if(ret == ENTER)
	{
	       switch(index)
	       {
	       		    case 0:Landing('1');break;//学生
			    case 1:Landing('2');break;//学生       	
			    case 2:Landing('3');break;
			    case 3:Sign_up();break;//注册	
			    case 4:Correct_password();break;//修改 	
			    case 5:Find_password();break;//找回
			    case 6:exit(0);break;//退出             
	       }
	}
    }
}

void showmenu(HANDLE hOut ,char **menu , int size , int index)
{
	int i ; 	
	//设置显示的文本的颜色 
	SetConsoleTextAttribute(hOut, FOREGROUND_RED|FOREGROUND_GREEN|0x8); 
	//初始化控制台显示的X,Y轴的坐标 
	pos.X = 32;
	pos.Y = 3 ;
	//设置显示到控制台终端的具体位置 
	SetConsoleCursorPosition(hOut,pos);    
	//调用printf在控制台对应的位置上输出 
	printf("%s",TITLE);
	//pos.X = 32;
//	pos.Y = 2 ;
	for(i = 0 ; i < size ; i++)
	{
		//如果i==index表示在当前选项的位置，默认初始化显示是第一项，显示为红色，
		//当按下上下按键选择的时候，光标会移动，也就看到了列表选择的现象 
		if(i == index)
		{
			//红色 
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | 0x8); 
			pos.X = 50;
    		pos.Y = 5+i;
    		//设置光标坐标
    		SetConsoleCursorPosition(hOut,pos);    
    		printf("%s",menu[i]);
		}
		//否则显示为白色 
		else
		{
			//白色 
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
			pos.X = 50;
    		pos.Y = 5+i;
    		//设置光标坐标
    		SetConsoleCursorPosition(hOut,pos);    //设置光标坐标
    		printf("%s",menu[i]);
		}
	}
	printf("\n");
	SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY); 
	printf("                                *************************************************\n");
	//刷新标准输出缓冲区 
	fflush(stdout);
}

//获取用户输入的接口 
int  get_userinput(int *index , int size)
{
	int ch ;
	ch = getch();
	switch(ch)
	{
		//上 
		//如果选择上，那么光标向上移动 
		case UP : if(*index > 0)  *index -= 1 ;  break; 
		//下 
		//如果选择下，那么光标向下移动 
		case DOWN :if(*index < size -1)  *index += 1 ;  break;
		//左 
		case LEFT: 
		case 97:return 0 ;
		//右 
		case RIGHT:return 0 ;
		//回车 
		case ENTER: return ENTER ;
		//ESC
		case ESC: return ESC ;
	} 
} 

