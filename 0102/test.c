#include <string.h>
#include <stdio.h>
struct EMM{
    char name[100];
    int age;
    char sex;
}emm[3], *p = emm;
int main() {
    int m = 0xA1;
//    printf("%04d", m);
    scanf("%c", &p->sex);
    scanf("%c", &emm[0].sex);
    scanf("%d", &(*p).age);
    scanf("%s", emm->name);
    return 0;
}