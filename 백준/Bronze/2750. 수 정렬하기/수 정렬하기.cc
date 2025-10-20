#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> arr;
void init() {
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
}

void solve() {
    sort(arr.begin(), arr.end());

    for (int n : arr) {
        cout << n << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    solve();
}