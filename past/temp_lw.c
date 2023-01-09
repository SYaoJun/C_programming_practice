#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student  //对应每个结构体
{
    char ID[20];
    char Name[40];
    int Chinese;
    int Math;
    int English;
} Stu[1000];
int num = 0;


void Copy(struct student *arr, int i, int j) {
    strcpy(arr[i].ID, arr[j].ID);
    strcpy(arr[i].Name, arr[j].Name);
    arr[i].Chinese = arr[j].Chinese;
    arr[i].Math = arr[j].Math;
    arr[i].English = arr[j].English;
}


int Student_SearchByIndex(char id[])//通过学号检索学生信息
{
    int i;
    for (i = 0; i < num; i++) {
        if (strcmp(Stu[i].ID, id) == 0)  //通过strcmp函数来对比学生id，找到返回位置
        {
            return i;
        }
    }
    return -1;
}

void student_DisplaySingle(int index)//输出学生各项信息
{
    puts("学号          姓名         语文        数学       英语");
    printf("----------------------------------------------------------------\n");
    printf("%s%10s%8.2d%8.2d%8.2d\n", Stu[index].ID, Stu[index].Name,
           Stu[index].Chinese, Stu[index].Math, Stu[index].English);
}

void inputt()//录入（输入）学生信息
{
    while (1) {
        printf("请输入学号:");
        scanf("%s", Stu[num].ID);
        getchar();
        printf("请输入姓名:");
        scanf("%s", Stu[num].Name);
        getchar();
        printf("输入语文成绩：");
        scanf("%d", &Stu[num].Chinese);
        getchar();
        printf("输入数学成绩：");
        scanf("%d", &Stu[num].English);
        getchar();
        printf("输入英语成绩：");
        scanf("%d", &Stu[num].Math);
        getchar();
        if (Student_SearchByIndex(Stu[num].ID) == -1) {
            num++;
        } else {
            printf("数据错误\n");
        }

        printf("是否继续?(y/n)");
        if (getchar() == 'n') {
            break;
        }
    }
}

void show()//显示学生信息
{
    int a;
    puts("学号          姓名         语文        数学       英语");
    printf("----------------------------------------------------------------\n");
    for (a = 0; a < num; a++) {
        printf("%s%10s%8.2d%8.2d%8.2d\n", Stu[a].ID, Stu[a].Name,
               Stu[a].Chinese, Stu[a].Math, Stu[a].English);
    }
    printf("----------------------------------------------------------------\n");
}


int search()//查询学生信息
{

    char id[20];
    int index;
    printf("请输入查询要学生的学号:");
    scanf("%s", id);
    getchar();
    index = Student_SearchByIndex(id);   //调用搜查id函数，根据其返回值确定位置
    if (index == -1) {
        printf("数据错误\n");
        return -1;
    } else {
        student_DisplaySingle(index);
        return -1;
    }
}


void Delete()//删除学生信息
{
    int i;
    char id[20];
    int index;
    printf("请输入要删除的学生的学号:");
    scanf("%s", id);
    getchar();
    index = Student_SearchByIndex(id);   //调用搜查id函数，根据其返回值确定位置
    if (index == -1) {
        printf("数据错误\n");
    } else {
        printf("你要删除的学生信息为:\n");
        student_DisplaySingle(index);
        printf("是否真的要删除?(y/n)");
        if (getchar() == 'y' || getchar() == 'Y') {
            for (i = index; i < num - 1; i++) {
                Copy(Stu, i, i + 1);
            }
            num--;
            printf("删除成功！\n");
        }
        getchar();
    }
}


void sort()//排序学生成绩和信息
{
    int i, j;
    for (i = 0; i < num; i++) {
        for (j = 0; j < num - i; j++) {
            if(Stu[j].English < Stu[j+1].English){
                struct student t;
                t = Stu[j];
                Stu[j] = Stu[j+1];
                Stu[j+1] = t;
            }
        }
    }
    puts("排序完成!");
    show();
}


void Modify() {

    char ID[40];
    int index;
    printf("输入要修改的学生学号:");
    scanf("%s", ID);
    index = Student_SearchByIndex(ID);
    if (index == -1) {
        printf("该学生不存在\n");
    } else {
        printf("要修改的学生信息为\n");
        student_DisplaySingle(index);
        printf("请输入修改后的值");
        printf("学号:");
        scanf("%s", Stu[index].ID);
        printf("姓名:");
        scanf("%s", Stu[index].Name);
        printf("语文成绩:");
        scanf("%d", &Stu[index].Chinese);
        printf("数学成绩:");
        scanf("%d", &Stu[index].Math);
        getchar();
        printf("英语成绩:");
        scanf("%d", &Stu[index].English);
    }

}

void Save() {
    int a;
    FILE *fp = fopen("temp.txt", "w+");
    fprintf(fp, "%d\n", num);
    for (a = 0; a < num; a++) {
        fprintf(fp, "%s %s %d %d %d\n", Stu[a].ID, Stu[a].Name, Stu[a].English,
                Stu[a].Chinese, Stu[a].Math);
    }
    fclose(fp);
}

void Load() {
    int i;
    FILE *fp = fopen("temp.txt", "r");
    fscanf(fp, "%d", &num);
    for (i = 0; i < num; i++) {
        fscanf(fp, "%s %s %d %d %d \n", Stu[i].ID, Stu[i].Name, &Stu[i].English,
               &Stu[i].Chinese, &Stu[i].Math);
    }
    fclose(fp);
}

void menu() {
    printf("*****************************************\n");
    printf("*            学生成绩系统                 *\n");
    printf("*****************************************\n");
    printf("*            1. 输入成绩                  *\n");
    printf("*            2. 显示成绩                  *\n");
    printf("*            3. 查询成绩                  *\n");
    printf("*            4. 更改成绩                  *\n");
    printf("*            5. 删除成绩                  *\n");
    printf("*            6. 排序                     *\n");
    printf("*            0. 退出系统                  *\n");
    printf("*****************************************\n");
}

void DisplayMenu() {
    int n;
    while (1) {

        menu();
        puts("请输入:");
        scanf("%d", &n);
        switch (n) {
            case 1:
                inputt();
                break;
            case 2:
                show();
                break;
            case 3:
                search();
                break;
            case 4:
                Modify();
                break;
            case 5:
                Delete();
                break;
            case 6:
                sort();
                break;
            case 0:
                exit(0);
                break;
            default:;
        }
        Save();
    }
}

int main() {

    DisplayMenu();
    puts("成功退出系统!");
    return 0;
}