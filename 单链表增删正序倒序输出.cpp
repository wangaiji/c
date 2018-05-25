#include"stdio.h"
#include"stdlib.h"
#include"string.h"
struct student
{
	int num;
	char name[20];
	struct student *next;
};
int n;
struct student *create()//尾插法正序输出 
{
	n=0;
	struct student *p1,*p2;
	struct student *head=NULL;
	head=p2=(struct student *)malloc(sizeof(struct student));
	p1=(struct student *)malloc(sizeof(struct student)); 
	printf("请输入学号：\n");
	scanf("%d",&p1->num);
	printf("请输入姓名：\n");
	scanf("%s",p1->name);
	while(p1->num!=0)
	{
		n++; 
		p2->next=p1;
		p1->next=NULL; 
		p2=p1;
		p1=(struct student *)malloc(sizeof(struct student));
		printf("请输入学号：\n");
                scanf("%d",&p1->num);
                printf("请输入姓名：\n");
	        scanf("%s",p1->name);
	}
	free(p1);
	return head;	
}
void print(struct student *head)//正序打印 
{
        struct student *p;
	p=head->next;
	if(p)
	{
		do
		{
			printf("学号为%d名字为:%s\n",p->num,p->name);
			p=p->next;
		}while(p);
	}
}
void print1(struct student *head)//逆序打印(递归) 
{
	if(head==NULL)
	return;
	if(head->next!=NULL) 
	{
		print1(head->next);
	}
	if(head->num!=NULL)
        printf("学号为%d名字为:%s\n",head->num,head->name);
        
} 
struct student *insert(struct student *head)
{
	struct student *p1,*p=head;
	char a[20];
	printf("请输入要插入的学生名字后：\n");
	scanf("%s",a);
	while(p->next)
        {
 	      if(strcmp(a,p->name)==0) break;
	      else p=p->next;
	}
        p1=(struct student *)malloc(sizeof(struct student));
 	printf("请输入学号:\n");
  	scanf("%d",&p1->num);
        printf("请输入姓名:\n");
   	scanf("%s",p1->name);
    	p1->next=p->next;
    	p->next=p1;
	return head;
}
void Delete(struct student *head)
{
	struct student *p;
	struct student *pre;
	char a[20];
	p=head->next;
	pre=head;
	printf("要删除的学生姓名：\n");
	scanf("%s",a);
	while(p)
	{
		if(strcmp(a,p->name)==0) break;
		pre=p;
		p=p->next;
	}
	pre->next=p->next;
	free(p);
	n--;	
}
int main()
{
	struct student *head;
	head=create();
	print(head);
	head=head->next;
	print1(head);
	insert(head);
	print(head);
	Delete(head);
	print(head);
}
