#include"Student.h"

using namespace std;

bool Student::Borrow_book(Book book, vector<Book>& books) {
    if(isGraduate) {
        if(book.type == 0) {
            if(EnglishNumber >= GRADUATE_ENGLISH_MAX) return false;
        }else{
            if(ChineseNumber >= GRADUATE_CHINESE_MAX) return false;
        }
    }
    if(isUndergraduate) {
        if(book.type == 0) {
            if(EnglishNumber >= UNDERGRADUATE_ENGLISH_MAX) return false;
        }else{
            if(ChineseNumber >= UNDERGRADUATE_CHINESE_MAX) return false;
        }
    }
    for(int i = 0; i < books.size(); i++) {
        if(books[i] == book && books[i].inStock > 0) {
            rent_books.push_back(book);
            if(book.type == 0) EnglishNumber++;
            else ChineseNumber++;
            books[i].inStock--;
            return true;
        }
    }
    return false;
}

bool Student::Return_book(Book book, vector<Book> &books) {
    bool is_exist = false;
    for(int i = 0; i < rent_books.size(); i++) {
        if(rent_books[i] == book) {
            is_exist = true;
            for(int j = 0; j < rent_books.size(); j++) {
                rent_books[j] = rent_books[j+1];
            }
            rent_books.pop_back();
        }
    }
    if(!is_exist) return false;
    for(int i = 0; i < books.size(); i++) {
        if(books[i] == book) {
            if(book.type == 1){
                ChineseNumber++;
            }else{
                EnglishNumber++;
            }
            books[i].inStock++;
            return true;
        }
    }
    return false;
}

bool Student::Query_book(Book book, vector<Book> &books) {
    for(int i = 0; i < books.size(); i++) {
        if(books[i] == book) {
            cout<<"查到该书"<<endl;
            cout<<books[i]<<endl;
            return true;
        }
    }
    return false;
}

Student::Student(string name_, string rentId_, string sex_, string birthday_,
                 string grade_, string department_, bool isUndergraduate_,
                 bool isGraduate_):User(name_, rentId_, sex_, birthday_) {
    this->grade = grade_;
    this->department = department_;
    this->isGraduate = isGraduate_;
    this->isUndergraduate = isUndergraduate_;
    this->EnglishNumber = 0;
    this->ChineseNumber = 0;
}



Student::~Student() = default;
