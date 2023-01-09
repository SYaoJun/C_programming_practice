#include"User.h"
const int ENGLISH_MAX = 10;
const int CHINESE_MAX = 20;

class Teacher : public User{
public:
    string department;
    int ChineseNumber;
    int EnglishNumber;
    Teacher() = default;
    ~Teacher();
    vector<Book> rent_books;
    bool Borrow_book(Book book, vector<Book>& books) override;
    bool Return_book(Book book, vector<Book>& books) override;
    bool Query_book(Book book, vector<Book>& books) override;

};
