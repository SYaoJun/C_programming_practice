#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int static n = 0;

int my_stoi(string s) {
    int sum = 0;
    for(int i = 0; i < s.size(); i++) {
        sum = sum *10 + x - '0';
    }
    return sum;
}
struct Student
{
    int id;
    string stu_id;
    string name;
    string sex;
    string depart;
    int English;
    int Math;
    int CS;
    int sum;
};
vector<Student> stus;
void Read()
{
    int i = 0;
    FILE *fp = fopen("ab_stu.txt", "r");
    if(fp == NULL) {
        cout<<"文件不存在..."<<endl;
        return;
    }
    char str[100];
    memset(str, 0, sizeof str);
    fscanf(fp,"%s",str);
    Student temp;
    int cnt = 0;
    while (!feof(fp)){
        cnt++;
        fscanf(fp,"%s",str);
        string t = str;
        if(cnt > 8) {
            n++;
            if(n % 8 == 1) {
//                cout<<"id = "<<t<<endl;
                temp.id = my_stoi(t);
            }
            if(n % 8 == 2) {
//                cout<<"stu_id = "<<t<<endl;
                temp.stu_id = t;
            }
            if(n % 8 == 3) {
//                cout<<"name = "<<t<<endl;
                temp.name = t;
            }
            if(n % 8 == 4) {
//                cout<<"sex = "<<t<<endl;
                temp.sex = t;
            }
            if(n % 8 == 5) {
//                cout<<"depart = "<<t<<endl;
                temp.depart = t;
            }
            if(n % 8 == 6) {
//                cout<<"Eng = "<<t<<endl;
                temp.English = my_stoi(t);
            }
            if(n % 8 == 7) {
//                cout<<"Math = "<<t<<endl;
                temp.Math = my_stoi(t);
            }
            if(n % 8 == 0) {
//                cout<<"CS = "<<t<<endl;
                temp.CS = my_stoi(t);
                temp.sum = temp.English + temp.Math + temp.CS;
                stus.push_back(temp);
            }
        }
    }
    n = n/8;
//    cout<<"closed"<<endl;
    fclose(fp);
}


void menu()//菜单
{
    printf("*****************************************\n");
    printf("*                                       *\n");
    printf("*            学生成绩管理系统           *\n");
    printf("*                                       *\n");
    printf("*****************************************\n");
    printf("*            1. 查询成绩                *\n");
    printf("*            2. 插入数据                *\n");
    printf("*            3. 删除数据                *\n");
    printf("*            4. 更新数据                *\n");
    printf("*            5. 排序                   *\n");
    printf("*            0. 退出系统                *\n");
    printf("*****************************************\n");
}


void query_by_stu_id(){
    cout<<"请输入查询学生的学号：";
    string stu_id;
    cin >> stu_id;
    bool exist = false;
    for(int i = 0; i < stus.size(); i++) {
        if(stus[i].stu_id == stu_id) {
            exist = true;
            cout<<"该学生信息如下:";
            cout<<"编号："<<stus[i].id<<endl;
            cout<<"学号："<<stus[i].stu_id<<endl;
            cout<<"姓名："<<stus[i].name<<endl;
            cout<<"性别："<<stus[i].sex<<endl;
            cout<<"系名："<<stus[i].depart<<endl;
            cout<<"英语："<<stus[i].English<<endl;
            cout<<"数学："<<stus[i].Math<<endl;
            cout<<"计算机："<<stus[i].CS<<endl;
            cout<<"总分："<<stus[i].sum<<endl;
            break;
        }
    }
    if(!exist) {
        cout<<"未找到该学生"<<endl;
    }
}
void query_by_name(){
    cout<<"请输入查询学生的姓名：";
    string name;
    cin >> name;
    bool exist = false;
    for(int i = 0; i < stus.size(); i++) {
        if(stus[i].name == name) {
            exist = true;
            cout<<"该学生信息如下:";
            cout<<"编号："<<stus[i].id<<endl;
            cout<<"学号："<<stus[i].stu_id<<endl;
            cout<<"姓名："<<stus[i].name<<endl;
            cout<<"性别："<<stus[i].sex<<endl;
            cout<<"系名："<<stus[i].depart<<endl;
            cout<<"英语："<<stus[i].English<<endl;
            cout<<"数学："<<stus[i].Math<<endl;
            cout<<"计算机："<<stus[i].CS<<endl;
            cout<<"总分："<<stus[i].sum<<endl;
            break;
        }
    }
    if(!exist) {
        cout<<"未找到该学生"<<endl;
    }
}

