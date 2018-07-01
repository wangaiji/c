#include "record.h"
static int Long=0;
//void Cip_input(char Fflag,char a);//Fflag-打开哪个端的密码 a-是否要输出
void Pass_Foutput(char Fflag1,char Fflag2)//密码写入文档中 Fflag1-打开哪个端的密码 Fflag2-手动输入还是输入数组中的
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
		printf("文件打开失败！\n");
		exit(0); 
	}
	
	srand((unsigned)time(NULL));
	if(Fflag2=='1')//手动输入 
	{
		printf("提示：");
		printf("一旦进行了数据的更新，所有原数据都会丢失\n");
		printf("用户名输入#停止,");
		printf("确定进行更新输入Y\n");
		char ch;
		fflush(stdin);
		scanf("%c",&ch);
		fflush(stdin);
		if(ch=='y'||ch=='Y')
		{
			while(1)
			{
				printf("请输入用户名：");
				gets(acc); 
				if(acc[0]=='#') break;
				printf("请输入密码：");
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
void Cip_input(char Fflag,char a)//密码读取 输出 
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
	if(fp1==NULL)//打开密码文件，存入结构体数组 
	{
		printf("文件打开失败！\n");
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
void Validate(char a)//验证 
{
	struct student *head;
	struct student *Head;
	int order,j,i;
	char acc[30],pass[30],flag;
	i=0;
        printf("\n\n\n\n\n\n\n\n\n\n\n"); 
       	HANDLE hOut;
	hOut=GetStdHandle(STD_OUTPUT_HANDLE);//获得控制台句柄 
	SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY); 
	do{     
 	//找到帐号在数组中的位置                             
 		printf("                              请输入帐号：");
 		fflush(stdin);
		gets(acc);
		for(order=0;order<Long&&strcmp(acc,cip[order].account)!=0;order++)
			;
		if(order==Long)
			printf("                              用户不存在！请重新输入\n");
		i++;
		if(i%3==0&&order==Long)
		{
			printf("                              是否返回上一层进行帐号注册,是按Y，否按其他\n");
			scanf("%c",&flag);
			if(flag=='Y'||flag=='y')
			return;
		}	
				
	}while(order==Long);
	 
        for(i=0;i<3;i++) 
    	{
		printf("                              请输入密码：");	
		for(j=0;pass[j-1]!=13;j++)//回车的ascii码为13 
		{
			pass[j]=getch();
			if(pass[j]==8&&j>0)//删除的ascii码为8 
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
		else printf("                                 密码输入错误!\n");
	}
    if(i==3)	
    {
	printf("                                              三次输入错误！是否返回上一层进行密码找回,是Y，否按其他\n");
	scanf("%c",&flag);
	if(flag=='Y'||flag=='y')
	return;
    else exit(1);
    }
    
	printf("                              正在登录");
	Sleep(1500);
	printf("...\n");
	Sleep(1500);
	printf("                              .......\n");
	Sleep(800);
	printf("                              登陆成功！\n");
	Sleep(800);
	printf("                              页面马上加载出来...\n");
	Sleep(1500); 
	
	head=Finput();//从文件中读取数据 
//	Head=Finput();
	Analysis(head); 
	if(a=='1')//跳转界面 
		Fstudent(head,acc);			
	else if(a=='2')
		Teacher(head);
	else if(a=='3')
		Administrator(head);	 
}
void Landing(char a)//登录
{
	system("cls"); 
	Cip_input(a,'0');//密码读取 
	Validate(a);//验证 	
}
void Cip_Increase(char Fflag)//增加密码 
{
	Cip_input(Fflag,'0');
	printf("请输入帐号:");
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
		
	for(i=0;i<Long;i++)
		if(strcmp(cip[i].account,r.account)==0) 
		{
			for(j=i;j<Long-1;j++)
				cip[j]=cip[j+1];
			Long--;
		}
	if(t==Long)
		printf("用户名输入错误，查无此人！\n");
	else
		printf("删除成功！\n"); 
	Pass_Foutput(Fflag,'2');
} 
void Cip_Chang(char Fflag)//修改密码 
{
	struct cipher r;
	int i,j; 
	Cip_input(Fflag,'0');
	printf("请输入要修改用户名:");
	scanf("%s",r.account);
		
	for(i=0;i<Long;i++)
		if(strcmp(cip[i].account,r.account)==0) 
		{
			printf("请输入新的密码:");
			scanf("%s",cip[i].password);
			printf("修改成功！\n");
			break;
		}
	if(i==Long) printf("用户名输入错误，查无此人！\n"); 
	Pass_Foutput(Fflag,'2');
}
void Cip_Inquiry(char Fflag)//查找密码 
{
	struct cipher r,t;
	int i,j; 
	Cip_input(Fflag,'0');
	printf("请输入要查找的用户名:");
	scanf("%s",r.account);		
	for(i=0;i<Long;i++)
		if(strcmp(cip[i].account,r.account)==0)
			printf("帐号为%s的密码为：%s\n",cip[i].account,cip[i].password);
}
