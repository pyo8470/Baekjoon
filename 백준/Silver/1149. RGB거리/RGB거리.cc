#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int N;
struct RGB {
    int r, g, b;
};
vector<RGB> costs;
vector<vector<int>> dp;
void init() {
    cin >> N;
    costs.resize(N);
    for (int i = 0; i < N; i++) {
        int r, g, b;
        cin >> r >> g >> b;
        costs[i] = {r, g, b};
    }
}

int ans = 2e9;

inline int get_cost(const int& depth, const int& idx) {
    if (idx == 0)
        return costs[depth].r;
    else if (idx == 1)
        return costs[depth].g;
    return costs[depth].b;
}

void dfs(const int& depth, const int& prev, const int& cost) {
    if (cost >= ans)
        return;
    if (depth == N) {
        ans = min(ans, cost);
        return;
    }

    for (int i = 0; i < 3; i++) {
        if (i == prev)
            continue;

        int c = get_cost(depth, i);
        dfs(depth + 1, i, cost + c);
    }
}
int get_min(int idx, int color) {
    if (color == 0) {
        return min(dp[idx - 1][1] + costs[idx].r, dp[idx - 1][2] + costs[idx].r);
    } else if (color == 1) {
        return min(dp[idx - 1][0] + costs[idx].g, dp[idx - 1][2] + costs[idx].g);
    }
    return min(dp[idx - 1][0] + costs[idx].b, dp[idx - 1][1] + costs[idx].b);
}
void solve() {
    dp.assign(N, vector<int>(3, 0));
    dp[0][0] = costs[0].r;
    dp[0][1] = costs[0].g;
    dp[0][2] = costs[0].b;
    for (int i = 1; i < N; i++) {
        for (int color = 0; color < 3; color++) {
            dp[i][color] = get_min(i, color);
        }
    }
    int ans = min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2]));
    cout << ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();
    solve();
}