#include "record.h"
static int Long=0;
//void Cip_input(char Fflag,char a);//Fflag-���ĸ��˵����� a-�Ƿ�Ҫ���
void Pass_Foutput(char Fflag1,char Fflag2)//����д���ĵ��� Fflag1-���ĸ��˵����� Fflag2-�ֶ����뻹�����������е�
{
	FILE *fp1;
	char acc[30]={0},pass[30],ch;
	int i,j;
	if(Fflag1=='1')
	{
		fp1=fopen("E://mimaS.txt","wt+");
	}
	else if(Fflag1=='2')
	{
		fp1=fopen("E://mimaT.txt","wt+");
	}
	else if(Fflag1=='3')
	{
		fp1=fopen("E://mimaA.txt","wt+");
	}
	
	if(fp1==NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		exit(0); 
	}
	
	srand((unsigned)time(NULL));
	if(Fflag2=='1')//�ֶ����� 
	{
		printf("��ʾ��");
		printf("һ�����������ݵĸ��£�����ԭ���ݶ��ᶪʧ\n");
		printf("�û�������#ֹͣ,");
		printf("ȷ�����и�������Y\n");
		char ch;
		fflush(stdin);
		scanf("%c",&ch);
		fflush(stdin);
		if(ch=='y'||ch=='Y')
		{
			while(1)
			{
				printf("�������û�����");
				gets(acc); 
				if(acc[0]=='#') break;
				printf("���������룺");
				gets(pass);
				fprintf(fp1,"%s %s\n",acc,pass);
			}
		}
		else
			Fflag2='2';
			
	}
	if(Fflag2=='2')
	{
		for(i=0;i<Long;i++)
		{	
			fprintf(fp1,"%s %s\n",cip[i].account,cip[i].password);
		} 
	}

	fclose(fp1);	 
}
void Cip_input(char Fflag,char a)//�����ȡ ��� 
{
	FILE *fp1; 
	Long=0;
	if(Fflag=='1')
	{
		fp1=fopen("E://mimaS.txt","rt");
	}
	else if(Fflag=='2')
	{
		fp1=fopen("E://mimaT.txt","rt");
	}
	else if(Fflag=='3')
	{
		fp1=fopen("E://mimaA.txt","rt");
	}
	if(fp1==NULL)//�������ļ�������ṹ������ 
	{
		printf("�ļ���ʧ�ܣ�\n");
		exit(0); 
	}
	int j,i;
	while(!feof(fp1))
	{
		fscanf(fp1,"%s %s\n",cip[Long].account,cip[Long].password);
		Long++; 
	}
	
	if(a=='1')
		for(i=0;i<Long;i++)
			printf("%s %s\n",cip[i].account,cip[i].password); 
	fclose(fp1);

} 
void Validate(char a)//��֤ 
{
	struct student *head;
	struct student *Head;
	int order,j,i;
	char acc[30],pass[30],flag;
	i=0;
        printf("\n\n\n\n\n\n\n\n\n\n\n"); 
       	HANDLE hOut;
	hOut=GetStdHandle(STD_OUTPUT_HANDLE);//��ÿ���̨��� 
	SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY); 
	do{     
 	//�ҵ��ʺ��������е�λ��                             
 		printf("                              �������ʺţ�");
 		fflush(stdin);
		gets(acc);
		for(order=0;order<Long&&strcmp(acc,cip[order].account)!=0;order++)
			;
		if(order==Long)
			printf("                              �û������ڣ�����������\n");
		i++;
		if(i%3==0&&order==Long)
		{
			printf("                              �Ƿ񷵻���һ������ʺ�ע��,�ǰ�Y��������\n");
			scanf("%c",&flag);
			if(flag=='Y'||flag=='y')
			return;
		}	
				
	}while(order==Long);
	 
        for(i=0;i<3;i++) 
    	{
		printf("                              ���������룺");	
		for(j=0;pass[j-1]!=13;j++)//�س���ascii��Ϊ13 
		{
			pass[j]=getch();
			if(pass[j]==8&&j>0)//ɾ����ascii��Ϊ8 
				printf("\b \b",j-=2);		
			else if(j>=0)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
		pass[j-1]='\0';
		if(strcmp(cip[order].password,pass)==0)
		break;
		else printf("                                 �����������!\n");
	}
    if(i==3)	
    {
	printf("                                              ������������Ƿ񷵻���һ����������һ�,��Y��������\n");
	scanf("%c",&flag);
	if(flag=='Y'||flag=='y')
	return;
    else exit(1);
    }
    
	printf("                              ���ڵ�¼");
	Sleep(1500);
	printf("...\n");
	Sleep(1500);
	printf("                              .......\n");
	Sleep(800);
	printf("                              ��½�ɹ���\n");
	Sleep(800);
	printf("                              ҳ�����ϼ��س���...\n");
	Sleep(1500); 
	
	head=Finput();//���ļ��ж�ȡ���� 
//	Head=Finput();
	Analysis(head); 
	if(a=='1')//��ת���� 
		Fstudent(head,acc);			
	else if(a=='2')
		Teacher(head);
	else if(a=='3')
		Administrator(head);	 
}
void Landing(char a)//��¼
{
	system("cls"); 
	Cip_input(a,'0');//�����ȡ 
	Validate(a);//��֤ 	
}
void Cip_Increase(char Fflag)//�������� 
{
	Cip_input(Fflag,'0');
	printf("�������ʺ�:");
	scanf("%s",cip[Long].account);
	printf("����������:");
	scanf("%s",cip[Long].password);
	Long++;	
	printf("���ӳɹ�\n");
	Pass_Foutput(Fflag,'2');
} 
void Cip_Strike_out(char Fflag)//ɾ������ 
{
	struct cipher r;
	int i,j,t=Long; 
	Cip_input(Fflag,'0');
	printf("������Ҫɾ���û���:");
	scanf("%s",r.account);
		
	for(i=0;i<Long;i++)
		if(strcmp(cip[i].account,r.account)==0) 
		{
			for(j=i;j<Long-1;j++)
				cip[j]=cip[j+1];
			Long--;
		}
	if(t==Long)
		printf("�û���������󣬲��޴��ˣ�\n");
	else
		printf("ɾ���ɹ���\n"); 
	Pass_Foutput(Fflag,'2');
} 
void Cip_Chang(char Fflag)//�޸����� 
{
	struct cipher r;
	int i,j; 
	Cip_input(Fflag,'0');
	printf("������Ҫ�޸��û���:");
	scanf("%s",r.account);
		
	for(i=0;i<Long;i++)
		if(strcmp(cip[i].account,r.account)==0) 
		{
			printf("�������µ�����:");
			scanf("%s",cip[i].password);
			printf("�޸ĳɹ���\n");
			break;
		}
	if(i==Long) printf("�û���������󣬲��޴��ˣ�\n"); 
	Pass_Foutput(Fflag,'2');
}
void Cip_Inquiry(char Fflag)//�������� 
{
	struct cipher r,t;
	int i,j; 
	Cip_input(Fflag,'0');
	printf("������Ҫ���ҵ��û���:");
	scanf("%s",r.account);		
	for(i=0;i<Long;i++)
		if(strcmp(cip[i].account,r.account)==0)
			printf("�ʺ�Ϊ%s������Ϊ��%s\n",cip[i].account,cip[i].password);
}
