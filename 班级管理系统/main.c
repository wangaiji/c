#include "record.h"
#define NR(x) (sizeof(x)/sizeof(x[0]+0))
#define TITLE "******************�༶����ϵͳ*******************"
void Show()
{
	HANDLE hOut;
	hOut=GetStdHandle(STD_OUTPUT_HANDLE);//��ÿ���̨��� 
	printf("\n\n\n");
	SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY); 
	printf("                                                    �����ʵ��ѧ\n");
	printf("                                                  ѧ���ɼ�����ϵͳ\n\n");
	printf("                                                    �汾�ţ�2.0\n"); 
	printf("\n\n\n\n\n\n");
	printf("                                                  �����ˣ�aijinova\n");
	printf("                                                  ʱ�䣺  2018��5��19��\n");
}
void Show1()
{	
        printf("                                              ��ӭ����༶����ϵͳ��\n");
	printf("                                 ******************�༶����ϵͳ*******************\n");
	printf("                                                   1.ѧ����¼\n");
	printf("                                                   2.��ʦ��¼\n");
	printf("                                                   3.����Ա��¼\n");
	printf("                                                   4.ע���ʺ�\n");
	printf("                                                   5.�����޸�\n");
	printf("                                                   6.�����һ�\n"); 
	printf("                                                   0.�˳�\n"); 
	printf("                                                 ��������Ӧ������\n"); 
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
			case '1':Landing(flag);break;//ѧ��
			case '2':Landing(flag);break;//��ʦ
			case '3':Landing(flag);break;//����Ա
			case '4':Sign_up();break;//ע��
			case '5':Correct_password();break;//�޸�
			case '6':Find_password();break;//�һ�
			case '0':exit(0);break;//�˳�
			default :printf("������������������\n");break; 
		}	
	}
}*/

//����Ҫ��ʾ�Ĳ˵� 
char *menu[] = 
{
	"1.ѧ����¼", 
	"2.��ʦ��¼",
	"3.����Ա��¼",
	"4.ע���ʺ�",
	"5.�����޸�",
	"6.�����һ�", 
	"0.�˳�",
};
//����ṹ��
CONSOLE_CURSOR_INFO cci; 
//����Ĭ�ϵ�����λ��  	
extern COORD pos = {0,0};
//��ʾ�˵� 
void showmenu(HANDLE hOut ,char **menu , int size , int index) ;
//��ȡ�û����� 
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
    //��ȡ��ǰ�ľ��---����Ϊ��׼������ 
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //��ȡ�����Ϣ
    GetConsoleCursorInfo(hOut, &cci); 
	//���ù���С   
    cci.dwSize = 1; 
	//���ù�겻�ɼ� FALSE   
    cci.bVisible =  0; 
    //����(Ӧ��)�����Ϣ
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
	       		    case 0:Landing('1');break;//ѧ��
			    case 1:Landing('2');break;//ѧ��       	
			    case 2:Landing('3');break;
			    case 3:Sign_up();break;//ע��	
			    case 4:Correct_password();break;//�޸� 	
			    case 5:Find_password();break;//�һ�
			    case 6:exit(0);break;//�˳�             
	       }
	}
    }
}

void showmenu(HANDLE hOut ,char **menu , int size , int index)
{
	int i ; 	
	//������ʾ���ı�����ɫ 
	SetConsoleTextAttribute(hOut, FOREGROUND_RED|FOREGROUND_GREEN|0x8); 
	//��ʼ������̨��ʾ��X,Y������� 
	pos.X = 32;
	pos.Y = 3 ;
	//������ʾ������̨�ն˵ľ���λ�� 
	SetConsoleCursorPosition(hOut,pos);    
	//����printf�ڿ���̨��Ӧ��λ������� 
	printf("%s",TITLE);
	//pos.X = 32;
//	pos.Y = 2 ;
	for(i = 0 ; i < size ; i++)
	{
		//���i==index��ʾ�ڵ�ǰѡ���λ�ã�Ĭ�ϳ�ʼ����ʾ�ǵ�һ���ʾΪ��ɫ��
		//���������°���ѡ���ʱ�򣬹����ƶ���Ҳ�Ϳ������б�ѡ������� 
		if(i == index)
		{
			//��ɫ 
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | 0x8); 
			pos.X = 50;
    		pos.Y = 5+i;
    		//���ù������
    		SetConsoleCursorPosition(hOut,pos);    
    		printf("%s",menu[i]);
		}
		//������ʾΪ��ɫ 
		else
		{
			//��ɫ 
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
			pos.X = 50;
    		pos.Y = 5+i;
    		//���ù������
    		SetConsoleCursorPosition(hOut,pos);    //���ù������
    		printf("%s",menu[i]);
		}
	}
	printf("\n");
	SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY); 
	printf("                                *************************************************\n");
	//ˢ�±�׼��������� 
	fflush(stdout);
}

//��ȡ�û�����Ľӿ� 
int  get_userinput(int *index , int size)
{
	int ch ;
	ch = getch();
	switch(ch)
	{
		//�� 
		//���ѡ���ϣ���ô��������ƶ� 
		case UP : if(*index > 0)  *index -= 1 ;  break; 
		//�� 
		//���ѡ���£���ô��������ƶ� 
		case DOWN :if(*index < size -1)  *index += 1 ;  break;
		//�� 
		case LEFT: 
		case 97:return 0 ;
		//�� 
		case RIGHT:return 0 ;
		//�س� 
		case ENTER: return ENTER ;
		//ESC
		case ESC: return ESC ;
	} 
} 

