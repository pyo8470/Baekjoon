#include <iostream>

using namespace std;

void solve(){
    int T; cin >> T;
    while(T--){
        int a,b; cin >> a >> b;
        cout << a + b << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
