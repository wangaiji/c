#include "record.h"
#define TITLE "******************班级管理系统*******************"
#define NAME "管理员端"
#define NR(x) (sizeof(x)/sizeof(x[0]+0))
void Show5()
{
	printf("                                 ******************学生信息管理系统*************************\n");
	printf("                                                     管理员端\n"); 
	printf("                                 1.查看待处理的事项                       2.进入教师端进行信息修改\n");
	printf("                                 3.增加帐号及密码                         4.删除帐号及密码\n");
	printf("                                 5.修改帐号及密码                         6.查找帐号及密码\n");
	printf("                                 7.更新所有帐号及密码                     8.输出所有帐号及密码\n");
	printf("                                 9.重新录入学生信息                       a.返回上一层\n");
	printf("                                 0.退出\n");
	printf("                                 ***********************************************************\n");
} 
void Choice_Cipher(char a)
{
	char ch;
	printf("1--学生帐号--\n");
	printf("2--教师帐号--\n");
	printf("3--管理员帐号--\n");
	printf("按其他返回上一层\n"); 
	fflush(stdin);
	scanf("%c",&ch);
	if(ch!='1'&&ch!='2'&&ch!='3')			
		return;
	if(a=='3')
		Cip_Increase(ch); 
	else if(a=='4')
		Cip_Strike_out(ch);
	else if(a=='5')
		Cip_Chang(ch);
	else if(a=='6')
		Cip_Inquiry(ch);
	else if(a=='7')
		Pass_Foutput(ch,'1');
	else if(a=='8')
		Cip_input(ch,'1');
} 
//显示菜单 
void showmenu4(HANDLE hOut ,char **menu4, int size , int index) ;
//获取用户输入 
int  get_userinput(int *index , int size) ;
char *menu4[] = 
{
	"1.查看待处理的事项",                      
	"2.进入教师端进行信息修改",
	"3.增加帐号及密码",                       
	"4.删除帐号及密码",
	"5.修改帐号及密码",                         
	"6.查找帐号及密码",
	"7.更新所有帐号及密码",                     
	"8.输出所有帐号及密码",
	"9.重新录入学生信息",                       
	"10.返回上一层",
	"0.退出",
};
//定义结构体
CONSOLE_CURSOR_INFO cci; 
//定义默认的坐标位置  	
COORD pos4 = {0,0};
//显示菜单 
void showmenu1(HANDLE hOut ,char **menu , int size , int index) ;
//获取用户输入 
int  get_userinput(int *index , int size) ;

void Administrator(struct student *head)
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
    	showmenu4(hOut , menu4, NR(menu4) , index);
	ret = get_userinput(&index , NR(menu4));
	if(ret == ESC)
	break ;
	if(ret == ENTER)
	{
	       switch(index)
	       {
   	                case 0:Open_Backlog();break;
			case 1:Teacher(head);break;
			case 2:Choice_Cipher('3');break; 
			case 3:Choice_Cipher('4');break;
			case 4:Choice_Cipher('5');break;
			case 5:Choice_Cipher('6');break; 
			case 6:Choice_Cipher('7');break;
			case 7:Choice_Cipher('8');break;
			case 8:Write_Foutput();break;
			case 9:return;break;
			case 10:exit(0);break;     	
	       }
	       	printf("按任意键进行下一步操作\n");
		getch();
	}
	
    }
}

void showmenu4(HANDLE hOut ,char **menu4 , int size , int index)
{
	int i ; 	
	//设置显示的文本的颜色 
	SetConsoleTextAttribute(hOut, FOREGROUND_RED|FOREGROUND_GREEN|0x8); 
	//初始化控制台显示的X,Y轴的坐标 
	pos4.X = 32;
	pos4.Y = 3 ;
	//设置显示到控制台终端的具体位置 
	SetConsoleCursorPosition(hOut,pos4);    
	//调用printf在控制台对应的位置上输出 
	printf("%s",TITLE);
	pos4.X = 53;
	pos4.Y = 4 ;
	SetConsoleCursorPosition(hOut,pos4);   
	printf("%s",NAME);
	for(i = 0 ; i < size ; i++)
	{
		//如果i==index表示在当前选项的位置，默认初始化显示是第一项，显示为红色，
		//当按下上下按键选择的时候，光标会移动，也就看到了列表选择的现象 
		if(i == index)
		{
			//红色 
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | 0x8); 
			pos4.X = 50;
    		pos4.Y = 5+i;
    		//设置光标坐标
    		SetConsoleCursorPosition(hOut,pos4);    
    		printf("%s",menu4[i]);
		}
		//否则显示为白色 
		else
		{
			//白色 
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
			pos4.X = 50;
    		pos4.Y = 5+i;
    		//设置光标坐标
    		SetConsoleCursorPosition(hOut,pos4);    //设置光标坐标
    		printf("%s",menu4[i]);
		}
	}
	printf("\n");
	SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY); 
	printf("                                *************************************************\n");
	//刷新标准输出缓冲区 
	fflush(stdout);
}
/*
void Administrator(struct student *head)
{

	char flag; 
	while(1)
	{
		system("cls");
		Show5();
		fflush(stdin);
		scanf("%c",&flag);
		switch(flag)
		{
			case '1':Open_Backlog();break;
			case '2':Teacher(head);break;
			case '3':Choice_Cipher(flag);break; 
			case '4':Choice_Cipher(flag);break;
			case '5':Choice_Cipher(flag);break;
			case '6':Choice_Cipher(flag);break; 
			case '7':Choice_Cipher(flag);break;
			case '8':Choice_Cipher(flag);break;
			case '9':Write_Foutput();break;
			case 'a':return; 
			case '0':exit(0);break;
			default :printf("输入有误请重新输入\n");break; 
		}
		printf("按任意键进行下一步操作\n");
		getch();
	}
}
*/
