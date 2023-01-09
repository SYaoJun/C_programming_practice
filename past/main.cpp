
#include <stdio.h>
#include <string.h>

struct Node{
    int id;//id号
    char* partition;//分区
    int start;//起始地址
    int end; //结束地址
    int size;//大小
    char* state;//当前的状态
}node[1000];

int cnt = 0;
int memory, minsize;//内存的大小和阙值
int sumSize = 0;//记录累计的容量

//1.初始化
void Initialize(){
    scanf("%d %d", &memory, &minsize );
    node[cnt].id = 1;
    node[cnt].start = 0;
    node[cnt].end = memory - 1;
    node[cnt].size = memory;

}

//2.分配

//分区号 分区 起始地址 结束地址 大小 当前状态
//1    void    0       1023    1024 空闲

//分区号 分区 起始地址 结束地址 大小 当前状态
//1    A     0         99      100 已分配
//2    B    100       299      200 已分配
//3    C    300       449      150 已分配
void distribution(){

    char processName[1024];
    int processSize;
    scanf("%s %d", processName, &processSize);

    if(cnt == 0){//这里主要是处理首个进程的计算
        node[cnt].end = -1;
    }


    int temp1 = memory - node[cnt].end - 1;//这里是求出容器距离上一次的结束地址 还剩的空间大小

    int temp2 = memory - sumSize;//这里是总的剩余内存的大小

    //考虑阙值
    int temp3 = temp1 - processSize;
    if(temp3 <= minsize && temp3 >= 0){ //如果剩余的空间小于阙值，那么的话我们就将剩下的空间全给其进程
        processSize = temp1;
    }

    if(temp1 >= processSize){

        cnt++;
        node[cnt].id = cnt;
        node[cnt].partition = processName;
        if(cnt == 1){
            node[cnt].start = 0;
        }else{
            node[cnt].start = node[cnt-1].start + node[cnt-1].size;//本次的开始地址等于上次的开始地址加其大小
        }
        node[cnt].end = node[cnt].start + processSize - 1;//本次的结束地址为开始地址+其大小减一
        node[cnt].size = processSize;
        strcpy(node[cnt].state, "已分配");

        sumSize += processSize;

        puts("分配成功！" );
    }else if(temp2 >= processSize){//如果第一个条件不满足，那么的话就判断剩余的总内存，也就是紧凑

        puts("是否通过紧凑技术，重新划分？(Y/N)");

        char ch;
        scanf("%c", &ch);

        /*如果我们的第一个if条件已经满足的话根本就不用考虑是否紧凑，那么好，如果我们要
            紧凑的话，只能说明在这个容器的前面还有空间，那么容器的前面有空间就说明发生了回收
           这时候如果我们选择 Y 那么的话我们就要更新前面的id....,如果是 N,那就不用更新
        */
        if(ch == 'Y'){

            //更新前面的空闲区，将非空的进程赋值给前面空的进程，紧凑出空间给新的进程
            for(int i = 1; i <= cnt; i++) {
                if(node[i].partition == "void"){

                    int value =  node[i].size;//记录下来空闲区的大小
                    int j = i;

                    bool temp = false;

                    for( ; j < cnt; j++){
                        node[j].id = j;
                        node[j].partition = node[j+1].partition;
                        node[j].start = node[j+1].start - value;
                        node[j].end = node[j+1].end - value;
                        node[j].size = node[j+1].size;
                        node[j].state = node[j+1].state;

                        temp = true;
                    }

                    cnt--;//这时候腾出一个空间,所以结构体数组的大小减一
                    i = 0;//再从头开始遍历空闲区，因为空闲区可能不止一个

                    if(temp == false)//说明要紧凑的空间是最后一个，那么直接跳出循环
                        break;

                }
            }

            //这时候考虑我们的阙值 因为当没有紧凑的时候根本没有空间来判断剩余空间的大小
            //跟阙值的关系

            int laterTemp1 = memory - node[cnt].end - 1;//紧凑后的空间大小

            int laterTemp3 = laterTemp1 - processSize;

            if(laterTemp3 <= minsize){

                processSize = laterTemp1;

            }
            //赋值，当上方完成后这时候就腾出一个大的size
            cnt++;
            node[cnt].id = cnt;
            node[cnt].partition = processName;
            if(cnt == 1){
                node[cnt].start = 0;
            }else{
                node[cnt].start = node[cnt-1].start + node[cnt-1].size;//本次的开始地址等于上次的开始地址加其大小
            }
            node[cnt].end = node[cnt].start + processSize - 1;
            node[cnt].size = processSize;
            node[cnt].state = "已分配";

            sumSize += processSize;

            puts("分配成功！");

        }else if (ch == 'N'){
            puts("没有合适的剩余空间，不予分配。");
        }

    }else{
        puts("剩余空间不足，不予分配。");
    }
}

