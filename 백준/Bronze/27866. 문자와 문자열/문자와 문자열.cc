#include <iostream>

using namespace std;


void solve(){
    string input; cin >> input;
    int i; cin >> i;
    cout << input[i-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}