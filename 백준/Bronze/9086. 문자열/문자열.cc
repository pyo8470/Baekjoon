#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


void solve(){
    int T; cin >> T;
    for(int t = 0; t<T; t++){
        string input; cin >> input;
        cout << input[0] << input[input.size()-1] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}