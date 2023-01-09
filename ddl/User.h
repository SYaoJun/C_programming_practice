#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Book.h"
using namespace std;

class User{
public:
    string name;
    string rentId;
    string sex;
    string birthday;

    User() = default;
    User(string name_, string rentId_, string sex_, string birthday_);
    virtual bool Borrow_book(Book book, vector<Book>& books) = 0;
    virtual bool Return_book(Book book, vector<Book>& books) = 0;
    virtual bool Query_book(Book book, vector<Book>& books) = 0;
};