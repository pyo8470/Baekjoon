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
    set<int> s(arr.begin(), arr.end());      // 자동 정렬 + 중복 제거
    vector<int> sorted(s.begin(), s.end());  // vector로 변환 (random access 가능)

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