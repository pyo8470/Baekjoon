#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int N;
vector<vector<int>> adj;
vector<bool> visited;
pair<int,int> dfs(int now) {

    int na = 1; 
    int nea = 0;
    for (int next : adj[now]) {
        if (visited[next]) continue;
        visited[next] = true;
        
        pair<int, int> child = dfs(next);
        nea += child.first;
        na += min(child.first, child.second);
        
    }
    return { na,nea };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    adj.assign(N + 1, {});
    visited.assign(N + 1, false);
    for (int i = 0; i < N - 1; i++) {
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    visited[1] = true;
    pair<int, int> result = dfs(1);

    cout << min(result.first, result.second);
}
