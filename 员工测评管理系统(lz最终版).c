#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 2
int number,o,z;
int mark[N];
int m[N];
int n[N];
int x[N];
int b=0,c=0,d=0,e=0,f=0,i=0,k=0,p=0,g=0,h=0,j=0;
int judge();
char ad2[30];
void notice();
void input();
void count();
void bubbling();
void Query();
void change();
void paixu();
void save();
void read();
void add();
void output1();
void output2();
void output3();
void output5();
void NO1();
void NO2();
void NO3();
void NO4();
void NO5();
void NO6();
void NO7();
void NO8();
void NO9();


struct worker
{
	int id;
	char name[20];
	char job[20];
	int age;
	float mark;
	char rank[10];
};
struct worker member[N];



struct add
{
	int id;
	char name[20];
	char job[20];
	int age;
	float mark;
	char rank[10];
};
struct add addd[1];

void notice()//提示信息
{
	printf("\n");
	printf("工号\t姓名\t职位\t年龄\t分数\n");
}


void input()//输入
{
	for(i=0;i<N;i++)
	{
		scanf("%d%s%s%d%f",&member[i].id,member[i].name,member[i].job,&member[i].age,&member[i].mark);
	}

}


int judge() //等级评定
{
	printf("\n");
	for(i=0;i<N;i++)
	{
		m[i]=member[i].mark/10;
	}
	for(i=0;i<N;i++)
	{
		switch(m[i])
		{	
		case 10:strcpy(member[i].rank,"优秀");break;
		case 9:strcpy(member[i].rank,"优秀");break;
		case 8:strcpy(member[i].rank,"良好");break;
		case 7:strcpy(member[i].rank,"中等");break;
		case 6:strcpy(member[i].rank,"及格");break;
		default:strcpy(member[i].rank,"不及格");break;
		}
	}
	return 0;
}


void count()//统计各分数段人数
{
for(i=0;i<N;i++)
{
	if(strcmp("优秀",member[i].rank)==0)
		b=b+1;
	else if(strcmp("良好",member[i].rank)==0)
		c=c+1;
	     else if(strcmp("中等",member[i].rank)==0)
		     d=d+1;
		      else if(strcmp("及格",member[i].rank)==0)
		             e=e+1;
			       else if(strcmp("不及格",member[i].rank)==0)
		                   f=f+1;
}
}


void bubbling()//排序
{
	mark[0]=0;
	for(i=1;i<N;i++)
	{
		mark[i]=mark[i-1]+1;
	}
	for(g=1;g<=N-1;g++)
		for(h=0;h<N-g;h++)
		{
			if(member[i].mark>member[i+1].mark)
				{	
					j=mark[i];
					mark[i]=mark[i+1];
					mark[i+1]=j;
				}	
		}
}


void Query()//查找
{
loop:printf("请输入要查找的员工号:");
	scanf("%d",&number);
	for(i=0;i<N;i++)
	{
		if(number==member[i].id)
		{
			printf("%-d\t%-s\t%s\t%d\t%.1f\t%s\t\n",member[i].id,member[i].name,member[i].job,member[i].age,member[i].mark,member[i].rank);
		    k=k+1;
			p=i;
		}
	}
	if(k==0)
	{
		printf("您查找的用户不存在，请重新输入!\n");
		goto loop;
	}   
}


void change()//修改
{
	int i;
	printf("\n请选择：1.退出\t\t2.修改姓名\t\t3.修改测评分\n");
	scanf("%d",&i);
	switch(i)
	{
		case 1: return;
		case 2:
		   printf("修改该员工的姓名为:");
		   scanf("%s",member[p].name);
		   judge();
	       printf("工号\t姓名\t职位\t年龄\t分数\t等级\n");
		   printf("%-d\t%-s\t%s\t%d\t%.1f\t%s\t\n",member[p].id,member[p].name,member[p].job,member[p].age,member[p].mark,member[p].rank);
	       printf("\n");
		   break;
		case 3:
		   printf("修改该员工的测评分为:");
		   scanf("%f",&member[p].mark);
		   judge();
		   printf("工号\t姓名\t职位\t年龄\t分数\t等级\n");
		   printf("%-d\t%-s\t%s\t%d\t%.1f\t%s\t\n",member[p].id,member[p].name,member[p].job,member[p].age,member[p].mark,member[p].rank);
	       printf("\n");
		   break;
	}
}

