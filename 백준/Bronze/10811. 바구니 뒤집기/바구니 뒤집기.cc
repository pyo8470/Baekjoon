#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


void solve(){
    int N,M; cin >> N >> M;
    vector<int> basket(N);
    for(int i=0; i<N; i++) basket[i] = i+1;
    for(int i=0; i<M; i++){
        int a,b; cin >> a >> b;
        
        reverse(basket.begin() + a-1, basket.begin() + b);
    }
    for(int i : basket) cout << i << " ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}