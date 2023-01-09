#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE sizeof(Stu)

struct stuF {
    char id[20];
    char name[20];
    char class[20];
    int year;
    int month;
    int day;
    float jScore;
    float zScore;
    float xScore;
    float rScore;
    float sScore;
    struct stuF *next;
};

typedef struct stu {
    struct stuF data;
    struct stu *next;
} Stu;

int Meum() {
    printf("\n学分管理系统\n");
    printf("\n  \t1.  添加学生信息 \t\t 2.  学号查询学分");
    printf("\n  \t3.  学号修改学分 \t\t 4.  学号删除学生信息");
    printf("\n  \t5.  达到毕业要求的学生 \t\t 6.  查询所有");
    printf("\n  \t \t\t ");
    printf("\n                       \t0.  退出系统");
    printf("\n\n****");
    int n;
    printf("\n请输入想使用的功能序号：");
    scanf("%d", &n);
    return n;
}

int isOne(Stu *stu, char id[20]);

int isNumber(char *num);

void Add(Stu *stu) {
    Stu *p, *q;
    char n[10] = {0};
    q = stu;
    while (q->next != NULL) {
        q = q->next;
    }
    while (1) {
        printf("提示：输入0返回主菜单,输入任意继续！\n");
        printf("请输入操作符：");
        scanf("%s", n, 20);
        if (strcmp(n, "0") == 0) {
            break;
        }
        p = (Stu *) malloc(SIZE);
        while (p != NULL) {
            printf("请输入学号：");
            scanf("%s", p->data.id, 20);
            if (isOne(stu, p->data.id) == 1) {
                printf("\n不能输入重复的学号！\n");
            } else if (isOne(stu, p->data.id) == 0) {
                break;
            }
        }
        if (p != NULL) {
            printf("请输入姓名：");
            scanf("%s", p->data.name, 20);
            printf("请输入班级：");
            scanf("%s", p->data.class, 20);
            while (1) {
                char year[20] = {0};
                printf("请输入入学年份：");
                scanf("%s", &year, 20);
                if (isNumber(year) == 1 && atoi(year) <= 2022) {
                    p->data.year = atoi(year);
                    break;
                } else {
                    printf("输入年份不合法！");
                }
            }
            while (1) {
                char month[20] = {0};
                printf("请输入入学月份：");
                scanf("%s", &month, 20);
                if (atoi(month) >= 1 && atoi(month) <= 12 &&
                    isNumber(month) == 1) {
                    p->data.month = atoi(month);
                    break;
                } else {
                    printf("输入月份不合法(1-12)！");
                }
            }
            while (1) {
                char day[20] = {0};
                printf("请输入入学日期：");
                scanf("%s", &day, 20);
                if (atoi(day) >= 1 && atoi(day) <= 31 && isNumber(day) == 1) {
                    p->data.day = atoi(day);
                    break;
                } else {
                    printf("输入日期不合法(1-31)！");
                }
            }
            printf("提示：已经完成一条记录的添加");
            p->next = NULL;
            q->next = p;
            q = p;
        } else {
            printf("分配内存失败！");
            return;
        }
    }

}

//学号唯一校验
int isOne(Stu *stu, char id[20]) {
    Stu *p;
    p = stu->next;
    if (p == NULL) {
        return 0;
    }
    while (p != NULL) {
        if (strcmp(p->data.id, id) == 0) {
            return 1;
            break;
        }
        p = p->next;
    }
    return 0;
}

//检验输入是否是数字
int isNumber(char *num) {
    int i;
    for (i = 0; num[i]; i++) {
        if (num[i] > '9' || num[i] < '0') {
            return 0;
        }
    }
    return 1;
}


//显示所有
int show(Stu *stu) {
    Stu *p;
    p = stu->next;
    if (p == NULL) {
        printf("没有信息可以显示！\n");
        return 0;
    }
    printf("\t\t\t\t显示结果\n");
    printf("\n学号\t姓名\t班级\t入学时间\t基础学分\t专业学分\t选修学分\t人文学分\t实验学分\n");
    while (p != NULL) {
        printf("\n%s\t%s\t%s\t%d-%d-%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t\n",
               p->data.id, p->data.name, p->data.class, p->data.year,
               p->data.month, p->data.day, p->data.jScore, p->data.zScore,
               p->data.xScore, p->data.rScore, p->data.sScore);
        p = p->next;
    }
    return 0;
}

