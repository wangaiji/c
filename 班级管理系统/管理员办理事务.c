#include "record.h"
static int Short=0;
void Backlog(char a)//代办事项的写入  a选择写入内容 
{
	FILE *fp1,*fp2;
	char str[3][20]={"帐号注册:","密码修改:","密码找回:"}; 
	char Tstr[300],str_t[20],str_t1[20],ch1[2]={32,0},ch2[2]={'\n',0};//32为空格 
	char r[20];
	
	fflush(stdin);
	fp1=fopen("E://Fbacklog.txt","at+");
	if(fp1==NULL)
 	{
		printf("文件打开失败\n");
		exit(1);		
 	}
 	strcpy(Tstr,str[a-'1']);	
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
	printf("请输入手机号：");
	gets(str_t);
	strcat(Tstr,ch1);
	strcat(Tstr,str_t); 
	if(a=='1') 
	{
		printf("请输入帐号：");
	        gets(r);
		printf("请输入密码：");
		gets(str_t);
		strcat(Tstr,ch1);
		strcat(Tstr,str_t);
		
		printf("请重复输入密码：");
		gets(str_t1);
		
		if(strcmp(str_t1,str_t)!=0)
		{
		printf("密码不一致！请重新输入：\n");
		gets(str_t1);
	        }
	}
	if(a=='2') 
	{
		printf("请输入帐号：");
		gets(r); 
	        printf("请输入原密码：");
	        gets(str_t);
		strcat(Tstr,ch1);
		strcat(Tstr,str_t);
		
		printf("请输入修改后密码：");
		gets(str_t);
		strcat(Tstr,ch1);
		strcat(Tstr,str_t);
	}
	strcat(Tstr,ch2);
	fputs(Tstr,fp1);
	fclose(fp1); 
	if(a=='3') 
	{
		fp2=fopen("E://mibao.txt","rt");
		if(fp2==NULL)
 	      {
		printf("文件打开失败\n");
		exit(1);		
 	      }
        
	      while(!feof(fp2))
	     {
		fscanf(fp2,"%s %s %s\n",ques[Short].name,ques[Short].birth,ques[Short].ma);
		Short++; 
             }
             fclose(fp2);
	}
}
void Open_Backlog()//打开代办事项 
{
	FILE *fp;
	char Tstr[700];
	fp=fopen("E://Fbacklog.txt","rt+");
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
	printf("是否要进行帐号注册，确定按Y\n");
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='Y'||ch=='y')
		Backlog('1');
	else
		return ;
	printf("已成功提醒管理员!\n");Sleep(1500);
	printf("等待管理员处理...\n");Sleep(1500);
	printf("注册成功会发短信到您手机上！请注意查看~~\n"); 
	printf("按0退出，其他返回上一层\n");
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='0')
		exit(1);
	else return ; 
}
void Correct_password()//修改密码
{
	char ch;
	printf("是否确定要进行密码修改，确定按Y\n");
	fflush(stdin);
	scanf("%c",&ch); 
	if(ch=='Y'||ch=='y')
		Backlog('2');
	else
		return ;
	printf("已成功提醒管理员,修改成功会发短信到您手机上！\n"); 
	printf("按0退出，其他返回上一层\n");
	scanf("%c",&ch);
	if(ch==0)
		exit(1);
	return ; 
}
void Find_password()//找回密码
{
	char ch,s1[20],s2[20],T[20],n[20];
	int flag=1,i;
	
	FILE *fp1; 
	printf("是否确定要进行密码找回，确定按Y\n"); 
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='Y'||ch=='y')
		Backlog('3');
	else
		return ;
	printf("请再次输入姓名：\n");
	gets(n);	
	printf("请回答以下密保问题：\n");
	printf("您的生日是：\n");
	gets(s1);
	printf("您母亲的姓名是：\n");
	gets(s2);
	for(i=0;i<Short;i++)
	if(strcmp(n,ques[i].name)==0&&strcmp(s1,ques[i].birth)==0&&strcmp(s2,ques[i].ma)==0)	
        {
		printf("已成功提醒管理员！若能找回密码会发短信到您的手机上\n");break;  
	}
	if(i==Short) 
	{
	printf("问题回答错误！！！无法找回密码\n"); 
	flag=0;
        }
        
        fp1=fopen("E://Fbacklog.txt","at+");
	if(fp1==NULL)
 	{
		printf("文件打开失败\n");
		exit(1);		
 	}
 	if(flag) strcpy(T,"correct");
 	else strcpy(T,"false");
	fputs(T,fp1);
	fclose(fp1); 
 	
	printf("按0退出，其他返回上一层\n");
	scanf("%c",&ch);
	if(ch==0)
		exit(1);	 
}
 
