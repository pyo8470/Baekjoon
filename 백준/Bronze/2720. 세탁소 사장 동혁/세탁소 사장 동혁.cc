#include <cctype>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;


void solve() {
    int T; cin >> T;
    
    int Q = 25, D = 10, N = 5, P = 1;
    while(T--){
        int money; cin >> money;
        
        int a_q = money / Q; money %= Q;
        int b_q = money / D; money %= D;
        int n_q = money / N; money %= N;
        int p_q = money / P; money %= P;

        cout << a_q << " " << b_q << " " << n_q << " " << p_q << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
