#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S;
    cin >> N >> S;
    vector<int> arr(N);
    vector<int> sum(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sum[i] = arr[i];
        if (i >= 1)
            sum[i] += sum[i - 1];
    }

    if (sum[N - 1] < S) {
        cout << 0;
        return 0;
    }

    int l = -1, r = 0;
    int MIN = 1e9;
    while (r < N) {
        int s = sum[r];
        if (l >= 0)
            s -= sum[l];
        if (s >= S) {
            MIN = min(r - l, MIN);
            l++;
        } else {
            r++;
        }
    }

    cout << MIN;
    return 0;
}