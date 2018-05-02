
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <conio.h>
#include <time.h> 
#define F_TEMP "temp.txt"//��Ϣ�����ļ�
#define F_Cipher_S "cipher_S"//ѧ���ʺ����뱣���ļ�
#define F_Cipher_T "cipher_T" //��ʦ���뱣���ļ�
#define F_Cipher_A "cipher_A" //����Ա���뱣���ļ� 
#define F_Cipher_SM "cipher_SM"//ѧ��������Կ
#define F_Cipher_TM "cipher_TM" //��ʦ������Կ�����ļ�
#define F_Cipher_AM "cipher_AM" //����Ա������Կ�����ļ�  
#define Fbacklog "Fbacklog.txt"//����Ա����������ļ� 
struct student
{
	int No; //���� 
	char name[20];//���� 
	char num[20];//ѧ�� 
	char classes[20];//�༶ 
	char score[3][10];//���� 
	double aver;//ƽ����
	struct student *next;//ָ���� 
}; 
struct cipher
{
	char account[30];
	char password[30];
}cip[50];
int iCound;
double Aver1,Aver2,Aver3,Aver4; 


void Show1();
struct student *Finput();//�ļ�¼�� 
void Input_1(struct student *pNew);//����ڵ��ֵ 
struct student *Input();//�ֶ�����
void Foutput(struct student *pHead);//�ļ�¼��
struct student *Write_Foutput();//��������д���ļ���
void Pass_Foutput(char Fflag1,char Fflag2);//����д���ĵ��� 
void Cip_input(char Fflag,char a);//��Կ�����ȡ ��� 
void Validate(char a);//��֤
void Landing(char a);//��¼
void Cip_Increase(char Fflag);//��������
void Cip_Strike_out(char Fflag);//ɾ������
void Cip_Chang(char Fflag);//�޸����� 
void Cip_Inquiry(char Fflag);//�������� 
void Output_t(struct student *pHead);//���
void Increase(struct student *pHead);//���� 
void Strike_out(struct student *pHead);//ɾ��
void Chang(struct student *pHead);//�޸�
void Inquiry(struct student *pHead); //��ѯ
void Sort(struct student *pHead,char a,int b); //���� a������������ b���������Ĳ��� 
void Analysis(struct student *pHead);//���ݷ��� 
void Output(struct student *pHead);//���
void Save_1(struct student *pHead);//�ļ�д�� 
void Save(struct student *pHead);//�ļ�����
void Backlog(char a);//���������д�� 
void Open_Backlog();//�򿪴�������
void Sign_up();//ע�� 
void Revise_password();//�޸�����
void Find_password();//�һ�����
void Appeal();//�ɼ�����
void Remind();//���Ѹ��³ɼ���
void Anal(struct student *pHead,char a[],int b);//���� 
void Fstudent(struct student *pHead,char a[]);//ѧ���� 
void Tanal_t(struct student *pHead);//�����ɼ�
void Show4();
void Tanal(struct student *pHead);
void Teacher(struct student *pHead);//��ʦ�� 
void Show5();
void Choice_Cipher(char a);
void Administrator(struct student *pHead);


void Show1()
{	
	printf("          ******************ѧ����Ϣ����ϵͳ*************************\n");
	printf("                          1.ѧ����¼\n");
	printf("                          2.��ʦ��¼\n");
	printf("                          3.����Ա��¼\n");
	printf("                          4.ע���ʺ�\n");
	printf("                          5.�����޸�\n");
	printf("                          6.�����һ�\n"); 
	printf("                          0.�˳�\n"); 
	printf("                          ��������Ӧ������\n"); 
	printf("          ***********************************************************\n");	
} 
int main(void)
{
	struct student *pHead;
	char flag;	
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
			case '5':Revise_password();break;//�޸�����
			case '6':Find_password();break;//�һ����� 
			case '0':exit(0);break;
			default :printf("������������������\n");break; 
		}
		printf("�������������һ������\n");
		getch();
	}
}


struct student *Finput()//�ļ�¼�� 
{
	
