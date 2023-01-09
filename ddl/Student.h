#include"User.h"

const int UNDERGRADUATE_ENGLISH_MAX = 2;
const int UNDERGRADUATE_CHINESE_MAX = 8;
const int GRADUATE_ENGLISH_MAX = 5;
const int GRADUATE_CHINESE_MAX = 15;

class Student : public User{
public:
    string grade;
    string department;
    int ChineseNumber{};
    int EnglishNumber{};
    bool isUndergraduate{};
    bool isGraduate{};

    vector<Book> rent_books;
    bool Borrow_book(Book book, vector<Book>& books) override;
    bool Return_book(Book book, vector<Book>& books) override;
    bool Query_book(Book book, vector<Book>& books) override;
    Student() = default;
    Student(string name_, string rentId_, string sex_, string birthday_,string grade_, string department_,bool isUndergraduate_, bool isGraduate_);
    ~Student();

};