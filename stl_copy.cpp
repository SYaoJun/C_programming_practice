#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void print(vector<int> &v){
    cout<<"打印数组：";
    for(auto x: v) {
        cout<<x<<" ";
    }
    cout<<endl;
}
int main() {
    /*
     * 1. move
     * 2. lower_bound
     * 3. copy
     * 3. distance
     * **/

    vector<int> src{99, 100, 88, 66};

    vector<int> dest(10);
    // 把src的区间拷贝到第三个位置
    int l = 0, r = 4;
    copy(src.begin()+l, src.end()+r, dest.begin());
    print(dest);
    print(src);
    return 0;
}