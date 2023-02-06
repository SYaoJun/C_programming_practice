#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    string t = "codeforces";
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if(t.find(c) != string::npos){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}