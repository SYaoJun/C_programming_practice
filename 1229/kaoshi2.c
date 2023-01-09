#include <stdio.h>
#include <string.h>


typedef struct Weather{
    int high;
    int low;
    char q;
    char date[64];
    int diff;
}W_T;
int n = 4;
W_T w[100];

void sort() {

    for(int i = 0; i < n; i++) {
        for(int j = 0; j + 1 < n; j++) {
            if(w[j].diff < w[j+1].diff){
                W_T t = w[j];
                w[j] = w[j+1];
                w[j+1] = t;
            }
        }
    }

}
int main() {
    w[0].high = 17;
    w[0].low = 8;
    strcpy(w[0].date, "12月21日");
    w[0].diff = 9;
    w[0].q = 'C';

    w[1].high = 17;
    w[1].low = 7;
    strcpy(w[1].date, "12月22日");
    w[1].diff = 10;
    w[1].q = 'S';

    w[2].high = 16;
    w[2].low = 7;
    strcpy(w[2].date, "12月23日");
    w[2].diff = 9;
    w[2].q = 'S';

    w[3].high = 15;
    w[3].low = 7;
    strcpy(w[3].date, "12月24日");
    w[3].diff = 8;
    w[3].q = 'S';
    sort();
    for(int i = 0; i < n; i++) {
        printf("%s，天气：%c，最高温度%d℃，最低温度%d℃，温差%d℃\n", w[i].date, w[i].q,
               w[i].high, w[i].low, w[i].diff);
    }
    return 0;
}