#include <iostream>
#include <vector>

using namespace std;


// 주 로직
void solve() {
    vector<string> arr;

    int max_len = 0;
    for(int i=0; i<5; i++){
        string in; cin >> in;
        arr.push_back(in);

        max_len = max(max_len,(int)in.size());
    }
    
    string answer = "";

    for(int x=0; x<max_len; x++){
        for(int i=0; i<5; i++){
            if(arr[i].size() <= x) continue;
            answer+=arr[i][x];
        }
    }
    cout << answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}

 