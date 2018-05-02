
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <conio.h>
#include <time.h> 
#define F_TEMP "temp.txt"//信息读入文件
#define F_Cipher_S "cipher_S"//学生帐号密码保存文件
#define F_Cipher_T "cipher_T" //老师密码保存文件
#define F_Cipher_A "cipher_A" //管理员密码保存文件 
#define F_Cipher_SM "cipher_SM"//学生密码密钥
#define F_Cipher_TM "cipher_TM" //老师密码密钥保存文件
#define F_Cipher_AM "cipher_AM" //管理员密码密钥保存文件  
#define Fbacklog "Fbacklog.txt"//管理员代办事项保存文件 
struct student
{
	int No; //排名 
	char name[20];//姓名 
	char num[20];//学号 
	char classes[20];//班级 
	char score[3][10];//分数 
	double aver;//平均分
	struct student *next;//指针域 
}; 
struct cipher
{
	char account[30];
	char password[30];
}cip[50];
int iCound;
double Aver1,Aver2,Aver3,Aver4; 


void Show1();
struct student *Finput();//文件录入 
void Input_1(struct student *pNew);//输入节点的值 
struct student *Input();//手动输入
void Foutput(struct student *pHead);//文件录入
struct student *Write_Foutput();//创建链表并写入文件中
void Pass_Foutput(char Fflag1,char Fflag2);//密码写入文档中 
void Cip_input(char Fflag,char a);//密钥密码读取 输出 
void Validate(char a);//验证
void Landing(char a);//登录
void Cip_Increase(char Fflag);//增加密码
void Cip_Strike_out(char Fflag);//删除密码
void Cip_Chang(char Fflag);//修改密码 
void Cip_Inquiry(char Fflag);//查找密码 
void Output_t(struct student *pHead);//输出
void Increase(struct student *pHead);//增加 
void Strike_out(struct student *pHead);//删除
void Chang(struct student *pHead);//修改
void Inquiry(struct student *pHead); //查询
void Sort(struct student *pHead,char a,int b); //排序 a控制排序依据 b控制排序后的操作 
void Analysis(struct student *pHead);//数据分析 
void Output(struct student *pHead);//输出
void Save_1(struct student *pHead);//文件写入 
void Save(struct student *pHead);//文件保存
void Backlog(char a);//代办事项的写入 
void Open_Backlog();//打开代办事项
void Sign_up();//注册 
void Revise_password();//修改密码
void Find_password();//找回密码
void Appeal();//成绩申诉
void Remind();//提醒更新成绩库
void Anal(struct student *pHead,char a[],int b);//分析 
void Fstudent(struct student *pHead,char a[]);//学生端 
void Tanal_t(struct student *pHead);//分析成绩
void Show4();
void Tanal(struct student *pHead);
void Teacher(struct student *pHead);//教师端 
void Show5();
void Choice_Cipher(char a);
void Administrator(struct student *pHead);


void Show1()
{	
	printf("          ******************学生信息管理系统*************************\n");
	printf("                          1.学生登录\n");
	printf("                          2.教师登录\n");
	printf("                          3.管理员登录\n");
	printf("                          4.注册帐号\n");
	printf("                          5.密码修改\n");
	printf("                          6.密码找回\n"); 
	printf("                          0.退出\n"); 
	printf("                          请输入相应的数字\n"); 
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
			case '1':Landing(flag);break;//学生 
			case '2':Landing(flag);break;//教师 
			case '3':Landing(flag);break;//管理员 
			case '4':Sign_up();break;//注册 
			case '5':Revise_password();break;//修改密码
			case '6':Find_password();break;//找回密码 
			case '0':exit(0);break;
			default :printf("输入有误请重新输入\n");break; 
		}
		printf("按任意键进行下一步操作\n");
		getch();
	}
}


struct student *Finput()//文件录入 
{
	
