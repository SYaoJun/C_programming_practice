#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define filename "hello.txt"
typedef struct Student{
    char name[100];
    int age;
}Student_T;
#define M 1000
Student_T student[M];
static int n = 0;
void save_file() {
    int i;
    FILE *fp = fopen(filename, "w");
    for (i = 0; i<2; i++)
        if (fwrite(&student[i], sizeof(Student_T), 1, fp) != 1)
            printf("file write error\n");
//    fwrite(&student, sizeof(Student_T), 1, fp);
    fclose(fp);
}
int main(){
    strcpy(student[n].name, "tom");
    student[n].age = 19;
    n++;
    strcpy(student[0].name, "jerry");
    student[0].age = 20;
    n++;
    save_file();
    return 0;
}