//根据学号修改学分  链表->比较常用且基础的数据结构
// 1. 代码风格
// 2. 健壮性（错误和边界情况，尽量写得详细一下）
// 3. 增加一些必要的注释
int update(Stu *stu) {
    // 【xx,yy】-> 【xx,yy】-> 【xx,yy】
    Stu *p;
    char find[20] = {0};
    p = stu->next;
    // 不存在有效的学生信息
    if (p == NULL) {
        printf("\n没有信息可以修改！\n");
        return 0;
    }
    printf("请输入要修改学分的学号：");
    // C标准库函数
    scanf("%s", find);

    while (p != NULL) {
        // 在链表中找到了要改的学号，就直接退出
        if (strcmp(p->data.id, find) == 0) {
            break;
        }
        p = p->next;
    }

    // p == NULL 在链表中没有 要修改的学号
    if (p != NULL) {
        int x;
        while (1) {
            printf("完成修改请输入0，否则输入非零进行修改！");
            scanf("%d", &x);
            if (x == 0) {
                break;
            }
            while (1) {
                float jscore;
                printf("请输入基础学分：");
                scanf("%f", &jscore);
                if (jscore <= 100) {
                    p->data.jScore = jscore;
                    break;
                } else {
                    printf("学分不合法！(最高为100)");
                }
            }
            while (1) {
                float zscore;
                printf("请输入专业学分：");
                scanf("%f", &zscore);
                if (zscore <= 100 && zscore >= 0) {
                    p->data.zScore = zscore;
                    break;
                } else {
                    printf("学分不合法！(最高为100)");
                }
            }
            while (1) {
                float xscore;
                printf("请输入选修学分：");
                scanf("%f", &xscore);
                if (xscore <= 100) {
                    p->data.xScore = xscore;
                    break;
                } else {
                    printf("学分不合法！(最高为100)");
                }
            }
            while (1) {
                float rscore;
                printf("请输入人文学分：");
                scanf("%f", &rscore);
                if (rscore <= 100) {
                    p->data.rScore = rscore;
                    break;
                } else {
                    printf("学分不合法！(最高为100)");
                }
            }
            while (1) {
                float sscore;
                printf("请输入实验学分：");
                scanf("%f", &sscore);
                if (sscore <= 100) {
                    p->data.sScore = sscore;
                    break;
                } else {
                    printf("学分不合法！(最高为100)");
                }
            }
            printf("\n信息已经修改！\n");
        }
    } else {
        printf("\n提示：没有你要修改的信息！\n");
    }
    return 0;
}


//按照学号查询学分
int selectId(Stu *stu) {
    Stu *p;
    int sel;
    char find[20] = {0};
    p = stu->next;
    if (p == NULL) {
        printf("\n提示：没有数据可以查询！\n");
        return 0;
    }
    printf("\n提示：\n输入0----退出\t输入1----按学号查询\n");
    printf("请选择：");
    scanf("%d", &sel);
    if (sel == 1) {
        printf("\n请输入你要查询学分的学生学号：");
        scanf("%s", find, 20);
        while (p != NULL) {
            if (strcmp(p->data.id, find) == 0) {
                printf("学号\t姓名\t基础学分\t专业学分\t选修学分\t人文学分\t实验学分\n");
                printf("\n%s\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\n",
                       p->data.id, p->data.name, p->data.jScore, p->data.zScore,
                       p->data.xScore, p->data.rScore, p->data.sScore);
                break;
            }
            p = p->next;
        }
    } else if (sel == 0) {
        return 0;
    }
    return 0;
}

//根据学生学号删除学生信息
int delete(Stu *stu) {
    Stu *p, *r;
    char find[20] = {0};
    p = stu->next;
    if (p == NULL) {
        printf("提示：没有学生信息可以删除！\n");
        return 0;
    }
    printf("\n提示：请输入你要删除的学生学号：");
    scanf("%s", find, 20);
    while (p != NULL) {
        if (strcmp(p->data.id, find) == 0) {
            break;
        }
        p = p->next;
    }
    if (p != NULL) {
        r = stu;
        while (r->next != p) {
            r = r->next;
        }
        r->next = r->next->next;
        printf("\n删除成功！\n");
    } else {
        printf("\n删除失败！");
    }

    return 0;
}

//查询满足毕业的学生信息
int selectC(Stu *stu) {
    Stu *p;
    p = stu->next;
    if (p == NULL) {
        printf("没有信息可以显示！\n");
        return 0;
    }
    printf("\t\t\t\t显示结果\n");
    printf("\n学号\t姓名\t班级\t入学时间\t基础学分\t专业学分\t选修学分\t人文学分\t实验学分\n");
    while (p != NULL) {
        if (p->data.jScore >= 50 && p->data.zScore >= 50 &&
            p->data.xScore >= 24 && p->data.rScore >= 8 &&
            p->data.sScore >= 20) {
            printf("\n%s\t%s\t%s\t%d-%d-%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t\n",
                   p->data.id, p->data.name, p->data.class, p->data.year,
                   p->data.month, p->data.day, p->data.jScore, p->data.zScore,
                   p->data.xScore, p->data.rScore, p->data.sScore);
        }
        p = p->next;
    }
    return 0;
}


int main() {
    Stu *stu;
    stu = (Stu *) malloc(SIZE);
    stu->next = NULL;

    while (1) {
        int a = Meum();
        switch (a) {
            case 1:
                Add(stu);
                break;
            case 2:
                selectId(stu);
                break;
            case 3:
                update(stu);
                break;
            case 4:
                delete(stu);
                break;
            case 5:
                selectC(stu);
                break;
            case 6:
                show(stu);
                break;
            case 0:
                printf("系统退出成功！");
                free(stu);
                exit(0);
            default:
                printf("输入选项错误！");
                break;
        }
    }
}





