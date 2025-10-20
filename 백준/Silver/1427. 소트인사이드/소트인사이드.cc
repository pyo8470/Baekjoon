#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> arr;
void init() {
    string s;
    cin >> s;
    for (char c : s) {
        arr.push_back(int(c - '0'));
    }
}

void solve() {
    sort(arr.begin(), arr.end(), greater<int>());
    for (int i : arr) cout << i;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    solve();
}