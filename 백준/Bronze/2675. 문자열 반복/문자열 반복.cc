#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


void solve(){
    int T; cin >> T;

    while(T--){
        int rep; string S; cin >> rep >> S;
        for(char c : S){
            for(int i=0; i<rep; i++) cout << c;
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