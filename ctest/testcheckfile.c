#include <unistd.h>
#include <stdio.h>

#include <sys/stat.h>
#define filename "hello.txt"
int main(){
    int is_exist = access(filename, F_OK);
    if(is_exist == 0) {
        puts("文件存在");
    }else{
        puts("文件不存在");
    }
    // 获取文件大小
    struct stat statbuf;
    stat(filename,&statbuf);
    int size=statbuf.st_size;
    printf("文件大小 = %d\n", size);
    return 0;
}