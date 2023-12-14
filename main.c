#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 2000
#define N 128
#define filename "student.txt"
void sum();
void average();
struct stu{
    char name[N];
    int id;
    char sex[N];
    int age;
    char grade[N];
    int math;
    int eng;
    int com;
    int av;
    int sum;
};

typedef struct stu Student;
Student T[M];
int total_num = 0;
static int n = 0;
void menu() {
    printf("============学生信息系统=========\n");
    printf("                                 \n");
    printf("          1.录入学生信息         \n");
    printf("          2.输出学生信息         \n");
    printf("          3.查询学生信息         \n");
    printf("          4.删除学生信息         \n");
    printf("          5.修改学生信息         \n");
    printf("          6.排序学生信息         \n");
    printf("          7.统计学生信息         \n");
    printf("          8.保存学生信息         \n");
    printf("          9.读取学生信息         \n");
    printf("          0.退出                 \n");
    printf("                                 \n");
    printf("=================================\n");
    printf("请选择(0-9):");
}
void add(){
    while(1){
        puts("开始录入信息");
        Student t;
        puts("请输入姓名:");
        scanf("%s", t.name);
        puts("请输入学号:");
        scanf("%d", &t.id);
        puts("请输入性别:");
        scanf("%s", t.sex);
        puts("请输入年龄:");
        scanf("%d", &t.age);
        puts("请输入班级:");
        scanf("%s", t.grade);
        puts("请输入学生C语言成绩:");
        scanf("%d", &t.com);
        puts("请输入学生高数成绩:");
        scanf("%d", &t.math);
        puts("请输入学生英语成绩:");
        scanf("%d", &t.eng);

        // 判重
        for(int i = 0; i < total_num; i++) {
            if(T[i].id == t.id){
                puts("添加失败,已存在相同学号。");
                return;
            }
        }
        t.sum = 0;
        t.sum = t.com + t.math + t.eng;
        t.av = t.sum / 3;
        T[total_num++] = t;
        puts("新增成功");
        puts("********");
        puts("1. 继续添加");
        puts("2. 退出");
        puts("********");
        int x;
        scanf("%d", &x);
        if(x == 2) break;
    }
}



void output() {
    puts("姓名\t学号\t性别\t年龄\t班级\tC语言成绩\t高数成绩\t英语成绩\t总分\t平均分\n");
    for(int i = 0; i < total_num; i++) {
        printf("%s\t%d\t%s\t%d\t%s\t%d\t%d\t%d\t%d\t%d\n",
               T[i].name,T[i].id,T[i].sex,T[i].age,T[i].grade,T[i].com,T[i].math,T[i].eng,T[i].sum,T[i].av);
    }
}

void modify(){
    puts("*******************");
    puts("1. 修改姓名");
    puts("2. 修改性别");
    puts("3. 修改年龄");
    puts("4. 修改班级");
    puts("5. 修改C语言成绩");
    puts("6. 修改高数成绩");
    puts("7. 修改英语成绩");
    puts("*******************");
    int x;
    scanf("%d", &x);
    puts("请输入学号:");
    int id;
    scanf("%d", &id);
    int state = -1;
    for(int i = 0; i < total_num; i++) {
        if(T[i].id == id){
            state = i;
            break;
        }
    }
    if(state == -1){
        puts("学号不存在,修改失败！");
    }
    if(x == 1){
        puts("请输入修改后的姓名:");
        scanf("%s", T[state].name);
        puts("修改成功!");
    }else if(x == 2){
        puts("请输入修改后的性别:");
        scanf("%s", T[state].sex);
        puts("修改成功!");
    }else if(x == 3){
        puts("请输入修改后的年龄:");
        scanf("%d", &T[state].age);
    }else if(x == 4){
        puts("请输入修改后的班级:");
        scanf("%s", T[state].grade);
        puts("修改成功!");
    }else if(x == 5){
        puts("请输入修改后的C语言成绩:");
        scanf("%d", &T[state].com);
        puts("修改成功!");
    }else if(x == 6){
        puts("请输入修改后的高数成绩:");
        scanf("%d", &T[state].math);
        puts("修改成功!");
    }else if(x == 7){
        puts("请输入修改后的英语成绩:");
        scanf("%d", &T[state].eng);
        puts("修改成功!");
    }
}

void query() {
    puts("*******************");
    puts("1. 按照学号查询");
    puts("2. 按照姓名查询");
    puts("*******************");
    int t;
    scanf("%d", &t);

    if(t == 1) {
        puts("请输入学号");
        int id;
        scanf("%d", &id);
        for(int i = 0; i < total_num; i++) {
            if (T[i].id == id) {
                printf("姓名 = %s,学号 = %d,性别 = %s, 年龄 = %d,班级 = %s\n", 
                T[i].name, T[i].id, T[i].sex, T[i].age, T[i].grade);
            }
        }
    }else if(t == 2){
        puts("请输入姓名:");
        char name[N];
        scanf("%s", name);
        for(int i = 0; i < total_num; i++) {
            if (strcmp(name, T[i].name) == 0) {
                printf("姓名 = %s,学号 = %d,性别 = %s, 年龄 = %d,班级 = %s\n",
                       T[i].name, T[i].id, T[i].sex, T[i].age, T[i].grade);
            }
        }
    }
}
void delete_() {
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
    puts("修改失败,学号不存在！");
}

struct S{
    char name[N];
    int cnt;
};



void sort() {
    // 默认是降序
    puts("=================");
    puts("1.按总分排序");
    puts("2.按平均分排序");
    puts("=================");
    puts("请输入对应的选项：");
    int x;
    scanf("%d", &x);
    if(x == 1) {
        // 冒泡排序算法
        for(int i = 0; i < total_num; i++) {
            for(int j = 0; j + 1 < total_num; j++) {
                // 交换两个元素
                if(T[j].sum > T[j+1].sum) {
                    Student t = T[j];
                    T[j] = T[j+1];
                    T[j+1] = t;
                }
            }
        }
        output();
    }else if(x == 2){
        for(int i = 0; i < total_num; i++) {
            for(int j = 0; j + 1< total_num; j++) {
                if(T[j].av > T[j+1].av) {
                    Student t = T[j];
                    T[j] = T[j+1];
                    T[j+1] = t;
                }
            }
        }
        output();
    }
}
void save(){
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
void stat(){

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
            case 4: delete_();break;
            case 5: modify();break;
            case 6: sort();break;
            case 7: stat();break;
            case 8: save();break;
            case 9: read();break;
            case 0: puts("退出成功");return 0;
        }
    }

}
