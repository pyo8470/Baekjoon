#include <bits/stdc++.h>

#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int N;

vector<pll> gain_upper;  // gain이 더 큰 그룹
vector<pll> loss_upper;  // loss가 더 큰 그룹
int solve() {
    ll happy = 0;
    for (pll& p : gain_upper) {
        ll gain = p.second;
        ll loss = p.first;
        if (happy < loss)
            return 0;
        happy += (gain - loss);
    }
    for (pll& p : loss_upper) {
        ll gain = p.second;
        ll loss = p.first;
        if (happy < loss)
            return 0;
        happy += (gain - loss);
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        ll l, g;
        cin >> l >> g;

        if (l > g) {
            loss_upper.push_back({l, g});
        } else {
            gain_upper.push_back({l, g});
        }
    }

    sort(loss_upper.begin(), loss_upper.end(), [](const pll& a, const pll& b) { return a.second > b.second; });
    sort(gain_upper.begin(), gain_upper.end(), [](const pll& a, const pll& b) { return a.first < b.first; });

    cout << solve();
}
