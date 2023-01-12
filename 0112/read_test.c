#include<stdio.h>
#include<string.h>
typedef struct Stu{
    char name[12];
    int age;
    char addr[15];
}Stu_T;
void read_file(){
    Stu_T stus[12];
    FILE* fp = fopen("hello", "rb");
    fread(&stus[0], sizeof(Stu_T), 1, fp);
    fread(&stus[1], sizeof(Stu_T), 1, fp);
    printf("%s %d %s\n", stus[0].name, stus[0].age, stus[0].addr);
    printf("%s %d %s\n", stus[1].name, stus[1].age, stus[1].addr);
}
void save_file(){
    Stu_T stus[12];
    strcpy(stus[0].name, "zhangsan");
    strcpy(stus[1].name, "zhangsan");
    strcpy(stus[0].addr, "chongqing");
    strcpy(stus[1].addr, "shanghai");
    stus[0].age = 10;
    stus[1].age = 12;
    FILE* fp = fopen("hello", "wb");
    fwrite(&stus[0], sizeof(Stu_T), 1, fp);
    fwrite(&stus[1], sizeof(Stu_T), 1, fp);
}
int main(){
    save_file();
    return 0;
}
