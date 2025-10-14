#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


void solve(){
    int N; cin >> N;
    vector<int> arr(N);
    for(int i=0; i<N; i++) cin >> arr[i];

    int MAX = *max_element(arr.begin(),arr.end());
    
    double sum = 0;
    for(int point : arr){
        sum += ((double)point / (double)MAX) * 100;
    }
    cout << sum / N;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}