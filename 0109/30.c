#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 30
typedef struct date {
    int year;
    int month;
    int day;
} DATE;
typedef struct gm {
    long Gmnumber;
    char Gmname[20];
    int quantity;
    int unitprice;
    int sum;
    DATE manufacture;
    char date[64];
} GM;

void Menu(void);

GM AppendGm(int *n);

void Appendtofile(GM stu);

void InputGM(GM stu[], int *n);

void WriteFile(GM stu[], int n);

void ReadFile(GM stu[], int *n);

void Print(GM stu[], int n);

void FindNumber(GM stu[], long number, int n);

void FindDate(GM stu[], int year, int month, int day, int n);

void FindRecord(GM stu[], int n);

void StatisticAnlysis(GM stu[], int n, int year, int month, int day);

void WriteCount(int n);

int ReadCount();


void Menu(void) {
    printf("************物资信息管理系统************\n");
    printf("|       1.物资入库台账                 |\n");
    printf("|       2.物资入库报表                 |\n");
    printf("|       3.按编号查询物资信息           |\n");
    printf("|       4.按日期查询物资信息           |\n");
    printf("|       5.查询入库金额最高和最低的记录 |\n");
    printf("|       6.入库金额统计分析             |\n");
    printf("|       0.退出系统                     |\n");
    printf("|______________________________________|\n");
}

void InputGM(GM stu[], int *n) {
    int i;
    char reply;
    i = -1;
    do {
        i++;
        printf("Input record %d:\n", i + 1);
        printf("编号；");
        scanf("%ld", &stu[i].Gmnumber);
        fflush(stdin);
        printf("品名；");
        gets(stu[i].Gmname);
        fflush(stdin);
        printf("数量；");
        scanf("%d", &stu[i].quantity);
        fflush(stdin);
        printf("单价；");
        scanf("%d", &stu[i].unitprice);
        fflush(stdin);
        printf("日期；");
        scanf("%d", &stu[i].manufacture.year);
        scanf("%d", &stu[i].manufacture.month);
        scanf("%d", &stu[i].manufacture.day);
        stu[i].sum = stu[i].quantity * stu[i].unitprice;
        printf("Do you want to continue(Y/y or N/n):");
        getchar();
        scanf("%c", &reply);
    } while (reply == 'Y' || reply == 'y');
    *n = i + 1;
}

void WriteFile(GM stu[], int n) {
    FILE *fp;
    int i;
    if ((fp = fopen("data.txt", "a")) == NULL) {
        printf("Faliure to open data.txt!\n");
        exit(0);
    }
    // 这个地方先保存数组的数量
    fprintf(fp, "%d ", n);
    for (i = 0; i < n; i++) {
        fprintf(fp, "%ld %s %d %d %d %04d-%02d-%02d\n", stu[i].Gmnumber,
                stu[i].Gmname, stu[i].quantity, stu[i].unitprice, stu[i].sum,
                stu[i].manufacture.year,
                stu[i].manufacture.month,
                stu[i].manufacture.day);

    }
    fclose(fp);
}

GM AppendGm(int *n) {
    int i;
    GM stu;
    printf("Input Append record%d:\n");
    printf("编号；");
    scanf("%ld", &stu.Gmnumber);
    fflush(stdin);
    printf("品名；");
    scanf("%d", &stu.Gmname);
    fflush(stdin);
    printf("数量；");
    scanf("%d", stu.quantity);
    fflush(stdin);
    printf("单价；");
    scanf("%d", &stu.unitprice);
    fflush(stdin);
    printf("日期；");
    scanf("%d", &stu.manufacture.year);
    scanf("%d", &stu.manufacture.month);
    scanf("%d", &stu.manufacture.day);
    stu.sum = stu.quantity * stu.unitprice;
    *n = *n + 1;
    return stu;
}

void Appendtofile(GM stu) {
    FILE *fp;
    int i;
    if ((fp = fopen("data.txt", "w")) == NULL) {
        printf("Faliure to open data.txt!\n");
        exit(0);
    }
    fprintf(fp, "%10ld %8s %4d %4d %4d %6d-%02d-%02d", stu.Gmnumber, stu.Gmname,
            stu.quantity, stu.unitprice, stu.sum, stu.manufacture.year,
            stu.manufacture.month,
            stu.manufacture.day);

    fclose(fp);
}

int ReadCount() {
    FILE *fp;
    int n = 0;
    if ((fp = fopen("Count.txt", "r")) == NULL) {
        printf("Faliure to open data.txt!\n");
        exit(0);
    }
    fscanf(fp, "%d", &n);
    fclose(fp);
    return n;
}

void WriteCount(int n) {
    FILE *fp;
    if ((fp = fopen("Count.txt", "r+")) == NULL) {
        printf("Faliure to open data.txt!\n");
        exit(0);
    }
    fprintf(fp, "%d\n", n);
    fclose(fp);
}

void FindRecord(GM stu[], int n)               //5.查询入库金额最高和最低的记录
{
    int i, j;
    GM temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (stu[j].sum > stu[i].sum) {
                temp = stu[j];
                stu[j] = stu[i];
                stu[i] = temp;
            }
        }
    }
    printf("%d %d", stu[0].sum, stu[n - 1].sum);
}

