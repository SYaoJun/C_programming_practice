#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Teacher {
    int id;
    char name[20];
    char sex[20];
    char workplace[50];
    char address[50];
    long phone;
    double de_salary;
    double de_jintie;
    double de_shenghuobutie;
    double yingfa_salary;
    double cost_phone;
    double cost_water_elec;
    double cost_rent;
    double cost_tax;
    double cost_weisheng;
    double cost_gongjijin;
    double cost_all;
    double shifa_salary;
} Teacher_Type;

#define N 4096
static int n = 0;
Teacher_Type faculty[N];
void save_info() {
    FILE *fp1 = fopen("sort.txt", "w+");
    if (fp1 == NULL) {
        printf("文件不存在，且已经重新创建!\n");
        fp1 = fopen("sort.txt", "w+");
    } else {
        printf("sort文件打开成功！\n");
    }
    sprintf(fp1, "%d ", n);
    for (int i = 0; i < n; i++) {
        fprintf(fp1, "教师号=%d 姓名=%s 性别=%s 单位名称=%s 家庭地址=%s 联系电话=%ld 基本工资=%.2f "
               "津贴=%.2f 生活补贴=%.2f 应发工资=%.2f 电费=%.2f 水电费=%.2f "
               "房租=%.2f 所得税=%.2f 卫生费=%.2f 公积金=%.2f 合计扣款=%.2f 实发工资=%.2f\n",
               faculty[i].id,
               faculty[i].name, faculty[i].sex, faculty[i].workplace,
               faculty[i].address,
               faculty[i].phone, faculty[i].shifa_salary, faculty[i].de_jintie,
               faculty[i].de_shenghuobutie, faculty[i].yingfa_salary,
               faculty[i].cost_phone, faculty[i].cost_water_elec,
               faculty[i].cost_rent, faculty[i].cost_tax,
               faculty[i].cost_weisheng, faculty[i].cost_gongjijin,
               faculty[i].cost_all,
               faculty[i].shifa_salary);
    }
    fclose(fp1);  //关闭第一个文件
}

void update(Teacher_Type *temp) {
    temp->yingfa_salary =
            temp->de_salary + temp->de_jintie + temp->de_shenghuobutie;
    temp->cost_all =
            temp->cost_water_elec + temp->cost_phone + temp->cost_rent +
            temp->cost_tax + temp->cost_weisheng + temp->cost_gongjijin;
    temp->shifa_salary = temp->yingfa_salary - temp->cost_all;
}

void add() {
    puts("请输入教师信息...");
    Teacher_Type temp;
    puts("请输入教师号:");
    scanf("%d", &temp.id);
    puts("请输入姓名:");
    scanf("%s", temp.name);
    puts("请输入电话号码:");
    scanf("%ld", &temp.phone);
    puts("请输入家庭地址:");
    scanf("%s", temp.address);
    puts("请输入基本工资:");
    scanf("%lf", &temp.de_salary);
    puts("请输入津贴:");
    scanf("%lf", &temp.de_jintie);
    puts("请输入生活补贴:");
    scanf("%lf", &temp.de_shenghuobutie);
    puts("请输入电话费:");
    scanf("%lf", &temp.cost_phone);
    puts("请输入水电费:");
    scanf("%lf", &temp.cost_water_elec);
    puts("请输入房租:");
    scanf("%lf", &temp.cost_rent);
    puts("请输入所得税:");
    scanf("%lf", &temp.cost_tax);
    puts("请输入卫生费:");
    scanf("%lf", &temp.cost_weisheng);
    puts("请输入公积金:");
    scanf("%lf", &temp.cost_gongjijin);

    update(&temp);
    faculty[n++] = temp;
}
void show_info(int i){
    printf("教师号=%d 姓名=%s 性别=%s 单位名称=%s 家庭地址=%s 联系电话=%ld 基本工资=%.2f "
           "津贴=%.2f 生活补贴=%.2f 应发工资=%.2f 电费=%.2f 水电费=%.2f "
           "房租=%.2f 所得税=%.2f 卫生费=%.2f 公积金=%.2f 合计扣款=%.2f 实发工资=%.2f\n",
           faculty[i].id,
           faculty[i].name, faculty[i].sex, faculty[i].workplace,
           faculty[i].address,
           faculty[i].phone, faculty[i].shifa_salary, faculty[i].de_jintie,
           faculty[i].de_shenghuobutie, faculty[i].yingfa_salary,
           faculty[i].cost_phone, faculty[i].cost_water_elec,
           faculty[i].cost_rent, faculty[i].cost_tax,
           faculty[i].cost_weisheng, faculty[i].cost_gongjijin,
           faculty[i].cost_all,
           faculty[i].shifa_salary);
}
void search_by_id() {
    int exist = 0;
    int id;
    puts("请输入你要查询的教师号:");
    scanf("%d", &id);

    for (int i = 0; i < n; i++) {
        if (faculty[i].id == id) {
            show_info(i);
            exist = 1;
            return;
        }
    }
    if (exist == 0) {
        puts("未找到相关信息");
    }
}

