#include <string.h>
#include <stdio.h>
int f[36];
int main() {
    f[1] = 1;
    f[2] = 1;
    int n;
    scanf("%d", &n);
    for(int i = 3; i <= n; i++){
        f[i] = f[i-2] + f[i-1];
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        printf("%d ", f[i]);
        cnt++;
        if(cnt % 5 == 0){
            puts("");
        }
    }
    return 0;
}