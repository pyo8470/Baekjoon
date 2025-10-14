#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


void solve(){
    string input; cin >> input;
    int arr[26];
    for(int i=0; i<26; i++) arr[i] = -1;

    for(int i=0; i<input.size(); i++){
        int idx = input[i] - 'a';
        if(arr[idx] != -1) continue;
        arr[idx] = i;
    }

    for(int i : arr) cout << i << " ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}