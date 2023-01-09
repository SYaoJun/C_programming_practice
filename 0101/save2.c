#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 2
struct stu {
    char name[10]; //姓名
    int num;  //学号
    int age;  //年龄
    float score;  //成绩
}boya[N], boyb[N], *pa, *pb;

int main() {

    FILE *fp;
    int i;
    pa = boya;
    pb = boyb;
    if ((fp = fopen("demo.txt", "wb+")) == NULL) {
        puts("Fail to open file!");
        exit(0);
    }
    //从键盘输入数据
    printf("Input data:\n");
    for (i = 0; i < N; i++, pa++) {
        scanf("%s %d %d %f", pa->name, &pa->num, &pa->age, &pa->score);
    }
    //将数组 boya 的数据写入文件
    fwrite(boya, sizeof(struct stu), N, fp);
    //将文件指针重置到文件开头
    rewind(fp);
    //从文件读取数据并保存到数据 boyb
    fread(boyb, sizeof(struct stu), N, fp);
    //输出数组 boyb 中的数据
    for (i = 0; i < N; i++, pb++) {
        printf("%s  %d  %d  %f\n", pb->name, pb->num, pb->age, pb->score);
    }
    fclose(fp);
    return 0;

}