void delete() {
    puts("请输入要删除的教师号:");
    int id;
    scanf("%d", &id);
    for (int i = 0; i < n; i++) {
        if (faculty[i].id == id) {
            for (int j = 0; j + 1 < n; j++) {
                faculty[j] = faculty[j + 1];
            }
            n--;
            puts("删除成功");
            return;
        }
    }
    puts("删除失败");
}


void browse() {
    if (n == 0) {
        puts("系统暂无教师信息");
        return;
    }
    puts("所有教师信息展示如下...");
    for (int i = 0; i < n; i++) {
        show_info(i);
    }
}

void menu() {
    printf(" -----------------教师工资管理系统--------------------\n");
    printf(" |                  1.输入教师信息                   |\n");
    printf(" |                  2.修改教师信息                   |\n");
    printf(" |                  3.删除教师信息                   |\n");
    printf(" |                  4.浏览教师信息                   |\n");
    printf(" |                  5.根据教师号查询信息              |\n");
    printf(" |                  0.退出系统                      |\n");
    printf("------------------------------------------------------\n");
}

void submeanu() {
    puts("1.修改姓名");
    puts("2.修改性别");
    puts("3.修改单位名称");
    puts("4.修改公积金");
    puts("0.返回转单");
}

void modify_name(int id) {
    puts("请输入新的名称:");
    char name[50];
    scanf("%s", name);
    strcpy(faculty[id].name, name);
    puts("更新成功");
}

void modify_gongjijin(int id) {
    puts("请输入新的公积金:");
    double gongjijin;
    scanf("%lf", &gongjijin);
    faculty[id].cost_gongjijin = gongjijin;
    update(&faculty[id]);
    puts("更新成功");
}

void modify_sex(int id) {
    puts("请输入新的性别:");
    char sex[50];
    scanf("%s", sex);
    strcpy(faculty[id].sex, sex);
    puts("更新成功");
}

void modify_workplace(int id) {
    puts("请输入新的性别:");
    char workplace[50];
    scanf("%s", workplace);
    strcpy(faculty[id].workplace, workplace);
    puts("更新成功");
}

void modify() {
    int id;
    puts("请输入你要修改的教师号:");
    scanf("%d", &id);
    int exist = 0;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (faculty[i].id == id) {
            exist = 1;
            idx = i;
            break;
        }
    }
    if (!exist) {
        puts("暂无该教师信息");
        return;
    }
    while (1) {
        submeanu();
        int choice;
        printf("请输入您的选择:\n ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                modify_name(idx);
                break;
            case 2:
                modify_sex(idx);
                break;
            case 3:
                modify_workplace(idx);
                break;
            case 4:
                modify_gongjijin(idx);
                break;
            case 0:
                return;
        }
    }
}

int main() {
    while (1) {
        menu();
        int choice;
        printf("请输入您的选择: \n ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                modify();
                break;
            case 3:
                delete();
                break;
            case 4:
                browse();
                break;
            case 5:
                search_by_id();
                break;
            case 0:
                save_info();
                puts("成功退出系统");
                return 0;
        }
    }
}
