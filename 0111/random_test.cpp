#include <iostream>
#include <random>
using namespace  std;
void test(){
    random_device d;    // random_device下面会介绍
    mt19937 m(d());  //初始化生成器
    cout<< mt19937() <<endl; //产生一个随机数
}
void test2(){
    default_random_engine engin;    //得到一个随机数生成器
    engin.seed(time(nullptr)); //传入种子
    uniform_int_distribution<int> dist(1, 10);  //得到一个随机分布
    for(int i=0;i<100;i++)
        cout<<dist(engin)<<endl;    //随机分布利用随机数生成器生成随机数


}
void test3(){
    random_device d;
    mt19937 m(d());    //先得到一个随机数生成器
    uniform_int_distribution dist{1,99};    //然后得到一个随机数分布
    cout << dist(m) <<endl;    //将生成器传入分布，得到最后的随机数


}
typedef struct Stu{
    char name[12];
    int age;
    char addr[15];
}Stu;
int main(){
    Stu stus[12];
    strcpy(stus[0].name, "zhangsan");
    strcpy(stus[1].name, "zhangsan");
    strcpy(stus[0].addr, "chongqing");
    strcpy(stus[1].addr, "shanghai");
    stus[0].age = 10;
    stus[1].age = 12;
    FILE* fp = fopen("hello", "rb");
    fwrite(stus[0], sizeof(Stu), 1, fp);
    fwrite(stus[0], sizeof(Stu), 1, fp);
    return 0;
}

