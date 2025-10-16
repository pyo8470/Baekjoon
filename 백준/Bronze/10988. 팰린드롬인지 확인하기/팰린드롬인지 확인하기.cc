#include <iostream>

using namespace std;


// 주 로직
int solve() {
    string input; cin >> input;
    int N = input.size();
    for(int i=0; i<N/2; i++){
        char front = input[i];
        char back = input[N-1-i];
        if(front != back) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solve();
}