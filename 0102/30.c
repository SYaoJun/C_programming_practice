#include <string.h>
#include <stdio.h>
#define M 64
#define N 1000

typedef struct Student{
    long long no; // 学号唯一
    char name[M];
    int math;
    int cprogram;
    int total;
}Student_T;
static int number = 0;
Student_T stus[N];
void menu() {
    printf("\t\t|----------------学生成绩管理系统-------------------|\n");
    printf("\t\t|\t1.新建数据                                      |\n");
    printf("\t\t|\t2.添加数据                                      |\n");
    printf("\t\t|\t3.删除数据                                      |\n");
    printf("\t\t|\t4.排序                                         |\n");
    printf("\t\t|\t5.查询                                         |\n");
    printf("\t\t|\t6.从文件中读数据                                 |\n");
    printf("\t\t|\t7.将所有数据写入文件                              |\n");
    printf("\t\t|\t0.退出                                         |\n");
    printf("\t\t|------------------------------------------------|\n");
    printf("\t\t\t请输入序号选择相应操作:");
}
void create_data(){
    Student_T temp;
    puts("请创建学生信息...");
    puts("请输入学生学号:");
    scanf("%lld", &temp.no);
    puts("请输入学生姓名:");
    scanf("%s", temp.name);
    puts("请输入学生数学成绩:");
    scanf("%d", &temp.math);
    puts("请输入学生程序设计成绩:");
    scanf("%d", &temp.cprogram);
    temp.total = temp.cprogram + temp.math;
    stus[number++] = temp;
    puts("新增成功");
}

void add_data(){
    Student_T temp;
    puts("请新增学生信息..");
    puts("请输入学生学号:");
    scanf("%lld", &temp.no);
    puts("请输入学生姓名:");
    scanf("%s", temp.name);
    puts("请输入学生数学成绩:");
    scanf("%d", &temp.math);
    puts("请输入学生程序设计成绩:");
    scanf("%d", &temp.cprogram);
    temp.total = temp.cprogram + temp.math;
    stus[number++] = temp;
    puts("添加成功");
}
void delete_data(){
    puts("请输入要删除的学生学号:");
    long long no;
    scanf("%lld", &no);
    for(int i = 0; i < number; i++) {
        if(stus[i].no == no){
            for(int j = i; j + 1 < number; j++) {
                stus[j] = stus[j+1];
            }
            number--;
            puts("删除成功");
            return;
        }
    }
    puts("删除失败");
}
void menu_sort(){
    printf("\t\t|----------------选择排序方式------------------------|\n");
    printf("\t\t|\t1.数学成绩排序                                    |\n");
    printf("\t\t|\t2.程序设计成绩排序                                 |\n");
    printf("\t\t|\t3.总分排序                                        |\n");
    printf("\t\t|\t4.返回主菜单                                      |\n");
    printf("\t\t|--------------------------------------------------|\n");
    printf("\t\t\t请按序号选择相应操作:");
}
void menu_query(){
    printf("\t\t|----------------选择查询方式-----------------------|\n");
    printf("\t\t|\t1.学号查询                                      |\n");
    printf("\t\t|\t2.姓名查询                                      |\n");
    printf("\t\t|\t3.数学成绩查询                                   |\n");
    printf("\t\t|\t4.程序设计成绩查询                                |\n");
    printf("\t\t|\t5.总分查询                                       |\n");
    printf("\t\t|\t6.返回主菜单                                     |\n");
    printf("\t\t|-------------------------------------------------|\n");
    printf("\t\t\t请按序号选择相应操作:");
}
void math_sort(){
    for(int i = 0; i < number; i++) {
        for(int j = 0; j + 1 < number; j++) {
            if(stus[j].math < stus[j+1].math){
                Student_T  t = stus[j];
                stus[j] = stus[j+1];
                stus[j+1] = t;
            }
        }
    }
}

void cprogram_sort(){
    for(int i = 0; i < number; i++) {
        for(int j = 0; j + 1 < number; j++) {
            if(stus[j].cprogram < stus[j+1].cprogram){
                Student_T  t = stus[j];
                stus[j] = stus[j+1];
                stus[j+1] = t;
            }
        }
    }
}
void total_sort(){
    for(int i = 0; i < number; i++) {
        for(int j = 0; j + 1 < number; j++) {
            if(stus[j].total < stus[j+1].total){
                Student_T  t = stus[j];
                stus[j] = stus[j+1];
                stus[j+1] = t;
            }
        }
    }
}
void sort(){
    while(1){
        int n;
        menu_sort();
        scanf("%d", &n);
        switch (n) {
            case 1:
                math_sort();
                break;
            case 2:
                cprogram_sort();
                break;
            case 3:
                total_sort();
                break;
            case 4:
                return;
        }
    }
}
void no_query() {
    puts("请输入要查询的学号：");
    long long no;
    scanf("%lld", &no);
    for(int i = 0; i < number; i++) {

        if(stus[i].no == no) {
            printf("学号 = %lld\n", stus[i].no);
            printf("姓名 = %s\n", stus[i].name);
            printf("数学成绩 = %d\n", stus[i].math);
            printf("程序设计成绩 = %d\n", stus[i].cprogram);
            printf("总分 = %d\n", stus[i].total);
            return;
        }
    }
    puts("找不到相关学号信息");
};