	FILE *fp;
	struct student *pHead=NULL,*pEnd,*pNew;
	int sum=0,i,j,num;
	iCound=0;
	pEnd=pHead=(struct student *)malloc(sizeof(struct student));
	fp=fopen(F_TEMP,"rt");
	if(fp==NULL)
	{
		printf("���ܴ��ļ�");
		exit(1); 
	}
	while(1)
	{
		sum=0;
		pNew=(struct student *)malloc(sizeof(struct student));
		fscanf(fp,"%s %s %s",pNew->name,pNew->num,pNew->classes);
		fscanf(fp,"%s %s %s",pNew->score[0],pNew->score[1],pNew->score[2]); 
		for(i=0;i<3;i++)//����ɼ��Ż� 
		{	
			for(j=0,num=0;pNew->score[i][j];j++)
				num=num*10+pNew->score[i][j]-'0';	
			sum=sum+num;	
		}	
		pNew->aver=sum*1.0/3;
		if(feof(fp))
			break;
		pEnd->next=pNew;
		pEnd=pNew;
		iCound++;
	}
	pEnd->next=NULL;
	fclose(fp);
	return pHead;
}
void Input_1(struct student *pNew)//����ڵ��ֵ 
{
	int i,j,num,sum=0;
	char ch;
	fflush(stdin);
	printf("������������");
	gets(pNew->name);
	if(pNew->name[0]=='#')
		return; 
	printf("������ѧ�ţ�");
	gets(pNew->num);
	printf("������༶��");
	gets(pNew->classes);
	printf("���������ſεĳɼ���");	
	scanf("%s%s%s",pNew->score[0],pNew->score[1],pNew->score[2]);
	for(i=0;i<3;i++)//����ɼ��Ż� 
	{
		num=0;
		for(j=0;pNew->score[i][j];j++)
		{
			if(!isdigit(pNew->score[i][j]))
			{
				strcpy(pNew->score[i],"����!");
				sum=0;num=0;
				break;
			}		
			num=num*10+pNew->score[i][j]-'0';
		}		
		sum=sum+num;	
	}	
	pNew->aver=sum*1.0/3;
	printf("\n");
}
struct student *Input()//�ֶ����� 
{
	struct student *pHead=NULL,*pEnd,*pNew;
	iCound=0;
	pEnd=pHead=(struct student *)malloc(sizeof(struct student));
	pNew=(struct student *)malloc(sizeof(struct student));
	printf("��������#ʱ��ֹͣ����\n");
	Input_1(pNew);
	while(pNew->name[0]!='#')
	{
		iCound++;
		pEnd->next=pNew;
		pNew->next=NULL;
		pEnd=pNew;
		pNew=(struct student *)malloc(sizeof(struct student)); 
		Input_1(pNew);
	} 
	free(pNew);
	return pHead; 	
}
void Foutput(struct student *pHead)//�ļ�¼�� 
{
	struct student *pt=pHead; 
	FILE *fp;
	int sum=0,i,j,num;
	pt=pt->next;
	fp=fopen(F_TEMP,"wt+");
	if(fp==NULL)
	{
		printf("���ܴ��ļ�");
		exit(1); 
	}
	while(pt)
	{
		fprintf(fp,"%s %s %s ",pt->name,pt->num,pt->classes);
		fprintf(fp,"%s %s %s\n",pt->score[0],pt->score[1],pt->score[2]); 	
		pt=pt->next;
	}
	fclose(fp);
}
struct student *Write_Foutput()//��������д���ļ��� 
{
	struct student *pHead;
	char ch;
	printf("һ�����������ݵĸ��£�����ԭ���ݶ��ᶪʧ\n");
	printf("ȷ�����и��°�Y\n"); 
	fflush(stdin);
	scanf("%c",&ch); 
	if(ch=='Y'||ch=='y')	
	{	
		pHead=Input();
		Foutput(pHead);
		printf("���³ɹ�\n");
		Sleep(150);
		exit(1); 
	}
	return pHead;
}


