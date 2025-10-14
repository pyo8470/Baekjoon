
#include <iostream>

using namespace std;

void solve(){
    int n; cin >> n;
    for(int i=0;i<n; i++){
        for(int j=n-i-1; j>0; j--){
            cout << " ";
        }
        for(int j=0; j<=i;j++){
            cout << "*";
        }
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}