void StatisticAnlysis(GM stu[], int n, int year, int month,
                      int day)        //6.入库金额统计分析
{
    int i, j;
    int dayprice = 0;
    // 先按照日期从小到大排序
    for (i = 0; i < n; i++) {
        for (j = 0; j + 1 < n; j++) {
            if (stu[j].manufacture.year > stu[j + 1].manufacture.year) {
                GM temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            } else if (stu[j].manufacture.year == stu[j + 1].manufacture.year &&
                       stu[j].manufacture.month >
                       stu[j + 1].manufacture.month) {
                GM temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            } else if (stu[j].manufacture.year == stu[j + 1].manufacture.year &&
                       stu[j].manufacture.month ==
                       stu[j + 1].manufacture.month &&
                       stu[j].manufacture.day > stu[j + 1].manufacture.day) {
                GM temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
    // 然后统计相邻日期的总和，并输出
    int sum = 0;
    for (int k = 0; k < n; ++k) {
        if (k == 0) {
            sum += stu[k].sum;
        } else {
            if (stu[k].manufacture.year == stu[k - 1].manufacture.year &&
                stu[k].manufacture.month == stu[k - 1].manufacture.month &&
                stu[k].manufacture.day == stu[k - 1].manufacture.day
                    ) {
                sum += stu[k].sum;
            } else {

                printf("%04d-%02d-%02d，总金额为%d\n",
                       stu[k - 1].manufacture.year,
                       stu[k - 1].manufacture.month, stu[k - 1].manufacture.day,
                       sum);
                sum = stu[k].sum;
            }
        }
        if (k == n - 1) {
            printf("%04d-%02d-%02d，总金额为%d\n", stu[k].manufacture.year,
                   stu[k].manufacture.month, stu[k].manufacture.day, sum);
        }
    }
}

void ReadFile(GM stu[], int *n) {
    // 从文件中读入数据，按照日期先后顺序输出
    FILE *fp;
    int i, j;
    GM temp;
    int m;

    if ((fp = fopen("data.txt", "rw+")) == NULL) {
        printf("Failure to open data.txt!\n");
        exit(0);
    }
    fscanf(fp, "%d ", &m);
    *n = m;
    for (i = 0; i < *n; i++) {
        fscanf(fp, "%ld", &stu[i].Gmnumber);
        fscanf(fp, "%s", stu[i].Gmname);
        fscanf(fp, "%d", &stu[i].quantity);
        fscanf(fp, "%d", &stu[i].unitprice);
        fscanf(fp, "%d", &stu[i].sum);
        fscanf(fp, "%s", stu[i].date);
    }
    // 排序
    for (i = 0; i < *n; i++) {
        for (j = 0; j + 1 < *n; j++) {
            if (strcmp(stu[j].date, stu[j+1].date) > 0) {
                temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
    fclose(fp);
}

void Print(GM stu[], int n) {
    int i;
    printf("%s   %s  %s %s %s  %s\n", "编号", "品名", "数量", "单价", "金额",
           "生产日期");
    for (i = 0; i < n; i++) {
        printf("%ld %s %4d %d %d %s\n", stu[i].Gmnumber,
               stu[i].Gmname, stu[i].quantity, stu[i].unitprice, stu[i].sum,
               stu[i].date);
    }
}


void FindNumber(GM stu[], long number, int n) {
    int i;
    int x = 0;
    printf("输入要查询的物资编号:\n");
    scanf("%ld", &number);
    for (i = 0; i < n; i++) {
        if (number == stu[i].Gmnumber) {
            x = 1;
            printf("%6d", stu[i].Gmnumber);
            printf("%8s", stu[i].Gmname);
            printf("%3d", stu[i].quantity);
            printf("%6d", stu[i].unitprice);
            printf("%3d", stu[i].sum);
            printf("%6d-%2d-%2d\n", stu[i].manufacture.year,
                   stu[i].manufacture.month, stu[i].manufacture.day);
        }
    }
    if (x = 0) {
        printf("Not Find!\n");
    }
}

void FindDate(GM stu[], int year, int month, int day, int n) {
    int i;
    int total = 0;
    int x = 0;
    printf("输入要查询的日期:\n");
    scanf("%d %d %d", &year, &month, &day);
    for (i = 0; i < n; i++) {
        if (year == stu[i].manufacture.year &&
            month == stu[i].manufacture.month &&
            day == stu[i].manufacture.day) {
            x = 1;
            total = total + stu[i].sum;
            printf("%6d", stu[i].Gmnumber);
            printf("%8s", stu[i].Gmname);
            printf("%3d", stu[i].quantity);
            printf("%6d", stu[i].unitprice);
            printf("%3d", stu[i].sum);
            printf("%6d-%2d-%2d\n", stu[i].manufacture.year,
                   stu[i].manufacture.month, stu[i].manufacture.day);
        }
    }
    printf("%d", total);
    if (x = 0) {
        printf("Not Find!\n");
    }
}


int main() {
    GM stu[N];
    GM t;
    int n, m, op;
    long number;
    int year, month, day;


    while (1) {
        Menu();
        fflush(stdin);
        printf("\n请选择相应操作的序号>:");
        scanf("%d", &op);
        switch (op) {
            case 1:
                InputGM(stu, &n);
                WriteFile(stu, n);
//                WriteCount(n);
                break;

            case 2:
                // n是入参，通过读取文件可以知道有几条数据，重新给n赋值
                ReadFile(stu, &n);
                Print(stu, n);
//                n = ReadCount();
                break;

            case 3:
                FindNumber(stu, number, n);
                WriteFile(stu, n);
                ReadCount();
                break;

            case 4:
                FindDate(stu, year, month, day, n);

                break;

            case 5:
                FindRecord(stu, n);

                break;

            case 6:
                StatisticAnlysis(stu, n, year, month, day);

                break;

            case 0:
                exit(0);

            default:
                printf("Input error!");
        }
//        printf("\nInput the next op:  1:Add List  2:Read List  3:Number Check  4:Date Check  5:Check Record  6:Anlysis  0:Exit");
    }
    return 0;
}