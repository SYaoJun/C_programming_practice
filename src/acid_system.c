#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define filename "student.txt"
#define N 10000
static int total = 0;
#define CHARSIZE 64
typedef struct Person
{
    char name[CHARSIZE];
    char sex[CHARSIZE];
    int age;
    char addr[CHARSIZE];
    long long idcard;
    char work_company[CHARSIZE];
    char family_member[CHARSIZE];
    char check_time[CHARSIZE];
    int check_result; // 1是阳  0是阴
}Person_T;

typedef struct Admin
{
    char name[CHARSIZE];
    char sex[CHARSIZE];
    char position[CHARSIZE];
}Admin_T;

Person_T students[N];
Admin_T admins[N];
int admin_number = 0;
void menu()
{
    printf("*****************************************\n");
    printf("*            核酸检测管理系统              *\n");
    printf("*****************************************\n");
    printf("*            1. 录入普通用户信息           *\n");
    printf("*            2. 录入管理员信息             *\n");
    printf("*            3. 查询信息                  *\n");
    printf("*            4. 更新信息                  *\n");
    printf("*            5. 删除信息                  *\n");
    printf("*            6. 显示所有信息               *\n");
    printf("*            0. 退出系统                  *\n");
    printf("*****************************************\n");
}
#define filename "student.txt"
void read_file(){
    int i = 0;
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        return;
    }
    while (!feof(fp))
    {
        fread(&students[i], 1, sizeof(Person_T), fp);
        i++;
    }
    total = i;
    fclose(fp);
}

void save_file() {
    int i;
    FILE *fp = fopen(filename, "w");
    fwrite(&students, total, sizeof(Person_T), fp);
    fclose(fp);
}

void query_info() {
    char name[CHARSIZE];
    char addr[CHARSIZE];
    char work_company[CHARSIZE];
    char check_time[CHARSIZE];
    int check_result;
    puts("请输入要查询人员的姓名:");
    scanf("%s", name);
    puts("请输入要查询人员的单位:");
    scanf("%s", work_company);
    puts("请输入要查询人员的核酸检测时间:");
    scanf("%s", check_time);
    puts("请输入要查询人员的新冠检测结果(1是阳，0是阴):");
    scanf("%d", &check_result);
    puts("请输入要查询人员的家庭地址:");
    scanf("%s", addr);
    int is_exist = 0;
    for(int i = 0; i < total; i++) {
        if(strcmp(students[i].name, name) == 0 &&
        strcmp(students[i].work_company, work_company) == 0 &&
        strcmp(students[i].check_time, check_time) == 0 &&
        students[i].check_result == check_result &&
        strcmp(students[i].addr, addr) == 0) {
            is_exist = 1;
            puts("找到相关人员");
            puts("-----------------------------------");
            printf("姓名=%s，性别= %s，年龄=%d，家庭住址=%s，身份证号码=%lld，"
                   "工作单位=%s，家庭成员=%s，核酸检测时间=%s，核酸检测结果=%d\n",
                   students[i].name, students[i].sex, students[i].age,students[i].addr,
            students[i].idcard ,students[i].work_company,students[i].family_member,
            students[i].check_time, students[i].check_result);
        }
    }

    if(is_exist == 1) {
        puts("查找完成!");
    }else{
        puts("未找到满足要求的人员!");
    }
}
void modify_info() {
    puts("请输入要修改人员的身份证号码:");
    long long idcard;
    scanf("%lld", &idcard);
    int status = 0;
    puts("请输入核酸结果（1是阳，0是阴）:");
    scanf("%d", &status);
    int is_exist = 0;
    for(int i = 0; i < total; i++) {
        if(students[i].idcard == idcard) {
            is_exist = 1;
            students[i].check_result = status;
        }
    }
    if(is_exist == 1) {
        puts("修改成功!");
    }else{
        puts("无效的身份证信息，该用户不存在!");
    }
}

void delete_info() {
    puts("请输入要删除人员的身份证号码:");
    long long idcard;
    scanf("%lld", &idcard);
    int is_exist = 0;
    for(int i = 0; i < total; i++) {
        if(students[i].idcard == idcard) {
            //移动数据
            for(int j = i; j < total; j++) {
                students[j] = students[j+1];
            }
            total--;
            is_exist = 1;
            break;
        }
    }
    if(is_exist != 0) {
        puts("删除成功!");
    }else{
        puts("无效的身份证信息，该用户不存在!");
    }
}

void insert_ordinary_info() {
    Person_T temp_person;
    puts("请输入普通用户姓名:");
    scanf("%s", temp_person.name);
    puts("请输入普通用户性别:");
    scanf("%s", temp_person.sex);
    puts("请输入普通用户年龄:");
    scanf("%d", &temp_person.age);
    puts("请输入普通用户家庭住址:");
    scanf("%s", temp_person.addr);
    puts("请输入普通用户身份证号码:");
    scanf("%lld", &temp_person.idcard);
    puts("请输入普通用户工作单位:");
    scanf("%s", temp_person.work_company);
    puts("请输入普通用户家庭成员:");
    scanf("%s", temp_person.family_member);
    puts("请输入普通用户核酸检测时间:");
    scanf("%s", temp_person.check_time);
    puts("请输入普通用户核酸检测结果:");
    scanf("%d", &temp_person.check_result);
    students [total++] = temp_person;
    puts("录入成功!");
}

