#include<vector>
#include<queue>
#include<iostream>
#include<cstring>
#include<unordered_set>
using namespace std;

const int MAX_N = 1000;
int N, K;
int build_time[MAX_N+1];
vector<vector<int>> adj;
vector<int> indeg, dist;
queue<int> q;
int target;

void init(){
    cin >> N >> K;
   
    adj.assign(N+1,{});
    indeg.assign(N+1,0);
    dist.assign(N+1,0);

    memset(build_time,0,sizeof(build_time));
    for(int i=0; i<N; i++){
        cin >> build_time[i+1];
    }
    
    for(int i=0; i<K; i++){
        int start, end;
        cin >> start >> end;
        adj[start].push_back(end);
        indeg[end]++;
    }
    cin >> target;
}

int solve(){
    for(int i=1; i<=N; i++){
        dist[i] = build_time[i];
        if(indeg[i] == 0) q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front(); q.pop();
        for(int nxt : adj[node]){
            dist[nxt] = max(dist[nxt],dist[node] + build_time[nxt]);
            if(--indeg[nxt] == 0){
                q.push(nxt);
            }
        }
    }
    
    return dist[target];

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T; cin >> T;
    while(T--){
        init();
        cout << solve() << '\n';
    }


    return 0;
}