static int Long=0;
void Pass_Foutput(char Fflag1,char Fflag2)//����д���ĵ��� 
{
	FILE *fp_1,*fp_2;
	char acc[30]={0},pass[30],key[30],ch;
	int i,j;
	Cip_input(Fflag1,'0');
	if(Fflag1=='1')
	{
		fp_1=fopen(F_Cipher_S,"wt+");
		fp_2=fopen(F_Cipher_SM,"wt+");
	}
	else if(Fflag1=='2')
	{
		fp_1=fopen(F_Cipher_T,"wt+");
		fp_2=fopen(F_Cipher_TM,"wt+");
	}
	else if(Fflag1=='3')
	{
		fp_1=fopen(F_Cipher_A,"wt+");
		fp_2=fopen(F_Cipher_AM,"wt+");
	}
	
	if(fp_1==NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		exit(0); 
	}
	if(fp_2==NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		exit(0); 
	}
	srand((unsigned)time(NULL));
	if(Fflag2=='1')
	{
		printf("һ�����������ݵĸ��£�����ԭ���ݶ��ᶪʧ\n");
		printf("�û�������#ֹͣ");
		printf("ȷ�����и�������Y\n");
		char ch;
		fflush(stdin);
		scanf("%c",&ch);
		fflush(stdin);
		if(ch=='y'||ch=='Y')
		{
			while(acc[0]!='#')
			{
				printf("�������û�����");
				gets(acc); 
				printf("���������룺");
				gets(pass);
				for(i=0;pass[i];i++)
				{
					key[i]=rand()%90+38;
					ch=key[i]^pass[i];
					if(isgraph(ch)==0)
						i--;
					else
						pass[i]=ch; 
				}
				key[i]=0;	
				fprintf(fp_1,"%s %s\n",acc,pass);
				fprintf(fp_2,"%s\n",key);
			}
		}
		else
			Fflag2='2';
			
	}
	if(Fflag2=='2')
	{
		for(i=0;i<Long;i++)
		{	
			for(j=0;cip[i].password[j];j++)
			{
				key[j]=rand()%90+38;
				ch=key[j]^cip[i].password[j];
				if(isgraph(ch)==0)
					j--;
				else
					cip[i].password[j]=ch; 
			}
			key[j]=0;	
			fprintf(fp_1,"%s %s\n",cip[i].account,cip[i].password);
			fprintf(fp_2,"%s\n",key);
		} 
	}


	fclose(fp_1);
	fclose(fp_2);	 
}
void Cip_input(char Fflag,char a)//��Կ�����ȡ ��� 
{
	FILE *fp_1,*fp_2;
	char key[30];
	Long=0;
	if(Fflag=='1')
	{
		fp_1=fopen(F_Cipher_S,"rt");
		fp_2=fopen(F_Cipher_SM,"rt");
	}
	else if(Fflag=='2')
	{
		fp_1=fopen(F_Cipher_T,"rt");
		fp_2=fopen(F_Cipher_TM,"rt");
	}
	else if(Fflag=='3')
	{
		fp_1=fopen(F_Cipher_A,"rt");
		fp_2=fopen(F_Cipher_AM,"rt");
	}
	if(fp_1==NULL||fp_2==NULL)//�������ļ�����Կ�ļ�������ṹ������ 
	{
		printf("�ļ���ʧ�ܣ�\n");
		exit(0); 
	}
	int j,i;
	while(!feof(fp_1))
	{
		fscanf(fp_1,"%s %s\n",cip[Long].account,cip[Long].password);
		fscanf(fp_2,"%s\n",key);
		for(i=0;cip[Long].password[i];i++)
			cip[Long].password[i]=cip[Long].password[i]^key[i];
		Long++; 
	}
	
	if(a=='1')
		for(i=0;i<Long;i++)
			printf("%s %s\n",cip[i].account,cip[i].password); 
	fclose(fp_1);
	fclose(fp_2);


} 
void Validate(char a)//��֤ 
{
	struct student *pHead;
	int order,j,i;
	char acc[30],pass[30],key[30],flag;
	i=0;
	do{                                    //�ҵ��ʺ��������е�λ�� 
 		printf("�������ʺţ�");
 		fflush(stdin);
		gets(acc);
		for(order=0;order<Long&&strcmp(acc,cip[order].account)!=0;order++)
			;
		if(order==Long)
			printf("�û������ڣ�����������\n");
		i++;
		if(i%4==0&&order==Long)
		{
			printf("�Ƿ񷵻���һ������ʺ����߻�ע��,��Y��������");
			scanf("%c",&flag);
			if(flag=='Y'||flag=='y')
				return;
		}	
				
	}while(order==Long);
	 
	 i=0; 
	 	//��֤����
	do{
		printf("���������룺");	
		for(j=0;pass[j-1]!=13;j++)
		{
			pass[j]=getch();
			if(pass[j]==8&&j>0)
				printf("\b \b",j-=2);		
			else if(j>=0)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
		pass[j-1]='\0';
		
		i++;
		if(i%4==0&&order==Long)
		{
			printf("�Ƿ񷵻���һ������ʺ����߻�ע��,��Y��������");
			scanf("%c",&flag);
			if(flag=='Y'||flag=='y')
				return;
		}	
	}while(strcmp(cip[order].password,pass)!=0);
	pHead=Finput();//���ļ��ж�ȡ���� 
	Analysis(pHead); 
	if(a=='1')//��ת���� 
		Fstudent(pHead,acc);			
	else if(a=='2')
		Teacher(pHead);
	else if(a=='3')
		Administrator(pHead);	 
}
void Landing(char a)//��¼
{
	system("cls"); 
	Cip_input(a,'0');//��Կ�����ȡ 
	Validate(a);//��֤ 	
}
void Cip_Increase(char Fflag)//�������� 
{
	Cip_input(Fflag,'0');
	printf("�������û���:");
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
	printf("������Ҫɾ���û�������:");
	scanf("%s",r.password);
		
	for(i=0;i<Long;i++)
		if(strcmp(cip[i].account,r.account)==0&&strcmp(cip[i].password,r.password)==0)
		{
			for(j=i;j<Long-1;j++)
				cip[j]=cip[j+1];
			Long--;
		}
	if(t==Long)
		printf("�û������������\n");
	else
		printf("ɾ���ɹ�\n"); 
	Pass_Foutput(Fflag,'2');
} 
void Cip_Chang(char Fflag)//�޸����� 
{
	struct cipher r,t;
	int i,j; 
	Cip_input(Fflag,'0');
	printf("������Ҫ�޸��û���:");
	scanf("%s",r.account);
	printf("������Ҫ�޸��û�������:");
	scanf("%s",r.password);
		
	for(i=0;i<Long;i++)
		if(strcmp(cip[i].account,r.account)==0&&strcmp(cip[i].password,r.password)==0)
		{
			printf("�������µĵ�����:");
			scanf("%s",cip[i].password);
			printf("�޸ĳɹ�\n");
		}
	Pass_Foutput(Fflag,'2');
}
void Cip_Inquiry(char Fflag)//�������� 
{
	struct cipher r,t;
	int i,j; 
	Cip_input(Fflag,'0');
	printf("������Ҫ�޸��û���:");
	scanf("%s",r.account);		
	for(i=0;i<Long;i++)
		if(strcmp(cip[i].account,r.account)==0)
			printf("�û�%s������Ϊ%s\n",cip[i].account,cip[i].password);
}




void Output_t(struct student *pHead)//��� 
{
	pHead=pHead->next;
	printf("������һ����%d��ѧ��\n",iCound);
	printf("����\t����\tѧ��\t�༶\t��Ŀһ\t��Ŀ��\t��Ŀ��\tƽ����\n");
	while(pHead!=NULL)
	{
		printf("No.%d\t",pHead->No);
		printf("%s\t%s\t%s\t",pHead->name,pHead->num,pHead->classes);
		printf("%s\t%s\t%s\t",pHead->score[0],pHead->score[1],pHead->score[2]);
		printf("%.1lf\n",pHead->aver);
		pHead=pHead->next;
	}
}
void Increase(struct student *pHead)//���� 
{
	char a[20];
	struct student *pNew;
	int flag=1;
	printf("�������������ѧ����(ѧ��)\n");
	scanf("%s",a);
	while(pHead->next&&strcmp(pHead->num,a)!=0)
		pHead=pHead->next;
	if(pHead->next==NULL&&strcmp(pHead->num,a)!=0)
	{
		printf("δ�ҵ����ˣ����Ҫ����β��������1\n");
		flag=0;
		scanf("%d",&flag); 
	}	
	if(flag==1)
	{
		pNew=(struct student *)malloc(sizeof(struct student)); 
		Input_1(pNew);
		pNew->next=pHead->next;
		pHead->next=pNew;
		iCound++;
	}		 
}
void Strike_out(struct student *pHead)//ɾ��
{
	char a[20];
	struct student *pHead_1=pHead;
	printf("����������ɾ��ѧ����ѧ��\n");
	scanf("%s",a);
	while(pHead&&strcmp(pHead->num,a))
	{
		pHead_1=pHead;
		pHead=pHead->next;
	}	
	if(pHead==NULL)
		printf("���޴��ˣ�\n");
	else
	{
		pHead_1->next=pHead->next;
		free(pHead);
		iCound--;
		printf("��ɾ����\n");
	}


}
void Chang(struct student *pHead)//�޸� 
{
	char a[20];
	printf("�����������޸�ѧ����ѧ��\n");
	scanf("%s",a);
	while(pHead&&strcmp(pHead->num,a))
		pHead=pHead->next;
	if(pHead==NULL)
		printf("δ�ҵ�����\n");	
	else 
		Input_1(pHead);	
}
void Inquiry(struct student *pHead) //��ѯ 
{
	char c[20];
	printf("�����������ѯѧ����ѧ��\n");
	scanf("%s",c);
	while(pHead&&strcmp(pHead->num,c))
		pHead=pHead->next;
	if(pHead==NULL)
		printf("δ�ҵ�����\n");	 
	else 
	{
		printf("����\t����\tѧ��\t�༶\t��Ŀһ\t��Ŀ��\t��Ŀ��\tƽ����\n");
		printf("%d\t",pHead->No); 
		printf("%s\t%s\t%s\t",pHead->name,pHead->num,pHead->classes);
		printf("%s\t%s\t%s\t",pHead->score[0],pHead->score[1],pHead->score[2]);
		printf("%.1lf\n",pHead->aver);
	}		
}
void Exchange(struct student *pj,struct student *pj_h,struct student *pj_1)//���� 
{
	struct student *pt;
	pt=pj->next;
	pj->next=pj_h->next;
	pj_h->next=pt;
				
	pt=pj_1->next;
	pj_1->next=pj_h->next;
	pj_h->next=pt;
}
void Sort(struct student *pHead,char a,int b) //���� a������������ b���������Ĳ��� 
{
	int i,j,flag;
	struct student *pj_1,*pj,*pj_h;
	for(i=0;i<iCound-1;i++)
		for(j=0,pj=pHead,flag=0;j<iCound-i-1;j++) 
		{
			if(flag==0)
			{
				pj_1=pj;
				pj=pj->next;
				pj_h=pj->next;
			}
			if(flag==1)
			{
				pj_1=pj_1->next;
				pj_h=pj->next;
			}	
			flag=0;
			if(a=='1'&&(pj->aver)<(pj_h->aver))
			{
				Exchange(pj,pj_h,pj_1);
				flag=1;	
			}
			else if(a=='2'&&strcmp(pj->num,pj_h->num)==1)	
			{
				Exchange(pj,pj_h,pj_1);
				flag=1;	
			}
			else if(a=='3'&&strcmp(pj->name,pj_h->name)==1)
			{
				Exchange(pj,pj_h,pj_1);
				flag=1;
			}
		}
	if(b==1)
		Output_t(pHead);
	if(b==2)
		Save_1(pHead);		
} 
void Analysis(struct student *pHead)//���ݷ��� 
{
	struct student *pt=pHead;
	Sort(pHead,'1',0); 
	int i=0,num1=0,num2=0,num3=0,num4=0,j,num;
	pt=pt->next;
	while(pt!=NULL)
	{
		i++;
		pt->No=i;	
		for(j=0,num=0;pt->score[0][j];j++)
				num=num*10+pt->score[0][j]-'0';		
		num1=num+num1;
		for(j=0,num=0;pt->score[1][j];j++)
				num=num*10+pt->score[1][j]-'0';
		num2=num+num2;
		for(j=0,num=0;pt->score[2][j];j++)
				num=num*10+pt->score[2][j]-'0';
		num3=num+num3;
		num4=pt->aver+num4;
		pt=pt->next;
	}
	Aver1=num1*1.0/i;
	Aver2=num2*1.0/i;
	Aver3=num3*1.0/i;
	Aver4=num4*1.0/i; 
	Sort(pHead,'2',0);
}


void Show4_1()
{
	printf("          ******************ѧ����Ϣ����ϵͳ*************************\n");
	printf("                               ѡ�������ʽ��\n");
	printf("                               1.���ɼ�ƽ���ִӸߵ���\n");
	printf("                               2.��ѧ��˳�����\n");
	printf("                               3.�������ֵ�˳�����\n");
	printf("                               4.������һ��\n");
	printf("                               0.�˳�\n");
	printf("                               ��������Ӧ������\n"); 
	printf("          ***********************************************************\n");
}
void Output(struct student *pHead)//��� 
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
			case '1':Sort(pHead,flag,1);break;//��ƽ������� 
			case '2':Sort(pHead,flag,1);break;//��ѧ����� 
			case '3':Sort(pHead,flag,1);break;//�������ֵ�˳����� 
			case '4':return;
			case '0':exit(0); 
			default :printf("������������������\n");break; 
		}
		printf("�������������һ������\n");
		getch();
	}
} 


