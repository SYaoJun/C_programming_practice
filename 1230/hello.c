#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char passage[500] = { 0 };
    char vocab[200][20];
    char word[20];
    char count[120] = { 0 };
    int i, k = 0, j = 0, num = 0;
    FILE* fp;
    char m[500] = " ";
    char file[30];
    char ch;
    fp = fopen("hello.txt", "r");
    if (fp == NULL)
    {
        printf("文件打开失败.\n");
    }
    else
    {
        printf("文件打开成功.\n");
    }
    int idx = 0;
    while ((ch = fgetc(fp)) != EOF)
    {
        passage[idx++] = ch;
    }
    passage[idx] = '\0';
    puts("读入完成...");
    puts(passage);
    char str[64];
    char new_str[64];
    puts("请输入你要替换的原单词:");
    scanf("%s", str);

    puts("请输入你要替换的新单词:");
    scanf("%s", new_str);



    char new_passage[1024];
    int kk = 0;
    int n = strlen(passage);
    for(int i  = 0; i < n; ) {
        if(passage[i] == ' ') {
            new_passage[kk++] = passage[i];
            i++;
            continue;
        }
        int j = 0;
        char temp[64];
        while(i + j < n && passage[i+j] != ' ') {
            temp[j] = passage[i+j];
            j++;
        }
        temp[j] = '\0';
//        puts(temp);
//        printf("j = %d\n", j);
        if(strcmp(temp, str) == 0) {
            for(int u = 0; u < strlen(new_str); u++) {
                new_passage[kk++] = new_str[u];
            };

        }else{
            for(int u = 0; u < strlen(temp); u++) {
                new_passage[kk++] = temp[u];
            };
        }
        i += j;
    }
    new_passage[kk++] = '\0';
    rewind(fp);
    puts(new_passage);
    int uu = 0;
    ch = new_passage[uu++];
    while(ch != '\0') {
        fputc(ch, fp);
        ch = new_passage[uu++];
    }
    fclose(fp);
}