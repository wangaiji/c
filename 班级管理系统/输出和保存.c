#include "record.h" 
#define TITLE "******************�༶����ϵͳ*******************"
#define NAME "ѡ�������ʽ��"
#define NR(x) (sizeof(x)/sizeof(x[0]+0))
void Show4_1()
{
	printf("                                 ******************ѧ����Ϣ����ϵͳ*************************\n");
	printf("                                                   ѡ�������ʽ��\n");
	printf("                                                  1.���ܳɼ��Ӹߵ������\n");
	printf("                                                  2.��ѧ��˳�����\n");
	printf("                                                  3.�����ĳɼ��Ӹߵ������\n");
	printf("                                                  4.����ѧ�ɼ��Ӹߵ������\n");
	printf("                                                  5.��Ӣ��ɼ��Ӹߵ������\n");
	printf("                                                  6.������һ��\n");
	printf("                                                  0.�˳�\n");
	printf("                                                 ��������Ӧ������\n"); 
	printf("                                 ***********************************************************\n");
}
//��ʾ�˵� 
void showmenu2(HANDLE hOut ,char **menu2, int size , int index) ;
//��ȡ�û����� 
int  get_userinput(int *index , int size) ;
char *menu2[] = 
{
	"1.���ܳɼ��Ӹߵ������",
	"2.��ѧ��˳�����",
	"3.�����ĳɼ��Ӹߵ������",
	"4.����ѧ�ɼ��Ӹߵ������",
	"5.��Ӣ��ɼ��Ӹߵ������",
	"6.������һ��",
	"0.�˳�",
};
/*
void output(struct student *head)//��� 
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
			case '1':Sort(head,flag);print(head);break;//��ƽ������� 
			case '2':Sort(head,flag);print(head);break;//��ѧ����� 
			case '3':Sort(head,flag);print(head);break; //���� 
			case '4':Sort(head,flag);print(head);break; //��ѧ 
			case '5':Sort(head,flag);print(head);break; //Ӣ�� 
			case '6':return;
			case '0':exit(0); 
			default :printf("������������������\n");break; 
		}
		printf("�������������һ������\n");
		getch();
	} 
}*/
//����ṹ��
CONSOLE_CURSOR_INFO cci; 
//����Ĭ�ϵ�����λ��  	
COORD pos2 = {0,0};
//��ʾ�˵� 
void showmenu2(HANDLE hOut ,char **menu2 , int size , int index) ;
//��ȡ�û����� 
int  get_userinput(int *index , int size) ;

void output(struct student *head)//��� 
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
    	showmenu2(hOut , menu2, NR(menu2) , index);
	ret = get_userinput(&index , NR(menu2));
	if(ret == ESC)
	break ;
	if(ret == ENTER)
	{
	       switch(index)
	       {
  		        case 0:Sort(head,'1');print(head);break;//��ƽ������� 
			case 1:Sort(head,'2');print(head);break;//��ѧ����� 
			case 2:Sort(head,'3');print(head);break; //���� 
			case 3:Sort(head,'4');print(head);break; //��ѧ 
			case 4:Sort(head,'5');print(head);break; //Ӣ�� 
			case 5:return;break;
			case 6:exit(0); break;  	
	       }
	       	printf("�������������һ������\n");
		getch();
	}
	
    }
}

void showmenu2(HANDLE hOut ,char **menu2 , int size , int index)
{
	int i ; 	
	//������ʾ���ı�����ɫ 
	SetConsoleTextAttribute(hOut, FOREGROUND_RED|FOREGROUND_GREEN|0x8); 
	//��ʼ������̨��ʾ��X,Y������� 
	pos2.X = 32;
	pos2.Y = 3 ;
	//������ʾ������̨�ն˵ľ���λ�� 
	SetConsoleCursorPosition(hOut,pos2);    
	//����printf�ڿ���̨��Ӧ��λ������� 
	printf("%s",TITLE);
	pos2.X = 50;
	pos2.Y = 4 ;
	SetConsoleCursorPosition(hOut,pos2);   
	printf("%s",NAME);
	for(i = 0 ; i < size ; i++)
	{
		//���i==index��ʾ�ڵ�ǰѡ���λ�ã�Ĭ�ϳ�ʼ����ʾ�ǵ�һ���ʾΪ��ɫ��
		//���������°���ѡ���ʱ�򣬹����ƶ���Ҳ�Ϳ������б�ѡ������� 
		if(i == index)
		{
			//��ɫ 
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | 0x8); 
			pos2.X = 50;
    		pos2.Y = 5+i;
    		//���ù������
    		SetConsoleCursorPosition(hOut,pos2);    
    		printf("%s",menu2[i]);
		}
		//������ʾΪ��ɫ 
		else
		{
			//��ɫ 
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
			pos2.X = 50;
    		pos2.Y = 5+i;
    		//���ù������
    		SetConsoleCursorPosition(hOut,pos2);    //���ù������
    		printf("%s",menu2[i]);
		}
	}
	printf("\n");
	SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY); 
	printf("                                *************************************************\n");
	//ˢ�±�׼��������� 
	fflush(stdout);
}

