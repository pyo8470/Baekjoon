#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

int N;
vector<long long> H;
vector<long long> ans;
int solve() {
    if (N == 1) {
        return 0;
    }

    ans.assign(N, 0);
    for (int s = 0; s < N - 1; s++) {      // 시작 건물
        for (int e = s + 1; e < N; e++) {  // 목표 건물

            bool blocked = false;
            for (int mid = s + 1; mid < e; mid++) {  // 중간 건물

                // (s, mid)의 기울기 * (e-s) 와 (s, e)의 기울기 * (e-s) 비교
                long long lhs = (H[mid] - H[s]) * (long long)(e - s);
                long long rhs = (H[e] - H[s]) * (long long)(mid - s);

                // s-mid 기울기가 s-e 기울기보다 크거나 같으면 막힌 것
                if (lhs >= rhs) {
                    blocked = true;
                    break;  // (s, e)는 막혔으므로 더 볼 필요 없음
                }
            }

            if (!blocked) {
                ans[s]++;
                ans[e]++;
            }
        }
    }

    int ret = 0;
    for (long long i : ans) {
        ret = max((int)i, ret);  
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    H.resize(N);
    for (int i = 0; i < N; i++) cin >> H[i];

    cout << solve();
}
