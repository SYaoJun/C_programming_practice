#include <stdio.h>
#include <string.h>
#define NUM_MAX 1000

struct message{
    char num[NUM_MAX];
    char email[NUM_MAX];
};

bool isValidEmail(char *s){
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        if(s[i]=='@'){
            return true;
        }
    }
    return false;
}
bool isValidNumber(char* s){
    int len = strlen(s);
    if(len != 11) {
        return false;
    }
    for(int i = 0; i < len; i++) {
        if(s[i] < '0' || s[i] > '9'){
            return false;
        }
    }
    return true;
}

int main() {
    struct message msg{"12345678910", "123@qq.com"};
    printf("号码是否合法: %s\n", isValidNumber(msg.num)?"yes":"no");
    printf("邮箱是否合法:%s\n", isValidEmail(msg.email)?"yes":"no");
}