void Show4_2()
{
	printf("          ******************ѧ����Ϣ����ϵͳ*************************\n");
	printf("                               ѡ�񱣴淽ʽ��\n");
	printf("                               1.���ɼ�ƽ���ִӸߵ���\n");
	printf("                               2.��ѧ��˳�򱣴�\n");
	printf("                               3.���������ֵ�˳�򱣴�\n");
	printf("                               4.������һ��\n");
	printf("                               0.�˳�\n");
	printf("                               ��������Ӧ������\n"); 
	printf("          ***********************************************************\n");
}
void Save_1(struct student *pHead)//�ļ�д�� 
{
	FILE *fp;
	char filename[100]; 
	char Hesder[8][20]={"����","����","ѧ��","�༶","��Ŀһ","��Ŀ��","��Ŀ��","ƽ����"};
	printf("�������ļ�·�����ļ�����"); 
	fflush(stdin);
	gets(filename); 
	fp=fopen(filename,"wt");
	if(fp==NULL)
	{
		printf("���ܴ��ļ�");
		exit(1); 
	}
	pHead=pHead->next;
	fprintf(fp,"%s\t%s\t%s\t%s\t",Hesder[0],Hesder[1],Hesder[2],Hesder[3]);
	fprintf(fp,"%s\t%s\t%s\t%s\n",Hesder[4],Hesder[5],Hesder[6],Hesder[7]);
	while(pHead)
	{
		fprintf(fp,"%d\t%s\t%s\t%s\t",pHead->No,pHead->name,pHead->num,pHead->classes);
		fprintf(fp,"%s\t%s\t%s\t%lf\n",pHead->score[0],pHead->score[1],pHead->score[2],pHead->aver);
		pHead=pHead->next;
	}
	fclose(fp);
}
void Save(struct student *pHead)//�ļ����� 
{
	char flag; 
	while(1)
	{
		system("cls");
		Show4_2();
		fflush(stdin);
		scanf("%c",&flag);
		switch(flag)
		{
			case '1':Sort(pHead,flag,2);break;//��ƽ������� 
			case '2':Sort(pHead,flag,2);break;//��ѧ����� 
			case '3':Sort(pHead,flag,2);break;//�������ֵ�˳����� 
			case '4':return;
			case '0':exit(0); 
			default :printf("������������������\n");break; 
		}
		printf("�������������һ������\n");
		getch();
	}
} 


