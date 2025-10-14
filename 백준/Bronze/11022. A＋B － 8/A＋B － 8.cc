#include <iostream>

using namespace std;

void solve(){
    int T; cin >> T;
    for(int i=0; i<T; i++){
        int a,b; cin >> a >> b;
        cout << "Case #" << i+1 << ": " << a << " + " << b << " = " << a + b << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
