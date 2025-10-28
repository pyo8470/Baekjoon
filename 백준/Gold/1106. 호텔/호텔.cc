#include <iostream>
#include <vector>
using namespace std;
int N, C;

vector<int> cost;
vector<int> customer;

int ans = 2e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> C >> N;
    cost.resize(N);
    customer.resize(N);
    int max_customer = 0;
    for (int i = 0; i < N; i++) {
        cin >> cost[i] >> customer[i];
        max_customer = max(max_customer, customer[i]);
    }

    // i명 꼬셨을 때 최소 비용
    vector<int> dp(C + max_customer + 1, (int)2e9);

    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j + customer[i] < dp.size(); j++) {
            dp[j + customer[i]] = min(dp[j + customer[i]], dp[j] + cost[i]);
        }
    }
    for (int i = C; i < dp.size(); i++) {
        ans = min(ans, dp[i]);
    }
    cout << ans;
}