
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define  N  100  //数组长度

//定义结构体类型，存放登录信息
struct  User
{
    char name[20];   //用户名称
    char code[20];   //用户密码
} user;

//定义结构体类型，存放学生数据
typedef struct
{
    int    num;
    char   name[10];
    float  score;
} Student; //类型名称

//调用在前，定义在后，函数声明
void Read(Student     *s, int *n);   //从文件读取数据
void Save(Student     *s, int n);    //数据保存到文件
void menu(Student     *s, int *n);   //显示主控菜单
void Display(Student  *s, int n);    //显示学生数据
void Append(Student   *s, int *n);   //追加学生数据
void Search(Student   *s, int n);    //查找学生
void Delete(Student   *s, int *n);   //删除学生
void Modify(Student   *s, int n);    //修改学生数据
void Census(Student   *s, int n);    //统计成绩
void SortBynum(Student   *s, int n);    //按照学号排序
void SortByscore(Student *s, int n);    //按照分数排序
void SortByname(Student  *s, int n);    //按照姓名排序
void entry(FILE  *fp);  //用户登录
void enroll(FILE *fp);  //用户注册
void Login();           //调用注册和登录函数

int main()
{
    int  n;          //记录实际学生人数
    Student s[N];    //定义数组，存放学生数据，N为数组长度
//    Login();         //登录系统
//    Read(s, &n);     //读取文件，统计学生人数
    menu(s, &n);     //主控菜单，实现追加、查找、修改、删除、排序等功能
//    Save(s,  n);     //保存数据，返回menu函数，自动保存数据
    return 0;
}

void menu(Student *s, int  *n )//菜单
{
    int choice;
    while (1)
    {        printf("\n\t\t          学生成绩管理系统");
        printf("\n\t\t**********************************");
        printf("\n\t\t*        1-----显示数据          *");
        printf("\n\t\t*        2-----追加学生          *");
        printf("\n\t\t*        3-----查找学生          *");
        printf("\n\t\t*        4-----删除学生          *");
        printf("\n\t\t*        5-----修改数据          *");
        printf("\n\t\t*        6-----统计成绩          *");
        printf("\n\t\t*        7-----按照学号排序      *");
        printf("\n\t\t*        8-----按照成绩排序      *");
        printf("\n\t\t*        9-----按照姓名排序      *");
        printf("\n\t\t*        0-----保存结束          *");
        printf("\n\t\t**********************************");
        printf("\n\t\t         选择菜单序号(0--9):");
        scanf("%d", &choice);
        switch (choice)
        {        case 1:
                Display(s,  *n);
                break;
            case 2:
                Append(s,   n);
                Display(s,  *n);
                break;
            case 3:
                Search(s,   *n);
                break;
            case 4:
                Delete(s, n);
                Display(s, *n);
                break;
            case 5:
                Modify(s,  *n);
                break;
            case 6:
                Census(s, *n);
                break;
            case 7:
                SortBynum(s, *n);
                Display(s,  *n);
                break;
            case 8:
                SortByscore(s, *n);
                Display(s,  *n);
                break;
            case 9:
                SortByname(s, *n);
                Display(s,  *n);
                break;
            case 0:
                return;    //返回main函数，执行保存操作
            default:
                printf("\n\t\t选择错误,再次选择!\n");
        }//switch
    }//while
}//menu

void Read(Student *s, int *n) //读取数据
{        int i = 0;
    FILE *fp = fopen("student.txt", "ab+");
    fread(&s[i], sizeof(Student), 1, fp);
    while (!feof(fp))
    {        i = i + 1;
        fread(&s[i], sizeof(Student), 1, fp);
    }
    *n = i;
    fclose(fp);
}

void Save(Student *s, int n)  //保存数据
{        int i;
    FILE *fp = fopen("student.txt", "wb");
    for (i = 0; i < n; i++)
        fwrite(&s[i], sizeof(Student), 1, fp);
    fclose(fp);
}

void Display(Student s[], int n) //显示数据
{        int i;
    printf("学号\t\t姓名\t\t成绩\n");
    for (i = 0;  i < n; i++)
    {        printf("%d\t\t",  s[i].num);
        printf("%s\t\t",  s[i].name);
        printf("%5.2f\n", s[i].score);
    }
}

void Append(Student *s, int *n) //追加学生
{
    Student t;
    printf("输入学号:");
    scanf("%d", &t.num);
    printf("输入姓名:");
    scanf("%s", t.name);
    printf("输入分数:");
    scanf("%f", &t.score);
    s[*n] = t; //尾部追加
    *n++;   //学生人数加1
}

