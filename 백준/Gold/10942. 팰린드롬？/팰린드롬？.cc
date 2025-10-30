#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> dp;
vector<int> arr;

void init() {
    dp.assign(N, vector<int>(N, -1));
    for (int i = 0; i < N; i++) {
        dp[i][i] = 1;
    }
}
bool solve(const int& start, const int& end) {
    if (dp[start][end] != -1)
        return dp[start][end];

    if (start >= end)
        return dp[start][end] = true;

    if (arr[start] != arr[end]) {
        return dp[start][end] = false;
    }

    return dp[start][end] = solve(start + 1, end - 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    init();
    int M;
    cin >> M;
    while (M--) {
        int s, e;
        cin >> s >> e;
        s--;
        e--;

        cout << solve(s, e) << '\n';
    }
}