#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;


void solve(){
    int a,b;
    cin >> a >> b;

    int rev_a = 0, rev_b = 0;
    for(int i=0; i<3; i++){
        int div = pow(10,2-i); // 100 10 1
        int mul = pow(10,i);
        rev_a += (a/div) * mul; a %= div;
        rev_b += b/div * mul; b %= div;

    }

    cout << max(rev_a, rev_b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}