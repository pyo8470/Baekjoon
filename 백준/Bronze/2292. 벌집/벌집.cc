#include <cctype>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;


void solve() {
    int N; cin >> N;

    int sub = 1;
    int ans = 0;
    while(N > 0){
        N -= sub;
        ans++;
        sub = (ans*6);
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}