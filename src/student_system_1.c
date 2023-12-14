#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define XX printf("%-10s%-10s%-10s%-10s%-10s%-10s\n","学号","姓名","语文","数学","英语","总分")
#define size 60

struct Student
{
    int ID;
    char name[8];
    int Chinese;
    int Math;
    int English;
    int sum;
};
static int n;
struct Student stu[60];

void menu()//菜单
{
    printf("*****************************************\n");
    printf("*                                       *\n");
    printf("*            学生成绩管理系统             *\n");
    printf("*                                       *\n");
    printf("*****************************************\n");
    printf("*                                       *\n");
    printf("*       (1)输入成绩     (2)显示成绩       *\n");
    printf("*                                      *\n");
    printf("*       (3)修改成绩     (4)删除成绩       *\n");
    printf("*                                       *\n");
    printf("*       (5)查询成绩     (6)成绩查询       *\n");
    printf("*                                       *\n");
    printf("*       (7)退出系统                      *\n");
    printf("*****************************************\n");
}
void add()
{
    int i,ID=0;
    char quit;
    do{
        printf("学号:");
        scanf("%d",&ID);
        for(i=0;i<n;i++)
        {
            if(ID==stu[i].ID)
            {
                printf("此学号存在\n");
                return;
            }
        }
        stu[n].ID=ID;
        printf("姓名:");
        scanf("%s", &stu[n].name);
        printf("语文成绩:");
        scanf("%d", &stu[n].Chinese);
        printf("数学成绩:");
        scanf("%d", &stu[n].Math);
        printf("英语成绩:");
        scanf("%d", &stu[n].English);
        stu[n].sum=stu[n].Chinese+stu[n].Math+stu[n].English;
        n++;
        printf("是否继续添加?(Y/N)");
        scanf("\t%c",&quit);
    }
    while (quit !='N');
}



void show(int i)
{
    printf("%-10d", stu[i].ID);
    printf("%-10s", stu[i].name);
    printf("%-10d", stu[i].Chinese);
    printf("%-10d", stu[i].Math);
    printf("%-10d", stu[i].English);
    printf("%-10d\n", stu[i].sum);
}
void showAll()
{
    int i;
    XX;
    for(i=0;i<n;i++)
    {
        show(i);
    }
}

void modify()
{
    char name[8],ch;
    int i;
    printf("修改学生成绩\n");
    printf("请输入学生姓名:");
    scanf("%s",&name);
    for(i=0;i<n;i++)
    {
        if(strcmp(name,stu[i].name)==0)
        {
            getchar();
            printf("学生信息如下\n");
            XX;
            show(i);
            printf("是否需要修改?(Y/N)\n");
            scanf("%c",&ch);
            if(ch=='Y'||ch=='y')
            {
                getchar();
                printf("姓名:");
                scanf("%s",&stu[i].name);
                printf("语文成绩:");
                scanf("%d",&stu[i].Chinese);
                printf("数学成绩:");
                scanf("%d",&stu[i].Math);
                printf("英语成绩:");
                scanf("%d",&stu[i].English);
                stu[i].sum=stu[i].Chinese+stu[i].Math+stu[i].English;
                printf("修改完毕!\n");
            }
            return;
        }
    }
    printf("找不到这个学生.\n");
}

void del()
{
    int ID,i;
    char ch;
    printf("删除学生信息\n");
    printf("请输入学号:");
    scanf("%d",&ID);
    for(i=0;i<n;i++)
    {
        if(ID==stu[i].ID)
        {
            getchar();
            printf("学生信息如下:\n");
            XX;
            show(i);
            printf("是否删除?(Y/N)\n");
            scanf("%c",&ch);
            if(ch=='Y'||ch=='y')
            {
                for(i=0;i<n;i++)
                    stu[i]=stu[i+1];
                n--;
                printf("删除成功!");
            }
            return;
        }
    }
    printf("找不到这个学生!\n");
}

void search()
{
    char name[8];
    int i;
    printf("查询学生成绩\n");
    printf("请输入学生姓名:");
    scanf("%s",&name);
    for(i=0;i<n;i++)
    {
        if(strcmp(name,stu[i].name)==0)
        {
            printf("学生成绩如下:");
            XX;
            show(i);
            return;
        }
    }
    printf("找不到这个学生!\n");
}

void sort ()
{
    int i,j;
    struct Student t;
    printf("按总成绩排序\n");
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(stu[i].sum<stu[j].sum)
            {
                t=stu[i];
                stu[i]=stu[j];
                stu[j]=t;
            }
        }
    }
    printf("结果如下:\n");
    showAll();
}

enum command{CMD_QUIT,CMD_ADD,CMD_SHOWALL,CMD_MODIFY,CMD_DEL,CMD_SEARCH,CMD_SORT,CMD_END};
struct cmdfunc
{
    enum command cmd;
    void(*runcmd)(struct Student stu[]);
}
        proc[CMD_END]=
        {
                {CMD_QUIT,NULL},
                {CMD_ADD,add},
                {CMD_SHOWALL,showAll},
                {CMD_MODIFY,modify},
                {CMD_DEL,del},
                {CMD_SEARCH,search},
                {CMD_SORT,sort}
        };
int main()
{

    int select,quit=1;
    while(1)
    {
        menu();
        scanf("%d",&select);
        if(select>=CMD_END||select<0)
        {
            printf("输入1-7之间的数字\n");
        }
        else{
            if(select==CMD_QUIT)
            {
                quit=2;
            }
            else
            {
                proc[select].runcmd(stu);
            }
        }
        if(quit==2)
        {
            break;
        }
        printf("按任意键返回主菜单\n");
        getchar();
        getchar();
    }

    printf("程序结束!\n");
    return 0;
}