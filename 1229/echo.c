#include<stdio.h>
#include <string.h>
int input();
void search();
int sort();
void add();
void defeat();
void name();
int number();
/*结构体储存员工消息*/
struct staff
{
    char name[20];
    int num;
    char bir[20];
    char sex[4];
    char dep[20];
    char tit[20];
    char lev[4];
    int title;
};
struct staff s[99];
int n;
float sta;
/*main函数*/
int main()
{
    int control;
    while(control!=6)
    {
        printf("职工信息管理系统\n");/*界面*/
        printf("1.输入信息\n");
        printf("2.查找功能\n");
        printf("3.排序功能\n");
        printf("4.增加功能\n");
        printf("5.删除功能\n");
        printf("6.quit\n");
        scanf("%d",&control);
        switch(control)
        {
            case 1:/*职工信息录入*/
                input();
                break;
            case 2:/*职工信息查找*/
                search();
                break;
            case 3:/*职工排序*/
                sort();
                break;
            case 4:/*职工信息增加*/
                add();
                break;
            case 5:/*职工信息删除*/
                defeat();
                break;
        }
    }

    printf("Bye!");
    return 0;
}

/*信息录入*/
int input() {
    while(1) {
        puts("职工编号： ");
        scanf("%d", &s[n].num);
        puts("职工姓名： ");
        scanf("%s", s[n].name);
        puts("职工性别： ");
        scanf("%s", s[n].sex);
        puts("职工出生年月： ");
        scanf("%s", s[n].bir);
        puts("职工所在部门： ");
        scanf("%s", s[n].dep);
        puts("职工职称： ");
        scanf("%s", s[n].tit);
        puts("职工月薪级别： ");
        scanf("%s", s[n].lev);
        n++;
        puts("是否继续添加(yes/no)");
        char input[64];
        scanf("%s", input);
        if(strcmp(input, "yes") == 0) {
            continue;
        } else {
            break;
        }
    }
    puts("职工编号 职工姓名 职工性别 职工出生年月 职工所在部门 职工职称 职工月薪级别");
    for(int i=0; i<n; i++)
        printf("%d，%s，%s，%s，%s, %s，%s \n",s[i].num,s[i].name,s[i].sex,s[i].bir,s[i].dep,s[i].tit,s[i].lev);
}
/*信息查询*/
void search()
{
    printf("按照姓名查询请输入7按照编号查询请按8: ");
    int choose;
    scanf("%d",&choose);
    switch(choose)
    {
        case 7:
            name();
            break;
        case 8:
            number();
            break;
    }
}
/*按照姓名查询职工信息*/
void name()
{   printf("输入查找姓名： ");

    char ch[99];

    scanf("%s",ch);
    for(int i=0; i < n; i++)
    {
        if(strcmp(ch,s[i].name)==0 )/*比较字符串是否相等*/
        {
            printf("%d, %s, %s ,%s, %s, %s, %s\n",s[i].num,s[i].name,s[i].sex,s[i].bir,s[i].dep,s[i].tit,s[i].lev);
        }
    }
}
/*按照编号查询职工信息*/
int number()
{   printf("输入查找编号： ");
    int conet;

    scanf("%d",&conet);
    for(int i=0; i < n; i++)
    {
        if(conet==(s[i].num) )
        {

            printf("%d, %s, %s ,%s, %s, %s, %s\n",s[i].num,s[i].name,s[i].sex,s[i].bir,s[i].dep,s[i].tit,s[i].lev);
        }
    }
}
/*排序功能*/
int sort()
{
    struct staff ch;/*定义中间结构体*/
    struct staff sh;/*定义中间结构体*/
    puts("请输入所有职工的职称");
    for(int i=0; i<n; i++)
    {
        scanf("%s",&s[i].tit);
        if(strcmp(s[i].tit,"组员")==0)/*将中文转化为数字*/
        {
            s[i].title=1;
        }
        if(strcmp(s[i].tit,"组长")==0)
        {
            s[i].title=2;
        }
        if(strcmp(s[i].tit,"副部长")==0)
        {
            s[i].title=3;
        }
        if(strcmp(s[i].tit,"部长")==0)
        {
            s[i].title=4;
        }
    }
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(s[j].title<s[j+1].title)
            {
                sh=s[j];
                s[j]=s[j+1];
                s[j+1]=sh;
            }
            if(s[j].title==s[j+1].title)
            {
                if(s[j].num<s[j+1].num)
                {
                    ch=s[j];
                    s[j]=s[j+1];
                    s[j+1]=ch;
                }
            }
        }
    }
    puts("职工编号 职工姓名 职工性别 职工出生年月 职工所在部门 职工职称 职工月薪级别");
    for(int j=0; j<n; j++)
        printf("%d，%s，%s，%s，%s, %s，%s\n",s[j].num,s[j].name,s[j].sex,s[j].bir,s[j].dep,s[j].tit,s[j].lev);
}
/*增加职工信息函数*/
void add()
{
    int i;
    char sh[99];
    printf("输入增加的职工姓名： ");
    scanf("%s",sh);
    input();
}
/*删除职工信息*/
void defeat()
{   char ch[99];
    puts("输入要删除信息的职工姓名： ");
    scanf("%s",ch);
    for(int i=0; i<n; i++)
        if(strcmp(ch,s[i].name)==0) {
            for(int j=i; j + 1 < n; j++)
            {
                s[j]=s[j+1];
            }
            n--;
            break;
        }

}