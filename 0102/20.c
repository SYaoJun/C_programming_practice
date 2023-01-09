#include <string.h>
#include <stdio.h>
int f[32];
int digit(int n, int k){
    memset(f, 0, sizeof(f));
    int i = 0;
    do{
        f[i++] = n%10;
        n /= 10;
    }while(n!=0);
    if(k > i) {
        return -1;
    }
    return f[k-1];
}
int main() {
    int n, k;
    scanf("%d,%d", &n, &k);
    printf("%d",digit(n, k));
    return 0;
}