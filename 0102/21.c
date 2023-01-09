#include <string.h>
#include <stdio.h>
#define M 64
typedef struct User{
    char name[M];
    char sex[M];
    int no;
    int votes;
    double rate;
}User_T;
void Input(User_T *user, int *n){
    puts("请输入候选人信息:");
    User_T temp;
    puts("请输入编号:");
    scanf("%d", &temp.no);
    puts("请输入姓名:");
    scanf("%s", temp.name);
    puts("请输入性别:");
    scanf("%s", temp.sex);
    user[*n] = temp;
    *n = *n+1;
}

void Statis(User_T *user, int m){
    int n;
    puts("请输入你投票对象的编号,输入-1结束");
    scanf("%d", &n);
    int total = 0;
    while(n!=-1){
        for(int i = 0; i < m; i++){
            if(n == user[i].no){
                user[i].votes++;
            }
        }
        scanf("%d", &n);
    }
    for(int i = 0; i < m; i++){
        total += user[i].votes;
    }
    for(int i = 0; i < m; i++){
        user[i].rate = (double)user[i].rate/total;
    }
}
void Sort(User_T *user, int m){
    for(int i = 0; i < m; i++) {
        for(int j = 0; j + 1 < m; j++) {
            if(user[j].votes < user[j+1].votes) {
                User_T t = user[j];
                user[j] = user[j+1];
                user[j+1] = t;
            }
            if(user[j].votes == user[j+1].votes && strcmp(user[j].name, user[j+1].name) > 0) {
                User_T t = user[j];
                user[j] = user[j+1];
                user[j+1] = t;
            }
        }
    }
}
void Output(User_T *user, int m) {
    puts("序号(no)   姓名(name)   性别(sex)   票数(votes)   得票率(rate)");
    for(int i = 0; i < m; i++){
        printf("%d %s %s %d %.2f\n", user[i].no, user[i].name, user[i].sex, user[i].votes, user[i].rate);
    }
}
int main() {
    User_T users[M];
    int n = 0;
    while(1){
        int u;

        puts("请选择:");
        puts("1. 输入候选人信息");
        puts("2. 统计票数");
        puts("3. 排序");
        puts("4. 输出");
        puts("0. 退出");
        scanf("%d", &u);
        switch (u) {
            case 1:
                Input(users, &n);
                break;
            case 2:
                Statis(users, n);
                break;
            case 3:
                Sort(users, n);
                break;
            case 4:
                Output(users, n);
                break;
            case 0:
                return 0;
        }
    }
    return 0;
}