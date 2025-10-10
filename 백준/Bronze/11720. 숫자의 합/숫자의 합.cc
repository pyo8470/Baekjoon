#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    string s;
    cin >> s;


    int ans = 0;
    for (char c : s) {
        int num = c - '0';
        ans += num;
    }
    cout << ans;
}
