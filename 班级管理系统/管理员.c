#include "record.h"
#define TITLE "******************�༶����ϵͳ*******************"
#define NAME "����Ա��"
#define NR(x) (sizeof(x)/sizeof(x[0]+0))
void Show5()
{
	printf("                                 ******************ѧ����Ϣ����ϵͳ*************************\n");
	printf("                                                     ����Ա��\n"); 
	printf("                                 1.�鿴�����������                       2.�����ʦ�˽�����Ϣ�޸�\n");
	printf("                                 3.�����ʺż�����                         4.ɾ���ʺż�����\n");
	printf("                                 5.�޸��ʺż�����                         6.�����ʺż�����\n");
	printf("                                 7.���������ʺż�����                     8.��������ʺż�����\n");
	printf("                                 9.����¼��ѧ����Ϣ                       a.������һ��\n");
	printf("                                 0.�˳�\n");
	printf("                                 ***********************************************************\n");
} 
void Choice_Cipher(char a)
{
	char ch;
	printf("1--ѧ���ʺ�--\n");
	printf("2--��ʦ�ʺ�--\n");
	printf("3--����Ա�ʺ�--\n");
	printf("������������һ��\n"); 
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
//��ʾ�˵� 
void showmenu4(HANDLE hOut ,char **menu4, int size , int index) ;
//��ȡ�û����� 
int  get_userinput(int *index , int size) ;
char *menu4[] = 
{
	"1.�鿴�����������",                      
	"2.�����ʦ�˽�����Ϣ�޸�",
	"3.�����ʺż�����",                       
	"4.ɾ���ʺż�����",
	"5.�޸��ʺż�����",                         
	"6.�����ʺż�����",
	"7.���������ʺż�����",                     
	"8.��������ʺż�����",
	"9.����¼��ѧ����Ϣ",                       
	"10.������һ��",
	"0.�˳�",
};
//����ṹ��
CONSOLE_CURSOR_INFO cci; 
//����Ĭ�ϵ�����λ��  	
COORD pos4 = {0,0};
//��ʾ�˵� 
void showmenu1(HANDLE hOut ,char **menu , int size , int index) ;
//��ȡ�û����� 
int  get_userinput(int *index , int size) ;

void Administrator(struct student *head)
{
   // system("cls");
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
	       	printf("�������������һ������\n");
		getch();
	}
	
    }
}

void showmenu4(HANDLE hOut ,char **menu4 , int size , int index)
{
	int i ; 	
	//������ʾ���ı�����ɫ 
	SetConsoleTextAttribute(hOut, FOREGROUND_RED|FOREGROUND_GREEN|0x8); 
	//��ʼ������̨��ʾ��X,Y������� 
	pos4.X = 32;
	pos4.Y = 3 ;
	//������ʾ������̨�ն˵ľ���λ�� 
	SetConsoleCursorPosition(hOut,pos4);    
	//����printf�ڿ���̨��Ӧ��λ������� 
	printf("%s",TITLE);
	pos4.X = 53;
	pos4.Y = 4 ;
	SetConsoleCursorPosition(hOut,pos4);   
	printf("%s",NAME);
	for(i = 0 ; i < size ; i++)
	{
		//���i==index��ʾ�ڵ�ǰѡ���λ�ã�Ĭ�ϳ�ʼ����ʾ�ǵ�һ���ʾΪ��ɫ��
		//���������°���ѡ���ʱ�򣬹����ƶ���Ҳ�Ϳ������б�ѡ������� 
		if(i == index)
		{
			//��ɫ 
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | 0x8); 
			pos4.X = 50;
    		pos4.Y = 5+i;
    		//���ù������
    		SetConsoleCursorPosition(hOut,pos4);    
    		printf("%s",menu4[i]);
		}
		//������ʾΪ��ɫ 
		else
		{
			//��ɫ 
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
			pos4.X = 50;
    		pos4.Y = 5+i;
    		//���ù������
    		SetConsoleCursorPosition(hOut,pos4);    //���ù������
    		printf("%s",menu4[i]);
		}
	}
	printf("\n");
	SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY); 
	printf("                                *************************************************\n");
	//ˢ�±�׼��������� 
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
			default :printf("������������������\n");break; 
		}
		printf("�������������һ������\n");
		getch();
	}
}
*/