void name_query() {
    puts("请输入要查询的姓名：");
    char name[M];
    scanf("%s", name);
    int cnt = 0;
    for(int i = 0; i < number; i++) {
        if(strcmp(name, stus[i].name) == 0) {
            printf("学号 = %lld\n", stus[i].no);
            printf("姓名 = %s\n", stus[i].name);
            printf("数学成绩 = %d\n", stus[i].math);
            printf("程序设计成绩 = %d\n", stus[i].cprogram);
            printf("总分 = %d\n", stus[i].total);
            cnt++;
        }
    }
    if(cnt == 0)
    puts("找不到相关学号信息");
};

void math_query() {
    puts("请输入要查询的数学成绩：");
     int math;
    scanf("%d", &math);
    int cnt = 0;
    for(int i = 0; i < number; i++) {
        if(stus[i].math >= math) {
            printf("学号 = %lld\n", stus[i].no);
            printf("姓名 = %s\n", stus[i].name);
            printf("数学成绩 = %d\n", stus[i].math);
            cnt++;
        }
    }
    printf("满足条件的同学数量为%d\n", cnt);
};
void cprogram_query() {
    puts("请输入要查询的数学成绩：");
    int cprogram;
    scanf("%d", &cprogram);
    int cnt = 0;
    for(int i = 0; i < number; i++) {
        if(stus[i].cprogram >= cprogram) {
            printf("学号 = %lld\n", stus[i].no);
            printf("姓名 = %s\n", stus[i].name);
            printf("程序设计成绩 = %d\n", stus[i].cprogram);
            cnt++;
        }
    }
    printf("满足条件的同学数量为%d\n", cnt);
};
void total_query() {
    puts("请输入要查询的数学成绩：");
    int total;
    scanf("%d", &total);
    int cnt = 0;
    for(int i = 0; i < number; i++) {
        if(stus[i].total >= total) {
            printf("学号 = %lld\n", stus[i].no);
            printf("姓名 = %s\n", stus[i].name);
            printf("数学成绩 = %d\n", stus[i].math);
            printf("程序设计成绩 = %d\n", stus[i].cprogram);
            cnt++;
        }
    }
    printf("满足条件的同学数量为%d\n", cnt);
};
void query(){
    while(1){
        int n;
        menu_query();
        scanf("%d", &n);
        switch (n) {
            case 1:
                no_query();
                break;
            case 2:
                name_query();
                break;
            case 3:
                math_query();
                break;
            case 4:
                cprogram_query();
                break;
            case 5:
                total_query();
                break;
            case 6:
                return;
        }
    }
}
void read_data(){
    char filename[M];
    puts("请输入读取的文件名:");
    memset(filename, 0, sizeof (filename));
    scanf("%s", filename);
    FILE *fp = fopen(filename, "r+");
    if(fp == NULL){
        puts("文件打开失败，文件可能不存在");
        return;
    }

    fscanf(fp, "%d", &number);
    printf("学生人数为:%d\n", number);
    for(int i = 0; i < number; i++) {
        fscanf(fp, "%lld %s %d %d %d", &stus[i].no, stus[i].name, &stus[i].math, &stus[i].cprogram,
                &stus[i].total);
    }
    fclose(fp);
}
void save_data() {
    char filename[M];
    puts("请输入读取的文件名:");
    scanf("%s", filename);
    FILE *fp = fopen(filename, "w");
    if(fp == NULL) {
        puts("文件打开失败!");
        return;
    }
//    fwrite(&stus, number, sizeof(Student_T), fp);
    fprintf(fp, "%d\n", number);

    for(int i = 0; i < number; i++) {
        fprintf(fp, "%lld %s %d %d %d\n", stus[i].no, stus[i].name, stus[i].math, stus[i].cprogram,
                stus[i].total);
    }
    fclose(fp);
}
void show(){
    for(int i = 0; i < number; i++) {
            printf("学号 = %lld\n", stus[i].no);
            printf("姓名 = %s\n", stus[i].name);
            printf("数学成绩 = %d\n", stus[i].math);
            printf("程序设计成绩 = %d\n", stus[i].cprogram);
    }
}
int main(){
    while(1) {
        menu();
        int m;
        scanf("%d", &m);
        switch (m) {
            case 1: create_data();break;
            case 2: add_data();break;
            case 3: delete_data();break;
            case 4: sort();break;
            case 5: query();break;
            case 6: read_data();break;
            case 7: save_data();break;
            case 8: show();break;
            case 0: puts("退出成功");return 0;
        }
    }

}