#include <bits/stdc++.h>
using namespace std;

const int MAX = 52;   // A-Z (0~25), a-z (26~51)
int N;

struct Edge {
    int v, cap, rev;
};

vector<vector<Edge>> graph;
vector<int> level, work;

// 문자 정점을 정수 ID로 변환
int id(char c) {
    if ('A' <= c && c <= 'Z') return c - 'A';
    return c - 'a' + 26;
}

// 잔여 그래프 간선 추가
void addEdge(int u, int v, int cap) {
    graph[u].push_back({v, cap, (int)graph[v].size()});
    graph[v].push_back({u, 0, (int)graph[u].size() - 1});
}

// BFS: Level Graph 생성
bool bfs(int s, int t) {
    fill(level.begin(), level.end(), -1);
    queue<int> q;
    level[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto &e : graph[u]) {
            if (level[e.v] == -1 && e.cap > 0) {
                level[e.v] = level[u] + 1;
                q.push(e.v);
            }
        }
    }
    return level[t] != -1;
}

// DFS: Blocking Flow
int dfs(int u, int t, int flow) {
    if (u == t) return flow;

    for (int &i = work[u]; i < graph[u].size(); i++) {
        Edge &e = graph[u][i];
        if (e.cap > 0 && level[e.v] == level[u] + 1) {
            int ret = dfs(e.v, t, min(flow, e.cap));
            if (ret > 0) {
                e.cap -= ret;
                graph[e.v][e.rev].cap += ret;
                return ret;
            }
        }
    }
    return 0;
}

// Dinic 메인
int dinic(int s, int t) {
    int result = 0;
    while (bfs(s, t)) {
        fill(work.begin(), work.end(), 0);
        while (int flow = dfs(s, t, INT_MAX)) {
            result += flow;
        }
    }
    return result;
}

void solve() {
    cin >> N;

    graph.assign(MAX, {});
    level.assign(MAX, 0);
    work.assign(MAX, 0);

    int s = id('A');  // Source
    int t = id('Z');  // Sink

    for (int i = 0; i < N; i++) {
        char a, b;
        int cap;
        cin >> a >> b >> cap;

        int u = id(a);
        int v = id(b);

        // 무향 + 중복 간선 처리
        addEdge(u, v, cap);
        addEdge(v, u, cap);
    }

    cout << dinic(s, t);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
