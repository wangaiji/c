#include "record.h"
#define TITLE "******************�༶����ϵͳ*******************"
#define NAME "ѧ����"
#define NR(x) (sizeof(x)/sizeof(x[0]+0))
/*
void Show3()
{
	printf("                                 **********************ѧ����Ϣ����ϵͳ********************\n");
	printf("                                                           ѧ����\n");
	printf("                                                        1.�ɼ���ѯ\n");
	printf("                                                        2.��ѯ����ɼ�\n");
	printf("                                                        3.�ɼ�����\n");
	printf("                                                        4.������һ��\n"); 
	printf("                                                        0.�˳�\n"); 
	printf("                                                       ��������Ӧ������\n"); 
	printf("                                 ********************************************************\n");
}
*/

//��ʾ�˵� 
void showmenu1(HANDLE hOut ,char **menu1, int size , int index) ;
//��ȡ�û����� 
int  get_userinput(int *index , int size) ;
char *menu1[] = 
{
	"1.�ɼ���ѯ",
	"2.��ѯ����ɼ�", 
	"3.�ɼ�����",
	"4.������һ��", 
 	"0.�˳�", 
};
void Anal(struct student *head,char a[],int b)//���� aѧ���˺ţ�bѡ����� 
{
	int x=0;
	while(head&&strcmp(head->num,a))
	{head=head->next;x++;}
	if(head==NULL) printf("���������Ϣ��\n");
	if(b==1&&head!=NULL)  
	{
		printf("����\t����\tѧ��\t�༶\t\t����\t��ѧ\tӢ��\t�ܷ�\tƽ����\n");
		printf("%d\t",x); 
		printf("%s\t",head->name);
		printf("%s\t%s\t",head->num,head->classes);
		printf("%s\t%s\t%s\t",head->score[0],head->score[1],head->score[2]);
		printf("%.1lf\t%.1lf\n",head->sum,head->aver);
	}
	if(b==2&&head!=NULL)
	{
		printf("%sͬѧ,�������ǰ�������No.%d\n",head->name,x);
		printf("��ĳɼ��������£�\n");
		printf("���ǰ�����ƽ����%.1lf,�����ķ���Ϊ%s\n",Aver1,head->score[0]);
		printf("���ǰ���ѧƽ����%.1lf,����ѧ����Ϊ%s\n",Aver2,head->score[1]);
		printf("���ǰ�Ӣ��ƽ����%.1lf,��Ӣ�����Ϊ%s\n",Aver3,head->score[2]);
		printf("���ǰ�����ƽ����%.1lf,�������ƽ����Ϊ%.1lf\n",Aver4,head->aver);	
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
			default :printf("������������������\n");break; 
		}
		printf("�������������һ������\n");
		getch();
	}
} 
*/
/*
//����Ҫ��ʾ�Ĳ˵� 
char *menu[] = 
{
	"1.�ɼ���ѯ",
	"2.��ѯ����ɼ�", 
	"3.�ɼ�����",
	"4.������һ��", 
 	"0.�˳�", 
};
*/

//����ṹ��
CONSOLE_CURSOR_INFO cci; 
//����Ĭ�ϵ�����λ��  	
COORD pos1 = {0,0};
//��ʾ�˵� 
void showmenu1(HANDLE hOut ,char **menu , int size , int index) ;
//��ȡ�û����� 
int  get_userinput(int *index , int size) ;

void Fstudent(struct student *head,char a[])
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
	       	printf("�������������һ������\n");
		getch();
	}
	
    }
}

void showmenu1(HANDLE hOut ,char **menu1 , int size , int index)
{
	int i ; 	
	//������ʾ���ı�����ɫ 
	SetConsoleTextAttribute(hOut, FOREGROUND_RED|FOREGROUND_GREEN|0x8); 
	//��ʼ������̨��ʾ��X,Y������� 
	pos1.X = 32;
	pos1.Y = 3 ;
	//������ʾ������̨�ն˵ľ���λ�� 
	SetConsoleCursorPosition(hOut,pos1);    
	//����printf�ڿ���̨��Ӧ��λ������� 
	printf("%s",TITLE);
	pos1.X = 53;
	pos1.Y = 4 ;
	SetConsoleCursorPosition(hOut,pos1);   
	printf("%s",NAME);
	for(i = 0 ; i < size ; i++)
	{
		//���i==index��ʾ�ڵ�ǰѡ���λ�ã�Ĭ�ϳ�ʼ����ʾ�ǵ�һ���ʾΪ��ɫ��
		//���������°���ѡ���ʱ�򣬹����ƶ���Ҳ�Ϳ������б�ѡ������� 
		if(i == index)
		{
			//��ɫ 
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | 0x8); 
			pos1.X = 50;
    		pos1.Y = 5+i;
    		//���ù������
    		SetConsoleCursorPosition(hOut,pos1);    
    		printf("%s",menu1[i]);
		}
		//������ʾΪ��ɫ 
		else
		{
			//��ɫ 
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
			pos1.X = 50;
    		pos1.Y = 5+i;
    		//���ù������
    		SetConsoleCursorPosition(hOut,pos1);    //���ù������
    		printf("%s",menu1[i]);
		}
	}
	printf("\n");
	SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY); 
	printf("                                *************************************************\n");
	//ˢ�±�׼��������� 
	fflush(stdout);
}

//��ȡ�û�����Ľӿ� 
/*
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
		//ESC6
		case ESC: return ESC ;
	} 
} 
*/
