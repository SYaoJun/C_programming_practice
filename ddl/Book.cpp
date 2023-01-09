#include"Book.h"

using namespace std;

Book::Book(string id,string n,string a,string tN,string pU,string pT,double pr,int is)
{
    name=n;ISBN=id;author =a;typeNumber =tN;publishingUnit=pU;
    publishingTime=pT;price =pr;inStock=is;
}
Book::~Book() {}

ostream &operator << (ostream &stream, Book &b)
{
    stream<< "\tISBN：" << setw(9) << b.ISBN
          << "书名：" << setw(9) << b.name
          << "\t作者：" << setw(9) << b.author
          << "\t分类号：" << setw(9) << b.typeNumber
          << "\t出版单位：" << setw(9) << b.publishingUnit
          << "\t出版时间：" << setw(9) << b.publishingTime
          << "\t价格：" << setw(5) << b.price
          << "\t库存：" << setw(5) << b.inStock << endl;
    return stream;
}

istream &operator >> (istream &stream,Book &b)
{
    cout<<"请输入ISBN:";
    stream>>b.ISBN;
    cout<<"请输入书名:";
    stream>>b.name;
    cout<<"请输入作者:";
    stream>>b.author;
    cout<<"请输入分类号:";
    stream>>b.typeNumber;
    cout<<"请输入出版单位:";
    stream>>b.publishingUnit;
    cout<<"请输入出版时间:";
    stream>>b.publishingTime;
    cout<<"请输入价格:";
    stream>>b.price;
    cout<<"请输入价格:";
    stream>>b.inStock;
    return stream;
}

