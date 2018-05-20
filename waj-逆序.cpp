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
struct student *create()//头插法倒序输出 
{
	n=0;
	struct student *pnew;
	struct student *head;
	head=(struct student *)malloc(sizeof(struct student));
	pnew=(struct student *)malloc(sizeof(struct student)); 
	head->next=NULL;
	printf("请输入学号：\n");
	scanf("%d",&pnew->num);
	printf("请输入姓名：\n");
	scanf("%s",pnew->name);
	while(pnew->num!=0)
	{
		n++; 
		pnew->next=head->next;
		head->next=pnew; 
		pnew=(struct student *)malloc(sizeof(struct student));
		printf("请输入学号：\n");
                scanf("%d",&pnew->num);
                printf("请输入姓名：\n");
	        scanf("%s",pnew->name);
	}
	free(pnew);
	return head;	
}
void print(struct student *head)
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
	insert(head);
	print(head);
	Delete(head);
	print(head);
}
