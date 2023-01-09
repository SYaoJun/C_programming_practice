#include <string.h>
#include <stdio.h>
int main() {
    for(int i = 2; i <= 1000; i++) {
        int sum = 0;
        for(int x = 2; x <= i; x++) {
            if(i % x == 0){
                sum += x;
            }
        }
        if(sum == i){
            printf("完数=%d\n", i);
        }
    }
    return 0;
}