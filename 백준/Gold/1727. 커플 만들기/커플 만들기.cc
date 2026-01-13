#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX / 4;
long long dp[1001][1001];
vector<int> small, big;

long long dfs(int i, int j){
    if(i == small.size()) return 0;
    if(j == big.size()) return INF;

    long long &ret = dp[i][j];
    if(ret != -1) return dp[i][j];
    ret = INF;
    // 매칭
    ret = min(ret, abs(small[i] - big[j]) + dfs(i+1, j+1));
    ret = min(ret, dfs(i, j+1));

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(M);
    for(int &x : A) cin >> x;
    for(int &x : B) cin >> x;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    if(N <= M){
        small = A;
        big = B;
    } else {
        small = B;
        big = A;
    }

    memset(dp, -1, sizeof(dp));

    cout << dfs(0, 0);
    return 0;
}
