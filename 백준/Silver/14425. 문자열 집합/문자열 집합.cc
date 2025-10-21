#include <bits/stdc++.h>

#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    unordered_map<string, int> S;
    S.reserve(N + 5);
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        S[s] = 1;
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        // 찾기
        string target;
        cin >> target;
        ans += S[target];  // 어차피 0으로 초기화
    }

    cout << ans;
}