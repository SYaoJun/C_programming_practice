#include<stdio.h>   // 实现学生信息管理系统 功能有：录入学生信息 查找学生信息 删除学生信息 处理学生信息
#include<string.h>
void menu();
void add();
void search();
void delete();
void handle();
static int n = 0;
struct student{
    char id;  //学号
    char name[100];  //姓名
    int score;  //成绩
    long long phone;  //电话号码
    char hometown[100];  //籍贯
    char address[100];  //地址
}stu[50];
int state[50];
void save_sort(){
    //判断文件是否存在，若不存在则新建
    FILE *fp1=fopen("sort.txt","w+");  //打开第一个存在的文件并进行读写
    if(fp1==NULL){
        printf("文件不存在，且已经重新创建!\n");
        fp1=fopen("sort.txt","w+");  //如果不存在则新建
    } else{
        printf("sort文件打开成功！\n");
    }
    for(int i = 0; i < n; i++) {
        puts("xx");
        fprintf(fp1, "%d %s %d %lld %s %s\n", stu[i].id, stu[i].name,stu[i].score,
               stu[i].phone,stu[i].hometown, stu[i].address);
    }
    fclose(fp1);  //关闭第一个文件
}
void save_fail(){
    FILE *fp2=fopen("fail.txt","r+");  //打开第二个存在的文件并进行读写
    if(fp2==NULL){
        printf("文件不存在，且已经重新创建!\n");
        fp2=fopen("fail.txt","w+");  //如果不存在则新建
    } else{
        printf("fail文件打开成功！\n");
    }
    for(int i = 0; i < n; i++) {
        if(state[i]==1)
        fprintf(fp2, "%d %s %d %lld %s %s\n", stu[i].id, stu[i].name,stu[i].score,
                stu[i].phone,stu[i].hometown, stu[i].address);
    }
    fclose(fp2);  //关闭第二个文件
}
 void add(){
     puts("请输入学生信息");
     struct student temp;
     puts("请输入学号:");
     scanf("%d", &temp.id);
     puts("请输入姓名:");
     scanf("%s", temp.name);
     puts("请输入成绩:");
     scanf("%d", &temp.score);
     puts("请输入电话:");
     scanf("%lld", &temp.phone);
     puts("请输入籍贯:");
     scanf("%s", temp.hometown);
     puts("请输入住址:");
     scanf("%s", temp.address);
     stu[n] = temp;
     n++;
}
void search_by_id(){
    int exist = 0;
    int id;
    puts("请输入你要查询的学号:");
    scanf("%d", &id);
    for(int i = 0; i < n; i++) {
        if(stu[i].id == id) {
            printf("%d %s %d %lld %s %s\n", stu[i].id, stu[i].name,stu[i].score,
                   stu[i].phone,stu[i].hometown, stu[i].address);
            exist = 1;
            return;
        }
    }
    if(exist == 0){
        puts("未找到相关信息");
    }
}
void search_by_name(){
    int exist = 0;
    char name[100];
    puts("请输入你要查询的姓名:");
    scanf("%s", name);
    for(int i = 0; i < n; i++) {
        if(strcmp(stu[i].name, name) == 0) {
            printf("%d %s %d %lld %s %s\n", stu[i].id, stu[i].name,stu[i].score,
                   stu[i].phone,stu[i].hometown, stu[i].address);
            exist = 1;
            return;
        }
    }
    if(exist == 0){
        puts("未找到相关信息");
    }
}
void search_by_address(){
    int exist = 0;
    char hometown[100];
    puts("请输入你要查询的籍贯:");
    scanf("%s", hometown);
    for(int i = 0; i < n; i++) {
        if(strcmp(stu[i].hometown, hometown) == 0) {
            printf("学号=%d，姓名=%s，成绩=%d，电话=%lld，籍贯=%s，地址=%s\n", stu[i].id, stu[i].name,stu[i].score,
                   stu[i].phone,stu[i].hometown, stu[i].address);
            exist = 1;
            return;
        }
    }
    if(exist == 0){
        puts("未找到相关信息");
    }
}
 void search(){
     while(1){
         puts("1.按照学号查找");
         puts("2.按照姓名查找");
         puts("3.按照籍贯查找");
         puts("4.返回主菜单");
         int choice;
         printf("请输入您的选择: \n ");
         scanf("%d", &choice);
         switch(choice){
             case 1:search_by_id();break;
             case 2:search_by_name();break;
             case 3:search_by_address();break;
             case 4:return;
         }
     }
}
void delete(){
    puts("请输入要删除的学号:");
    int id;
    scanf("%d", &id);
    for(int i = 0; i < n; i++) {
        if(stu[i].id == id) {
            for(int j = 0; j+1 < n; j++) {
                stu[j] = stu[j+1];
            }
            n--;
           puts("删除成功");
            return;
        }
    }
    puts("删除失败");
}
void show(){
    for(int i = 0; i < n; i++) {
        printf("学号=%d，姓名=%s，成绩=%d，电话=%lld，籍贯=%s，地址=%s\n", stu[i].id, stu[i].name,stu[i].score,
               stu[i].phone,stu[i].hometown, stu[i].address);
    }
}
void sort(){
    for(int i = 0; i < n; i++) {
        for(int j = 0; j + 1 < n; j++) {
            if(stu[j].score < stu[j+1].score) {
                struct student t = stu[j];
                stu[j] = stu[j+1];
                stu[j+1] = t;
            }

        }
    }
    show();
}
void stat(){
    int cnt = 0;
    memset(state, 0, sizeof(state));
    for(int i = 0; i < n; i++) {
        if(stu[i].score < 60){
            cnt++;
            state[i] = 1;
        }
    }
    printf("不及格人数为=%d\n", cnt);
}
void avg(){

    int sum = 0;
    for(int i = 0; i < n; i++) {
      sum += stu[i].score;
    }
    printf("总分为=%d,平均分为=%.2f\n", sum, sum/(double)n);
}
int max(int a, int b){
    return a>b?a:b;
}
int min(int a, int b){
    return a<b?a:b;
}
void get_max(){
    if(n == 0){
        return;
    }
    int idx = 0;
    for(int i = 0; i < n; i++) {
        if(stu[idx].score < stu[i].score){
            idx = i;
        }
    }
    printf("学号=%d，姓名=%s，成绩=%d，电话=%lld，籍贯=%s，地址=%s\n", stu[idx].id, stu[idx].name,stu[idx].score,
           stu[idx].phone,stu[idx].hometown, stu[idx].address);
}
void get_min(){
    if(n == 0){
        return;
    }
    int idx = 0;
    for(int i = 0; i < n; i++) {
        if(stu[idx].score > stu[i].score){
            idx = i;
        }
    }
    printf("学号=%d，姓名=%s，成绩=%d，电话=%lld，籍贯=%s，地址=%s\n", stu[idx].id, stu[idx].name,stu[idx].score,
           stu[idx].phone,stu[idx].hometown, stu[idx].address);
}
void handle(){
    while(1){
        puts("1.显示学生信息");
        puts("2.成绩排序");
        puts("3.不及格学生统计");
        puts("4.统计平均分及总分");
        puts("5.返回主菜单");
        int choice;
        printf("请输入您的选择: \n ");
        scanf("%d", &choice);
        switch(choice){
            case 1:show();break;
            case 2:sort();save_sort(); break;
            case 3:stat();save_fail();break;
            case 4:avg();break;
            case 5:return;
        }
    }

}
int main(){
    while(1){
        menu();
        int choice;
        printf("请输入您的选择: \n ");
        scanf("%d", &choice);
        switch(choice){
            case 1:add();break;  //录入学生信息
            case 2:search();break;  //查找学生信息
            case 3:delete();break;  //删除学生信息
            case 4:handle();break;   //处理学生信息
            case 0: puts("成功退出系统");return 0;
        }
    }
}
void menu(){
    printf(" -----------------学生信息系统管理--------------------\n");
    printf(" |                  1.录入学生信息                   |\n");
    printf(" |                  2.查找学生信息                   |\n");
    printf(" |                  3.删除学生信息                   |\n");
    printf(" |                  4.处理学生信息                   |\n");
    printf("------------------------------------------------------\n");
}