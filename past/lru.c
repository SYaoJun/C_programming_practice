/**
 	思路: 
 		1.基本和上道题一样，但是我们在处理这个页面置换算法的时候用的是 LRU 
		  最近最久未使用的思想进行置换页面  
		2.这个算法每次处理的置换页面号，我们依然用队列进行处理，但是我们要注意的是
		  我们在如果这个页号已经在内存中存在,那么就要就要将其
		
		debug:解决运行时错误 
		  1.将int类型转换成string类型没问题
		  2.[178781373];非结构体数组范围问题
		  3.最后一行有空行无问题                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        z 
*/ 



#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>
int N,M;//N代表页面大小 M代表物理块数
int cnt = 0;

typedef struct Node{
	int block;  //块 
	char page[1024]; //页
	int priority;//优先级 
}Node;

Node node[1000];
void sort() {
    for(int i = 0; i < M; i++) {
        for(int j = 0; j+1 < M; j++) {
            if(node[j].priority > node[j+1].priority) {
                Node t;
                t = node[j];
                node[j] = node[j+1];
                node[j+1] = t;
            }
        }
    }
}

void printSate(){
    puts("物理块号 页号");

	for(int i = 0; i < M; i++){
		for(int j = 0;  j < M; j++){
			if(i == node[j].block){
                printf("%d %s\n", node[j].block, node[j].page);
			}	
		}
	}	 
} 

void outResult(int address){
	
	int pageNumber = address/N;    //页号 
	int pageMigration = address%N; //页内偏移	
	
     char str[1024];
     memset(str, 0, sizeof(str));
     sprintf(str,"%d",pageNumber);
	int temp1 = 0,temp2 = 0;
	
    printf("页号：%d 页内偏移：%d\n", pageNumber, pageMigration);
	
	//遍历内存的物理块中是否有该页号
	for(int i = 0; i < M; i++){
		if(strcmp(node[i].page, str) == 0){
			temp1 = 1;		
		}
		if(strcmp(node[i].page, "void") == 0){ //统计有空闲的位置 
			temp2++;	
		}
	}  
	
	//在内存的时候 
	if(temp1 == 1){
		
		cnt++;
		
		//这个时候因为块中已有该页  我们遍历整个结构体数组 找到  该页号  将新的优先级赋值给它
		for(int i = 0; i < M; i++){
			if(strcmp(node[i].page, str) == 0){
				node[i].priority = cnt;
			}
		}

        sort();

		printSate();	
	}
	
	//不在内存的时候, 且内存中还有空间
	if(temp1 == 0 && temp2 > 0){
        puts("该页不在内存中,调入!");
		
		//更新物理块中的页号状态 
		for(int i = 0; i < M; i++){
			if(strcmp(node[i].page, "void") == 0){			
				strcpy(node[i].page, str);
				cnt++;
				node[i].priority = cnt;
				break;
			}		
		}
        sort();
		printSate();	
	}	
	
	//当不在内存的时候,内存中没有空间
	if(temp1 == 0 && temp2 == 0){	
	
        puts("已无空闲物理块,置换!");
			
		cnt++; 
		
		//这个时候就覆盖结构体数组当中的首个元素的  页号
		strcpy(node[0].page, str);
		node[0].priority = cnt; 
		 
		sort();
		printSate();
	} 	 
}

int main(){
	int logicAddress;
    for(int i = 0; i < 1000; i++) {
        node[i].priority = 0;
    }
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; i++){
		node[i].block = i;
		strcpy(node[i].page, "void");	
	}
	
	while(1){		
		scanf("%d", &logicAddress);
		if(logicAddress != -1){
		 outResult(logicAddress);
		}else{
			break;
		}		
	}
	
} 