void Backlog(char a)//���������д�� 
{
	FILE *fp;
	char str[5][20]={"����ע��:","�����޸�:","�����һ�:","�ɼ�����:","�ɼ�����:"}; 
	char Tstr[300],str_t[20],ch1[2]={32,0},ch2[2]={'\n',0};
	fflush(stdin);
	fp=fopen(Fbacklog,"at+");
	if(fp==NULL)
 	{
		printf("�ļ���ʧ��\n");
		exit(1);		
 	}
 	strcpy(Tstr,str[a-'1']);
 	if(a!='5') 
	{	
		printf("������������");
		gets(str_t);
		strcat(Tstr,ch1);
		strcat(Tstr,str_t);
		printf("������ѧ�ţ�");
		gets(str_t);
		strcat(Tstr,ch1);
		strcat(Tstr,str_t);
		printf("������༶��");
		gets(str_t);
		strcat(Tstr,ch1);
		strcat(Tstr,str_t);
		if(a=='1') 
		{
			printf("���������룺");
			gets(str_t);
			strcat(Tstr,ch1);
			strcat(Tstr,str_t);
		
			printf("���ظ��������룺");
			gets(str_t);
			strcat(Tstr,ch1);
			strcat(Tstr,str_t);
		}
		if(a=='2') 
		{
			printf("������ԭ���룺");
			gets(str_t);
			strcat(Tstr,ch1);
			strcat(Tstr,str_t);
		
			printf("�������޸ĺ����룺");
			gets(str_t);
			strcat(Tstr,ch1);
			strcat(Tstr,str_t);
		}
		if(a=='4') 
		{
			printf("���������룺");
			gets(str_t);
			strcat(Tstr,ch1);
			strcat(Tstr,str_t);
		}
		printf("�������ֻ��ţ�");
		gets(str_t);
		strcat(Tstr,ch1);
		strcat(Tstr,str_t); 
	}
	strcat(Tstr,ch2);
	fputs(Tstr,fp);
	fclose(fp); 
}
void Open_Backlog()//�򿪴������� 
{
	FILE *fp;
	char Tstr[700];
	fp=fopen(Fbacklog,"rt+");
	if(fp==NULL)
 	{
		printf("�ļ���ʧ��\n");
		exit(1);		
 	}
	fread(Tstr,700,1,fp);	
	fclose(fp);
	puts(Tstr);
}
void Sign_up()//ע�� 
{
	char ch;
	printf("�Ƿ�ȷ��Ҫ��������ע�ᣬȷ����Y\n");
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='Y'||ch=='y')
		Backlog('1');
	else
		return ;
	printf("�ѳɹ����ѹ���Ա,ע��ɹ���ᷢ���ŵ������ֻ���\n");
	printf("��0�˳�������������һ��\n");
	scanf("%c",&ch);
	if(ch==0)
		exit(1);
	return ; 
}
void Revise_password()//�޸�����
{
	char ch;
	printf("�Ƿ�ȷ��Ҫ���������޸ģ�ȷ����Y\n");
	fflush(stdin);
	scanf("%c",&ch); 
	if(ch=='Y'||ch=='y')
		Backlog('2');
	else
		return ;
	printf("�ѳɹ����ѹ���Ա,�޸ĳɹ���ᷢ�Ͷ��ŵ������ֻ���\n"); 
	printf("��0�˳�������������һ��\n");
	scanf("%c",&ch);
	if(ch==0)
		exit(1);
	return ; 
}
void Find_password()//�һ�����
{
	char ch;
	printf("�Ƿ�ȷ��Ҫ���������һأ�ȷ����Y\n"); 
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='Y'||ch=='y')
		Backlog('3');
	else
		return ;
	printf("�ѳɹ����ѹ���Ա,������뷢���ŵ������ֻ���\n");  
	printf("��0�˳�������������һ��\n");
	scanf("%c",&ch);
	if(ch==0)
		exit(1);	 
}
void Appeal()//�ɼ�����
{
	char ch;
	printf("�Ƿ�ȷ��Ҫ���гɼ����ߣ�ȷ����Y\n");
	fflush(stdin); 
	scanf("%c",&ch);
	if(ch=='Y'||ch=='y')
		Backlog('4');
	else
		return ;
	printf("�ѳɹ����ѹ���Ա,����Ա����޸ĳɹ������ŵ������ֻ���\n");  
	printf("��0�˳�������������һ��\n");
	scanf("%c",&ch);
	if(ch==0)
		exit(1);
	return ; 
} 
void Remind()//���Ѹ��³ɼ���
{
	char ch;
	printf("�Ƿ�ȷ��Ҫ���и���ɼ������ѣ�ȷ����Y\n");
	fflush(stdin);
	scanf("%c",&ch); 
	if(ch=='Y'||ch=='y')
		Backlog('5');
	else
		return ;
	printf("�ѳɹ����ѹ���Ա\n");  
	printf("��0�˳�������������һ��\n");
	scanf("%c",&ch);
	if(ch==0)
		exit(1);
	return ;
} 
 
 
void Show3()
{
	printf("          **********************ѧ����Ϣ����ϵͳ********************\n");
	printf("                                ѧ����\n");
	printf("                              1.�ɼ���ѯ\n");
	printf("                              2.��ѯ����ɼ�\n");
	printf("                              3.�ɼ�����\n");
	printf("                              4.�ɼ�����\n");
	printf("                              5.������һ��\n"); 
	printf("                              0.�˳�\n"); 
	printf("                              ��������Ӧ������\n"); 
	printf("          ********************************************************\n");
}
void Anal(struct student *pHead,char a[],int b)//���� 
{
	while(pHead&&strcmp(pHead->num,a))
		pHead=pHead->next;
	if(b==1) 
	{
		printf("����\t����\tѧ��\t�༶\t��Ŀһ\t��Ŀ��\t��Ŀ��\tƽ����\n");
		printf("%d\t",pHead->No); 
		printf("%s\t%s\t%s\t",pHead->name,pHead->num,pHead->classes);
		printf("%s\t%s\t%s\t",pHead->score[0],pHead->score[1],pHead->score[2]);
		printf("%.1lf\n",pHead->aver);
	}
	else
	{
		printf("%sͬѧ,�������ǰ�����%d\n",pHead->name,pHead->No);
		printf("���ǰ��Ŀһƽ����%.1lf,���Ŀһ����Ϊ%s\n",Aver1,pHead->score[0]);
		printf("���ǰ��Ŀ��ƽ����%.1lf,���Ŀ������Ϊ%s\n",Aver2,pHead->score[1]);
		printf("���ǰ��Ŀ��ƽ����%.1lf,���Ŀ������Ϊ%s\n",Aver3,pHead->score[2]);
		printf("���ǰ�����ƽ����%.1lf,�������ƽ����Ϊ%.1lf\n",Aver4,pHead->aver);	
	}		
}
void Fstudent(struct student *pHead,char a[])
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
			case '1':Anal(pHead,a,1);break;
			case '2':Output_t(pHead);break;
			case '3':Anal(pHead,a,2);break; 
			case '4':Appeal();break;
			case '5':return;break; 
			case '0':exit(0);break;
			default :printf("������������������\n");break; 
		}
		printf("�������������һ������\n");
		getch();
	}
}


