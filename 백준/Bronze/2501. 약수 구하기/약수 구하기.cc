#include <cmath>
#include <iostream>
#include <vector>

using namespace std;



void solve() {
    int a, b; cin >> a >> b;
    
    vector<int> arr;
    for(int i=1; i<=a; i++){
        if(a%i == 0) arr.push_back(i);        
    }

    if(arr.size() < b) cout << 0;
    else cout << arr[b-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}

