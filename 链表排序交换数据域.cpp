#include"stdio.h" 
#include"stdlib.h"
#include"string.h"
struct node
{
	char name[20];
	int score;	
};
struct student
{
	struct node element;
	struct student *next;
};
int n;
struct student *create()
{
	struct student *head;
	struct student *p1,*p2;
	p1=p2=(struct student *)malloc(sizeof(struct student));
	printf("please put in the name:\n");
	scanf("%s",p1->element.name);
	printf("please put in the score:\n");
	scanf("%d",&p1->element.score);
	head=NULL;n=0;
	while(p1->element.score!=0)
	{
		n++;
		if(n==1) head=p1;
		else p2->next=p1;
	    p2=p1;
            p1=(struct student *)malloc(sizeof(struct student));
	    printf("please put in the name:\n");
	    scanf("%s",p1->element.name);
	    printf("please put in the score:\n");
	    scanf("%d",&p1->element.score);
	}
	p2->next=NULL;
	free(p1);
	return head;
}
struct student *sort(struct student *head)
{
	struct node temp;
	struct student *p,*f,*t;
	for(p=head;p->next!=NULL;p=p->next)
	{
		for(t=p->next;t!=NULL;t=t->next)
		{
			if(p->element.score>t->element.score)
			{
				temp=p->element;
				p->element=t->element;
				t->element=temp; 
			}
		}
	}
	return head;	
}
void print(struct student *head)
{
	struct student *p;
	p=head;
	if(p)
	{
		do
		{
			printf("%s³É¼¨Îª:%d\n",p->element.name,p->element.score);
			p=p->next;
		}while(p);
	}
}
int main()
{
	struct student *head;
	head=create();
	sort(head);
	print(head);
	printf("\n\n");
}