static int T_max[4]={0};
static int T_min[4]={0};
static int T_num1[4]={0};
void Tanal_t(struct student *pHead)//�����ɼ�
{
	int num,i,j;
	pHead=pHead->next;
	for(i=0;i<3;i++)
	{
		num=0;
		for(j=0,num=0;pHead->score[i][j];j++)
			num=num*10+pHead->score[i][j]-'0';
		T_min[i]=num;	
	}
	T_min[3]=pHead->aver;
	while(pHead!=NULL)
	{
		for(i=0;i<3;i++)
		{
			num=0;
			for(j=0,num=0;pHead->score[i][j];j++)
				num=num*10+pHead->score[i][j]-'0';
			if(num>T_max[i])
				T_max[i]=num;
			if(num<T_min[i])
				T_min[i]=num;	
		}
		if(pHead->aver>90)
			T_num1[0]++;
		else if(pHead->aver>70)
			T_num1[1]++;
		else if(pHead->aver>60)
			T_num1[2]++;
		else 
			T_num1[3]++;
		if(pHead->aver>T_max[3])
			T_max[3]=pHead->aver;
		if(pHead->aver<T_min[3])
			T_min[3]=pHead->aver;
	pHead=pHead->next;			
	}
}
void Show4()
{
	printf("          ******************ѧ����Ϣ����ϵͳ*************************\n");
	printf("                             ��ʦ��\n");	
	printf("          1.�����µ�ѧ����Ϣ             2.ɾ��ѧ����Ϣ\n");
	printf("          3.�޸�ѧ����Ϣ                 4.��ѯѧ����Ϣ\n");
	printf("          5.�������ɼ�                 6.���ص��ļ���\n");
	printf("          7.�ɼ�����                     8.���ѹ���Ա���гɼ��ĸ���\n"); 
	printf("          9.������һ��                   0.�˳�\n");
	printf("          ��������Ӧ������\n"); 
	printf("          ***********************************************************\n");
}


