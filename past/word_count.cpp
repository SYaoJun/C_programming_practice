#include <time.h>
#include <string.h>
#include <iostream>
#define MaxFiles 30
#define FileNameLength 20
#define PageSize 40
#define MaxLength 30
#define RowSize 80
#define pathIn "./"
#define pathOut "./"

typedef struct {
    char data[MaxLength];
    int length;
}SqString;
typedef struct {
    unsigned int count;
    int localPath[100], localRow[100];
}SearchOut;
typedef struct {
    char files[MaxFiles/2][FileNameLength];
    unsigned int files_num;
}Param;
void getFiles(unsigned  int& filesnum, char  filename[MaxFiles][20])
{
    long Handle;
    filesnum = 0;
    struct  _finddata_t   FileInfo;
    char path[50] = pathIn;
    strcat(path, "*.txt");
    if ((Handle = findfirst(path, &FileInfo)) == -1L)
        printf("没有找到匹配的项目\n");
    else
        int  i = 0;
    for (; FileInfo.name[i]!= '\0'; i++)//将FileInfo.name[i]复制到filename数组
        filename[files  num][i] = FileInfo.name[i];
    filename[filesnum][i] = '\0';//添加"\0"
    files num++;
    while (findnext(Handle, &FileInfo) == 0 && filesnum(MaxFiles)
    {
        for (i = 0; FileInfo.name[i] != '\0'; i++)
            //将FileInfo.name[i]复制到filename数组
            filename[files  num][i] = FileInfo.name[i];
        filename[files  num][i] = '\0';   //添加‘\0’
        files num++;
    }
    findclose(Handle);
}
}
//线程函数
unsigned int  WINAPI count(PVOID param)
{
WordCount((char*)param);
printf("\2\2\2");
return  NULL;
}
void countAllPaper()
{
    //统计所有文件
    char  files[MaxFiles][20];  //存放文件列表数组MaxFiles为可读最大文件数，20为文件名长度
    unsigned int  filesnum = 0;
    getFiles(filesnum, files);
    HANDLE  hThread[MaxFiles];

    unsigned int threadID;
    //设置参数
    clock_t tl = clock();
    //创建线程
    printf("--------------");
    for (int i = 0; i < files num; i++)
    {
        hThread[i] = (HANDLE)beginthreadex(NULL, 0, count, files[i], 0, &threadID);
    }
    //等待线程结束
    for (int i = 0; i < files num; i++) {
        WaitForSingleObject(hThread[i], -1);
        CloseHandle(hThread[i]);
    }
    printf("------\n已统计该文件夹下%d个txt文件单词个数,\n本次统计耗时：%dms\n1", files  num, clock() - t1);
    printf("注：统计结果存放于%s目录下\n", pathOut);
}
void  InitSqString(SqString& s, char  str[])
{
    int  i;
    for (i = 0; str[i] != '\0'; i++)
    {
        s.data[i] = str[i];
    }
    s.data[i] = '\0';
    s.length = i;
    //输出查找结果到文件

    void OutFile(SearchOut & s, FILE * fout)
    {
        if (s.count == 0)
        {
            fputs("There is no word which you want in this article.\n", fout);
            return;
        }
        for (int i = 0; i < s.count % 100; i++)
            fprintf(fout, " %d\t %d\n",s.localPage[i],s.localRow[i]);
    }
    //查找单词
    int Mate(SqString t)
    {
        clock_t t1;
        int j0, page, row, k, rear;//k为数组头指针，first为尾指针

        bool  flag;
        char  ch, files[MaxFiles][20], inFile[50], outFile[50] = pathOut;
        char  temp[81] :
        //files存放文件列表数组MaxFiles为可读最大文件数，20为文件名长度

        strcat(outFile, "SearchResult.txt");
        unsigned  int files  num = 0, totaltime = 0, usedtime;
        //文件个数
        getFiles(files num, files);
        SearchOut  s;
        FILE* fin, * fout;
        if ((fout = fopen(outFile, "w"))==NULL)
        {
            printf("Can't creat a new txt:%s\n", outFile);
            return  -1;
        }
        fprintf(fout, "Word \”%s\”in every article location(page\trow):\n", t.data);
        for (unsigned int i = 0; i < files num; i++)
        {
            //打开文件
            strcpy(inFile, "F:\\Test\\paper\\");
            strcat(inFile, files[i]);
            if ((fin = fopen(inFile, "r")) == NULL)
            {
                printf("can't open %s\n", inFile);
                return  -1;
            }
            //初始化
            s.count = 0;
            page = row = 1;
            rear = 79;
            flag = false;//文件末尾标志
            fprintf(fout, "\n\nWord in %s location:\n", files[i]);
            tl = clock();
            while (!flag) {
                reart + ;
                for (k = 0; rear < 80; k++, rear++)
                    temp[k] = temp[rear];
                for (; k < 80; k++)//读满temp
                    temp[k] = fgetc(fin);
                k--;//k指向最后一个字符

                for (; k >= 0; k--) {//k指向最后一个非字母
                    if (temp[k] < 'A'lltemp[k]> 'z'll(temp[k] > 'Z'&&temp[k]<'a'))
                        break;
                }
                rear = k; //rear指向最后一个非字母
                if (k >= 0)
                    temp[k] = '\n';//换为‘换行符’
                k = 0;//k指向temp头
                ch = temp[k];

                //开始匹配，直到文章结束为止
                while (k < (rear) && ch != E0F) {//rear为temp可读长度
                    j = 0;
                    while (ch == t.data[j] && j < t.length) {
                        ch = temp[++k];//指向下一个字符
                        j++;


                        if (j == t.length)
                        {
                            //匹配
                            if (ch < 'A'llch>'z'll(ch > 'Z' && ch < 'a'))
                            {
                                s.localPage[s.count % 100] = page;
                                s.localRow[s.count % 100] = row;
                                s.count++; //s已满，输出并初始化
                                if (s.count % 100 == 99)
                                {
                                    OutFile(s, fout);

                                    while ((ch >= 'a' && ch <= 'z')川I(ch <= 'Z' && ch >= 'A') && k < rear)//单词
                                    间以非字母隔开
                                            ch = temp[++k];  //若为换行符，则行数加1
                                    if (ch == '\n')
                                    {
                                        rowt + ;
                                        if (row > PageSize) { //PageSize为最大行数
                                            row = 1;
                                            page++;

                                        }
                                        ch = temp[++k];
                                    }
                                    if (ch == EOF)
                                        flag = true;
                                }
                                usedtime = clock() - t1;
                                OutFile(s, fout);     //读完一篇输出s
                                fprintf(fout, "the numbre of words:%d", s.count);
                                fprintf(fout, "\nused time:%d", usedtime);
                                fclose(fin);
                                totaltime += usedtime;
                            }
                            fprintf(fout, "\n\nUsed totaltime:%d", totaltime);
                            fclose(fout);
                            return totaltime;
                        }
                        void Search() {
                            char  search[MaxLength];
                            SqString t;
                            int time;

                            printf("请输入要查找的单词：");
                            fflush(stdin);   //清空输入缓冲区
                            scanf("%s",search);
                            InitSqString(t, search);
                            time = Mate(t) :
                            if (time != -1) {
                                printf("已统计可匹配单词：%s\n", search);
                                printf("本次统计耗时：%d ms\n", time);
                            }
                            else
                                printf("统计失败，请检查后再试!\n");
                        }
                        int   tmain(int argc, TCHAR * argv[])
                        {
                            char  ifContinue;
                            int   choose;
                            do {
                                printf("---------------------Welcome------------------------------------------\n")
                                printf("*请将需要统计的英文文章存放于%s目录下\n", pathIn);
                                printf("\n\t\t\t\t1 、统计单词\n\n\t\t\t\t2 、查找单词\n");
                                printf("---------------------------------------------\n");
                                printf("请输入功能号(1/2):");

                                fflush(stdin);  //清空输入缓冲区
                                scanf("%d", &choose);
                                if (choose == 1) {
                                    countAllPaper();
                                }
                                else  if (choose == 2)
                                {
                                    Search();
                                    printf("------统计结果已存放于%sSearchResult.txt 目录下文档.------\n", pathOut);
                                }


                                else
                                    printf("输入不正确!\n");

                                fflush(stdin);
                                printf("\n是否继续?(Y/y):");
                                scanf("%c", &ifContinue);
                                std::system("CLS");
                            } while (ifContinue == 'Y' || ifContinue = ' y');
                            printf("\n\n\t\t程序已退出……………\n\n\n");
                            Printf("------------------------------------------------------------------------\n");
                            system("pause") ;
                            return 0;
                        }
typedef struct node {
    char data;
    unsigned int count;
    struct  node* next, * sibling;
}Word;
typedef struct {
    int  top;
    Word* data[MaxLength];
}Stack;

class  WordCount
{
private:
    Stack St;
    Word* root;
    unsigned int  usedTime;
    void InitStack(Stack& s);
    void Init(Word*& node, int  ch);
    void  Insert(Word*& p, char ch);
    void JoinTree(Word*& p, char ch);
    void Fout(Word* r, int& d, FILE* fout, unsigned int& sum);
public:

    WordCount();
    WordCount(char* filesname);
    unsigned   int   getusedTime(void);
    WordCount(void);
};


WordCount::WordCount() {}
WordCount::WordCount(char* filename)
{
    char outFile[50] = pathOut, inFile[50] = pathIn;//文件名
    char  s1[20];
    char  ch;//文件读入字符， outTxt Name文件名
    int  i = 0, d = 0;   //d为不同单词数，j为当前行截止下标
    unsigned   int   sum = 0;
    root = new  Word();
    Word* p = root;
    InitStack(St);
    Clock_t     t1;
    //生成文件目录和文件名
    for (i = 0; filename[i] != '.'; i++)
        s1[i] = filename[i];
    s1[i] = '\0';
    strcat(outFile, s1);
    strcat(outFile, "Count.txt\0");
    strcat(inFile, filename);

    FILE* fin, * fout;
    if ((fin = fopen(inFile, "r"))=NULL)
    {
        printf("can't   open   %s\n", inFile);
    }
    else {
        if ((fout = fopen(outFile, "w"))==NULL)
        {
            printf("can't  creat  a  new  txt:%s\n", outFile);
        }
        t1 = clock();    //开始计时
        while ((ch = fgetc(fin)) != EOF)
        {
            //开始统计个数


            JoinTree(p, ch);
        }
        usedTime = clock() - t1;
        fclose(fin);
        Fout(root->next, d, fout, sum);
        fprintf(fout, "%s%d" ,"the   number   of   all   words : ",sum);
        fprintf(fout, "%s%d", "\nthe   number   of   different   words:", d);
        fprintf(fout,"%s%d", "\nused  time:", usedTime); //将计时差存入txt
        fclose(fout);
    }
}
WordCount::~WordCount(void)
{
}
void    WordCount::InitStack(Stack & s) {
    s.top = -1;
}
void  WordCount::Init(Word * &node, int   ch) {
    node = new Word();
    node->data = ch;
    node->count = 0;
    node->sibling = node->next = NULL;
}
void  WordCount::Insert(Word * &p, char  ch) { //p节点前插入新节点
    Word *newnode;//p节点后插入新节点newnode
    Init(newnode, p->data);
    newnode->sibling = p->sibling;
    p->sibling = newnode;

    newnode->count = p->count; //将p 的值赋予newnode
    newnode->next = p->next;

    p->next = NULL;//p节点赋新值
    p->data = ch;
    p->count = 0;
}
void WordCount::JoinTree(Word *kp, char ch)
{
    //将读入的字母字符加入树 if((ch>='a'&&ch<='z') |(ch<='Z'&&ch>='A')){//是否为字母
    if (p->next == NULL)
    {
        Word* newnode;//创建并初始化节点
        Init(newnode, ch);
        p->next = newnode;


        p = p->next;
        return;
    }
    p = p->next;
    while (p->sibling != NULL && p->data < ch)
        p = p->sibling;
    if (p->data == ch)
        return;
    else  if (p->data > ch) {
        Insert(p, ch); //在p前面插入新节点
        return;
    }
    else  if (p->sibling = NULL) {
        Word *newnode;//创建并初始化节点
        Init(newnode, ch);
        p->sibling = newnode;
        p = newnode;
    }
}
else
{
p->count++;
p = root;
}
}
void  WordCount::Fout(Word * r, int& d, FILE * fout, unsigned int& sum) {//将单词个数 输出，root为树根
    if (r == NULL)
        return;
    St.data[++St.top] = r;
    if (r->count != 0) {
        d++;
        int  i = 0;
        char inSt[MaxLength];
        for (; i <= St.top; i++)
            inSt[i] = St.data[i]->data;
        inSt[i++] = '\t';
        inSt[i] = '\0';
        fprintf(fout, "%s%d\n", inSt, r->count);
        sum += r->count;
    }

    Fout(r->next, d, fout, sum);
    St.top--;


    Fout(r->sibling, d, fout, sum);
}
unsigned  int  WordCount::getUsedTime()
{
    return    usedTime;
}