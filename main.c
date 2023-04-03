#include <stdio.h>
#include <string.h>

#define N 128
char array[8][128] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int min(int a, int b){
    if(a < b) {
        return a;
    }
    return b;
}
int isCapital(char c){
    if(c >= 'A' && c <= 'Z'){
        return 1;
    }
    return 0;
}
int isalpha(char c){
    if(c >='a' && c <='z'){
        return 1;
    }
    if(c >='A' && c <='Z'){
        return 1;
    }
    return 0;
}
int isValid(char c){
    if(c >='0' && c <='9'){
        return 1;
    }
    if(c >='A' && c <='N'){
        return 1;
    }
    return 0;
}
int main() {
    char a[N], b[N], c[N], d[N];
    scanf("%s", a);
    scanf("%s", b);
    scanf("%s", c);
    scanf("%s", d);

    int len1 = strlen(a);
    int len2 = strlen(b);
    int ok = 0;
    int week = 0;
    int hour = 0;
    for(int i = 0; i < min(len1, len2); i++) {
        if(ok == 0 && a[i] == b[i] && isCapital(a[i])) {
            ok = 1;
            week = a[i] - 'A';
            continue;
        }
        if(ok && a[i] == b[i] && isValid(a[i])){
            if(a[i] >= '0' && a[i] <='9'){
                hour = a[i] - '0';
            }else{
                hour = a[i] - 'A' + 10;
            }
            break;
        }
    }
    int minutes = 0;
    int len3 = strlen(c);
    int len4 = strlen(d);
    for(int i = 0; i < min(len3, len4); i++) {
        if(c[i] == d[i] && isalpha(c[i])){
            minutes = i;
            break;
        }
    }
    printf("%s %02d:%02d\n", array[week], hour, minutes);
    return 0;
}