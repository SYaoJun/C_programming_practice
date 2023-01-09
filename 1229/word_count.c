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
    /*printf("输入文章路径：");*/
    char file[30];
    char ch;
    /*scanf("%s", &file);//输入文件路径*/
    fp = fopen("hello.txt", "r");
    if (fp == NULL)
    {
        printf("文件打开失败.\n");
    }
    else
    {
        printf("文件打开成功.\n");
    }
    char content[4096];
    int idx = 0;
    while ((ch = fgetc(fp) )!= EOF)
    {
        content[idx++] = ch;
    }
    content[idx] ='\0';
    puts("读入完成...");
    puts(content);
    for (i = 0; i < strlen(passage); i++)
    {
        m[j++] += passage[i];
    }
    printf("%s\n\n", m[j]);
    if ((fp = fopen("world.txt", "w+"))== NULL)
    {
        printf("文件不存在.\n");
    }
    else
    {
        printf("文件存在.\n");
        printf("-------统计结果-------");
    }
    for (i = num - 1; i >= 0; i--)
    {
        fprintf(fp, "%s\t", vocab[i]);
        fprintf(fp, "%d\n", count[i]);
        printf("%5s   %5d\n", vocab[i], count[i]);
    }
    fclose(fp);
    printf("以上为统计的结果!");

}