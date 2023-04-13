#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
int main()
{
    char* dir = "/Users/yaojun/sildes";
    char* file = "/Users/yaojun/sildes/README.md";
    struct stat buf;
    int result;
    result = stat(file, &buf);
    if(S_IFDIR & buf.st_mode){
        printf("folder\n");
    }else if(S_IFREG & buf.st_mode){
        printf("file\n");
    }
    return 0;
}