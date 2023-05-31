#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define M 2000
#define N 128
struct quest {
    char q[N];
    char A[N];
    char B[N];
    char C[N];
    char D[N];
};

typedef struct quest Question;
Question T[M];
int static total_num = 0;
int count[M];

void init(){
    memset(count, 0, sizeof(count));
}
void menu() {
    printf("=================问卷系统===========\n");
    puts("1.读取问卷内容");
    puts("2.读取答案并统计");
    puts("3.输出统计信息");
    puts("4.查询对应题目内容");
    puts("5.保存统计信息到文件中");
    printf("===================================\n");
    printf("请选择(0-4):");
}

void save() {
    FILE *fp = fopen("RSLT.txt", "rw");
    if(fp == NULL) {
        puts("文件打开失败");
        return ;
    }
    fprintf(fp, "%d", count[0]);
    fprintf(fp, "%d", count[1]);
    fprintf(fp, "%d", count[2]);
    fprintf(fp, "%d", count[3]);
    fprintf(fp, "%d", count[4]);
    fflush(fp);
    fclose(fp);
    puts("保存成功");
}
int content_num = 3;
void read_qst() {

    FILE *fp = fopen("QST.txt", "r");
    if(fp == NULL) {
        puts("文件打开失败");
        return;
    }
    for(int i = 0; i < content_num; i++) {
        fscanf(fp, "%s", T[total_num].q);
        fscanf(fp, "%s", T[total_num].A);
        fscanf(fp, "%s", T[total_num].B);
        fscanf(fp, "%s", T[total_num].C);
        fscanf(fp, "%s", T[total_num].D);
        total_num++;
    }
}
int valid_number = 0;
void read_ans() {
    char buf[M];
    FILE *fp = fopen("ANS.txt", "r");
    for(int i = 0; i < content_num; i++) {
        fscanf(fp, "%s", buf);
        for(int i = 0; buf[i]; i++) {
            if(buf[i] >= 'A' &&  buf[i]<='D'){
                count[buf[i]-'A']++;
                valid_number++;
            }else{
                buf[4]++;
            }
        }
    }
}
void show_info(){
    puts("请输入你要查询的题目编号:");
    int id;
    scanf("%d", &id);
    if(id > content_num) {
        puts("不存在该题号");
        return;
    }
    puts(T[id-1].q);
    puts(T[id-1].A);
    puts(T[id-1].B);
    puts(T[id-1].C);
    puts(T[id-1].D);
}

// 统计每个选项的数量，百分比通过当前数量除以总数量
void stat() {
    printf("A选项：%d，所占百分比为：%.2f\n", count[0], count[0]*1.0/valid_number);
    printf("B选项：%d, 所占百分比为：%.2f\n", count[1], count[1]*1.0/valid_number);
    printf("C选项：%d, 所占百分比为：%.2f\n", count[2], count[2]*1.0/valid_number);
    printf("D选项：%d, 所占百分比为：%.2f\n", count[3], count[3]*1.0/valid_number);
    printf("无效选项：%d, 所占百分比为：%.2f\n", count[4], count[4]*1.0/valid_number);
}
int main() {
    init();
    while (1) {
        menu();
        puts("请选择:");
        int m;
        scanf("%d", &m);
        switch (m) {
            case 1:
                read_qst();
                break;
            case 2:
                read_ans();
                break;
            case 3:
                stat();
                break;
            case 4:
                show_info();
                break;
            case 5:
                save();
                break;
            case 0:
                puts("退出成功");
                return 0;
        }
    }

}