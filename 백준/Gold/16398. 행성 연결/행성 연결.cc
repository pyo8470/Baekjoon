#include <bits/stdc++.h>
using namespace std;

/*
    제국 내 모든 행성을 연결하면서 유지 비용이 최소? MST
    간선이 많으니 Prim 씁시디
*/
const int MAX = 1001;
int N;
int matrix[MAX][MAX];
bool visited[MAX];
struct edge{
    int w,v;

    bool operator<(const edge &other) const {
        if(w != other.w) return w > other.w;
        return v > other.v; 
    }
};
long long prim(){
    memset(visited,false,sizeof(visited));
    priority_queue<edge> pq;
    pq.push({0,0});
    
    int edge_count = 0;
    long long ret = 0;
    while(!pq.empty()){
        edge cur = pq.top(); pq.pop();
        int cur_w = cur.w, cur_node = cur.v;

        if(visited[cur_node]) continue;
        visited[cur_node] = true;
        ret += cur_w;
        edge_count++;
        if(edge_count == N) {
            return ret;
        }

        for(int i=0; i<N; i++){
            int next_node = i;
            int next_w = matrix[cur_node][next_node];
            if(matrix[cur_node][next_node] == 0 || visited[next_node]) continue;
            
            // cout << cur_node << " " << next_node << " : " << next_w << '\n';
            pq.push({next_w,next_node});
        }
    }
    return -1;
}
void solve(){
    cin >> N;
    // memset(matrix,0,sizeof(matrix));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> matrix[i][j];
        }
    }

    cout << prim();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
