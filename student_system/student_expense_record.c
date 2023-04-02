#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define M 2000
#define N 128
#define filename "student.txt"
struct stu{
    char name[N];
    int id;
    double amount;
    char kind[N];
    char date[N];
};

typedef struct stu Student;
Student T[M];
int total_num = 0;
static int n = 0;
void menu() {
    printf("\t\t|----------------学生消费系统-------------- |\n");
    printf("\t\t|\t1.录入学生信息                              |\n");
    printf("\t\t|\t2.输出学生信息                              |\n");
    printf("\t\t|\t3.查询学生信息                              |\n");
    printf("\t\t|\t4.删除学生信息                              |\n");
    printf("\t\t|\t5.修改学生信息                              |\n");
    printf("\t\t|\t6.排序学生信息                              |\n");
    printf("\t\t|\t7.统计学生信息                              |\n");
    printf("\t\t|\t8.保存学生信息                              |\n");
    printf("\t\t|\t9.读取学生信息                              |\n");
    printf("\t\t|\t0.退出                                     |\n");
    printf("\t\t|--------------------------------------------|\n\n");
    printf("\t\t\t请选择(0-9):");
}
void add(){
    puts("开始录入信息");
    Student t;
    puts("请输入姓名:");
    scanf("%s", t.name);
    puts("请输入学号:");
    scanf("%d", &t.id);
    puts("请输入消费金额:");
    scanf("%lf", &t.amount);
    puts("请输入消费用途:");
    scanf("%s", t.kind);
    puts("请输入消费日期:");
    scanf("%s", t.date);

    // 判重
    for(int i = 0; i < total_num; i++) {
        if(T[i].id == t.id){
            puts("添加失败，已存在相同学号。");
            return;
        }
    }
    T[total_num++] = t;
    puts("新增成功");
}
void output() {
    for(int i = 0; i < total_num; i++) {
        printf("姓名 = %s，学号 = %d，消费金额 = %lf, 消费用途 = %s，消费日期 = %s\n",
               T[i].name, T[i].id, T[i].amount, T[i].kind, T[i].date);
    }
}

void modify(){
    puts("*******************");
    puts("1. 全部修改");
    puts("2. 部分修改");
    puts("*******************");
    int t;
    scanf("%d", &t);
    if(t == 1 || t == 2) {
        puts("请输入要修改的学号:");
        Student t;
        scanf("%d", &t.id);
        for(int i = 0; i < total_num; i++) {
            if(T[i].id == t.id) {
                puts("请输入修改后的姓名:");
                scanf("%s", T[i].name);
                puts("请输入修改后的消费金额:");
                scanf("%lf", &T[i].amount);
                puts("请输入修改后的消费用途:");
                scanf("%s", T[i].kind);
                puts("请输入修改后的消费日期:");
                scanf("%s", T[i].date);
            }
        }
        puts("修改失败，学号不存在！");
    }
}
void query() {
    puts("*******************");
    puts("1. 按照学号查询");
    puts("2. 按照姓名查询");
    puts("3. 按照消费用途查询");
    puts("*******************");
    int t;
    scanf("%d", &t);

    if(t == 1) {
        puts("请输入学号");
        int id;
        scanf("%d", &id);
        for(int i = 0; i < total_num; i++) {
            if (T[i].id == id) {
                printf("姓名 = %s，学号 = %d，消费金额 = %lf, 消费用途 = %s，消费日期 = %s\n",
                       T[i].name, T[i].id, T[i].amount, T[i].kind, T[i].date);
            }
        }
    }else if(t == 2){
        puts("请输入姓名:");
        char name[N];
        scanf("%s", name);
        for(int i = 0; i < total_num; i++) {
            if (strcmp(name, T[i].name) == 0) {
                printf("姓名 = %s，学号 = %d，消费金额 = %lf, 消费用途 = %s，消费日期 = %s\n",
                       T[i].name, T[i].id, T[i].amount, T[i].kind, T[i].date);
            }
        }
    }else if(t == 3){
        puts("请输入消费用途:");
        char kind[N];
        scanf("%s", kind);
        for(int i = 0; i < total_num; i++) {
            if (strcmp(kind, T[i].kind) == 0) {
                printf("姓名 = %s，学号 = %d，消费金额 = %lf, 消费用途 = %s，消费日期 = %s\n",
                       T[i].name, T[i].id, T[i].amount, T[i].kind, T[i].date);
            }
        }
    }
}
void delete() {
    puts("请输入要删除的学生学号:");
    int id;
    scanf("%d", &id);
    for(int i = 0; i < total_num; i++) {
        if(T[i].id == id) {
            for(int j = i; j < total_num; j++) {
                T[j] = T[j+1];
            }
            total_num--;
            puts("删除成功");
            return;
        }
    }
    puts("修改失败，学号不存在！");
}
int max(int a, int b){
    return a > b?a:b;
}
int min(int a, int b) {
    return a > b?b:a;
}
struct S{
    char name[N];
    int cnt;
};

