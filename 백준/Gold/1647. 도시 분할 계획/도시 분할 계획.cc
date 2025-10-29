#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, M;

// 간선
struct edge {
    int s, e, w;
};
vector<edge> adj;
vector<int> parent;
vector<int> u_size;
int find(const int &x) {
    if (x == parent[x])
        return parent[x];
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    int A = find(a);
    int B = find(b);

    if (A == B)
        return;
    parent[B] = A;
    u_size[A] += u_size[B];
}

int solve() {
    int ret = 0;

    // 끊는 용도;
    int max_w = 0;
    for (edge &ed : adj) {
        int s = ed.s, e = ed.e, w = ed.w;
        int p_s = find(s), p_e = find(e);
        if (u_size[p_s] == N || u_size[p_e] == N)
            break;
        if (p_s == p_e)
            continue;

        merge(s, e);
        max_w = max(max_w, w);
        ret += w;
    }

    // 스패닝 트리 - 가장 큰 가중치를 가진 edge의 w를 하나 빼주면 도시 분할 완성!
    return ret - max_w;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;

    parent.resize(N + 1);
    u_size.assign(N + 1, 1);
    for (int i = 0; i < N + 1; i++) parent[i] = i;

    for (int i = 0; i < M; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        adj.push_back({s, e, w});
    }

    sort(adj.begin(), adj.end(), [](const edge &a, const edge &b) {
        if (a.w != b.w)
            return a.w < b.w;
        if (a.s != b.s)
            return a.s < b.s;
        return a.e < b.e;
    });

    cout << solve();
}
