#include <stdio.h>
void fun(int q[][7],int n,int m);
// 结构体，存储信息
typedef struct people_info{
    char* name;
    int age;
    char type;
}people_info_type;

int main()
{
    int k,h,n=0,flag=1;//用于判断的变量
    int a,b,c,d,e,f,g;
    int achoice,bchoice,cchoice,dchoice,echoice,fchoice,gchoice;//用于确定员工选择个数的变量
    int q[7][7];//用于员工存储所选择的休假日的变量
    int A[7];
    printf("保安休息日排班系统\n");
    printf("***********************\n");
    printf(" 1. 休息日期信息输入\n");
    printf(" 2. 休息日信息存入文件\n");
    printf(" 3. 轮休方案\n");
    printf(" 0. 退出\n");
    printf("***********************\n");
    printf("请选择相应的数字：\n");

    printf("赵：");
    printf("请您输入您想选择的次数\n:      ");//a录入休假日
    scanf("%d",&achoice);
    fun(q,achoice,1);

    printf("钱：");
    printf("请您输入您想选择的次数\n:      "); //b录入休假日
    scanf("%d",&bchoice);
    fun(q,bchoice,2);



    printf("孙：");
    printf("请您输入您想选择的次数\n:      ");//c录入休假日
    scanf("%d",&cchoice);
    fun(q,cchoice,3);

    printf("李：");
    printf("请您输入您想选择的次数\n:      ");//d录入休假日
    scanf("%d",&dchoice);
    fun(q,dchoice,4);

    printf("周：");
    printf("请您输入您想选择的次数\n:      ");//e录入休假日
    scanf("%d",&echoice);
    fun(q,echoice,5);

    printf("吴：");
    printf("请您输入您想选择的次数\n:      ");//f录入休假日
    scanf("%d",&fchoice);
    fun(q,fchoice,6);

    printf("陈：");
    printf("请您输入您想选择的次数\n:      ");//g录入休假日
    scanf("%d",&gchoice);
    fun(q,gchoice,6);

    for(a=0;a<achoice&&q[a][0]!=0;a++)
    {
        for(b=0;b<bchoice&&q[b][1]!=0;b++)
        {
            for(c=0;c<cchoice&&q[c][2]!=0;c++)
            {
                for(d=0;d<dchoice&&q[d][3]!=0;d++)
                {
                    for(e=0;e<echoice&&q[e][4]!=0;e++)
                    {
                        for(f=0;f<fchoice&&q[f][5]!=0;f++)
                        {
                            for(g=0;g<gchoice&&q[g][6]!=0;g++)
                            {             //7个循环实现遍历
                                A[0]=q[a][0];
                                A[1]=q[b][1];
                                A[2]=q[c][2];
                                A[3]=q[d][3];
                                A[4]=q[e][4];
                                A[5]=q[f][5];
                                A[6]=q[g][6];
                                flag=1;
                                for(k=0;k<6;k++)
                                {
                                    for(h=k+1;h<7;h++)
                                    {
                                        if(A[k]==A[h]) flag=0;  //比较任意两个数是否相等

                                    }
                                }


                                if(flag==1)
                                {                             //如果不等则输出结果
                                    printf("得到以下组合：\n");
                                    printf("赵:  "); printf("星期%d \n",A[0]);
                                    printf("钱:  "); printf("星期%d \n",A[1]);
                                    printf("孙:  "); printf("星期%d \n",A[2]);
                                    printf("李:  "); printf("星期%d \n",A[3]);
                                    printf("周:  "); printf("星期%d \n",A[4]);
                                    printf("吴:  "); printf("星期%d \n",A[5]);
                                    printf("陈:  "); printf("星期%d \n",A[6]);
                                    printf("   \n  ");
                                    n++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(n==0)
    {
        printf("对不起，你们的选择不能实现排班，请重新选择!!\n");
    }
    return 0;
}
void fun(int q[][7],int n,int m)
{
    people_info_type info_inst;
    info_inst.name = "zhangsan";
    info_inst.age = 22;
    info_inst.type = 'X';
    // 需要打印就解除注释
    //printf("name = %s,  age = %d, type = %c\n",info_inst.name, info_inst.age, info_inst.type);
    int i;
    printf("请您输入轮休日期:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&q[i][m]);
    }
}