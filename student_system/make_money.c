#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define M 2000
int students[M];
static int n = 0;
void menu() {
        printf("\t\t|----------------学生成绩管理系统-------------- |\n");
        printf("\t\t|\t1.添加学成成绩                              |\n");
        printf("\t\t|\t2.修改学生成绩                              |\n");
        printf("\t\t|\t3.删除学生成绩                              |\n");
        printf("\t\t|\t4.查询学生成绩                              |\n");
        printf("\t\t|\t5.显示学生成绩                              |\n");
        printf("\t\t|\t6.统计学生成绩                              |\n");
        printf("\t\t|\t7.排序学生成绩                              |\n");
        printf("\t\t|\t0.退出                                     |\n");
        printf("\t\t|--------------------------------------------|\n\n");
        printf("\t\t\t请选择(0-7):");
}
void add(){
        puts("添加成绩...");
        puts("请输入学生成绩:");
        int score;
        scanf("%d", &score);
        students[n++] = score;
        puts("新增成功");
}
void show() {
    puts("显示成绩...");
    puts("*********************************");
    for(int i = 0; i < n; i++) {
        printf("学号 = %d，成绩 = %d\n", i, students[i]);
    }
    puts("*********************************");
}

void update(){
    puts("更新成绩...");
    puts("请输入要修改的学生编号:");
    int id;
    scanf("%d", &id);
    if(id >= 0 && id < n) {
        puts("请输入修改的学生的成绩:");
        int score;
        scanf("%d", &score);
        students[id] = score;
    }else{
        puts("学生编号无效!");
    }
}
void find() {
    puts("查找成绩...");
    puts("请输入要查找的学生编号:");
    int id;
    scanf("%d", &id);
    if(id >= 0 && id < n) {
        printf("学生的成绩 = %d\n", students[id]);
    }else{
        puts("学生编号无效!");
    }
}
void del() {
    puts("请输入要删除的学生编号:");
    int id;
    scanf("%d", &id);
    if(id >= 0 && id < n) {
        for(int i = 0; i < n; i++) {
            if(id == i) {
                for(int j = 0; j < n; j++) {
                    students[j] = students[j+1];
                }
                n--;
                puts("删除成功");
                return;
            }
        }

    }else{
        puts("学生编号无效!");
        return;
    }
    puts("删除失败");
}
int max(int a, int b){
    return a > b?a:b;
}
int min(int a, int b) {
    return a > b?b:a;
}
void stat(){
    if(n <= 0) {
        puts("暂无学生信息");
        return;
    }
    int sum = 0;
    double avg = 0;
    int high = students[0];
    int low = students[0];

    for(int i = 0; i < n; i++) {
        sum += students[i];
        high = max(high, students[i]);
        low = min(low, students[i]);
    }
    printf("最高分 = %d\n", high);
    printf("最低分 = %d\n", low);
    printf("平均分 = %.2f\n", sum/(double)n);
}

void sort() {
    puts("请选择排序方式:");
    puts("1.从低到高");
    puts("2.从高到低");
    int x;
    scanf("%d", &x);
    if(x == 1) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j + 1 < n; j++) {
                if(students[j] > students[j+1]) {
                    int t = students[j];
                    students[j] = students[j+1];
                    students[j+1] = t;
                }
            }
        }
    }else if(x == 2){
        for(int i = 0; i < n; i++) {
            for(int j = 0; j + 1< n; j++) {
                if(students[j] < students[j+1]) {
                    int t = students[j];
                    students[j] = students[j+1];
                    students[j+1] = t;
                }
            }
        }
    }else{
        return;
    }
    show();
}
int main(){
    while(1) {
        menu();
        puts("请选择:");
        int m;
        scanf("%d", &m);
        switch (m) {
            case 1: add();break;
            case 2: update();break;
            case 3: del();break;
            case 4: find();break;
            case 5: show();break;
            case 6: stat();break;
            case 7: sort();break;
            case 0: puts("退出成功");return 0;
        }
    }

}