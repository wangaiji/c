#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h> 
#include <ctype.h>
#include <time.h> 

struct student
{
	char name[20];//���� 
	char num[20];//ѧ�� 
	char classes[20];//�༶ 
	char score[3][10];//���� 
	double sum;//�ܷ� 
	double aver;//ƽ����
	struct student *next;//ָ���� 
}; 
struct cipher
{
	char account[30];
	char password[30];
}cip[50];
struct mibao
{
	char name[20];
	char birth[20];
	char ma[20];
}ques[50];
int n;
double Aver1,Aver2,Aver3,Aver4; 

//����ö��Keyboard�ļ�ֵ���� 
enum 
{
	UP = 72,
	DOWN = 80 ,
	LEFT = 75 ,
	RIGHT = 77 ,
	ENTER = 13 ,
	ESC = 27 ,
};

