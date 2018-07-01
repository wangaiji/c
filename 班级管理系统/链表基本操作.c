#include "record.h"
int n;
void print(struct student *head)//输出 
{
	int i=0;
	head=head->next;
	printf("名单内一共有%d个学生\n",n);
	printf("排名\t姓名\t学号\t班级\t\t语文\t数学\t英语\t总分\t平均分\n");
	if(head)
	{
		do{
		printf("No.%d\t",++i);
		printf("%s\t%s\t%s\t",head->name,head->num,head->classes);
		printf("%s\t%s\t%s\t",head->score[0],head->score[1],head->score[2]);
		printf("%.1lf\t%.1lf\n",head->sum,head->aver);
		head=head->next;
	    }while(head);
	}
}
void increase(struct student *head)//增加 
{
	char a[20];
	struct student *pnew;
	struct student *p=head;
	char flag='y';
	printf("请输入你想插入到学生后(学号或姓名)：\n");
	scanf("%s",a); 
	while(p->next)
	{
	  if((p->next&&strcmp(p->num,a)==0)||(p->next&&strcmp(p->name,a))==0) break;
	  else p=p->next;
        }
	if(p->next==NULL&&strcmp(p->num,a)!=0)
	{
		printf("未找到此人，如果要插入尾部请输入y\n");
		flag='n';
		getchar();
		scanf("%c",&flag); 
	}	
	if(flag=='y'||flag=='Y')
	{
		pnew=(struct student *)malloc(sizeof(struct student)); 
		input(pnew,head);
		pnew->next=p->next;
		p->next=pnew;
		n++;
	}		 
}
void Delete(struct student *head)//删除
{
	char a[20];
	struct student *pre=head,*p=head->next;
        printf("请输入你想删除的学生的学号或姓名\n");
        scanf("%s",&a);
        while(p)
       {
       	if((p&&strcmp(p->num,a)==0)||(p&&strcmp(p->name,a))==0) break;
        pre=p;//该节点的前一个节点 
        p=p->next;
       }   
        if(p==NULL)
        printf("未找到这个人！\n");
        else
       {
        pre->next=p->next;//删除 
        free(p);//释放空间 
        printf("已删除！\n");
        n--; 
    }
}
void change(struct student *head)//修改
{
	struct student *p=head;
	char a[20];
	printf("请输入你想修改学生的学号或姓名:\n");
	scanf("%s",a);
	while(p)
	{
	  if((p&&strcmp(p->num,a)==0)||(p&&strcmp(p->name,a))==0) break;
	  else p=p->next;
        }
	if(p==NULL)
	printf("未找到此人\n");	
	else
	input(p,head); 
}
void inquiry(struct student *head) //查询 
{
	struct student *p=head;
	char a[20];
	int flag=1;
	printf("请输入你想查询学生的学号或姓名：\n");
	scanf("%s",a);
	while(p)
	{
	  if((p&&strcmp(p->num,a)==0)||(p&&strcmp(p->name,a))==0) break;
	  else p=p->next;
        }
	if(p==NULL)
	{
	   printf("未找到此人\n");
	   p=head->next;
	   while(p)
	   {
	      if(strstr(p->name,a)) 
	      {
	      	if(!flag) {printf("或%s",p->name);}
	      	if(flag==1)
                {printf("emmm...\n");Sleep(1500);
		printf("你是不是想找%s",p->name);flag=0;}
              }
                p=p->next;
           }
           printf("\n");
           Sleep(300);
           printf("请重新进行查询\n");
        }
	   
			 
	else 
	{
		printf("姓名\t学号\t班级\t\t语文\t数学\t英语\t总分\t平均分\n");
		printf("%s\t%s\t%s\t",p->name,p->num,p->classes);
		printf("%s\t%s\t%s\t%.1lf\t",p->score[0],p->score[1],p->score[2],p->sum);
		printf("%.1lf\n",p->aver);
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
void Sort(struct student *head,char a) //排序 a控制排序依据 
{
	int i,j,flag;
	struct student *pj_1,*pj,*pj_h;
	for(i=0;i<n-1;i++)
		for(j=0,pj=head,flag=0;j<n-i-1;j++) 
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
			
	                else if(a=='3'&&atoi(pj->score[0])<atoi(pj_h->score[0]))
	                {
               		        Exchange(pj,pj_h,pj_1);
				flag=1;	
			}
			else if(a=='4'&&atoi(pj->score[1])<atoi(pj_h->score[1]))
			{
				Exchange(pj,pj_h,pj_1);
				flag=1;	
			}
			else if(a=='5'&&atoi(pj->score[2])<atoi(pj_h->score[2]))
			{
				Exchange(pj,pj_h,pj_1);
				flag=1;	
			}
		}
		
	
} 
void Analysis(struct student *head)//数据分析 
{
	struct student *pt=head; 
	int i=0,num1=0,num2=0,num3=0,num4=0,j,num;
	pt=pt->next;
	while(pt!=NULL)
	{
		i++;	
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
}

