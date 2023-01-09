#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define password "abc123"
#define M 2000
static int N = 1001;
int students[M];
void menu() {
    printf("*****************************************\n");
    printf("*            学生成绩系统                 *\n");
    printf("*****************************************\n");
    printf("*            1. 登录                     *\n");
    printf("*            2. 录入信息                  *\n");
    printf("*            3. 浏览信息                  *\n");
    printf("*            4. 统计总分和平均分            *\n");
    printf("*            5. 统计最高分和最低分          *\n");
    printf("*            6. 统计各分数段人数            *\n");
    printf("*            0. 退出系统                  *\n");
    printf("*****************************************\n");
}
void insert_data(){
    while(1){
        puts("请输入要新增的成绩，输入-1结束录入:");
        int n;
        scanf("%d", &n);
        if(n == -1) return;
        if(N == 1030) {
            puts("已达到最大人数30");
            return;
        }
        students[N++] = n;
        puts("新增成功");
    }
}
void show_data() {
    puts("显示成绩...");
    puts("*********************************");
    for(int i = 1001; i < N; i++) {
        printf("学号 = %d，成绩 = %d\n", i, students[i]);
    }
    puts("*********************************");
}
void get_total_and_avg(){
    int sum = 0;
    double avg = 0;
    for(int i = 1001; i < N; i++) {
        sum += students[i];
    }
    int cnt = N - 1001;
    printf("总分 = %d\n", sum);
    printf("平均分 = %.2f\n", sum/(double)cnt);
}

int max(int a, int b){
    return a > b?a:b;
}
int min(int a, int b) {
    return a > b?b:a;
}
void get_high_and_low(){
    if(N == 1001) {
        puts("暂无学生信息");
        return;
    }
    int high = students[1001];
    int low = students[1001];
    for(int i = 1001; i < N; i++) {
        high = max(high, students[i]);
        low = min(low, students[i]);
    }
    printf("最高分 = %d\n", high);
    printf("最低分 = %d\n", low);
}

void get_phase_info() {
    int you = 0,liang = 0,zhong = 0,jige = 0,bujige = 0;
    for(int i = 1001; i < N; i++) {
        if(students[i] >= 90) you++;
        else if(students[i] >= 80){
            liang++;
        }else if(students[i] >= 70) {
            zhong++;
        }else if(students[i] >= 60) {
            jige++;
        }else{
            bujige++;
        }
    }
    printf("成绩为优的人数 = %d\n", you);
    printf("成绩为良的人数 = %d\n", liang);
    printf("成绩为中的人数 = %d\n", zhong);
    printf("成绩为及格的人数 = %d\n", jige);
    printf("成绩为不及格的人数 = %d\n", bujige);
}
int main(){
    while(1) {
        menu();
        puts("请选择:");
        int n;
        scanf("%d", &n);
        if(n == 1){
            puts("请输入登录密码:");
            char pwd[64];
            scanf("%s", pwd);
            if(strcmp(pwd, password) == 0) {
                puts("登录成功");
                while(1) {
                    menu();
                    puts("请选择:");
                    int m;
                    scanf("%d", &m);
                    switch (m) {
                        case 1: puts("已登录");break;
                        case 2: insert_data();break;
                        case 3: show_data();break;
                        case 4: get_total_and_avg();break;
                        case 5: get_high_and_low();break;
                        case 6: get_phase_info();break;
                        case 0: puts("退出成功");return 0;
                    }
                }

            }else{
                puts("登录失败，请重新登录");
                continue;
            }
        }else if(n == 0){
            puts("成功退出系统");
            return 0;
        }else{
            puts("请先登录");
        }
    }

}