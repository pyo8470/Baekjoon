#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int N, M;
    cin >> N >> M;
    vector<int> arr(N);
    for(int i=0; i<M; i++){
        int a,b,c; cin >> a >> b >> c;
        for(int j=a-1; j<=b-1; j++){
            arr[j] = c;
        }
    }

    for(int ball : arr) cout << ball << " ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}