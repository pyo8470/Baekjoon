#include <algorithm>
#include <iostream>
#include <set>
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
    vector<int> sorted = arr;  // vector로 변환 (random access 가능)

    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    for (int i = 0; i < N; i++) {
        int rank = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin();
        cout << rank << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    solve();
}