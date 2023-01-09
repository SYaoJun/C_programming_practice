#include <stdio.h>
#include <string.h>
int main() {
    char ch;
    FILE* fp = fopen("poem.txt", "rw+");
    ch = getchar();
    while(ch != '\n') {
        fputc(ch, fp);
        ch = getchar();

    }
    rewind(fp);
    ch = fgetc(fp);
    while(ch != EOF) {
        printf("%c", ch);
        ch = fgetc(fp);
    }
    fclose(fp);
    return 0;
}