#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int N, M;
    cin >> N >> M;
    vector<int> arr(N);
    for(int i=0; i<N; i++) arr[i] = i+1;
    for(int i=0; i<M; i++){
        int a, b; cin >> a >> b; 
        swap(arr[a-1],arr[b-1]);
    }

    for(int i : arr) cout << i << " ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}