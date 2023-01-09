#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
class Num{
public:
    // 1. 最大公约数
    int static gcd_(int x, int y) {
        if(y == 0) return x;
        return gcd_(y, x % y);
    }
    // 2. 最小公倍数
    int static lcm_(int x, int y) {
        return x / gcd_(x, y) * y;
    }

    // 3. 判定一个数是否是素数
    bool static is_prime_(int x) {
        if(x  <= 1) return false;
        int sq = sqrt(x);
        for(int i = 2; i <= sq; i++) {
            if(x % i == 0){
                return false;
            }
        }
        return true;
    }

    // 4. 求阶乘n！
    long long static get_fact_(int x) {
        if(x == 1) return 1;
        return x * get_fact_(x - 1);
    }

    // 5. 判断一个数是否是回文奇数
    bool static is_hwjs(int x) {
        if(x % 2 == 0) {
            return false;
        }
        string s = to_string(x);
        int n = s.size();
        for(int i = 0; i < n/2; i++) {
            if(s[i] != s[n-1-i]) {
                return false;
            }
        }
        return true;
    }

    // 6. 判断一个三位整数是否是水仙花数
    bool static is_sxhs(int x) {
        if(x < 100 || x > 1000) return false;
        string s = to_string(x);
        int a = x%10;
        int b = x%100/10;
        int c = x/100;
        if(a*a*a + b*b*b + c*c*c == x) {
            return true;
        }else{
            return false;
        }
    }

    string static to_string(int x) {
        string res;
        do{
            res += x % 10 + '0';
            x /= 10;
        }while(x != 0);
        reverse(res.begin(), res.end());
        return res;
    }
};

void gcd_test(){
    cout<<"输入两个数: "<<endl;
    int a, b;
    cin >> a >> b;
    int res = Num::gcd_(a, b);
    cout<<"最大公约数的结果是："<<res<<endl;
}

void lcm_test(){
    cout<<"输入两个数: "<<endl;
    int a, b;
    cin >> a >> b;
    int res = Num::lcm_(a, b);
    cout<<"最小公倍数的结果是："<<res<<endl;
}

void prime_test(){
    cout<<"输入一个数: "<<endl;
    int a;
    cin >> a;
    bool res = Num::is_prime_(a);
    cout<<"判断素数的结果是："<<res<<endl;
}

void fact_test(){
    cout<<"输入一个数: "<<endl;
    int a;
    cin >> a;
    long long res = Num::get_fact_(a);
    cout<<"阶乘的结果是："<<res<<endl;
}

void jhws_test(){
    cout<<"输入一个数: "<<endl;
    int a;
    cin >> a;
    int res = Num::is_hwjs(a);
    cout<<"判断的结果是"<<res<<endl;
}

void sxhs_test(){
    cout<<"输入一个数: "<<endl;
    int a;
    cin >> a;
    int res = Num::is_sxhs(a);
    cout<<"判断的结果是："<<res<<endl;
}

void show_menu() {
    cout << "*************************************************" << endl;
    cout << "*        根据所做操作选择以下数字序号                *" << endl;
    cout << "*             1. 最大公约数                       *" << endl;
    cout << "*             2. 最小公倍数                       *" << endl;
    cout << "*             3. 判断素数                        *" << endl;
    cout << "*             4. 求阶乘                          *" << endl;
    cout << "*             5. 判断回文奇数                     *" << endl;
    cout << "*             6. 判断水仙花数                     *" << endl;
    cout << "*             0. 重新选择                         *" << endl;
    cout << "*             -1. 退出                           *" << endl;
    cout << "*************************************************" << endl;
}
int main() {
        while(1){
            show_menu();
            int n;
            cout<<">";
            cin>>n;
            switch(n){
                case 1:{
                    gcd_test();
                    break;
                }
                case 2:{
                    lcm_test();
                    break;
                }
                case 3:{
                    prime_test();
                    break;
                }
                case 4:{
                    fact_test();
                    break;
                }
                case 5:{
                    jhws_test();
                    break;
                }
                case 6: {
                    sxhs_test();
                    break;
                }
                case 0: {
                    break;
                }
                case -1:{
                    return 0;
                }
                default:
                    cout<<"输入有误，请重新输入！"<<endl;
            }
        }
    return 0;
}