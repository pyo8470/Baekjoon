#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
vector<int> arr;
void init() {
    N = 5;
    arr.resize(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
}

void solve() {
    sort(arr.begin(), arr.end());

    int sum = 0;
    for (int n : arr) {
        sum += n;
    }
    cout << sum / 5 << '\n' << arr[2];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    solve();
}