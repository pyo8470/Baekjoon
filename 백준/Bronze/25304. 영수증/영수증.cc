#include <algorithm>
#include <iostream>

using namespace std;

string solve(){
    int X; cin >> X;
    int N; cin >> N;

    int total = 0;
    for(int i=0; i<N; i++){
        int money, n; cin >> money >> n;
        total += (money * n);
    }

    if(total == X) return "Yes";
    return "No";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << solve();
}
