#include <stdio.h>
#include <random.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

typedef struct info{
	char jiang[2];
	char ID[20];
	char name[10];
	char gender[10];
	char grade[10];
	char introduction[20];
}Info;

int shuzunumber=0;
int N=100;

void init(Info student[]);
void hprintf();
void inputtext(Info student[]);
void inputnew(Info student[]);
void deletstudent(Info student[]);
void choujiang(Info student[]);
void show(Info student);
void showprize(int n);
void histroicalquery(Info student[]);
void delet(Info student[], int n);
char zhuanhuan(int n);

int main()
{
	//FILE* fp;
	int flag=1,a=2;
	Info student[N];
	init(student);
	inputtext(student);
	while(flag!=0)
	{
	printf("enter 1 :join in the choujiang  enter 2 : delet someone'S introuduction    enter 3 : begin to choujiang   enter 4: historical query  enter 0 :exit\n");
	
//	hprintf();
//	inputtext(fp,student);
	scanf("%d",&flag);
	if(flag==0){
			int i,j;
			FILE* fp1;
			fp1=fopen("output.txt","w");
                        for(i=0;i<shuzunumber;i++){
                                        fprintf(fp1,"%s",&student[i].jiang);
					fprintf(fp1,"%c",'#');
					fprintf(fp1,"%s",&student[i].ID);
					fprintf(fp1,"%c",'#');
					fprintf(fp1,"%s",&student[i].name);
					fprintf(fp1,"%c",'#');
					fprintf(fp1,"%s",&student[i].gender);
                                        fprintf(fp1,"%c",'#');
					fprintf(fp1,"%s",&student[i].grade);
                                        fprintf(fp1,"%c",'#');
					fprintf(fp1,"%s",&student[i].introduction);
                                        fprintf(fp1,"%c",'#');
				//	fprintf(fp1,"%c",&a);
			}
			fclose(fp1);
			break;
		}
	switch(flag){
		case 1:inputnew(student);break;
		case 2:deletstudent(student);break;	
		case 3:choujiang(student);break;
		case 4:histroicalquery(student);break;
			
		}
	}	
	return 0;
}


void init(Info student[])
{
	int i=0;
	 while(i<N)
	{
		student[i].jiang[0]='3';
		student[i].jiang[1]='\0';
		i++;
	}

}



void hprintf()
{
	printf("welcome to this");




}


void inputtext(Info student[])
{
	//读取文件并放入info[]中
}

//录入个人信息
void inputnew(Info student[])
{	
	int flag,number=0;
	while(flag!=0)
	{
		printf("enter 1: please enter your information ");
		printf("enter 0: drop out ");
		scanf("%d",&flag);
		if(flag==1)
		{
		//	s=student(number);
			number=shuzunumber;
			printf("please input your name : ");
			scanf("%s",&student[number].name);
			printf("please input your ID : ");
			scanf("%s",&student[number].ID);
			printf("please input your gender : ");
			scanf("%s",&student[number].gender);
			printf("please input your grade : ");
                        scanf("%s",&student[number].grade);
			printf("please input your introduction : ");
                        scanf("%s",&student[number].introduction);
			shuzunumber+=1;
			printf("%d",shuzunumber);
		}
		
		if(flag==0)return ;
	}
		

}

//历史信息查询
void histroicalquery(Info student[])
{
	
}

//删除学生信息
void deletstudent(Info student[])
{
	int flag=1,i=0,n=0;
	while(flag!=0)
	{
		printf("enter 1: to detel   enter 2: view number  enter 0: exit    ");
		scanf("%d",&flag);
		if(flag==0)break;
		if(flag==1)
		{
			i=0;
			while(i<shuzunumber)
                	{
                        	printf("%d: ",i+1);
                       	 	show(student[i]);
                      		printf("\n");
				i++;
              		 }
		printf("\n");
		printf("which do you want to delet. please enter it's number :");
		scanf("%d",&n);
		delet(student,n);	
		}
		if(flag==2)
		{
			  i=0;
                        while(i<shuzunumber)
                        {
                                printf("%d: ",i+1);
                                show(student[i]);
                                printf("\n");
                                i++;
                         }
			printf("\n");
		}
	}


}

void delet(Info student[], int n)
{
	int j,b=shuzunumber;
	if((n<0) || (n>b))return;	
	for(j=n;j<=b;j++)
	{
		strcpy(student[j-1].name,student[j].name);
		strcpy(student[j-1].ID,student[j].ID);
		strcpy(student[j-1].gender,student[j].gender);
		strcpy(student[j-1].grade,student[j].grade);
		strcpy(student[j-1].introduction,student[j].introduction);
		strcpy(student[j-1].jiang,student[j].jiang);
	}
	--shuzunumber;
	return ;
}




//开始抽奖
void choujiang(Info student[])
{
	//单人抽奖为人选奖品
	//多人抽奖为奖品选人
	}




 
