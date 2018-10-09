#include <stdio.h>
#include <random.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "./random.c"

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
	hprintf();
	while(flag!=0)
	{
	printf("输入1 : 加入抽奖\n输入2 : 删除个人信息\n输入3 : 开始抽奖\n输入4 : 历史查询\n输入0 : 退出\n");
	
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
	printf("                       抽奖小活动\n");
	printf("    为丰富现代大学生的大学生活，XX公司特举办抽奖活动，让大\n学生广泛投入社交活动中。其中奖品费用由本公司承担，奖项分为\n一等奖一名，奖品为苹果手机;二等奖两名，奖品为收音机;三等奖\n三名，奖品为保温杯;谢谢参与若干。欢迎各位同学踊跃参加，请按\n下列提示参与抽奖。\n\n");
}


void inputtext(Info student[])
{
	int j=0,i=1,k=0,m=0;
	
	FILE *fp;
	char ch;
	fp=fopen("output.txt","r");
	if(fp==NULL)return;
	ch=getc(fp);
	while(ch!=EOF)
	{
	
		if(ch=='#'){i++;k=0;ch=getc(fp);if(ch==EOF)break;if(i%6==1)j++;}
		if(i%6==1){student[j].jiang[k]=ch;k++;m=k;if(i!=1 && k==0)student[j-1].introduction[m]='\0';}
		if(i%6==2){if(k==0)student[j].jiang[m]='\0';student[j].ID[k]=ch;k++;m=k;}
		if(i%6==3){if(k==0)student[j].ID[m]='\0';student[j].name[k]=ch;k++;m=k;}
		if(i%6==4){if(k==0)student[j].name[m]='\0';student[j].gender[k]=ch;k++;m=k;}
                if(i%6==5){if(k==0)student[j].gender[m]='\0';student[j].grade[k]=ch;k++;m=k;}
                if(i%6==0){if(k==0)student[j].grade[m]='\0';student[j].introduction[k]=ch;k++;m=k;}
		ch=getc(fp);
	}
	shuzunumber=j+1;
	fclose(fp);
}


void inputnew(Info student[])
{	
	int flag,number=0;
	while(flag!=0)
	{
		printf("输入1: 请完善你的个人信息\n");
		printf("输入0: 退出\n");
		scanf("%d",&flag);
		if(flag==1)
		{
		//	s=student(number);
			number=shuzunumber;
			printf("请输入你的姓名 : ");
			scanf("%s",&student[number].name);
			printf("请输入你的学号 : ");
			scanf("%s",&student[number].ID);
			printf("请输入你的性别 : ");
			scanf("%s",&student[number].gender);
			printf("请输入你的年级 : ");
                        scanf("%s",&student[number].grade);
			printf("请输入你的个人简介 : ");
                        scanf("%s",&student[number].introduction);
			shuzunumber+=1;
			printf("参与者%d :",shuzunumber+1);
		}
		
		if(flag==0)return ;
	}
		

}


void histroicalquery(Info student[])
{
	int n=1,i,x=0,y=0,z=0;
	int b[20],c[20],d[20];

	for(i=0;i<20;i++)
	{
		b[i]=0;
		c[i]=0;
		d[i]=0;
	}
	i=0;
        while(i<shuzunumber)
        {
         	if(student[i].jiang[0]=='0'){b[x]=i;x++;}
                if(student[i].jiang[0]=='1'){c[y]=i;y++;}
                if(student[i].jiang[0]=='2'){d[z]=i;z++;}
                i++;
         }

	while(n!=0)
	{
		printf("输入1 : 信息统计\n输入2 : 信息查询\n输入3 : 信息清除\n输入0 : 退出\n");
		scanf("%d",&n);
		if(n==0)return;
		if(n==1)
		{
			printf("这里有%d个人获得了一等奖\n这里有%d个人获得了二等奖\n这里有%d个人获得了三等奖\n",x,y,z);
		}
		if(n==2)
		{
			printf("一等奖 : ");
			if(x!=0) for(i=0;i<x;i++)show(student[b[i]]);
			else printf("  nobody");
			printf("\n");
			printf("二等奖 : ");
                        if(y!=0) for(i=0;i<y;i++)show(student[c[i]]);
			else printf("  nobody");
			printf("\n");
			printf("三等奖 : ");
                        if(z!=0)for(i=0;i<z;i++)show(student[d[i]]);
			else printf("  nobody");
			printf("\n");
	}
		if(n==3)
		{
			for(i=0;i<x;i++){student[b[i]].jiang[0]='3';x=0;}
			for(i=0;i<y;i++){student[c[i]].jiang[0]='3';y=0;}
			for(i=0;i<z;i++){student[d[i]].jiang[0]='3';z=0;}
		}


	}		




}


void deletstudent(Info student[])
{
	int flag=1,i=0,n=0;
	while(flag!=0)
	{
		printf("输入1 : 删除信息\n输入2 : 查看所有信息\n输入0 : 退出\n");
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
		printf("请输入你想删除的信息对应号码 :");
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
		printf("输入1 : 开始\n输入0 : 退出\n");
		scanf("%d",&flag);
		if(flag==1)
		{
			while(flags!=0)
			{
				printf("输入1 : 一人参与\n输入2 ：多人参与\n输入0 : 退出\n");
				scanf("%d",&flags);
				Randomize();
				if(flags==1)
				{
				//	Randomize();
					nb=RandomInteger(0,4);
					student[shuzunumber-1].jiang[0]=zhuanhuan(nb);
					printf("结果是 : ");
					showprize(nb);
					printf("  中奖者个人信息是 : ");
				//	printf("%d",shuzunumber);
					show(student[shuzunumber-1]);
					printf("\n");
				}
				if(flags==2)
				{
					printf("这里有%d个人在抽奖名单中\n",shuzunumber);
					printf("多少人加入抽奖 : ");
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
						//printf("%d ",shuzunumber);
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
	printf("  姓名 : %-10s",student.name);
	printf("学号 : %-20s ",student.ID);
        printf("性别 : %-10s ",student.gender);
        printf("年级 : %-10s ",student.grade);
        printf("个人简介 : %s ",student.introduction);
}


void showprize(int n)
{
	if(n==0)printf("第一名 : 苹果手机");
	else if(n==1)printf("第二名 : 收音机");
	else if(n==2)printf("第三名 : 保温杯");
	else printf("谢谢参与");
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


 
