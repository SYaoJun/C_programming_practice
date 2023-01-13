#include <cstdio>

#define MAX(x, y) (((x)>(y))?(x):(y))
#define MIN(x, y) (((x)<(y))?(x):(y))

int main() {
#ifdef MAX    //判断这个宏是否被定义
    printf("3 and 5 the max is:%d\n", MAX(3, 5));
#endif
#ifndef HELLO
    puts("HELLO宏未定义");
#endif

#ifdef MIN
    printf("3 and 5 the min is:%d\n", MIN(3, 5));
#endif
    return 0;
}

/*
 * (1)三元运算符要比if,else效率高
 * （2）宏的使用一定要细心，需要把参数小心的用括号括起来，
 * 因为宏只是简单的文本替换，不注意，容易引起歧义错误。
*/