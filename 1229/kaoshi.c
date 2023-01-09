#include <stdio.h>
#include <string.h>
#include <math.h>
char num[128];
int IsIntString() {
    int n = strlen(num);
    if(n == 0) {
        puts("不是数字字符串");
        return 0;
    }
    for(int i = 0; i < n; i ++) {
        if(!(num[i] >='0' && num[i] <= '9')) {
            puts("不是数字字符串");
            return 0;
        }
    }
    puts("是数字字符串");
    return 1;
}
void FindMax(){
    int n = strlen(num);
    int cnt[16]={0};
    int maxValue = 0;
    for(int i = 0; i < n; i++) {
        cnt[num[i]-'0']++;
        if((num[i]-'0') > maxValue) {
            maxValue = (num[i]-'0');
        }
    }
    printf("最大数字是%d，共出现%d次\n",maxValue, cnt[maxValue]);
}
int IsTimeof3() {
    int n = strlen(num);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += (num[i]-'0');
    }
    if(sum % 3 == 0) {
        puts("是3的倍数");
        return 1;
    }else{
        puts("不是3的倍数");
        return 0;
    }
}

int IsPrime() {
    int n = strlen(num);
    int sum = 0;
    if(n == 1) {
        sum = num[n-1] - '0';
    }else{
        int a = num[n-2] -'0';
        int b = num[n-1] -'0';
        sum = a*10 + b;
    }
    int sq = sqrt(sum);
    for(int i = 2; i <= sq; i++) {
        if(sum % i == 0) {
            printf("末位两位数是%d，不是质数\n", sum);
            return 0;
        }
    }
    printf("末位两位数是%d，是质数\n", sum);
    return 1;
}
int main() {
    puts("输入一个大整数:");
    scanf("%s", num);
    if(IsIntString()) {
        FindMax();
        IsTimeof3();
        IsPrime();
    }
    return 0;
}
