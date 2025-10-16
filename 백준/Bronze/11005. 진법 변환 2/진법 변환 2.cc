#include <cctype>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;


void solve() {
    int N, B;
    cin >> N >> B;

    string ans = "";
    while(N){
        int mod = N % B;
        char append;
        if(mod >= 10){
            append = 'A' + (mod-10);
        }
        else{
            append = '0' + mod;
        }
        ans = append + ans;
        N /= B;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}