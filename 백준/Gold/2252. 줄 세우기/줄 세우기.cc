#include<vector>
#include<queue>
#include<iostream>

using namespace std;

int N,M;

vector<vector<int>> adj;
vector<int> indegree;
queue<int> q;

void solve(){
    for(int i=1; i<=N; i++){
        if(indegree[i] == 0) q.push(i);
    }

    // vector<int> result(N+1,0);
    
    for(int i=1; i<=N; i++){
        int node = q.front(); q.pop();
        cout << node << " ";
        for(int next : adj[node]){
            if(--indegree[next] == 0){
                q.push(next);
            }
        }
    }
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    
    adj.assign(N+1,{});
    indegree.assign(N+1,0);
    for(int i=0; i<M; i++){
        int front, back;
        cin >> front >> back;

        adj[front].push_back(back);
        indegree[back]++;
    } 
    
    solve();
    return 0;
}