	FILE *fp;
	struct student *pHead=NULL,*pEnd,*pNew;
	int sum=0,i,j,num;
	iCound=0;
	pEnd=pHead=(struct student *)malloc(sizeof(struct student));
	fp=fopen(F_TEMP,"rt");
	if(fp==NULL)
	{
		printf("不能打开文件");
		exit(1); 
	}
	while(1)
	{
		sum=0;
		pNew=(struct student *)malloc(sizeof(struct student));
		fscanf(fp,"%s %s %s",pNew->name,pNew->num,pNew->classes);
		fscanf(fp,"%s %s %s",pNew->score[0],pNew->score[1],pNew->score[2]); 
		for(i=0;i<3;i++)//输入成绩优化 
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
void Input_1(struct student *pNew)//输入节点的值 
{
	int i,j,num,sum=0;
	char ch;
	fflush(stdin);
	printf("请输入姓名：");
	gets(pNew->name);
	if(pNew->name[0]=='#')
		return; 
	printf("请输入学号：");
	gets(pNew->num);
	printf("请输入班级：");
	gets(pNew->classes);
	printf("请输入三门课的成绩：");	
	scanf("%s%s%s",pNew->score[0],pNew->score[1],pNew->score[2]);
	for(i=0;i<3;i++)//输入成绩优化 
	{
		num=0;
		for(j=0;pNew->score[i][j];j++)
		{
			if(!isdigit(pNew->score[i][j]))
			{
				strcpy(pNew->score[i],"错误!");
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
struct student *Input()//手动输入 
{
	struct student *pHead=NULL,*pEnd,*pNew;
	iCound=0;
	pEnd=pHead=(struct student *)malloc(sizeof(struct student));
	pNew=(struct student *)malloc(sizeof(struct student));
	printf("姓名输入#时，停止输入\n");
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
void Foutput(struct student *pHead)//文件录入 
{
	struct student *pt=pHead; 
	FILE *fp;
	int sum=0,i,j,num;
	pt=pt->next;
	fp=fopen(F_TEMP,"wt+");
	if(fp==NULL)
	{
		printf("不能打开文件");
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
struct student *Write_Foutput()//创建链表并写入文件中 
{
	struct student *pHead;
	char ch;
	printf("一旦进行了数据的更新，所有原数据都会丢失\n");
	printf("确定进行更新按Y\n"); 
	fflush(stdin);
	scanf("%c",&ch); 
	if(ch=='Y'||ch=='y')	
	{	
		pHead=Input();
		Foutput(pHead);
		printf("更新成功\n");
		Sleep(150);
		exit(1); 
	}
	return pHead;
}


static int Long=0;
void Pass_Foutput(char Fflag1,char Fflag2)//密码写入文档中 
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
		printf("文件打开失败！\n");
		exit(0); 
	}
	if(fp_2==NULL)
	{
		printf("文件打开失败！\n");
		exit(0); 
	}
	srand((unsigned)time(NULL));
	if(Fflag2=='1')
	{
		printf("一旦进行了数据的更新，所有原数据都会丢失\n");
		printf("用户名输入#停止");
		printf("确定进行更新输入Y\n");
		char ch;
		fflush(stdin);
		scanf("%c",&ch);
		fflush(stdin);
		if(ch=='y'||ch=='Y')
		{
			while(acc[0]!='#')
			{
				printf("请输入用户名：");
				gets(acc); 
				printf("请输入密码：");
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
void Cip_input(char Fflag,char a)//密钥密码读取 输出 
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
	if(fp_1==NULL||fp_2==NULL)//打开密码文件和密钥文件，存入结构体数组 
	{
		printf("文件打开失败！\n");
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
void Validate(char a)//验证 
{
	struct student *pHead;
	int order,j,i;
	char acc[30],pass[30],key[30],flag;
	i=0;
	do{                                    //找到帐号在数组中的位置 
 		printf("请输入帐号：");
 		fflush(stdin);
		gets(acc);
		for(order=0;order<Long&&strcmp(acc,cip[order].account)!=0;order++)
			;
		if(order==Long)
			printf("用户不存在！请重新输入\n");
		i++;
		if(i%4==0&&order==Long)
		{
			printf("是否返回上一层进行帐号申诉或注册,是Y，否按其他");
			scanf("%c",&flag);
			if(flag=='Y'||flag=='y')
				return;
		}	
				
	}while(order==Long);
	 
	 i=0; 
	 	//验证密码
	do{
		printf("请输入密码：");	
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
			printf("是否返回上一层进行帐号申诉或注册,是Y，否按其他");
			scanf("%c",&flag);
			if(flag=='Y'||flag=='y')
				return;
		}	
	}while(strcmp(cip[order].password,pass)!=0);
	pHead=Finput();//从文件中读取数据 
	Analysis(pHead); 
	if(a=='1')//跳转界面 
		Fstudent(pHead,acc);			
	else if(a=='2')
		Teacher(pHead);
	else if(a=='3')
		Administrator(pHead);	 
}
void Landing(char a)//登录
{
	system("cls"); 
	Cip_input(a,'0');//密钥密码读取 
	Validate(a);//验证 	
}
void Cip_Increase(char Fflag)//增加密码 
{
	Cip_input(Fflag,'0');
	printf("请输入用户名:");
	scanf("%s",cip[Long].account);
	printf("请输入密码:");
	scanf("%s",cip[Long].password);
	Long++;	
	printf("增加成功\n");
	Pass_Foutput(Fflag,'2');
} 
void Cip_Strike_out(char Fflag)//删除密码 
{
	struct cipher r;
	int i,j,t=Long; 
	Cip_input(Fflag,'0');
	printf("请输入要删除用户名:");
	scanf("%s",r.account);
	printf("请输入要删除用户的密码:");
	scanf("%s",r.password);
		
	for(i=0;i<Long;i++)
		if(strcmp(cip[i].account,r.account)==0&&strcmp(cip[i].password,r.password)==0)
		{
			for(j=i;j<Long-1;j++)
				cip[j]=cip[j+1];
			Long--;
		}
	if(t==Long)
		printf("用户名或密码错误\n");
	else
		printf("删除成功\n"); 
	Pass_Foutput(Fflag,'2');
} 
void Cip_Chang(char Fflag)//修改密码 
{
	struct cipher r,t;
	int i,j; 
	Cip_input(Fflag,'0');
	printf("请输入要修改用户名:");
	scanf("%s",r.account);
	printf("请输入要修改用户的密码:");
	scanf("%s",r.password);
		
	for(i=0;i<Long;i++)
		if(strcmp(cip[i].account,r.account)==0&&strcmp(cip[i].password,r.password)==0)
		{
			printf("请输入新的的密码:");
			scanf("%s",cip[i].password);
			printf("修改成功\n");
		}
	Pass_Foutput(Fflag,'2');
}
void Cip_Inquiry(char Fflag)//查找密码 
{
	struct cipher r,t;
	int i,j; 
	Cip_input(Fflag,'0');
	printf("请输入要修改用户名:");
	scanf("%s",r.account);		
	for(i=0;i<Long;i++)
		if(strcmp(cip[i].account,r.account)==0)
			printf("用户%s的密码为%s\n",cip[i].account,cip[i].password);
}




void Output_t(struct student *pHead)//输出 
{
	pHead=pHead->next;
	printf("名单内一共有%d个学生\n",iCound);
	printf("排名\t姓名\t学号\t班级\t科目一\t科目二\t科目三\t平均分\n");
	while(pHead!=NULL)
	{
		printf("No.%d\t",pHead->No);
		printf("%s\t%s\t%s\t",pHead->name,pHead->num,pHead->classes);
		printf("%s\t%s\t%s\t",pHead->score[0],pHead->score[1],pHead->score[2]);
		printf("%.1lf\n",pHead->aver);
		pHead=pHead->next;
	}
}
void Increase(struct student *pHead)//增加 
{
	char a[20];
	struct student *pNew;
	int flag=1;
	printf("请输入你想插入学生后(学号)\n");
	scanf("%s",a);
	while(pHead->next&&strcmp(pHead->num,a)!=0)
		pHead=pHead->next;
	if(pHead->next==NULL&&strcmp(pHead->num,a)!=0)
	{
		printf("未找到此人，如果要插入尾部请输入1\n");
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
void Strike_out(struct student *pHead)//删除
{
	char a[20];
	struct student *pHead_1=pHead;
	printf("请输入你想删除学生的学号\n");
	scanf("%s",a);
	while(pHead&&strcmp(pHead->num,a))
	{
		pHead_1=pHead;
		pHead=pHead->next;
	}	
	if(pHead==NULL)
		printf("查无此人！\n");
	else
	{
		pHead_1->next=pHead->next;
		free(pHead);
		iCound--;
		printf("已删除！\n");
	}


}
void Chang(struct student *pHead)//修改 
{
	char a[20];
	printf("请输入你想修改学生的学号\n");
	scanf("%s",a);
	while(pHead&&strcmp(pHead->num,a))
		pHead=pHead->next;
	if(pHead==NULL)
		printf("未找到此人\n");	
	else 
		Input_1(pHead);	
}
void Inquiry(struct student *pHead) //查询 
{
	char c[20];
	printf("请输入你想查询学生的学号\n");
	scanf("%s",c);
	while(pHead&&strcmp(pHead->num,c))
		pHead=pHead->next;
	if(pHead==NULL)
		printf("未找到此人\n");	 
	else 
	{
		printf("排名\t姓名\t学号\t班级\t科目一\t科目二\t科目三\t平均分\n");
		printf("%d\t",pHead->No); 
		printf("%s\t%s\t%s\t",pHead->name,pHead->num,pHead->classes);
		printf("%s\t%s\t%s\t",pHead->score[0],pHead->score[1],pHead->score[2]);
		printf("%.1lf\n",pHead->aver);
	}		
}
void Exchange(struct student *pj,struct student *pj_h,struct student *pj_1)//交换 
{
	struct student *pt;
	pt=pj->next;
	pj->next=pj_h->next;
	pj_h->next=pt;
				
	pt=pj_1->next;
	pj_1->next=pj_h->next;
	pj_h->next=pt;
}
void Sort(struct student *pHead,char a,int b) //排序 a控制排序依据 b控制排序后的操作 
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
void Analysis(struct student *pHead)//数据分析 
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
	printf("          ******************学生信息管理系统*************************\n");
	printf("                               选择输出方式：\n");
	printf("                               1.按成绩平均分从高到低\n");
	printf("                               2.按学号顺序输出\n");
	printf("                               3.按姓名字典顺序输出\n");
	printf("                               4.返回上一层\n");
	printf("                               0.退出\n");
	printf("                               请输入相应的数字\n"); 
	printf("          ***********************************************************\n");
}
void Output(struct student *pHead)//输出 
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
			case '1':Sort(pHead,flag,1);break;//按平均分输出 
			case '2':Sort(pHead,flag,1);break;//按学号输出 
			case '3':Sort(pHead,flag,1);break;//按名字字典顺序输出 
			case '4':return;
			case '0':exit(0); 
			default :printf("输入有误请重新输入\n");break; 
		}
		printf("按任意键进行下一步操作\n");
		getch();
	}
} 


void Show4_2()
{
	printf("          ******************学生信息管理系统*************************\n");
	printf("                               选择保存方式：\n");
	printf("                               1.按成绩平均分从高到低\n");
	printf("                               2.按学号顺序保存\n");
	printf("                               3.按姓名的字典顺序保存\n");
	printf("                               4.返回上一层\n");
	printf("                               0.退出\n");
	printf("                               请输入相应的数字\n"); 
	printf("          ***********************************************************\n");
}
void Save_1(struct student *pHead)//文件写入 
{
	FILE *fp;
	char filename[100]; 
	char Hesder[8][20]={"排名","姓名","学号","班级","科目一","科目二","科目三","平均分"};
	printf("请输入文件路径及文件名："); 
	fflush(stdin);
	gets(filename); 
	fp=fopen(filename,"wt");
	if(fp==NULL)
	{
		printf("不能打开文件");
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
void Save(struct student *pHead)//文件保存 
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
			case '1':Sort(pHead,flag,2);break;//按平均分输出 
			case '2':Sort(pHead,flag,2);break;//按学号输出 
			case '3':Sort(pHead,flag,2);break;//按名字字典顺序输出 
			case '4':return;
			case '0':exit(0); 
			default :printf("输入有误请重新输入\n");break; 
		}
		printf("按任意键进行下一步操作\n");
		getch();
	}
} 


void Backlog(char a)//代办事项的写入 
{
	FILE *fp;
	char str[5][20]={"密码注册:","密码修改:","密码找回:","成绩申诉:","成绩更新:"}; 
	char Tstr[300],str_t[20],ch1[2]={32,0},ch2[2]={'\n',0};
	fflush(stdin);
	fp=fopen(Fbacklog,"at+");
	if(fp==NULL)
 	{
		printf("文件打开失败\n");
		exit(1);		
 	}
 	strcpy(Tstr,str[a-'1']);
 	if(a!='5') 
	{	
		printf("请输入姓名：");
		gets(str_t);
		strcat(Tstr,ch1);
		strcat(Tstr,str_t);
		printf("请输入学号：");
		gets(str_t);
		strcat(Tstr,ch1);
		strcat(Tstr,str_t);
		printf("请输入班级：");
		gets(str_t);
		strcat(Tstr,ch1);
		strcat(Tstr,str_t);
		if(a=='1') 
		{
			printf("请输入密码：");
			gets(str_t);
			strcat(Tstr,ch1);
			strcat(Tstr,str_t);
		
			printf("请重复输入密码：");
			gets(str_t);
			strcat(Tstr,ch1);
			strcat(Tstr,str_t);
		}
		if(a=='2') 
		{
			printf("请输入原密码：");
			gets(str_t);
			strcat(Tstr,ch1);
			strcat(Tstr,str_t);
		
			printf("请输入修改后密码：");
			gets(str_t);
			strcat(Tstr,ch1);
			strcat(Tstr,str_t);
		}
		if(a=='4') 
		{
			printf("请输入密码：");
			gets(str_t);
			strcat(Tstr,ch1);
			strcat(Tstr,str_t);
		}
		printf("请输入手机号：");
		gets(str_t);
		strcat(Tstr,ch1);
		strcat(Tstr,str_t); 
	}
	strcat(Tstr,ch2);
	fputs(Tstr,fp);
	fclose(fp); 
}
void Open_Backlog()//打开代办事项 
{
	FILE *fp;
	char Tstr[700];
	fp=fopen(Fbacklog,"rt+");
	if(fp==NULL)
 	{
		printf("文件打开失败\n");
		exit(1);		
 	}
	fread(Tstr,700,1,fp);	
	fclose(fp);
	puts(Tstr);
}
void Sign_up()//注册 
{
	char ch;
	printf("是否确定要进行密码注册，确定按Y\n");
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='Y'||ch=='y')
		Backlog('1');
	else
		return ;
	printf("已成功提醒管理员,注册成功后会发短信到您的手机中\n");
	printf("按0退出，其他返回上一层\n");
	scanf("%c",&ch);
	if(ch==0)
		exit(1);
	return ; 
}
void Revise_password()//修改密码
{
	char ch;
	printf("是否确定要进行密码修改，确定按Y\n");
	fflush(stdin);
	scanf("%c",&ch); 
	if(ch=='Y'||ch=='y')
		Backlog('2');
	else
		return ;
	printf("已成功提醒管理员,修改成功后会发送短信到您的手机中\n"); 
	printf("按0退出，其他返回上一层\n");
	scanf("%c",&ch);
	if(ch==0)
		exit(1);
	return ; 
}
void Find_password()//找回密码
{
	char ch;
	printf("是否确定要进行密码找回，确定按Y\n"); 
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='Y'||ch=='y')
		Backlog('3');
	else
		return ;
	printf("已成功提醒管理员,你的密码发短信到您的手机中\n");  
	printf("按0退出，其他返回上一层\n");
	scanf("%c",&ch);
	if(ch==0)
		exit(1);	 
}
void Appeal()//成绩申诉
{
	char ch;
	printf("是否确定要进行成绩申诉，确定按Y\n");
	fflush(stdin); 
	scanf("%c",&ch);
	if(ch=='Y'||ch=='y')
		Backlog('4');
	else
		return ;
	printf("已成功提醒管理员,管理员审核修改成功发短信到您的手机中\n");  
	printf("按0退出，其他返回上一层\n");
	scanf("%c",&ch);
	if(ch==0)
		exit(1);
	return ; 
} 
void Remind()//提醒更新成绩库
{
	char ch;
	printf("是否确定要进行更像成绩库提醒，确定按Y\n");
	fflush(stdin);
	scanf("%c",&ch); 
	if(ch=='Y'||ch=='y')
		Backlog('5');
	else
		return ;
	printf("已成功提醒管理员\n");  
	printf("按0退出，其他返回上一层\n");
	scanf("%c",&ch);
	if(ch==0)
		exit(1);
	return ;
} 
 
 
void Show3()
{
	printf("          **********************学生信息管理系统********************\n");
	printf("                                学生端\n");
	printf("                              1.成绩查询\n");
	printf("                              2.查询本班成绩\n");
	printf("                              3.成绩分析\n");
	printf("                              4.成绩申诉\n");
	printf("                              5.返回上一层\n"); 
	printf("                              0.退出\n"); 
	printf("                              请输入相应的数字\n"); 
	printf("          ********************************************************\n");
}
void Anal(struct student *pHead,char a[],int b)//分析 
{
	while(pHead&&strcmp(pHead->num,a))
		pHead=pHead->next;
	if(b==1) 
	{
		printf("排名\t姓名\t学号\t班级\t科目一\t科目二\t科目三\t平均分\n");
		printf("%d\t",pHead->No); 
		printf("%s\t%s\t%s\t",pHead->name,pHead->num,pHead->classes);
		printf("%s\t%s\t%s\t",pHead->score[0],pHead->score[1],pHead->score[2]);
		printf("%.1lf\n",pHead->aver);
	}
	else
	{
		printf("%s同学,你在你们班排名%d\n",pHead->name,pHead->No);
		printf("你们班科目一平均分%.1lf,你科目一分数为%s\n",Aver1,pHead->score[0]);
		printf("你们班科目二平均分%.1lf,你科目二分数为%s\n",Aver2,pHead->score[1]);
		printf("你们班科目三平均分%.1lf,你科目三分数为%s\n",Aver3,pHead->score[2]);
		printf("你们班三科平均分%.1lf,你的三科平均分为%.1lf\n",Aver4,pHead->aver);	
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
			default :printf("输入有误请重新输入\n");break; 
		}
		printf("按任意键进行下一步操作\n");
		getch();
	}
}


static int T_max[4]={0};
static int T_min[4]={0};
static int T_num1[4]={0};
void Tanal_t(struct student *pHead)//分析成绩
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
	printf("          ******************学生信息管理系统*************************\n");
	printf("                             教师端\n");	
	printf("          1.增加新的学生信息             2.删除学生信息\n");
	printf("          3.修改学生信息                 4.查询学生信息\n");
	printf("          5.输出本班成绩                 6.下载到文件中\n");
	printf("          7.成绩分析                     8.提醒管理员进行成绩的更新\n"); 
	printf("          9.返回上一层                   0.退出\n");
	printf("          请输入相应的数字\n"); 
	printf("          ***********************************************************\n");
}


void Tanal(struct student *pHead)
{	
	Tanal_t(pHead);
	printf("平均分%.1lf\n",Aver4);
	printf("平均分最高%d,最低%d\n",T_max[3],T_min[3]);
	printf("科目一最高分%d，最低分%d\n",T_max[0],T_min[0]);
	printf("科目二最高分%d，最低分%d\n",T_max[1],T_min[1]);
	printf("科目三最高分%d，最低分%d\n",T_max[2],T_min[2]);
	printf("平均分在90~100有%d人\n",T_num1[0]);
	printf("平均分在70~90有%d人\n",T_num1[1]); 
	printf("平均分在60~70有%d人\n",T_num1[2]);
	printf("平均分在60分以下有%d人\n",T_num1[3]); 
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
			default :printf("输入有误请重新输入\n");break; 
		}
		printf("按任意键进行下一步操作\n");
		getch();
	}
}


void Show5()
{
	printf("          ******************学生信息管理系统*************************\n");
	printf("                             管理员端\n"); 
	printf("          1.查看代办选项                           2.进入教师端进行信息修改\n");
	printf("          3.增加帐号及密码                         4.删除帐号及密码\n");
	printf("          5.修改帐号及密码                         6.查找帐号及密码\n");
	printf("          7.录入所有帐号及密码                     8.输出所有帐号及密码\n");
	printf("          9.手动重新录入学生信息                   a.返回上一层\n");
	printf("                             0.退出\n");
	printf("          ***********************************************************\n");
} 
void Choice_Cipher(char a)
{
	char ch;
	printf("按1进入学生帐号管理\n");
	printf("按2进入教师帐号管理\n");
	printf("按3进入管理员帐号管理\n");
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
			default :printf("输入有误请重新输入\n");break; 
		}
		printf("按任意键进行下一步操作\n");
		getch();
	}
}

