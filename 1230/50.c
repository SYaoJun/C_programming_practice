#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define M 2000
typedef struct teacher{
  int id;
  char name[64];
  double basic;
  double performance;
  double bonus;
  double total;
}T;
T ts[M];
static int n = 0;
void menu() {
    printf("\t\t|----------------教工信息管理系统-------------------|\n");
    printf("\t\t|\t1.请录入教工基本信息                             |\n");
    printf("\t\t|\t2.工资最高的教工信息                             |\n");
    printf("\t\t|\t3.显示所有教工信息                               |\n");
    printf("\t\t|\t4.按照奖金降序方式显示教工姓名                     |\n");
    printf("\t\t|\t0.退出系统                                     |\n");
    printf("\t\t|------------------------------------------------|\n\n");
    printf("\t\t\t请选择(0-4):");
}
void Information() {
    T temp;
    puts("请输入教师工号:");
    scanf("%d", &temp.id);
    puts("请输入教师姓名:");
    scanf("%s", temp.name);
    puts("请输入教师基本工资:");
    scanf("%lf", &temp.basic);
    puts("请输入教师绩效工资:");
    scanf("%lf", &temp.performance);
    puts("请输入教师奖金:");
    scanf("%lf", &temp.bonus);
    temp.total =  temp.basic + temp.performance + temp.bonus;
    ts[n++] = temp;
}
void show_(int id){
    printf("工号 = %d， 姓名 = %s, 基本工资 = %f, 绩效工资 = %f, 奖金 = %f\n",
           ts[id].id, ts[id].name, ts[id].basic, ts[id].performance, ts[id].bonus
    );
}
void Salary_Max() {
    if(n == 0 ){
        puts("暂无教工信息");
        return;
    }
    int id = 0;
    for(int i = 0; i < n; i++) {
        if(ts[id].total < ts[i].total) {
            id = i;
        }
    }
    show_(id);
}

void Show() {
    if(n == 0 ){
        puts("暂无教工信息");
        return;
    }
    puts("显示信息...");
    for(int i  = 0; i < n; i++) {
        show_(i);
    }
}
void BE_sort() {
    if(n == 0 ){
        puts("暂无教工信息");
        return;
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j + 1 < n; j ++) {
            if(ts[j].bonus < ts[j+1].bonus) {
                T t = ts[j];
                ts[j] = ts[j+1];
                ts[j+1] = t;
            }
        }
    }
    puts("按照奖金降序排列如下...");
    for(int i = 0; i < n; i++) {
        printf("%s\n", ts[i].name);
    }
}
int main(){
    while(1) {
        menu();
        puts("请选择:");
        int m;
        scanf("%d", &m);
        switch (m) {
            case 1: Information();break;
            case 2: Salary_Max();break;
            case 3: Show();break;
            case 4: BE_sort();break;
            case 0: puts("退出成功");return 0;
        }
    }

}