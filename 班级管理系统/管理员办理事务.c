#include "record.h"
static int Short=0;
void Backlog(char a)//���������д��  aѡ��д������ 
{
	FILE *fp1,*fp2;
	char str[3][20]={"�ʺ�ע��:","�����޸�:","�����һ�:"}; 
	char Tstr[300],str_t[20],str_t1[20],ch1[2]={32,0},ch2[2]={'\n',0};//32Ϊ�ո� 
	char r[20];
	
	fflush(stdin);
	fp1=fopen("E://Fbacklog.txt","at+");
	if(fp1==NULL)
 	{
		printf("�ļ���ʧ��\n");
		exit(1);		
 	}
 	strcpy(Tstr,str[a-'1']);	
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
	printf("�������ֻ��ţ�");
	gets(str_t);
	strcat(Tstr,ch1);
	strcat(Tstr,str_t); 
	if(a=='1') 
	{
		printf("�������ʺţ�");
	        gets(r);
		printf("���������룺");
		gets(str_t);
		strcat(Tstr,ch1);
		strcat(Tstr,str_t);
		
		printf("���ظ��������룺");
		gets(str_t1);
		
		if(strcmp(str_t1,str_t)!=0)
		{
		printf("���벻һ�£����������룺\n");
		gets(str_t1);
	        }
	}
	if(a=='2') 
	{
		printf("�������ʺţ�");
		gets(r); 
	        printf("������ԭ���룺");
	        gets(str_t);
		strcat(Tstr,ch1);
		strcat(Tstr,str_t);
		
		printf("�������޸ĺ����룺");
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
		printf("�ļ���ʧ��\n");
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
void Open_Backlog()//�򿪴������� 
{
	FILE *fp;
	char Tstr[700];
	fp=fopen("E://Fbacklog.txt","rt+");
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
	printf("�Ƿ�Ҫ�����ʺ�ע�ᣬȷ����Y\n");
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='Y'||ch=='y')
		Backlog('1');
	else
		return ;
	printf("�ѳɹ����ѹ���Ա!\n");Sleep(1500);
	printf("�ȴ�����Ա����...\n");Sleep(1500);
	printf("ע��ɹ��ᷢ���ŵ����ֻ��ϣ���ע��鿴~~\n"); 
	printf("��0�˳�������������һ��\n");
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='0')
		exit(1);
	else return ; 
}
void Correct_password()//�޸�����
{
	char ch;
	printf("�Ƿ�ȷ��Ҫ���������޸ģ�ȷ����Y\n");
	fflush(stdin);
	scanf("%c",&ch); 
	if(ch=='Y'||ch=='y')
		Backlog('2');
	else
		return ;
	printf("�ѳɹ����ѹ���Ա,�޸ĳɹ��ᷢ���ŵ����ֻ��ϣ�\n"); 
	printf("��0�˳�������������һ��\n");
	scanf("%c",&ch);
	if(ch==0)
		exit(1);
	return ; 
}
void Find_password()//�һ�����
{
	char ch,s1[20],s2[20],T[20],n[20];
	int flag=1,i;
	
	FILE *fp1; 
	printf("�Ƿ�ȷ��Ҫ���������һأ�ȷ����Y\n"); 
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='Y'||ch=='y')
		Backlog('3');
	else
		return ;
	printf("���ٴ�����������\n");
	gets(n);	
	printf("��ش������ܱ����⣺\n");
	printf("���������ǣ�\n");
	gets(s1);
	printf("��ĸ�׵������ǣ�\n");
	gets(s2);
	for(i=0;i<Short;i++)
	if(strcmp(n,ques[i].name)==0&&strcmp(s1,ques[i].birth)==0&&strcmp(s2,ques[i].ma)==0)	
        {
		printf("�ѳɹ����ѹ���Ա�������һ�����ᷢ���ŵ������ֻ���\n");break;  
	}
	if(i==Short) 
	{
	printf("����ش���󣡣����޷��һ�����\n"); 
	flag=0;
        }
        
        fp1=fopen("E://Fbacklog.txt","at+");
	if(fp1==NULL)
 	{
		printf("�ļ���ʧ��\n");
		exit(1);		
 	}
 	if(flag) strcpy(T,"correct");
 	else strcpy(T,"false");
	fputs(T,fp1);
	fclose(fp1); 
 	
	printf("��0�˳�������������һ��\n");
	scanf("%c",&ch);
	if(ch==0)
		exit(1);	 
}
 
