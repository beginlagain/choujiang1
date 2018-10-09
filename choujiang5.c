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

}


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


void histroicalquery(Info student[])
{
		
}


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





void choujiang(Info student[])
{
	int flag=1,nb,flags=1,sb,a[50],i,b,j,c;
	
	while(flag!=0)
	{
		printf("enter 1: begin  enter 0: exit      ");
		scanf("%d",&flag);
		if(flag==1)
		{
			while(flags!=0)
			{
				printf("enter 1: a person take part in the game   enter 2 :many people take part in the game  enter 0 : exit   ");
				scanf("%d",&flags);
				Randomize();
				if(flags==1)
				{
				//	Randomize();
					nb=RandomInteger(0,4);
					student[shuzunumber-1].jiang[0]=zhuanhuan(nb);
					printf("the result is :   ");
					showprize(nb);
					printf("winner's controduction :");
				//	printf("%d",shuzunumber);
					show(student[shuzunumber-1]);
					printf("\n");
				}
				if(flags==2)
				{
					printf("now there are %d people in the menu\n",shuzunumber);
					printf("how mang people take part in game : ");
					scanf("%d",&c);
					Randomize();
					for(i=0;i<c;i++)
					{
						
						b=RandomInteger(0,shuzunumber-1);
						if(i==0)a[i]=b;
						else
						{
							for(j=0;j<i;j++)
							{
								if(b==a[j]){i--;break;}																																				}
							if(j==i)a[i]=b;
						}
					}
					for(j=0;j<c;j++)
					{
						printf("%d ",shuzunumber);
						if(j<=2){showprize(j);show(student[a[j]]);printf("\n");student[a[j]].jiang[0]=zhuanhuan(j);}
						else {showprize(2);show(student[a[j]]);printf("\n");}
					}	
				}
			}
		}			
			if(flag==0)break;
		}
	}




void show(Info student)
{
	printf("name: %-10s",student.name);
	printf("ID : %-20s ",student.ID);
        printf("gender : %-10s ",student.gender);
        printf("grade : %-10s ",student.grade);
        printf("introduction : %s ",student.introduction);
}


void showprize(int n)
{
	if(n==0)printf("first prize winner:get a mobile phone ");
	else if(n==1)printf("second prize winner :get a video recorder");
	else if(n==2)printf("third prize winner :get a bottle of water ");
	else printf("thanks for participating  ");
}


char zhuanhuan(int n)
{
	char a;
	switch(n)
	{
		case 0:a='0';break;
		case 1:a='1';break;
		case 2:a='2';break;
		default:a='3';break;
	}
	return a;
}


 





 
