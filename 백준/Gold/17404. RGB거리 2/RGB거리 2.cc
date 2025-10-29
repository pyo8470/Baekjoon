#include <bits/stdc++.h>
using namespace std;

struct RGB {
    int r, g, b;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<RGB> cost(N);
    for (int i = 0; i < N; i++)
        cin >> cost[i].r >> cost[i].g >> cost[i].b;

    // N == 1 예외 처리
    if (N == 1) {
        cout << min({cost[0].r, cost[0].g, cost[0].b}) << '\n';
        return 0;
    }

    const int INF = 1e9;
    int answer = INF;

    // 첫 번째 집의 색을 0(R), 1(G), 2(B)로 각각 고정
    for (int first = 0; first < 3; first++) {
        vector<vector<int>> dp(N, vector<int>(3, INF));

        // 첫 번째 집 초기화
        dp[0][first] = (first == 0 ? cost[0].r : (first == 1 ? cost[0].g : cost[0].b));

        // DP 진행
        for (int i = 1; i < N; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i].r;
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i].g;
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i].b;
        }

        // 마지막 집의 색은 첫 번째 색과 달라야 함
        for (int last = 0; last < 3; last++) {
            if (last == first) continue;
            answer = min(answer, dp[N - 1][last]);
        }
    }

    cout << answer << '\n';
    return 0;
}
