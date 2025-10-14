
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve(){
    vector<int> arr;
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int k; cin >> k;
        arr.push_back(k);
    }
    int v; cin >> v;
    cout << count(arr.begin(),arr.end(),v);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}