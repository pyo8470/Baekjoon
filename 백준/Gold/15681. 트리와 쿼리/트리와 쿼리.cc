#include <iostream>
#include <vector>
using namespace std;
int N, R, Q;
vector<vector<int>> adj;

vector<vector<int>> childs;
vector<int> parents;
vector<int> u_size;
void make_tree(const int& cur, const int& parent) {
    for (int& node : adj[cur]) {
        if (node != parent) {
            childs[cur].push_back(node);
            parents[node] = cur;
            make_tree(node, cur);
        }
    }
}

void count_subtree_nodes(const int& cur) {
    for (int& node : childs[cur]) {
        count_subtree_nodes(node);
        u_size[cur] += u_size[node];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> R >> Q;
    adj.assign(N + 1, {});
    childs.assign(N + 1, {});
    u_size.assign(N + 1, 1);
    parents.assign(N + 1, -1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    make_tree(R, -1);
    count_subtree_nodes(R);
    for (int i = 0; i < Q; i++) {
        int root;
        cin >> root;
        cout << u_size[root] << '\n';
    }
}
