#include "record.h"

void input(struct student *p1,struct student *head)//����ڵ��ֵ H
{
	int sum=0,i,j,num,x;
	fflush(stdin);
	for(j=0;j<3;j++) 
	{ 
	printf("������������");
	gets(p1->name);
	for(i=0;i<strlen(p1->name);i++)//����������Ϣ 
	{
		if(0<=p1->name[i]&&p1->name[i]<=255)
		{
			printf("����������������������\n");break;
		}
	}
	if(i==strlen(p1->name)) break;
        }
       
        if(j==3){ printf("������������˳�...\n");exit(1);}
	
	for(j=0;j<3;j++)//��λѧ�ţ������ظ� 
	{
		int flag=1;
        	printf("������ѧ�ţ�");
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
		printf("ѧ������������ѧ���Ѵ��ڣ�����������\n");
		else break;
	}
	if(j==3){ printf("������������˳�...\n");exit(1);}

	        
                
	for(j=0;j<3;j++)
	{
	  printf("������༶��");
	  gets(p1->classes);
	  for(i=0;i<strlen(p1->classes);i++)//����������Ϣ 
	{
		if((0<=p1->classes[i]&&p1->classes[i]<'0')||('9'<p1->classes[i]&&p1->classes[i]<=255))
		{
			printf("�༶������������������\n");break;
		}
	}
	if(i==strlen(p1->classes)) break;
        }
        if(j==3){ printf("������������˳�...\n");exit(1);}
	
	for(x=0;x<3;x++)
	{
	   printf("���������ſεĳɼ���");	
 	   scanf("%s %s %s",&p1->score[0],&p1->score[1],&p1->score[2]);
	   for(i=0;i<3;i++)
	   {
	      for(j=0,num=0;p1->score[i][j];j++)
	      num=num*10+p1->score[i][j]-'0';
	      if(num<0||num>100) 
	      {printf("�ɼ�������������������\n");break;}
           }
           if(i==3) break;
        }
        if(x==3){ printf("������������˳�...\n");exit(1);}
        
        for(i=0;i<3;i++)//����ɼ��Ż� 
	{	
		for(j=0,num=0;p1->score[i][j];j++)
		num=num*10+p1->score[i][j]-'0';	
		sum=sum+num;	
	}
	p1->sum=sum;
	p1->aver=sum/3;
	printf("\n");
}
struct student *Finput()//���������ļ�¼�� 
{
	FILE *fp; 
	struct student *head=NULL,*p1,*p2;
        n=0;
	int sum,i,j,num;
	head=p2=(struct student *)malloc(sizeof(struct student));
	fp=fopen("E://chengji.txt","rt");
	if(fp==NULL)
	{
		printf("���ܴ��ļ�");
		exit(1); 
	}
	while(1)
	{
	   sum=0;
  	   p1=(struct student *)malloc(sizeof(struct student));
	   fscanf(fp,"%s %s %s",p1->name,p1->num,p1->classes);
	   fscanf(fp,"%s %s %s",p1->score[0],p1->score[1],p1->score[2]);
	   	for(i=0;i<3;i++)//����ɼ��Ż� 
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
struct student *create()//�ֶ����� 
{
	struct student *head=NULL,*p2,*p1;
	n=0;
	p2=head=(struct student *)malloc(sizeof(struct student));
	p1=(struct student *)malloc(sizeof(struct student));
	printf("��������#ʱ��ֹͣ����\n");
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
void Foutput(struct student *head)//�ļ�¼�� 
{
	struct student *p=head; 
	FILE *fp;
	int sum=0,i,j,num;
	p=p->next;
	fp=fopen("E://chengji.txt","wt+");
	if(fp==NULL)
	{
		printf("���ܴ��ļ�");
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

struct student *Write_Foutput()//��������д���ļ��� 
{
	struct student *head;
	char ch;
	printf("һ�����������ݵĸ��£�����ԭ���ݶ��ᶪʧ\n");
	printf("ȷ�����и��°�Y\n"); 
	fflush(stdin);
	scanf("%c",&ch); 
	if(ch=='Y'||ch=='y')	
	{	
		head=create();
		Foutput(head);
		printf("���³ɹ�\n");
		Sleep(150);
		exit(1); 
	}
	return head;
}
