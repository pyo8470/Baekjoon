#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> arr;
long long answer = 0;
long long memo[100][21];

// 일단 dfs로 풀이 생각
long long dfs(const int& depth,int cal){
    if(depth == N-1){
        if(cal == arr[N-1]) return 1;
        return 0;
    }  

    if(memo[depth][cal] != -1) return memo[depth][cal];
    long long ret = 0;
    if(cal + arr[depth] <= 20){
        ret += dfs(depth + 1, cal + arr[depth]);
    }
    if(cal - arr[depth] >= 0){
        ret += dfs(depth + 1, cal - arr[depth]);
    }

    return memo[depth][cal] = ret;
}

int main() {
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N; arr.resize(N);
    memset(memo, -1, sizeof(memo));
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    cout << dfs(1,arr[0]);
}