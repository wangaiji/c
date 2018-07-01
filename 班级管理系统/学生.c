#include "record.h"
#define TITLE "******************班级管理系统*******************"
#define NAME "学生端"
#define NR(x) (sizeof(x)/sizeof(x[0]+0))
/*
void Show3()
{
	printf("                                 **********************学生信息管理系统********************\n");
	printf("                                                           学生端\n");
	printf("                                                        1.成绩查询\n");
	printf("                                                        2.查询本班成绩\n");
	printf("                                                        3.成绩分析\n");
	printf("                                                        4.返回上一层\n"); 
	printf("                                                        0.退出\n"); 
	printf("                                                       请输入相应的数字\n"); 
	printf("                                 ********************************************************\n");
}
*/

//显示菜单 
void showmenu1(HANDLE hOut ,char **menu1, int size , int index) ;
//获取用户输入 
int  get_userinput(int *index , int size) ;
char *menu1[] = 
{
	"1.成绩查询",
	"2.查询本班成绩", 
	"3.成绩分析",
	"4.返回上一层", 
 	"0.退出", 
};
void Anal(struct student *head,char a[],int b)//分析 a学生账号，b选择输出 
{
	int x=0;
	while(head&&strcmp(head->num,a))
	{head=head->next;x++;}
	if(head==NULL) printf("暂无你的信息！\n");
	if(b==1&&head!=NULL)  
	{
		printf("排名\t姓名\t学号\t班级\t\t语文\t数学\t英语\t总分\t平均分\n");
		printf("%d\t",x); 
		printf("%s\t",head->name);
		printf("%s\t%s\t",head->num,head->classes);
		printf("%s\t%s\t%s\t",head->score[0],head->score[1],head->score[2]);
		printf("%.1lf\t%.1lf\n",head->sum,head->aver);
	}
	if(b==2&&head!=NULL)
	{
		printf("%s同学,你在你们班排名：No.%d\n",head->name,x);
		printf("你的成绩分析如下：\n");
		printf("你们班语文平均分%.1lf,你语文分数为%s\n",Aver1,head->score[0]);
		printf("你们班数学平均分%.1lf,你数学分数为%s\n",Aver2,head->score[1]);
		printf("你们班英语平均分%.1lf,你英语分数为%s\n",Aver3,head->score[2]);
		printf("你们班三科平均分%.1lf,你的三科平均分为%.1lf\n",Aver4,head->aver);	
	}		
}
/* 
void Fstudent(struct student *head,char a[])
{
	
	char flag; 
	while(1)
	{
		system("cls");
		Show3();
		fflush(stdin);
		scanf("%c",&flag);
		switch(flag)
		{
			case '1':Sort(head,'1');Anal(head,a,1);break;
			case '2':output(head);break;
			case '3':Sort(head,'1');Anal(head,a,2);break; 
			case '4':return;break; 
			case '0':exit(0);break;
			default :printf("输入有误请重新输入\n");break; 
		}
		printf("按任意键进行下一步操作\n");
		getch();
	}
} 
*/
/*
//定义要显示的菜单 
char *menu[] = 
{
	"1.成绩查询",
	"2.查询本班成绩", 
	"3.成绩分析",
	"4.返回上一层", 
 	"0.退出", 
};
*/

//定义结构体
CONSOLE_CURSOR_INFO cci; 
//定义默认的坐标位置  	
COORD pos1 = {0,0};
//显示菜单 
void showmenu1(HANDLE hOut ,char **menu , int size , int index) ;
//获取用户输入 
int  get_userinput(int *index , int size) ;

void Fstudent(struct student *head,char a[])
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
    	showmenu1(hOut , menu1, NR(menu1) , index);
	ret = get_userinput(&index , NR(menu1));
	if(ret == ESC)
	break ;
	if(ret == ENTER)
	{
	       switch(index)
	       {
  		        case 0:Sort(head,'1');Anal(head,a,1);break;
			case 1:output(head);break;
			case 2:Sort(head,'1');Anal(head,a,2);break; 
			case 3:return;break; 
			case 4:exit(0);break;	
	       }
	       	printf("按任意键进行下一步操作\n");
		getch();
	}
	
    }
}

void showmenu1(HANDLE hOut ,char **menu1 , int size , int index)
{
	int i ; 	
	//设置显示的文本的颜色 
	SetConsoleTextAttribute(hOut, FOREGROUND_RED|FOREGROUND_GREEN|0x8); 
	//初始化控制台显示的X,Y轴的坐标 
	pos1.X = 32;
	pos1.Y = 3 ;
	//设置显示到控制台终端的具体位置 
	SetConsoleCursorPosition(hOut,pos1);    
	//调用printf在控制台对应的位置上输出 
	printf("%s",TITLE);
	pos1.X = 53;
	pos1.Y = 4 ;
	SetConsoleCursorPosition(hOut,pos1);   
	printf("%s",NAME);
	for(i = 0 ; i < size ; i++)
	{
		//如果i==index表示在当前选项的位置，默认初始化显示是第一项，显示为红色，
		//当按下上下按键选择的时候，光标会移动，也就看到了列表选择的现象 
		if(i == index)
		{
			//红色 
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | 0x8); 
			pos1.X = 50;
    		pos1.Y = 5+i;
    		//设置光标坐标
    		SetConsoleCursorPosition(hOut,pos1);    
    		printf("%s",menu1[i]);
		}
		//否则显示为白色 
		else
		{
			//白色 
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
			pos1.X = 50;
    		pos1.Y = 5+i;
    		//设置光标坐标
    		SetConsoleCursorPosition(hOut,pos1);    //设置光标坐标
    		printf("%s",menu1[i]);
		}
	}
	printf("\n");
	SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY); 
	printf("                                *************************************************\n");
	//刷新标准输出缓冲区 
	fflush(stdout);
}

//获取用户输入的接口 
/*
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
		//ESC6
		case ESC: return ESC ;
	} 
} 
*/
