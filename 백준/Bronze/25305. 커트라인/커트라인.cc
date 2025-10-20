#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int N, k;
vector<int> arr;
void init() {
    cin >> N >> k;
    arr.resize(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
}

void solve() {
    sort(arr.begin(), arr.end(), greater<int>());

    cout << arr[k - 1];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    solve();
}