//3.回收
void recycling(){
/*
	如果发生回收的话，要将 分区改为 void,其状态为空闲，其他均不变;
	分为四种情况：
	 <1>:如果其上下均无空闲区，那么该回收的进程就单独成一行
	 <2>:如果该回收的进程上放有一个空的空闲区，那么就要和其上方进行合并，修改上方的结束地址和空间大小
	 <3>:如果该回收的进程的下方有一个空闲区，那么就修改回收进程的大小和结束地址即可
	 <4>:如果该回收的进程上下都有空闲区，那么的话我们就修改最上方的空闲区的大小和结束地址即可

*/

    char processName[1024];
    int flag = 0;

    scanf("%s", processName);

    for(int i = 1; i <= cnt; i++) {
        if(processName == node[i].partition){

            node[i].partition = "void";
            node[i].state = "空闲";

            sumSize -= node[i].size;//一旦发生回收那么这个累计的容量就要减去回收的容量

            flag = 1;
            break;
        }
    }

    if(flag == 1){
        puts("回收成功！" );

        /*
          这里我们在合并空闲区的时候只需要当发现一个空闲区的时候，看看下一个分区是否是空闲区
          如果是就合并
        */
        for(int i = 1; i < cnt; i++){

            if(node[i].partition == "void" && node[i+1].partition == "void"){

                node[i].size += node[i+1].size;//其大小为两个分区的和
                node[i].end = node[i+1].end;//其结束地址为下一个空闲区的结束地址

                //因为分区少了一个所以要更新后面分区的id号
                int j = i+2;
                for( ; j <= cnt; j++){
                    node[j-1].id = j - 1;
                    node[j-1].partition = node[j].partition;
                    node[j-1].start = node[j].start;
                    node[j-1].end = node[j].end;
                    node[j-1].size = node[j].size;
                    node[j-1].state = node[j].state;
                }

                cnt--;//分区少一个
                i = 0;//再从头开始遍历 因为可能有多个空闲区
            }
        }
    }else{
        puts("查无此分区！");
    }
}

//4.显示
void show(){
   puts("分区号 分区 起始地址 结束地址 大小 当前状态");

    if (cnt == 0) {
        for(int i = 0; i <= cnt; i++){
            printf("%d %s %d %d %d %s\n", node[i].id, node[i].partition, node[i].start,
                  node[i].end, node[i].size, node[i].state);
        }
    } else {
        //这里需要将剩余的空间也得输出一下

        int remainTemp = memory - node[cnt].end - 1;

        //这里写大于0 是因为上方我已经处理 minsize;
        if(remainTemp > 0){
            cnt++;
            node[cnt].id = cnt;
            node[cnt].partition = "void";
            if(cnt == 1){
                node[cnt].start = 0;
            }else{
                node[cnt].start = node[cnt-1].start + node[cnt-1].size;//本次的开始地址等于上次的开始地址加其大小
            }
            node[cnt].end = node[cnt].start + remainTemp - 1;
            node[cnt].size = remainTemp;
            node[cnt].state = "空闲";
        }



        for(int i = 1; i <= cnt; i++){

            scanf("%d %s %d %d %d %s", &node[i].id, node[i].partition, &node[i].start,
                  &node[i].end, &node[i].size, node[i].state);
        }
    }
}

//菜单栏
void menu(){
    puts("1.初始化\n2.分配\n3.回收\n4.显示\n0.退出\n请选择：\n");
}


int main(){

    bool flag = true;
    menu();

    while(flag){
        int option;
        scanf("%d", &option);

        switch(option){

            case 1: Initialize();
                break;

            case 2: distribution();
                break;

            case 3: recycling();
                break;

            case 4:	show();
                break;

            case 0 : flag = false;
                break;

            default: puts("输入错误，请重新输入。");

        }
    }
}

