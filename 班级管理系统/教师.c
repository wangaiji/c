#include "record.h"
#define TITLE "******************�༶����ϵͳ*******************"
#define NAME "��ʦ��"
#define NR(x) (sizeof(x)/sizeof(x[0]+0))
static int T_max[4]={0};
static int T_min[4]={0};
static int T_num1[4]={0};
void Tanal_t(struct student *head)//�����ɼ�
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
	printf("                                 ******************ѧ����Ϣ����ϵͳ*************************\n");
	printf("                                                     ��ʦ��\n");	
	printf("                                 1.�����µ�ѧ����Ϣ             2.ɾ��ѧ����Ϣ\n");
	printf("                                 3.�޸�ѧ����Ϣ                 4.��ѯѧ����Ϣ\n");
	printf("                                 5.�������ɼ�                 6.����ɼ�����\n");
	printf("                                 7.������һ��\n"); 
	printf("                                 0.�˳�\n");
	printf("                                 ��������Ӧ������\n"); 
	printf("                                 ***********************************************************\n");
}
//��ʾ�˵� 
void showmenu3(HANDLE hOut ,char **menu3, int size , int index) ;
//��ȡ�û����� 
int  get_userinput(int *index , int size) ;
char *menu3[] = 
{
     "1.�����µ�ѧ����Ϣ",            
     "2.ɾ��ѧ����Ϣ",
     "3.�޸�ѧ����Ϣ",                 
     "4.��ѯѧ����Ϣ",
     "5.�������ɼ�",                
     "6.����ɼ�����",
     "7.������һ��",
     "0.�˳�", 
};
void Tanal(struct student *head)
{	
	Tanal_t(head);
	printf("���ǰ�ɼ��������£�\n");
	printf("���ǰ�ƽ����%.1lf\n",Aver4);
	printf("ƽ�������:%d,���:%d\n",T_max[3],T_min[3]);
	printf("������߷�:%d����ͷ�:%d\n",T_max[0],T_min[0]);
	printf("��ѧ��߷�:%d����ͷ�:%d\n",T_max[1],T_min[1]);
	printf("Ӣ����߷�:%d����ͷ�:%d\n",T_max[2],T_min[2]);
	printf("ƽ������90~100��:%d��\n",T_num1[0]);
	printf("ƽ������70~90��:%d��\n",T_num1[1]); 
	printf("ƽ������60~70��:%d��\n",T_num1[2]);
	printf("ƽ������60��������:%d��\n",T_num1[3]); 
} 
//����ṹ��
CONSOLE_CURSOR_INFO cci; 
//����Ĭ�ϵ�����λ��  	
COORD pos3 = {0,0};
//��ʾ�˵� 
void showmenu3(HANDLE hOut ,char **menu3 , int size , int index) ;
//��ȡ�û����� 
int  get_userinput(int *index , int size) ;

void Teacher(struct student *head)
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
	       	printf("�������������һ������\n");
		getch();
	}
	
    }
}

void showmenu3(HANDLE hOut ,char **menu3 , int size , int index)
{
	int i ; 	
	//������ʾ���ı�����ɫ 
	SetConsoleTextAttribute(hOut, FOREGROUND_RED|FOREGROUND_GREEN|0x8); 
	//��ʼ������̨��ʾ��X,Y������� 
	pos3.X = 32;
	pos3.Y = 3 ;
	//������ʾ������̨�ն˵ľ���λ�� 
	SetConsoleCursorPosition(hOut,pos3);    
	//����printf�ڿ���̨��Ӧ��λ������� 
	printf("%s",TITLE);
	pos3.X = 53;
	pos3.Y = 4 ;
	SetConsoleCursorPosition(hOut,pos3);   
	printf("%s",NAME);
	for(i = 0 ; i < size ; i++)
	{
		//���i==index��ʾ�ڵ�ǰѡ���λ�ã�Ĭ�ϳ�ʼ����ʾ�ǵ�һ���ʾΪ��ɫ��
		//���������°���ѡ���ʱ�򣬹����ƶ���Ҳ�Ϳ������б�ѡ������� 
		if(i == index)
		{
			//��ɫ 
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | 0x8); 
			pos3.X = 50;
    		pos3.Y = 5+i;
    		//���ù������
    		SetConsoleCursorPosition(hOut,pos3);    
    		printf("%s",menu3[i]);
		}
		//������ʾΪ��ɫ 
		else
		{
			//��ɫ 
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
			pos3.X = 50;
    		pos3.Y = 5+i;
    		//���ù������
    		SetConsoleCursorPosition(hOut,pos3);    //���ù������
    		printf("%s",menu3[i]);
		}
	}
	printf("\n");
	SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY); 
	printf("                                *************************************************\n");
	//ˢ�±�׼��������� 
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
			default :printf("������������������\n");break; 
		}
		printf("�������������һ������\n");
		getch();
	}
}
 */
