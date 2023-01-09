#include<stdio.h>
#include <string.h>

int input();

void search();

int sort();

void add();

void defeat();

void name();

int number();

void num();

void nam();

void bir();

void sex();

void tit();

void lev();

void dep();

/*结构体储存员工消息*/
struct staff {
    char name[20];
    int num;
    char bir[20];
    char sex[4];
    char dep[20];
    char tit[20];
    char lev[4];
    float sta;
    int title;
};
struct staff s[99];
/*main函数*/
static int n = 0;

int main() {
    int control;
    while (control != 6) {
        printf("职工信息管理系统\n");/*界面*/
        printf("1.输入信息\n");
        printf("2.查找功能\n");
        printf("3.排序功能\n");
        printf("4.增加功能\n");
        printf("5.删除功能\n");
        printf("6.quit\n");
        scanf("%d", &control);
        switch (control) {
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
        }else{
            break;
        }
    }

    puts("职工编号 职工姓名 职工性别 职工出生年月 职工所在部门 职工职称 职工月薪级别");
    for (int i = 0; i < n; i++)
        printf("%d，%s，%s，%s，%s, %s，%s\n", s[i].num, s[i].name, s[i].sex,
               s[i].bir, s[i].dep, s[i].tit, s[i].lev);
}

/*信息查询*/
void search() {
    printf("按照姓名查询请输入0，按照编号查询请按7");
    int choose;
    scanf("%d", &choose);
    switch (choose) {
        case 0:
            name();
            break;
        case 7:
            number();
            break;
    }
}

void name() {
    printf("输入查找姓名： ");
    char ch[99];
    scanf("%s", ch);
    for (int i = 0; i < n; i++) {
        if (strcmp(ch, s[i].name) == 0) {
            printf("%d, %s, %s ,%s, %s, %s, %s, %f\n", s[i].num, s[i].name,
                   s[i].sex, s[i].bir, s[i].dep, s[i].tit, s[i].lev, s[i].sta);
        }


    }

}

int number() {
    printf("输入查找编号： ");
    int conet;
    scanf("%d", &conet);
    for (int i = 0; i < n; i++) {
        if (conet == s[i].num) {
            printf("%d, %s, %s ,%s, %s, %s, %s, %f\n", s[i].num, s[i].name,
                   s[i].sex, s[i].bir, s[i].dep, s[i].tit, s[i].lev, s[i].sta);
        }


    }

}

void show_info(){
    puts("职工编号 职工姓名 职工性别 职工出生年月 职工所在部门 职工职称 职工月薪级别");
    for (int j = 0; j < n; j++)
        printf("%d，%s，%s，%s，%s, %s，%s\n", s[j].num, s[j].name, s[j].sex,
               s[j].bir, s[j].dep, s[j].tit, s[j].lev);
}
int sort() {
    struct staff ch;
    struct staff sh;
//    puts("请输入所有职工的职称");
    for (int i = 0; i < n; i++) {
//        scanf("%s", s[i].tit);
        if (strcmp(s[i].tit, "组员") == 0) {
            s[i].title = 1;
        } else if (strcmp(s[i].tit, "组长") == 0) {
            s[i].title = 2;
        } else if (strcmp(s[i].tit, "副部长") == 0) {
            s[i].title = 3;
        } else if (strcmp(s[i].tit, "部长") == 0) {
            s[i].title = 4;
        } else {
            s[i].title = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (s[j].title < s[j + 1].title) {
                sh = s[j];
                s[j] = s[j + 1];
                s[j + 1] = sh;
            }
            if (s[j].title == s[j + 1].title && s[j].num > s[j + 1].num) {
                ch = s[j];
                s[j] = s[j + 1];
                s[j + 1] = ch;
            }
        }
    }
    show_info();
}

void add() {
    int i;
    char sh[99];
    printf("输入增加信息的职工姓名： ");
    scanf("%s", sh);
    for (i = 0; i < n; i++) {
        if (strcmp(sh, s[i].name) == 0) {
            puts("职工月薪： ");
            scanf("%f", &s[i].sta);
            printf("%d, %s, %s ,%s, %s, %s, %s, %f\n", s[i].num, s[i].name,
                   s[i].sex, s[i].bir, s[i].dep, s[i].tit, s[i].lev, s[i].sta);
        }
    }

}

void defeat() {
    int select;
    puts("删除职工编号请输入9 ");
    puts("删除职工姓名请输入10 ");
    puts("删除职工性别请输入11 ");
    puts("删除职工出生年月请输入12 ");
    puts("删除职工所在部门请输入13 ");
    puts("删除职工职称请输入14 ");
    puts("删除职工月薪级别请输入15 ");
    scanf("%d", &select);
    switch (select) {
        case 9:
            num();
            break;
        case 10:
            nam();
            break;
        case 11:
            sex();
            break;
        case 12:
            bir();
            break;
        case 13:
            dep();
            break;
        case 14:
            tit();
            break;
        case 15:
            lev();
            break;
    }
}

void num() {
    puts("请输入所要删除的职工编号:");
    int a;
    scanf("%d", &a);
    for (int i = 0; i < n; i++)
        if (a == s[i].num) {
            for(int j = i; j < n; j++) {
                s[j] = s[j+1];
            }
            n--;
        }
    show_info();
}

void nam() {
    puts("请输入所要删除姓名的职工编号 ");
    int b;
    scanf("%d", &b);
    for (int i = 0; i < n; i++)
        if (b == (s[i].num))
            printf("%d, %s ,%s, %s, %s, %s\n", s[i].num, s[i].sex, s[i].bir,
                   s[i].dep, s[i].tit, s[i].lev);

}

void sex() {
    puts("请输入所要删除性别的职工编号 ");
    int c;
    scanf("%d", &c);
    for (int i = 0; i < n; i++)
        if (c == (s[i].num))
            printf("%d, %s, %s, %s, %s, %s\n", s[i].num, s[i].name, s[i].bir,
                   s[i].dep, s[i].tit, s[i].lev);
}

void bir() {
    puts("请输入所要删除出生年月的职工编号 ");
    int d;
    scanf("%d", &d);
    for (int i = 0; i < n; i++)
        if (d == (s[i].num))
            printf("%d, %s, %s ,%s, %s, %s, %s\n", s[i].num, s[i].name,
                   s[i].sex, s[i].dep, s[i].tit, s[i].lev);
}

void dep() {
    puts("请输入所要删除的职工编号 ");
    int d;
    scanf("%d", &d);
    for (int i = 0; i < n; i++)
        if (d == (s[i].num))
            printf("%d, %s, %s ,%s, %s, %s\n", s[i].num, s[i].name, s[i].sex,
                   s[i].bir, s[i].tit, s[i].lev);
}

void tit() {
    puts("请输入所要删除的职工编号 ");
    int e;
    scanf("%d", &e);
    for (int i = 0; i < n; i++)
        if (e == (s[i].num))
            printf("%d, %s, %s ,%s, %s, %s\n", s[i].num, s[i].name, s[i].sex,
                   s[i].bir, s[i].dep, s[i].lev);
}

void lev() {
    puts("请输入所要删除的职工编号 ");
    int f;
    scanf("%d", &f);
    for (int i = 0; i < n; i++)
        if (f == (s[i].num))
            printf("%d, %s, %s ,%s, %s, %s\n", s[i].num, s[i].name, s[i].sex,
                   s[i].bir, s[i].dep, s[i].tit);
}