void Tanal(struct student *pHead)
{	
	Tanal_t(pHead);
	printf("ƽ����%.1lf\n",Aver4);
	printf("ƽ�������%d,���%d\n",T_max[3],T_min[3]);
	printf("��Ŀһ��߷�%d����ͷ�%d\n",T_max[0],T_min[0]);
	printf("��Ŀ����߷�%d����ͷ�%d\n",T_max[1],T_min[1]);
	printf("��Ŀ����߷�%d����ͷ�%d\n",T_max[2],T_min[2]);
	printf("ƽ������90~100��%d��\n",T_num1[0]);
	printf("ƽ������70~90��%d��\n",T_num1[1]); 
	printf("ƽ������60~70��%d��\n",T_num1[2]);
	printf("ƽ������60��������%d��\n",T_num1[3]); 
} 
void Teacher(struct student *pHead)
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
			case '1':Increase(pHead);Foutput(pHead);break;
			case '2':Strike_out(pHead);Foutput(pHead);break;
			case '3':Chang(pHead);Foutput(pHead);break; 
			case '4':Inquiry(pHead);Foutput(pHead);break;
			case '5':Output(pHead);break;
			case '6':Save(pHead);break;
			case '7':Tanal(pHead);break; 
			case '8':Remind();break;
			case '9':return; 
			case '0':exit(0);break;
			default :printf("������������������\n");break; 
		}
		printf("�������������һ������\n");
		getch();
	}
}


void Show5()
{
	printf("          ******************ѧ����Ϣ����ϵͳ*************************\n");
	printf("                             ����Ա��\n"); 
	printf("          1.�鿴����ѡ��                           2.�����ʦ�˽�����Ϣ�޸�\n");
	printf("          3.�����ʺż�����                         4.ɾ���ʺż�����\n");
	printf("          5.�޸��ʺż�����                         6.�����ʺż�����\n");
	printf("          7.¼�������ʺż�����                     8.��������ʺż�����\n");
	printf("          9.�ֶ�����¼��ѧ����Ϣ                   a.������һ��\n");
	printf("                             0.�˳�\n");
	printf("          ***********************************************************\n");
} 
void Choice_Cipher(char a)
{
	char ch;
	printf("��1����ѧ���ʺŹ���\n");
	printf("��2�����ʦ�ʺŹ���\n");
	printf("��3�������Ա�ʺŹ���\n");
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
void Administrator(struct student *pHead)
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
			case '2':Teacher(pHead);break;
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

