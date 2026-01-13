#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = LLONG_MAX / 4;

int N;
ll W[16][16];
ll dp[1 << 16][16];

// mask : 방문한 도시 집합
// u    : 현재 도시
ll dfs(int mask, int u) {
    // 모든 도시 방문 완료
    if (mask == (1 << N) - 1) {
        if (W[u][0] == 0) return INF; // 시작점으로 못 돌아가면 불가능
        return W[u][0];
    }

    ll &ret = dp[mask][u];
    if (ret != -1) return ret;

    ret = INF;

    for (int v = 0; v < N; v++) {
        // 이미 방문한 도시
        if (mask & (1 << v)) continue;
        // 길이 없음
        if (W[u][v] == 0) continue;

        ret = min(ret, W[u][v] + dfs(mask | (1 << v), v));
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> W[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    // 0번 도시에서 시작
    cout << dfs(1, 0) << '\n';

    return 0;
}
