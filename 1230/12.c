#include <stdio.h>
#include <string.h>
#define N 100
typedef struct Student{
    char name[64];
    int age;
    char address[64];
}Student_T;
Student_T students[N];
static int n = 0;
void add(){

}
int main() {
    FILE* fp = fopen("gg.txt", "rw");
    if(fp == NULL) {
        puts("打开文件失败");
    }else{
        puts("打开文件成功");
    }
    for(int i = 0; i < n; i ++) {
        fwrite(students, 1, sizeof(Student_T), fp);
    }
    return 0;
}