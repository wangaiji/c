#include "record.h"
#define TITLE "******************班级管理系统*******************"
#define NAME "教师端"
#define NR(x) (sizeof(x)/sizeof(x[0]+0))
static int T_max[4]={0};
static int T_min[4]={0};
static int T_num1[4]={0};
void Tanal_t(struct student *head)//分析成绩
{
	int num,i,j;
	head=head->next;
	for(i=0;i<3;i++)
	{
		num=0;
		for(j=0,num=0;head->score[i][j];j++)
			num=num*10+head->score[i][j]-'0';
		T_min[i]=num;	
	}
	T_min[3]=head->aver;
	while(head!=NULL)
	{
		for(i=0;i<3;i++)
		{
			num=0;
			for(j=0,num=0;head->score[i][j];j++)
				num=num*10+head->score[i][j]-'0';
			if(num>T_max[i])
				T_max[i]=num;
			if(num<T_min[i])
				T_min[i]=num;	
		}
		if(head->aver>90)
			T_num1[0]++;
		else if(head->aver>70)
			T_num1[1]++;
		else if(head->aver>60)
			T_num1[2]++;
		else 
			T_num1[3]++;
		if(head->aver>T_max[3])
			T_max[3]=head->aver;
		if(head->aver<T_min[3])
			T_min[3]=head->aver;
	head=head->next;			
	}
}
void Show4()
{
	printf("                                 ******************学生信息管理系统*************************\n");
	printf("                                                     教师端\n");	
	printf("                                 1.增加新的学生信息             2.删除学生信息\n");
	printf("                                 3.修改学生信息                 4.查询学生信息\n");
	printf("                                 5.输出本班成绩                 6.本班成绩分析\n");
	printf("                                 7.返回上一层\n"); 
	printf("                                 0.退出\n");
	printf("                                 请输入相应的数字\n"); 
	printf("                                 ***********************************************************\n");
}
//显示菜单 
void showmenu3(HANDLE hOut ,char **menu3, int size , int index) ;
//获取用户输入 
int  get_userinput(int *index , int size) ;
char *menu3[] = 
{
     "1.增加新的学生信息",            
     "2.删除学生信息",
     "3.修改学生信息",                 
     "4.查询学生信息",
     "5.输出本班成绩",                
     "6.本班成绩分析",
     "7.返回上一层",
     "0.退出", 
};
void Tanal(struct student *head)
{	
	Tanal_t(head);
	printf("你们班成绩分析如下：\n");
	printf("你们班平均分%.1lf\n",Aver4);
	printf("平均分最高:%d,最低:%d\n",T_max[3],T_min[3]);
	printf("语文最高分:%d，最低分:%d\n",T_max[0],T_min[0]);
	printf("数学最高分:%d，最低分:%d\n",T_max[1],T_min[1]);
	printf("英语最高分:%d，最低分:%d\n",T_max[2],T_min[2]);
	printf("平均分在90~100有:%d人\n",T_num1[0]);
	printf("平均分在70~90有:%d人\n",T_num1[1]); 
	printf("平均分在60~70有:%d人\n",T_num1[2]);
	printf("平均分在60分以下有:%d人\n",T_num1[3]); 
} 
//定义结构体
CONSOLE_CURSOR_INFO cci; 
//定义默认的坐标位置  	
COORD pos3 = {0,0};
//显示菜单 
void showmenu3(HANDLE hOut ,char **menu3 , int size , int index) ;
//获取用户输入 
int  get_userinput(int *index , int size) ;

void Teacher(struct student *head)
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
    	showmenu3(hOut , menu3, NR(menu3) , index);
	ret = get_userinput(&index , NR(menu3));
	if(ret == ESC)
	break ;
	if(ret == ENTER)
	{
	       switch(index)
	       {
  		        case 0:increase(head);Foutput(head);break;//Head=Finput();break;
			case 1:Delete(head);Foutput(head);break;
			case 2:print(head);change(head);Foutput(head);break;//Head=Finput();break; 
			case 3:inquiry(head);Foutput(head);break;
			case 4:output(head);break;
			case 5:Tanal(head);break; 
			case 6:return;break; 
			case 7:exit(0);break; 	
	       }
	       	printf("按任意键进行下一步操作\n");
		getch();
	}
	
    }
}

void showmenu3(HANDLE hOut ,char **menu3 , int size , int index)
{
	int i ; 	
	//设置显示的文本的颜色 
	SetConsoleTextAttribute(hOut, FOREGROUND_RED|FOREGROUND_GREEN|0x8); 
	//初始化控制台显示的X,Y轴的坐标 
	pos3.X = 32;
	pos3.Y = 3 ;
	//设置显示到控制台终端的具体位置 
	SetConsoleCursorPosition(hOut,pos3);    
	//调用printf在控制台对应的位置上输出 
	printf("%s",TITLE);
	pos3.X = 53;
	pos3.Y = 4 ;
	SetConsoleCursorPosition(hOut,pos3);   
	printf("%s",NAME);
	for(i = 0 ; i < size ; i++)
	{
		//如果i==index表示在当前选项的位置，默认初始化显示是第一项，显示为红色，
		//当按下上下按键选择的时候，光标会移动，也就看到了列表选择的现象 
		if(i == index)
		{
			//红色 
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | 0x8); 
			pos3.X = 50;
    		pos3.Y = 5+i;
    		//设置光标坐标
    		SetConsoleCursorPosition(hOut,pos3);    
    		printf("%s",menu3[i]);
		}
		//否则显示为白色 
		else
		{
			//白色 
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
			pos3.X = 50;
    		pos3.Y = 5+i;
    		//设置光标坐标
    		SetConsoleCursorPosition(hOut,pos3);    //设置光标坐标
    		printf("%s",menu3[i]);
		}
	}
	printf("\n");
	SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY); 
	printf("                                *************************************************\n");
	//刷新标准输出缓冲区 
	fflush(stdout);
}
/*
void Teacher(struct student *head)
{
	char flag; 
	while(1)
	{
		system("cls");
		Show4();
		fflush(stdin);
		scanf("%c",&flag);
		switch(flag)
		{
			case '1':increase(head);Foutput(head);break;//Head=Finput();break;
			case '2':Delete(head);Foutput(head);break;
			case '3':print(head);change(head);Foutput(head);break;//Head=Finput();break; 
			case '4':inquiry(head);Foutput(head);break;
			case '5':output(head);break;
			case '6':Tanal(head);break; 
			case '7':return; 
			case '0':exit(0);break;
			default :printf("输入有误请重新输入\n");break; 
		}
		printf("按任意键进行下一步操作\n");
		getch();
	}
}
 */
