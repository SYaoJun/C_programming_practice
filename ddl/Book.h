#include <iostream>
#include <fstream>//文件输入输出
#include<iomanip>//控制输出格式
#include<string>
#include <vector>
#define FILENAME "library.txt"

using namespace std;

class Book{
    friend istream& operator >> (istream &stream,Book &b);//重载操作符>>
    friend ostream& operator << (ostream &stream,Book &b);//重载操作符<<

public:
    int type{}; // English = 0 Chinese = 1
    string ISBN;//图书号
    string name;//书名
    string author;//作者
    string typeNumber;//分类号
    string publishingUnit;//出版单位
    string publishingTime;//出版时间
    double price{};//价格
    int inStock{};//库存


    Book() = default;
    Book(string ,string ,string ,string ,string ,string ,double ,int );
    ~Book();
    bool operator == (const Book&a) const {
        if(a.price == price && a.ISBN == ISBN && a.publishingTime == publishingTime
        && a.publishingUnit == publishingUnit && a.name == name && a.author == author
        && a.name == name){
            return true;
        }else {
            return false;
        }
    }
};