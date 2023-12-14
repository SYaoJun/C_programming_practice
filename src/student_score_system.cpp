#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define M 2000
#define N 128
#define filename "student.txt"
struct stu {
    char name[N];
    int id;
    double amount;
    char kind[N];
    char date[N];
    char department[N];
    char sex[N];
    double score;
};

typedef struct stu Student;
Student T[M];
int total_num = 0;
static int n = 0;

void menu() {
    printf("=================学生成绩管理系统===========\n");
    printf("1.录入学生信息                              \n");
    printf("2.输出学生信息                              \n");
    printf("3.查询学生信息                              \n");
    printf("4.删除学生信息                              \n");
    printf("5.修改学生信息                              \n");
    printf("6.排序学生信息                              \n");
    printf("7.统计学生信息                              \n");
    printf("8.保存学生信息                              \n");
    printf("9.读取学生信息                              \n");
    printf("0.退出                                     \n");
    printf("==========================================\n");
    printf("请选择(0-9):");
}

void add() {
    while (1) {
        puts("开始录入信息");
        Student t;
        puts("请输入姓名:");
        scanf("%s", t.name);
        puts("请输入学号:");
        scanf("%d", &t.id);
        puts("请输入所在院系:");
        scanf("%s", t.department);
        puts("请输入性别:");
        scanf("%s", t.sex);
        puts("请输入成绩:");
        scanf("%lf", &t.score);

        // 判重
        for (int i = 0; i < total_num; i++) {
            if (T[i].id == t.id) {
                puts("添加失败，已存在相同学号。");
                return;
            }
        }
        T[total_num++] = t;
        puts("新增成功");
        puts("********");
        puts("1. 继续添加");
        puts("2. 退出");
        puts("********");
        int x;
        scanf("%d", &x);
        if (x == 2) break;
    }
}

void output() {
    puts("姓名\t学号\t所在院系\t性别\t成绩");
    for (int i = 0; i < total_num; i++) {
        printf("%s\t%d\t%s\t%s\t%f\n",
               T[i].name, T[i].id, T[i].department, T[i].sex, T[i].score);
    }
}

void part_modify() {
    puts("请输入学号:");
    int id;
    scanf("%d", &id);
    int state = -1;
    for (int i = 0; i < total_num; i++) {
        if (T[i].id == id) {
            state = i;
            break;
        }
    }
    if (state == -1) {
        puts("学号不存在，修改失败！");
    }

    puts("请输入修改后的院系:");
    scanf("%s", T[state].department);
    puts("修改成功!");
    output();
}

void modify() {
    part_modify();
}

void query() {
    puts("*******************");
    puts("1. 按照姓名查询");
    puts("2. 按照所在院系查询");
    puts("*******************");
    int t;
    scanf("%d", &t);

    if (t == 1) {
        puts("请输入姓名:");
        char name[N];
        scanf("%s", name);
        for (int i = 0; i < total_num; i++) {
            if (strcmp(name, T[i].name) == 0) {
                printf("姓名 = %s，学号 = %d，所在院系 = %s，性别 = %s\n",
                       T[i].name, T[i].id, T[i].department, T[i].sex);
                return;
            }
        }
        puts("查询不存在");
    } else{
        puts("请输入所在院系:");
        char department[N];
        scanf("%s", department);
        for (int i = 0; i < total_num; i++) {
            if (strcmp(department, T[i].department) == 0) {
                printf("姓名 = %s，学号 = %d，所在院系 = %s，性别 = %s\n",
                       T[i].name, T[i].id, T[i].department, T[i].sex);
                return;
            }
        }
        puts("查询不存在");
    }
}
/*删除一个学生的信息*/
void delete_() {
    puts("请输入要删除的学生学号:");
    int id;
    scanf("%d", &id);
    for (int i = 0; i < total_num; i++) {
        if (T[i].id == id) {
            for (int j = i; j < total_num; j++) {
                T[j] = T[j + 1];
            }
            total_num--;
            puts("删除成功");
            return;
        }
    }
    puts("修改失败，学号不存在！");
}


void stat() {
    puts("请输入要统计的院系名称：");
    char department[N];
    scanf("%s", department);
    int cnt = 0;
    for (int i = 0; i < total_num; i++) {
        if (strcmp(department, T[i].department) == 0) {
            cnt++;
        }
    }
    printf("院系: %s 共计%d人\n", department, cnt);
    // 排序
    for (int i = 0; i < total_num; i++) {
        for (int j = 0; j + 1 < total_num; j++) {
            // 冒泡排序 按照姓名从小到大排序
            if (strcmp(T[j].name, T[j + 1].name) > 0) {
                Student t = T[j];
                T[j] = T[j + 1];
                T[j + 1] = t;
            }
        }
    }
    // 输出指定院系的学生信息
    for (int i = 0; i < total_num; i++) {
        if (strcmp(department, T[i].department) == 0) {
            printf("姓名 = %s，学号 = %d，所在院系 = %s，性别 = %s，成绩 = %f\n",
                   T[i].name, T[i].id, T[i].department, T[i].sex, T[i].score);
        }
    }
}

void sort() {
    // 按照姓名排序
    for (int i = 0; i < total_num; i++) {
        for (int j = 0; j + 1 < total_num; j++) {
            if (T[j].score > T[j + 1].score) {
                Student t = T[j];
                T[j] = T[j + 1];
                T[j + 1] = t;
            }
        }
    }
    output();
}
#define filename "student.txt"
void save() {
    int i;
    FILE *fp = fopen(filename, "w");
    fwrite(&T, total_num, sizeof(Student), fp);
    fclose(fp);
    puts("保存成功");
}

void read() {
    int i = 0;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return;
    }
    while (!feof(fp)) {
        fread(&T[i], 1, sizeof(Student), fp);
        i++;
    }
    total_num = i - 1;
    fclose(fp);
    puts("读取成功");
}

int main() {
    while (1) {
        menu();
        puts("请选择:");
        int m;
        scanf("%d", &m);
        switch (m) {
            case 1:
                add();
                break;
            case 2:
                output();
                break;
            case 3:
                query();
                break;
            case 4:
                delete_();
                break;
            case 5:
                modify();
                break;
            case 6:
                sort();
                break;
            case 7:
                stat();
                break;
            case 8:
                save();
                break;
            case 9:
                read();
                break;
            case 0:
                puts("退出成功");
                return 0;
        }
    }

}