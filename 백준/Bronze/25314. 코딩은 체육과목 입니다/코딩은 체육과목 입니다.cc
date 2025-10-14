#include <algorithm>
#include <iostream>

using namespace std;

string solve(){
    string k = "long ";
    
    int n; cin >> n;
    n /= 4;

    string ans = "";
    for(int i=0; i<n; i++){
        ans += k;
    }
    return ans + "int";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << solve();
}