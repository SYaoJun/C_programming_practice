#include <stdio.h>
#include <stdlib.h>
typedef struct stu {
    int id;
    char *name;
}stu;
typedef stu* stu_ptr;

typedef struct person{
    int age_;
    stu_ptr stu_ptr_;
}person;

void test(stu st){
    printf("address = %p, id = %d, name = %s\n", &st, st.id, st.name);
}
void test_stu(){
    stu stu1;
    stu1.id = 1;
    stu1.name = "zhang";
    printf("address = %p, at main function.\n", &stu1);
    test(stu1);
}
void test_pointer(){
    char *p1 = NULL;
    int *p2 = NULL;
    double *p3 = NULL;

    printf("char*p1 = %lu\n", sizeof p1);
    printf("char*p2 = %lu\n", sizeof p2);
    printf("char*p3 = %lu\n", sizeof p3);
    /*结果都是8，如何去理解不同类型的指针具有相同的大小？*/
    /*64位机，指针都是8个字节。不同类型是因为指针指向的内容所占的大小。*/
}
void init_stu(){
    stu boy = {1024, "lisi"};
    stu girl = {1024, "mali"};
    printf("id = %d, name = %s\n", boy.id, boy.name);
    printf("id = %d, name = %s\n", girl.id, girl.name);
}
void memory_align(){
    stu boy = {1024, "lisi"};
    printf("address_struct = %p\n", &boy);
    printf("address_first_element = %p\n", &boy.id);
    printf("address_second_element = %p\n", &boy.name);
}
void designated_initializer(){
    int id = 99;
    stu boy = {.name = "lisi", .id = id};
    printf("id = %d, name = %s\n", boy.id, boy.name);
}
void pointer_to_struct(){
    stu boy = {19, "tom"};
    stu* stu_ptr = &boy;
    printf("id = %d, name = %s\n", boy.id, boy.name);
}
int main(void){
    pointer_to_struct();
    return 0;
}