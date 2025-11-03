#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int s, e;
vector<int> parent;

struct edge {
    int s, e, w;
};
vector<edge> adj;
void init() {
    cin >> N >> M;
    cin >> s >> e;
    parent.assign(N + 1, 0);
    for (int i = 0; i < N + 1; i++) {
        parent[i] = i;
    }
    adj.assign(N + 1, {});

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj.push_back({u, v, w});
    }
}
int find(int x) {
    if (x == parent[x])
        return parent[x];
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    int A = find(a);
    int B = find(b);

    if (A == B)
        return;
    parent[A] = B;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    sort(adj.begin(), adj.end(), [](const edge &a, const edge &b) {
        if (a.w != b.w)
            return a.w > b.w;
        if (a.s != b.s)
            return a.s < b.s;
        return a.e < b.e;
    });

    int MIN = 2e9;
    for (edge &ed : adj) {
        auto [u, v, w] = ed;

        if (find(u) == find(v))
            continue;
        MIN = min(w, MIN);
        merge(u, v);
        if (find(s) == find(e)) {
            cout << MIN;
            return 0;
        }
    }
    
    cout << 0;
}