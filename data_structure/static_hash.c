#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 131

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @brief The Student struct
 * 定义 结构体 数据类型 , 同时为该结构体类型声明 别名
 * 可以直接使用 别名 结构体变量名 声明结构体类型变量
 * 不需要在前面添加 struct 关键字
 */
typedef struct Student
{
    char name[5];
    int age;
    int id;
}Student;
/**
 * @brief printf_struct_array 打印结构体数组
 * @param array 数组作为函数参数退化为指针
 * @param count 数组中的元素个数
 */
void printf_struct_array(Student *array, int count)
{
    // 循环控制变量
    int i = 0;
    // 验证数组合法性
    if(array == NULL)
    {
        return;
    }
    // 打印结构体数组中的 结构体 age 字段
    for(i = 0; i < count; i++)
    {
        printf("Student age = %d\n", array[i].age);
    }
}
/**
 * @brief sort_struct_array 对结构体数组 按照年龄进行排序
 * @param array 结构体指针
 * @param count 结构体数组的元素个数
 */
void sort_struct_array(Student *array, int count)
{
    // 循环控制变量
    int i = 0, j = 0;
    // 学生年龄
    Student tmp;
    // 验证数组合法性
    if(array == NULL)
    {
        return;
    }
    // 排序
    for(i = 0; i < count; i++)
    {
        for(j = i + 1; j < count; j++)
        {
            if(array[i].age > array[j].age)
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}
/**
 * @brief create_student 堆内存中分配内存
 * @param array 二级指针 , 指向结构体数组
 * @return
 */
int create_student(Student **array, int count)
{
    // 返回值
    int ret = 0;
    // 临时变量
    Student *tmp = NULL;
    // 验证二级指针合法性
    if(array == NULL)
    {
        ret = -1;
        return ret;
    }
    // 堆内存中申请内存
    tmp = (Student *)malloc(sizeof(Student) * count);
    // 通过间接赋值 设置返回值
    *array = tmp;
    return ret;
}
/**
 * @brief free_student 释放内存
 * @param array
 * @return
 */
int free_student(Student **array)
{
    // 返回值
    int ret = 0;
    // 验证二级指针合法性
    if(array == NULL)
    {
        ret = -1;
        return ret;
    }
    // 释放内存
    free(*array);
    // 指针置空 , 防止野指针
    *array = NULL;
    return ret;
}
/**
 * @brief 主函数入口
 * @return
 */
int main(int argc, char* argv[], char**env)
{
    // 声明结构体数组 , 该数组在栈内存中
    Student *array = NULL;
    // 循环控制变量
    int i = 0;
    // 堆内存中为结构体指针分配内存
    create_student(&array, 3);
    // 命令行中 , 接收输入的年龄
    for(i = 0; i < 3; i++)
    {
        printf("\n Input Age :\n");
        // 命令换行中 接收 输入的年龄 ,
        // 设置到 Student 数组元素的 age 成员中
        scanf("%d", &(array[i].age));
    }
    // 结构体数组 按照 age 排序
    sort_struct_array(array, 3);
    // 打印结构体数组中的 结构体 age 字段
    printf_struct_array(array, 3);
    // 释放堆内存数据
    free_student(&array);
    // 命令行不要退出
    system("pause");
    return 0;
}

//int main(){
//    /*hash桶*/
//    ListType bucket[BUCKET_SIZE];
//
//
//    return 0;
//}