void query_by_id() {
    cout<<"请输入查询学生的编号：";
     int id;
    cin >> id;
    bool exist = false;
    for(int i = 0; i < stus.size(); i++) {
        if(stus[i].id == id) {
            exist = true;
            cout<<"该学生信息如下:";
            cout<<"编号："<<stus[i].id<<endl;
            cout<<"学号："<<stus[i].stu_id<<endl;
            cout<<"姓名："<<stus[i].name<<endl;
            cout<<"性别："<<stus[i].sex<<endl;
            cout<<"系名："<<stus[i].depart<<endl;
            cout<<"英语："<<stus[i].English<<endl;
            cout<<"数学："<<stus[i].Math<<endl;
            cout<<"计算机："<<stus[i].CS<<endl;
            cout<<"总分："<<stus[i].sum<<endl;
            break;
        }
    }
    if(!exist) {
        cout<<"未找到该学生"<<endl;
    }
}
void show_score() {
    cout<<"****************"<<endl;
    cout<<"*  1.根据学号查  *"<<endl;
    cout<<"*  2.根据姓名查  *"<<endl;
    cout<<"*  3.根据位置查  *"<<endl;
    cout<<"****************"<<endl;
    cout<<">";
    int x;
    cin >> x;
    switch (x) {
        case 1: {
            query_by_stu_id();
            break;
        }
        case 2: {
            query_by_name();
            break;
        }
        case 3:{
            query_by_id();
            break;
        }
        default:break;
    }

}

void showall() {
    cout<<"编号  学号  姓名  性别 系名  英语  数学 计算机 总分"<<endl;
    for(int i = 0; i < stus.size(); i++) {
        cout<<stus[i].id<<" "<<stus[i].stu_id<<" "<<stus[i].name<<" "<<stus[i].sex
        <<stus[i].depart<<" "<<stus[i].English<<" "<<stus[i].Math<<" "<<stus[i].CS<<" "<<stus[i].sum<<endl;
    }
}
void insert_data() {
    Student temp;
    temp.id = n++;
    cout<<"请输入查询学生的学号：";
    cin >> temp.stu_id;
    cout<<"请输入查询学生的姓名：";
    cin >> temp.name;
    cout<<"请输入查询学生的性别：";
    cin >> temp.sex;
    cout<<"请输入查询学生的系名：";
    cin >> temp.depart;
    cout<<"请输入查询学生的英语：";
    cin >> temp.English;
    cout<<"请输入查询学生的数学：";
    cin >> temp.Math;
    cout<<"请输入查询学生的计算机：";
    cin >> temp.CS;
    temp.sum = temp.English + temp.Math + temp.CS;
    stus.push_back(temp);
    showall();
}

void delete_data() {
    cout<<"请输入你要删除的学号：";
    string stu_id;
    cin >> stu_id;
    for(int i = 0; i < stus.size(); i++) {
        if(stu_id == stus[i].stu_id) {
            for(int j = i; j + 1 < stus.size(); j++) {
                stus[j] = stus[j+1];
            }
            stus.pop_back();
            break;
        }
    }
    showall();
}
void modify_data() {
    Student temp;
    cout<<"请输入你要更改的学号：";
    string stu_id;
    cin >> stu_id;
    cout<<"请输入更改后的姓名：";
    cin >> temp.name;
    cout<<"请输入更改后的性别：";
    cin >> temp.sex;
    cout<<"请输入更改后的系名：";
    cin >> temp.depart;
    cout<<"请输入更改后的英语：";
    cin >> temp.English;
    cout<<"请输入更改后的数学：";
    cin >> temp.Math;
    cout<<"请输入更改后的计算机：";
    cin >> temp.CS;
    temp.sum = temp.English + temp.Math + temp.CS;
    for(auto &stu: stus) {
        if(stu.stu_id == stu_id) {
            temp.id = stu.id;
            stu = temp;
            break;
        }
    }
    showall();
}
bool cmp_quick_sort(Student a, Student b) {
    return a.sum > b.sum;
}
void insert_sort() {
    int m = stus.size();
    for(int i = 0; i < m; i++) {
        for(int j = 0; j + 1 < m; j++) {
            if(stus[j].sum < stus[j+1].sum) {
                swap(stus[j], stus[j+1]);
            }
        }
    }
}

void bubble_sort() {
    int m = stus.size();
    for(int i = 0; i < m; i++) {
        for(int j = 0; j + 1 < m; j++) {
            if(stus[j].sum < stus[j+1].sum) {
                swap(stus[j], stus[j+1]);
            }
        }
    }
}
void sort_data() {
    cout<<"****************"<<endl;
    cout<<"*  1.使用快速排序  *"<<endl;
    cout<<"*  2.使用插入排序  *"<<endl;
    cout<<"*  3.使用冒泡排序  *"<<endl;
    cout<<"****************"<<endl;
    cout<<">";
    int x;
    cin >> x;
    switch (x) {
        case 1: {
            sort(stus.begin(), stus.end(), cmp_quick_sort);
            break;
        }
        case 2: {
            insert_sort();
            break;
        }
        case 3:{
            bubble_sort();
            break;
        }
        default:break;
    }
    showall();
}
int main(){

    int select, quit=1;
    Read();
    while(1)
    {
        menu();
        cout<<">";
        cin>>n;
        switch(n){
            case 1:{
                show_score();
                break;
            }
            case 2:{
                insert_data();
                break;
            }
            case 3:{
                delete_data();
                break;
            }
            case 4:{
                modify_data();
                break;
            }
            case 5:{
                sort_data();
                break;
            }
            case 0: {
                return 0;
            }
            default:
                cout<<"输入有误，请重新输入！"<<endl;
        }
    }

    printf("程序结束!\n");
    return 0;
}