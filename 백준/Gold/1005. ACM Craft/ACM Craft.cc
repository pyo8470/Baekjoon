#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> D(N + 1), dp(N + 1, 0);
        for (int i = 1; i <= N; i++) cin >> D[i];

        vector<vector<int>> adj(N + 1);
        vector<int> indeg(N + 1, 0);

        for (int i = 0; i < K; i++) {
            int X, Y;
            cin >> X >> Y;
            adj[X].push_back(Y);
            indeg[Y]++;
        }

        int W;
        cin >> W;

        queue<int> q;
        for (int i = 1; i <= N; i++) {
            dp[i] = D[i];
            if (indeg[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                dp[v] = max(dp[v], dp[u] + D[v]);
                if (--indeg[v] == 0) q.push(v);
            }
        }

        cout << dp[W] << "\n";
    }
    return 0;
}