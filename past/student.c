#include <stdio.h>
#define N 20
int main()
{
    float ave[3];
    float score[32][8];
    float sum;
    int i,j,n;
    printf("请输入学生的人数:");
    scanf("%d",&n);
    printf("请输入这些学生的三门成绩:");
    for(i=0;i<n;i++)
    {
        printf("请输入第%d个学生的3门成绩:",i+1);
        for(j=0;j<3;j++)
            scanf("%f",&score[i][j]);
    }
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<3;j++)
            sum=sum+score[i][j];
        score[i][3]=sum/3;
    }
    for(j=0;j<3;j++)
    {
        sum=0;
        for(i=0;i<n;i++)
            sum=sum+score[i][j];
        ave[j]=sum/n;
    }
    printf("序号  课程1  课程2  课程3  平均成绩 \n");
    for(i=0;i<n;i++)
    {
        printf("%-10d",i+1);
        for(j=0;j<4;j++)
            printf("%-9.1f",score[i][j]);
        printf("\n");
    }
    printf("平均成绩 ");
    for(j=0;j<3;j++)
        printf("%-9.1f",ave[j]);
    getchar();
}