void paixu()//排序
{
	for(i=0;i<N;i++)
	{
		x[i]=i;
	}

	for(i=0;i<N;i++)
	{
		if(member[i].mark<member[i+1].mark)
		{
			z=x[i];
			x[i]=x[i+1];
			x[i+1]=z;
		}
	}
}


void output1()
{
	printf("=======================================================");
	printf("\n");
	printf("工号\t姓名\t职位\t年龄\t分数\n");
	for(i=0;i<N;i++)
	{
		printf("%-d\t%-s\t%s\t%d\t%.1f\t%s\t\n",member[i].id,member[i].name,member[i].job,member[i].age,member[i].mark,member[i].rank);
	}
	printf("\n");
}


void output2()
{
	printf("=======================================================");
	printf("\n");
	printf("工号\t姓名\t职位\t年龄\t分数\t等级\n");
	for(i=0;i<N;i++)
	{
		printf("%-d\t%-s\t%s\t%d\t%.1f\t%s\t\n",member[i].id,member[i].name,member[i].job,member[i].age,member[i].mark,member[i].rank);
	}
	printf("=======================================================");
	printf("\n");
	printf("成绩为优秀的人数有：%d\n",b);
	printf("成绩为良好的人数有：%d\n",c);
	printf("成绩为中等的人数有：%d\n",d);
	printf("成绩为及格的人数有：%d\n",e);
	printf("成绩为不及格的人数有：%d\n",f);
	printf("=======================================================");
	printf("\n");
}


void output3()
{
	printf("考核得分最高的员工:");
	printf("%-9d%-9s%-9s%-9d%-9.1f%-9s\n",member[mark[N-1]].id,member[mark[N-1]].name,member[mark[N-1]].job,member[mark[N-1]].age,member[mark[N-1]].mark,member[mark[N-1]].rank);
	printf("考核得分最低的员工:");
    printf("%-9d%-9s%-9s%-9d%-9.1f%-9s\n",member[mark[0]].id,member[mark[0]].name,member[mark[0]].job,member[mark[0]].age,member[mark[0]].mark,member[mark[0]].rank);
	printf("\n");
}

void output5()
{
	printf("=======================================================");
	printf("\n");
	printf("工号\t姓名\t职位\t年龄\t分数\n");
	for(i=0;i<N;i++)
	{
		printf("%-d\t%-s\t%s\t%d\t%.1f\t%s\t\n",member[x[i]].id,member[x[i]].name,member[x[i]].job,member[x[i]].age,member[x[i]].mark,member[x[i]].rank);
	}
	printf("\n");
}

void save()
{	
	FILE *fp;
	char ad[30];
	printf("请输入要保存的路径和文件名:（如：c:\\\\info.txt)\n");
	scanf("%s",ad);
	if((fp=fopen(ad,"w+"))==NULL)
		{
        printf("无法打开文件！\n");
		return;
		}
	fprintf(fp,"工号\t姓名\t职位\t年龄\t分数\t等级\n");
	judge();
	for(i=0;i<N;i++)
	{
		fprintf(fp,"%-d\t%-s\t%s\t%d\t%.1f\t%s\t\n",member[i].id,member[i].name,member[i].job,member[i].age,member[i].mark,member[i].rank);
	}
	fclose(fp);
	printf("保存成功！");
}



void read()
{
	FILE *fp;
	char ad2[30];
	printf("请输入要读取的路径和文件名:（如：c:\\\\info.txt)\n");
	scanf("%s",ad2);
	if((fp=fopen(ad2,"r"))==NULL)
	{
		printf("无法打开文件！\n");
		return;
	}
	fscanf(fp,"工号\t姓名\t职位\t年龄\t分数\t等级\n");
	for(i=0;i<N;i++)
	{
		fscanf(fp,"%d%s%s%d%f%s\n",&member[i].id,&member[i].name,&member[i].job,&member[i].age,&member[i].mark,&member[i].rank);
	}
	{
	fclose(fp);
	}
	if(EOF==-1)
	{
		o=o+1;
	}
}


