#pragma once

#include <iostream>
#include"Teacher.h"
#include"Student.h"
#include <vector>

using namespace std;
const string filename = "book.txt";

void menu() {
    printf("*****************************************\n");
    printf("*            图书管理系统                 *\n");
    printf("*****************************************\n");
    printf("*            1. 录入书籍                  *\n");
    printf("*            2. 图书借阅                  *\n");
    printf("*            3. 图书归还                  *\n");
    printf("*            4. 图书查询                  *\n");
    printf("*            0. 退出系统                  *\n");
    printf("*****************************************\n");
}

void select() {
    printf("*****************************************\n");
    printf("*             用户选择                    *\n");
    printf("*****************************************\n");
    printf("*            1. 普通学生                  *\n");
    printf("*            2. 学校老师                  *\n");
    printf("*****************************************\n");
}

vector<Book> storage_book;

void insert_book() {
    Book temp_book;
    cout << "输入图书名:";
    cin >> temp_book.ISBN;
    cout << "输入书名:";
    cin >> temp_book.name;
    cout << "输入作者名:";
    cin >> temp_book.author;
    cout << "输入分类号:";
    cin >> temp_book.typeNumber;
    cout << "输入出版单位:";
    cin >> temp_book.publishingUnit;
    cout << "输入出版时间:";
    cin >> temp_book.publishingTime;
    cout << "输入价格:";
    cin >> temp_book.price;

    int n = storage_book.size();
    bool is_exist = false;
    for (int i = 0; i < n; i++) {
        if (storage_book[i] == temp_book) {
            storage_book[i].inStock++;
            is_exist = true;
            break;
        }
    }
    if (!is_exist) {
        temp_book.inStock = 1;
        storage_book.push_back(temp_book);
    }
}

void borrow_book() {
    Book temp_book;
    cout << "输入图书名:";
    cin >> temp_book.ISBN;
    cout << "输入书名:";
    cin >> temp_book.name;
    cout << "输入作者名:";
    cin >> temp_book.author;
    cout << "输入分类号:";
    cin >> temp_book.typeNumber;
    cout << "输入出版单位:";
    cin >> temp_book.publishingUnit;
    cout << "输入出版时间:";
    cin >> temp_book.publishingTime;
    cout << "输入价格:";
    cin >> temp_book.price;

    select();
    int input_;
    cin >> input_;
    bool is_exist = false;
    if (input_ == 1) {
        Student student;
        cout << "请输入用户姓名:";
        cin >> student.name;
        cout << "请输入用户借阅证:";
        cin >> student.rentId;
        cout << "请输入用户性别:";
        cin >> student.sex;
        cout << "请输入用户出生日期:";
        cin >> student.birthday;
        cout << "请输入用户年级:";
        cin >> student.grade;
        cout << "请输入用户专业:";
        cin >> student.department;
        cout << "请输入用户是否是本科生:";
        cin >> student.isUndergraduate;
        cout << "请输入用户是否是研究生:";
        cin >> student.isGraduate;
        is_exist = student.Borrow_book(temp_book, storage_book);
    } else {
        Teacher teacher;
        cout << "请输入用户姓名:";
        cin >> teacher.name;
        cout << "请输入用户借阅证:";
        cin >> teacher.rentId;
        cout << "请输入用户性别:";
        cin >> teacher.sex;
        cout << "请输入用户出生日期:";
        cin >> teacher.birthday;
        cout << "请输入用户部门:";
        cin >> teacher.department;
        is_exist = teacher.Borrow_book(temp_book, storage_book);
    }

    if (!is_exist) {
        cout << "图书不存在" << endl;
    } else {
        cout << "借阅成功" << endl;
    }
}

