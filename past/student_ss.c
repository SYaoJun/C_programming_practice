#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>//用于getch
#define N 50

typedef struct _Student//结构体类型
{
    char name[20];
    int studentID;
    int yuwen;
    int math;
    int English;
    int s;
}Student;

typedef struct _Node
{
    Student stu;
    struct _Node* pNext;//指向下一个节点的指针
}Node;

Node *g_pHead = NULL;//头结点

void StartSystem();
void Input();//输入学生信息
void Signal();//显示学生成绩
Node* FindStudent();//查找学生成绩
void ModifyStudent();//修改学生信息
void DeleteStudent();//删除学生信息

int main()
{
    while(1)
    {
        StartSystem();

        char ch = getch();//接受一个字符 ,不需要按回车
        switch(ch)
        {
            case '1'://输入学生信息
                Input();
                break;
            case '2':// 显示学生成绩
                Signal();
                break;
            case '3'://查询成绩
            {
                Node*p = FindStudent();
                if(p !=NULL)
                {
                    printf("名字：%s\t学号：%d\t语文：%d\t数学：%d\t英语：%d\n",p->stu.name,p->stu.studentID,p->stu.yuwen,p->stu.math,p->stu.English);
                }
                else
                {
                    printf("没找到该学生:\n");
                }
                system("pause");
                system("cls");
                break;
            }
            case '4'://修改成绩
                ModifyStudent();
                break;
            case '5'://删除成绩
                DeleteStudent();
                break;
            case '6'://成绩排序
                break;
            case '7'://退出系统
                printf("操作结束\n");
                return 0;
            default:
                printf("您的输入有误，请重新输入\n");
                system("pause");
                system("cls");
                break;
        }
    }

    return 0;
}

void StartSystem()
{
    printf("****************************************\n");
    printf("*         学生成绩管理系统             *\n");
    printf("****************************************\n");
    printf("*  欢迎使用系统，请选择要执行的功能    *\n");
    printf("****************************************\n");
    printf("*    1.成绩输入       2.显示成绩       *\n");
    printf("*    3.查询成绩       4.修改成绩       *\n");
    printf("*    5.删除成绩       6.成绩排序       *\n");
    printf("*    7.退出系统                        *\n");
    printf("****************************************\n");
}

void Input()
{
    //创建一个新结点
    Node* pNewNode = (Node*)malloc(sizeof(Node));
    pNewNode->pNext = NULL;

    if (g_pHead == NULL)
    {
        g_pHead = pNewNode;
    }
    else
    {
        pNewNode->pNext = g_pHead;
        g_pHead = pNewNode;
    }

    printf("输入学生名字：\n");
    scanf("%s",pNewNode->stu.name);//只有地址不用加&
    printf("输入学生学号：\n");
    scanf("%d",&pNewNode->stu.studentID);
    printf("输入学生语文成绩：\n");
    scanf("%d",&pNewNode->stu.yuwen);
    printf("输入学生数学成绩：\n");
    scanf("%d",&pNewNode->stu.math);
    printf("输入学生英语成绩：\n");
    scanf("%d",&pNewNode->stu.English);

    printf("学生信息已输入完毕\n");
    system("pause");
    system("cls");//清屏
}

void Signal()
{
    system("cls");
    printf("*******************************************\n");
    printf("*         学生成绩管理系统                *\n");
    printf("*******************************************\n");

    printf("*\t名字\t*\t学号\t*\t语文\t*\t数学\t*\t英语\n");
    printf("*******************************************\n");

    Node* p = g_pHead;
    while (p != NULL)
    {
        printf("*\t%s\t*\t%d\t*\t%d\t*\t%d\t*\t%d*\n",p->stu.name,p->stu.studentID,p->stu.yuwen,p->stu.math,p->stu.English);

        p = p->pNext;
    }
    printf("*******************************************\n");
    system("pause");
    system("cls");
}

Node* FindStudent()
{
    char sName[20];

    printf("请输入要查找的学生的名字：\n");
    scanf("%s",sName);
    Node* p = g_pHead;
    while(p != NULL)
    {
        if(p->stu.name == sName  ||  0 == strcmp(p->stu.name,sName) )//strcmp字符串比较函数
        {
            return p;
        }
        p = p->pNext;
    }

    return NULL;
}
void ModifyStudent() {
    int nStuID;
    printf("请输入修改学生信息的学号：\n");
    scanf("%d", &nStuID);

    Node *p = g_pHead;
    while (p != NULL) {
        if (p->stu.studentID == nStuID) {
            printf("请输入要修改的学生名字 语文成绩 数学成绩 英语成绩：\n");
            scanf("%s %d %d %d ", p->stu.name, &p->stu.yuwen, &p->stu.math,
                  &p->stu.English);
            printf("修改成功\n");
            break;
        }
        p = p->pNext;
    }
    if (p == NULL) {
        printf("没找到该学生信息\n");
    }

    system("pause");
    system("cls");
}
void DeleteStudent()
{
    int nStuNum;
    printf("请输入要删除的学生学号：\n");
    scanf("%d",&nStuNum);

    Node* p1, *p2;
    if(g_pHead->stu.studentID == nStuNum)
    {
        p1 = g_pHead;
        g_pHead = g_pHead->pNext;
        free(p1);
        return;
    }

    Node* p = g_pHead;
    while(p->pNext != NULL)
    {
        if(p->pNext->stu.studentID == nStuNum)
        {
            p2 = p->pNext;
            p->pNext = p->pNext->pNext;
            free(p2);
            return;
        }

        p = p->pNext;

        if(p->pNext == NULL)
        {
            break;
        }
    }
    if(p->pNext == NULL)
    {
        printf("没有找到该学生\n");
    }
}