void stat(){
    struct S kinds[M];
    puts("*******************");
    puts("1.按消费用途统计");
    puts("2.按消费日期统计");
    puts("*******************");
    int x;
    scanf("%d", &x);
    int k = 0;
    if(x == 1) {
        for(int i = 0; i < total_num; i++) {
            int j;
            for(j = 0; j < k; j++) {
                if(strcmp(T[i].kind, kinds[j].name) == 0){
                    kinds[j].cnt++;
                }
            }
            if(j == k){
                strcpy(kinds[k].name, T[i].kind);
                kinds[k].cnt = 1;
                k++;
            }
        }
        // 输出
        for(int i = 0; i < k; i++) {
            printf("消费用途 = %s，同类人数 = %d\n", kinds[i].name, kinds[i].cnt);
        }
    }else if(x == 2){
        for(int i = 0; i < total_num; i++) {
            int j;
            for(j = 0; j < k; j++) {
                if(strcmp(T[i].date, kinds[j].name) == 0){
                    kinds[j].cnt++;
                }
            }
            if(j == k){
                k++;
                strcpy(kinds[k].name, T[i].date);
                kinds[k].cnt = 1;
            }
        }
        // 输出
        for(int i = 0; i < k; i++) {
            printf("消费日期 = %s，同类人数 = %d\n", kinds[i].name, kinds[i].cnt);
        }
    }
}

void sort() {
    puts("*******************");
    puts("1.按姓名排序");
    puts("2.按消费金额");
    puts("*******************");
    int x;
    scanf("%d", &x);
    if(x == 1) {
        for(int i = 0; i < total_num; i++) {
            for(int j = 0; j + 1 < n; j++) {
                if(strcmp(T[j].name, T[j+1].name) > 0) {
                    Student t = T[j];
                    T[j] = T[j+1];
                    T[j+1] = t;
                }
            }
        }
    }else if(x == 2){
        for(int i = 0; i < total_num; i++) {
            for(int j = 0; j + 1< n; j++) {
                if(T[j].amount > T[j+1].amount) {
                    Student t = T[j];
                    T[j] = T[j+1];
                    T[j+1] = t;
                }
            }
        }
    }
}
void save(){
    int i;
    FILE *fp = fopen(filename, "w");
    fwrite(&T, total_num, sizeof(Student), fp);
    fclose(fp);
    puts("保存成功");
}

void read(){
    int i = 0;
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        return;
    }
    while (!feof(fp))
    {
        fread(&T[i], 1, sizeof(Student), fp);
        i++;
    }
    total_num = i - 1;
    fclose(fp);
    puts("读取成功");
}
int main(){
    while(1) {
        menu();
        puts("请选择:");
        int m;
        scanf("%d", &m);
        switch (m) {
            case 1: add();break;
            case 2: output();break;
            case 3: query();break;
            case 4: delete();break;
            case 5: modify();break;
            case 6: sort();break;
            case 7: stat();break;
            case 8: save();break;
            case 9: read();break;
            case 0: puts("退出成功");return 0;
        }
    }

}