#include <cmath>
#include <iostream>

using namespace std;


void solve() {
    int A,B,V; cin >> A >>B >> V; 
    int H = V-A; // 마지막날까지 올라가야하는 높이
    int delta = A-B;
    
    int ans = (int) ceil((double)H/delta);
    
    ans++;
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}