void add()
{	
	FILE *fp;
	printf("请输入要添加的员工信息：\n");
	printf("工号\t姓名\t职位\t年龄\t分数\n");
	scanf("%d%s%s%d%f",&addd[1].id,addd[1].name,addd[1].job,&addd[1].age,&addd[1].mark);
	printf("请输入要添加的路径和文件名:（如：c:\\\\info.txt)\n");
	scanf("%s",ad2);
	if((fp=fopen(ad2,"a"))==NULL)
	{
		printf("无法打开文件！\n");
		return;
	}
	printf("\n");
	for(i=0;i<N;i++)
	{
		m[1]=addd[1].mark/10;
	}
	for(i=0;i<1;i++)
	{
		switch(m[1])
		{	
		case 10:strcpy(addd[1].rank,"优秀");break;
		case 9:strcpy(addd[1].rank,"优秀");break;
		case 8:strcpy(addd[1].rank,"良好");break;
		case 7:strcpy(addd[1].rank,"中等");break;
		case 6:strcpy(addd[1].rank,"及格");break;
		default:strcpy(addd[1].rank,"不及格");break;
		}
	}
	fprintf(fp,"%-d\t%-s\t%s\t%d\t%.1f\t%s\t\n",addd[1].id,addd[1].name,addd[1].job,addd[1].age,addd[1].mark,addd[1].rank);
	fclose(fp);
	printf("保存成功！");

	}


void NO1()
{
	notice();
	input();
	output1();
	o=o+1;
}


void NO2()
{
	judge();
	count();
	output2();
}


void NO3()
{
	judge();
	count();
	bubbling();
	output3();
}


void NO4()
{
	Query();
	change();
}


void NO5()
{
	judge();
	paixu();
	output5();
}


void NO6()
{
	save();
}


void NO7()
{
	read();
	judge();
	printf("=======================================================");
	printf("\n");
	printf("工号\t姓名\t职位\t年龄\t分数\t等级\n");
	for(i=0;i<N;i++)
	{
		printf("%-d\t%-s\t%s\t%d\t%.1f\t%s\t\n",member[i].id,member[i].name,member[i].job,member[i].age,member[i].mark,member[i].rank);
	}
	printf("=======================================================");
	printf("\n");
}


void NO8()
{
	add();
}

void NO9()
{
	exit(0);
}

int main(void)
{
    int t;
	printf("*********************欢迎使用员工信息管理系统*********************\n");
	while(1)
	{
		printf("1.输入并显示员工信息\n");
		printf("2.统计各等级员工各有多少人\n");
		printf("3.查询考核得分最高和最低员工\n");
		printf("4.查询并修改员工信息\n");
		printf("5.通过分数对员工进行排序\n");
		printf("6.保存员工信息到硬盘\n");
		printf("7.从硬盘读取员工信息\n");
		printf("8.添加员工信息到硬盘\n");
		printf("9.退出程序\n");
		printf("\n请输入您的选择编号：\n");
		scanf("%d",&t);
		switch(t)
		{
		case 1:NO1();break;

		case 2:
			if(o==0)
			{
				printf("请完成输入!\n");
				printf("\n");
			break;
			}
			printf("\n");
			NO2();break;
		case 3:
			if(o==0)
			{
				printf("请完成输入!\n");
				printf("\n");
			break;
			}
			printf("\n");
			NO3();break;
		case 4:
			if(o==0)
			{
				printf("请完成输入!\n");
				printf("\n");
			break;
			}
			printf("\n");
			NO4();break;
		case 5:
				if(o==0)
			{
				printf("请完成输入!\n");
				printf("\n");
			break;
				}
			NO5();break;
		case 6:
				if(o==0)
			{
				printf("请完成输入!\n");
				printf("\n");
			break;
				}
			NO6();break;
		case 7:
			NO7();break;
		case 8:
			NO8();break;
		case 9:
			NO9();break;
		}
	}
}