void insert_super_admin_info(){
    Admin_T temp_admin;
    puts("请输入管理员姓名:");
    scanf("%s", temp_admin.name);
    puts("请输入管理员性别:");
    scanf("%s", temp_admin.sex);
    puts("请输入管理员职位:");
    scanf("%s", temp_admin.position);
    admins[admin_number++] = temp_admin;
    puts("录入成功!");
}

void show_all_info() {
    puts("姓名   性别  年龄   家庭住址  身份证号码   工作单位  家庭成员   核酸检测时间  核酸检测结果");
    puts("-------------------------------------------------------------------------------");
    for(int i = 0; i < total; i++) {
        printf("%s   %s   %d   %s  %lld    %s    %s   %s   %d\n",
               students[i].name, students[i].sex, students[i].age,students[i].addr,
               students[i].idcard ,students[i].work_company,students[i].family_member,
               students[i].check_time, students[i].check_result);
    }
}

void show_user(){
    printf("******************************************\n");
    printf("*            选择你的登录身份               *\n");
    printf("*****************************************\n");
    printf("*            1. 普通用户                  *\n");
    printf("*            2. 管理员信息                *\n");
    printf("*            3. 退出                     *\n");
    printf("*****************************************\n");
}

void show_ordinary_page(){
        printf("******************************************\n");
        printf("*            普通用户操作页面               *\n");
        printf("*****************************************\n");
        printf("*            1. 注册                     *\n");
        printf("*            2. 登录                     *\n");
        printf("*            3. 退出                     *\n");
        printf("*****************************************\n");
}

void show_admin_page(){
        printf("******************************************\n");
        printf("*            管理员操作页面                *\n");
        printf("*****************************************\n");
        printf("*            1. 注册                     *\n");
        printf("*            2. 登录                     *\n");
        printf("*            3. 退出                     *\n");
        printf("*****************************************\n");
}

void success_login(){
        printf("******************************************\n");
        printf("*            登录成功                     *\n");
        printf("*****************************************\n");
        printf("*            1. 查询个人信息               *\n");
        printf("*            2. 退出                      *\n");
        printf("******************************************\n");
}


typedef struct user{
    char name[CHARSIZE];
    char password[CHARSIZE];
    char idcard[CHARSIZE];
}User_T;

User_T registers[N];
int register_number = 0;
void register_info() {
    User_T  user;
    puts("输入你的姓名:");
    scanf("%s", user.name);
    puts("输入你的密码:");
    scanf("%s", user.password);
    puts("输入你的身份证号码:");
    scanf("%s", user.idcard);
    registers[register_number++] = user;
    puts("注册成功!");
}

int log_info() {
    User_T  user;
    puts("输入你的姓名:");
    scanf("%s", user.name);
    puts("输入你的密码:");
    scanf("%s", user.password);
    puts("输入你的身份证号码:");
    scanf("%s", user.idcard);
    for(int i = 0; i < register_number; i++) {
        if(strcmp(user.idcard, registers[i].idcard) == 0 && strcmp(user.name, registers[i].name) == 0 &&
            strcmp(user.password, registers[i].password) == 0){
                puts("登录成功");
                return 1;
            }

    }

    puts("登录失败");
    return 0;
}

int main(){
    read_file();
    while(1)
    {
        int n;
        show_user();
        puts(">");
        scanf("%d", &n);
        if(n == 1) {
            while(1){
                show_ordinary_page();
                puts("请输入你的选择(1-3):");
                int n;
                scanf("%d", &n);
                if(n == 1) {
                    register_info();
                }else if(n == 2){
                    log_info();
                    success_login();
                    puts("请选择:");
                    int x;
                    scanf("%d", &x);
                    if(x == 1) {
                        query_info();
                    }else{
                        break;
                    }
                }else if(n == 3) {
                    break;
                }
            }
        }else if(n == 2){
            while(1){
                show_admin_page();
                puts("请选择(1-3)：");
                int x;
                scanf("%d", &n);
                if(n == 1) {
                    register_info();
                }else if(n == 2){
                    int s = log_info();
                    if(s == 0) continue;
                    menu();
                    puts(">");
                    scanf("%d", &n);
                    switch(n){
                        case 1:insert_ordinary_info();break;
                        case 2:insert_super_admin_info();break;

                        case 3:{
                            query_info();
                            break;
                        }
                        case 4:{
                            modify_info();
                            break;
                        }
                        case 5:{
                            delete_info();
                            break;
                        }
                        case 6:{
                            show_all_info();
                            break;
                        }
                        case 0: {
                            save_file();
                            printf("程序结束!\n");
                            return 0;
                        }
                        default:
                            puts("输入有误，请重新输入！");
                    }

                }else if(n == 3) {
                    break;
                }
            }
        }else if(n == 3){
            puts("成功退出!");
            return 0;
        }
    }
    return 0;
}


