#include"Teacher.h"


Teacher::~Teacher() = default;

bool Teacher::Borrow_book(Book book, vector<Book> &books) {
    if(book.type == 0) {
        if(EnglishNumber >= ENGLISH_MAX) return false;
    }else{
        if(ChineseNumber >= CHINESE_MAX) return false;
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

bool Teacher::Return_book(Book book, vector<Book> &books) {
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

bool Teacher::Query_book(Book book, vector<Book> &books) {
    for(int i = 0; i < books.size(); i++) {
        if(books[i] == book) {
            cout<<"查到该书"<<endl;
            cout<<books[i]<<endl;
            return true;
        }
    }
    return false;
}
