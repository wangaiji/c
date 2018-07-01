#include "record.h"

void input(struct student *p1,struct student *head)//输入节点的值 H
{
	int sum=0,i,j,num,x;
	fflush(stdin);
	for(j=0;j<3;j++) 
	{ 
	printf("请输入姓名：");
	gets(p1->name);
	for(i=0;i<strlen(p1->name);i++)//限制名字信息 
	{
		if(0<=p1->name[i]&&p1->name[i]<=255)
		{
			printf("姓名输入有误！请重新输入\n");break;
		}
	}
	if(i==strlen(p1->name)) break;
        }
       
        if(j==3){ printf("三次输入错误！退出...\n");exit(1);}
	
	for(j=0;j<3;j++)//四位学号，不能重复 
	{
		int flag=1;
        	printf("请输入学号：");
        	fflush(stdin);
                gets(p1->num);
         
         
                if(strlen(p1->num)!=4)
                flag=0;
                if(flag)
                {
                	for(i=0;i<strlen(p1->num);i++)
                	if(p1->num[i]<'0'||p1->num[i]>'9')
                	{flag=0;break;}
	        }
	        if(flag)
	        {
			struct student *pt=NULL;
		        for(pt=head->next;pt;pt=pt->next)
		       {
			if(pt!=p1&&strcmp(pt->num,p1->num)==0)
			{flag=0;break;}
		       }
	        }
	        
	        if(flag==0) 
		printf("学号输入有误或该学号已存在！请重新输入\n");
		else break;
	}
	if(j==3){ printf("三次输入错误！退出...\n");exit(1);}

	        
                
	for(j=0;j<3;j++)
	{
	  printf("请输入班级：");
	  gets(p1->classes);
	  for(i=0;i<strlen(p1->classes);i++)//限制名字信息 
	{
		if((0<=p1->classes[i]&&p1->classes[i]<'0')||('9'<p1->classes[i]&&p1->classes[i]<=255))
		{
			printf("班级输入有误！请重新输入\n");break;
		}
	}
	if(i==strlen(p1->classes)) break;
        }
        if(j==3){ printf("三次输入错误！退出...\n");exit(1);}
	
	for(x=0;x<3;x++)
	{
	   printf("请输入三门课的成绩：");	
 	   scanf("%s %s %s",&p1->score[0],&p1->score[1],&p1->score[2]);
	   for(i=0;i<3;i++)
	   {
	      for(j=0,num=0;p1->score[i][j];j++)
	      num=num*10+p1->score[i][j]-'0';
	      if(num<0||num>100) 
	      {printf("成绩输入有误！请重新输入\n");break;}
           }
           if(i==3) break;
        }
        if(x==3){ printf("三次输入错误！退出...\n");exit(1);}
        
        for(i=0;i<3;i++)//输入成绩优化 
	{	
		for(j=0,num=0;p1->score[i][j];j++)
		num=num*10+p1->score[i][j]-'0';	
		sum=sum+num;	
	}
	p1->sum=sum;
	p1->aver=sum/3;
	printf("\n");
}
struct student *Finput()//创建链表文件录入 
{
	FILE *fp; 
	struct student *head=NULL,*p1,*p2;
        n=0;
	int sum,i,j,num;
	head=p2=(struct student *)malloc(sizeof(struct student));
	fp=fopen("E://chengji.txt","rt");
	if(fp==NULL)
	{
		printf("不能打开文件");
		exit(1); 
	}
	while(1)
	{
	   sum=0;
  	   p1=(struct student *)malloc(sizeof(struct student));
	   fscanf(fp,"%s %s %s",p1->name,p1->num,p1->classes);
	   fscanf(fp,"%s %s %s",p1->score[0],p1->score[1],p1->score[2]);
	   	for(i=0;i<3;i++)//输入成绩优化 
		{	
		    
			for(j=0,num=0;p1->score[i][j];j++)
			num=num*10+p1->score[i][j]-'0';	
		    sum=sum+num;	
		}
		p1->sum=sum;
		p1->aver=sum/3;
	   
	   if(feof(fp)) break;
	   p2->next=p1;
   	   p2=p1;
   	   n++; 
    }
	p2->next=NULL;
	fclose(fp);
	return head; 	
}
struct student *create()//手动输入 
{
	struct student *head=NULL,*p2,*p1;
	n=0;
	p2=head=(struct student *)malloc(sizeof(struct student));
	p1=(struct student *)malloc(sizeof(struct student));
	printf("姓名输入#时，停止输入\n");
	input(p1,head);
	while(p1->name[0]!='#')
	{
		n++;
		p2->next=p1;
		p1->next=NULL;
		p2=p1;
		p1=(struct student *)malloc(sizeof(struct student)); 
		input(p1,head);
	} 
	free(p1);
	return head; 	
}
void Foutput(struct student *head)//文件录入 
{
	struct student *p=head; 
	FILE *fp;
	int sum=0,i,j,num;
	p=p->next;
	fp=fopen("E://chengji.txt","wt+");
	if(fp==NULL)
	{
		printf("不能打开文件");
		exit(1); 
	}
	while(p)
	{
		fprintf(fp,"%s %s %s ",p->name,p->num,p->classes);
		fprintf(fp,"%s %s %s\n",p->score[0],p->score[1],p->score[2]); 	
		p=p->next;
	}
	fclose(fp);
}

struct student *Write_Foutput()//创建链表并写入文件中 
{
	struct student *head;
	char ch;
	printf("一旦进行了数据的更新，所有原数据都会丢失\n");
	printf("确定进行更新按Y\n"); 
	fflush(stdin);
	scanf("%c",&ch); 
	if(ch=='Y'||ch=='y')	
	{	
		head=create();
		Foutput(head);
		printf("更新成功\n");
		Sleep(150);
		exit(1); 
	}
	return head;
}