void return_book() {
    Book temp_book;
    cout << "输入图书名:";
    cin >> temp_book.ISBN;
    cout << "输入书名:";
    cin >> temp_book.name;
    cout << "输入作者名:";
    cin >> temp_book.author;
    cout << "输入分类号:";
    cin >> temp_book.typeNumber;
    cout << "输入出版单位:";
    cin >> temp_book.publishingUnit;
    cout << "输入出版时间:";
    cin >> temp_book.publishingTime;
    cout << "输入价格:";
    cin >> temp_book.price;

    select();
    int input_;
    cin >> input_;
    bool is_exist = false;
    if (input_ == 1) {
        Student student;
        cout << "请输入用户姓名:";
        cin >> student.name;
        cout << "请输入用户借阅证:";
        cin >> student.rentId;
        cout << "请输入用户性别:";
        cin >> student.sex;
        cout << "请输入用户出生日期:";
        cin >> student.birthday;
        cout << "请输入用户年级:";
        cin >> student.grade;
        cout << "请输入用户专业:";
        cin >> student.department;
        cout << "请输入用户是否是本科生:";
        cin >> student.isUndergraduate;
        cout << "请输入用户是否是研究生:";
        cin >> student.isGraduate;
        is_exist = student.Return_book(temp_book, storage_book);
    } else {
        Teacher teacher;
        cout << "请输入用户姓名:";
        cin >> teacher.name;
        cout << "请输入用户借阅证:";
        cin >> teacher.rentId;
        cout << "请输入用户性别:";
        cin >> teacher.sex;
        cout << "请输入用户出生日期:";
        cin >> teacher.birthday;
        cout << "请输入用户部门:";
        cin >> teacher.department;
        is_exist = teacher.Return_book(temp_book, storage_book);
    }
    if (!is_exist) {
        cout << "图书不存在" << endl;
    } else {
        cout << "归还成功" << endl;
    }
}

void query_book() {
    Book temp_book;
    cout << "输入图书名:";
    cin >> temp_book.ISBN;
    cout << "输入书名:";
    cin >> temp_book.name;
    cout << "输入作者名:";
    cin >> temp_book.author;
    cout << "输入分类号:";
    cin >> temp_book.typeNumber;
    cout << "输入出版单位:";
    cin >> temp_book.publishingUnit;
    cout << "输入出版时间:";
    cin >> temp_book.publishingTime;
    cout << "输入价格:";
    cin >> temp_book.price;

    select();
    int input_;
    cin >> input_;
    bool is_exist = false;
    if (input_ == 1) {
        Student student;
        cout << "请输入用户姓名:";
        cin >> student.name;
        cout << "请输入用户借阅证:";
        cin >> student.rentId;
        cout << "请输入用户性别:";
        cin >> student.sex;
        cout << "请输入用户出生日期:";
        cin >> student.birthday;
        cout << "请输入用户年级:";
        cin >> student.grade;
        cout << "请输入用户专业:";
        cin >> student.department;
        cout << "请输入用户是否是本科生:";
        cin >> student.isUndergraduate;
        cout << "请输入用户是否是研究生:";
        cin >> student.isGraduate;
        is_exist = student.Query_book(temp_book, storage_book);
    } else {
        Teacher teacher;
        cout << "请输入用户姓名:";
        cin >> teacher.name;
        cout << "请输入用户借阅证:";
        cin >> teacher.rentId;
        cout << "请输入用户性别:";
        cin >> teacher.sex;
        cout << "请输入用户出生日期:";
        cin >> teacher.birthday;
        cout << "请输入用户部门:";
        cin >> teacher.department;
        is_exist = teacher.Query_book(temp_book, storage_book);
    }
    if (!is_exist) {
        cout << "图书不存在" << endl;
    }

}

void read_file() {
    std::ofstream outFile;
    outFile.open(filename);
    int n = storage_book.size();
    for (int i = 0; i < 5; i++) {
        outFile << storage_book[i].name << storage_book[i].ISBN;
    }
    outFile.close();
}

void save_file() {
    ifstream infile;
    infile.open(filename);
    while (infile) {
        Book book;
        string temp;
        infile >> temp;
        storage_book.push_back(book);
    }
}

int main() {
//    read_file();
    while (true) {
        menu();
        puts("请选择你要进行的操作：");
        int input;
        cin >> input;
        switch (input) {
            case 1:
                insert_book();
                break;
            case 2:
                borrow_book();
                break;
            case 3:
                return_book();
                break;
            case 4:
                query_book();
                break;
            case 0:
//                save_file();
                return 0;
            default:
                continue;
        }
    }
}
