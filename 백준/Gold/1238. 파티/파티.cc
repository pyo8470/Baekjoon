#include <bits/stdc++.h>

#include <queue>

using namespace std;

int N, M, X;
vector<vector<pair<int, int>>> adj_go;
vector<vector<pair<int, int>>> adj_back;
vector<int> dist_go;
vector<int> dist_back;
void print(vector<int>& dist) {
    for (int d : dist) {
        cout << d << " ";
    }
    cout << '\n';
}
void dijk(vector<vector<pair<int, int>>>& adj, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, X});

    while (!pq.empty()) {
        auto [w, e] = pq.top();
        pq.pop();
        for (auto& next : adj[e]) {
            auto [nw, ne] = next;
            if (dist[e] + nw < dist[ne]) {
                dist[ne] = dist[e] + nw;
                pq.push({nw, ne});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> X;

    dist_go.assign(N + 1, 2e9);
    dist_back.assign(N + 1, 2e9);
    adj_go.assign(N + 1, {});
    adj_back.assign(N + 1, {});
    dist_go[X] = 0;
    dist_back[X] = 0;
    for (int i = 0; i < M; i++) {
        int s, e, w;
        cin >> s >> e >> w;

        adj_go[s].push_back({w, e});
        adj_back[e].push_back({w, s});
    }

    dijk(adj_go, dist_go);
    dijk(adj_back, dist_back);

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, dist_go[i] + dist_back[i]);
    }
    cout << ans;
}