void Search(Student *s, int n) //查找
{        int i, num;
    printf("输入学号:");
    scanf("%d", &num);
    for (i = 0;  i < n;  i++ )
        if (s[i].num == num )
        {        printf("%d\t",    s[i].num);
            printf("%s\t",    s[i].name);
            printf("%5.2f\n", s[i].score);
            return;
        }
    printf("该学生不存在!\n");
}

void Delete(Student *s, int  *n) //删除一个学生
{        int  num, i, k;
    printf("输入学号:");
    scanf("%d", &num);
    for (i = 0;  i < *n;  i++ )
        if (s[i].num == num ) //如果找到
        {
            for (k = i;  k + 1 < *n;  k++)
                s[k] = s[k+1];    //依次左移
            *n--;           //学生人数减1

            return;
        }
    printf("该学生不存在!\n");
}

void Modify(Student *s, int n) //修改数据
{        int i, num;
    printf("输入学号:");
    scanf("%d", &num);
    for (i = 0;  i < n;  i++ )
        if ( s[i].num == num )
        {
            printf("%s\t",   s[i].name);
            scanf("%s", s[i].name);
            printf("%5.2f\t", s[i].score);
            scanf("%f", &s[i].score);
            return;
        }
    printf("该学生不存在!\n");
}

void Census(Student *s, int n) //统计成绩
{
    int i;
    float max, min, sum;
    max = min = sum = s[0].score;
    for (i = 1;  i < n; i++)
    {
        sum ++;
        if (s[i].score > max)
            max = s[i].score;
        else if (s[i].score < min)
            min = s[i].score;

    }
    printf("max=%5.2f min=%5.2f av=%5.2f\n", max, min, sum / n);
}

void SortBynum(Student *s, int n)
{        //按照学号升序排列
    int i, j;
    Student t;
    for (i = 1;  i < n;  i++)        //n个学生，n-1趟排序
        for (j = 0;   j < n - i;   j++)
            if (s[j].num > s[j + 1].num )
            {
                t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;
            }
}

void SortByscore(Student *s, int n)
{        //按照成绩升序排列
    int i, j;
    Student t;
    for (i = 1;  i < n;  i++)        //n个学生，n-1趟排序
        for (j = 0;   j < n - i;   j++)
            if (s[j].score > s[j + 1].score )
            {
                t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;
            }
}

void SortByname(Student *s, int n)
{
    //按照姓名升序排列
    int i, j;
    Student t;
    for (i = 1;  i < n;  i++)      //n个数，n-1趟排序
        for (j = 0;  j < n - i;   j++)
            if (strcmp(s[j].name, s[j+1].name) > 0)
            {
                t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;
            }
}

void entry(FILE *fp) //用户登录
{
    int count = 0;
    char name[20];
    char code[20];
    while (count < 3)
    {        printf("输入用户名称:");
        scanf("%s", name);
        printf("输入用户密码:");
        scanf("%s", code);
        rewind(fp);
        while (!feof(fp))
        {
            fread(&user, sizeof(user), 1, fp);
            if (strcmp(user.name, name) == 0 && strcmp(user.code, code) == 0 )
                return;
        }
        if (feof(fp))
            printf("登录失败，用户名称或密码错误!\n");
        count = count + 1;
    }
    if (count >= 3) //超出登录次数，结束运行
        exit(0);
}

void enroll(FILE *fp) //用户注册
{
    printf("输入用户名称:");
    scanf("%s", user.name);
    printf("输入用户密码:");
    scanf("%s", user.code);
    fseek(fp, 0, 2);
    fwrite(&user, sizeof(user), 1, fp);
    printf("注册成功!\n");
}

void Login()
{        int choice;
    FILE *fp = fopen("users.txt", "at+");
    while (1)
    {        printf("\t\t*************************\n");
        printf("\t\t*      1--登录          *\n");
        printf("\t\t*      2--注册          *\n");
        printf("\t\t*      3--结束          *\n");
        printf("\t\t*************************\n");
        printf("\t\t    选择菜单序号(1--3):");
        scanf("%d", &choice);
        switch (choice)
        {
            case  1:
                entry(fp);
                return;
            case  2:
                enroll(fp);
                continue;
            case  3:
                exit(0);    //结束运行
        }
    }
    fclose(fp);
}