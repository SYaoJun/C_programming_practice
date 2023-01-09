#include <stdio.h>

int get_fact_(int x) {
    if(x == 1) return 1;
    return x * get_fact_(x - 1);
}


double fun(int n){
    double sum = 0;
    for(int i = 1; i<= n;i ++) {
        sum += get_fact_(i);
    }
    return sum;
}
int main(){
    printf("%.2f\n", fun(7));
    return 0;
}