#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;


void solve(){
    int correct[6] = {1,1,2,2,2,8};
    int arr[6] = {0,};   

    int answer[6] = {0,};
    for(int i=0; i<6; i++){
        cin >> arr[i];
        answer[i] = correct[i] - arr[i];
        cout << answer[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    solve();
}
