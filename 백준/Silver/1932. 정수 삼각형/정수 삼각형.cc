#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<int>> dp;

void init() {
	cin >> n;
	dp.assign(n, {});
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int num; cin >> num;
			dp[i].push_back(num);
		}
	}
}

int solve() {
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i;j++) {
			if (j == 0) {
				dp[i][j] += dp[i - 1][j];
			}
			else if (j == i) {
				dp[i][j] += dp[i - 1][j - 1];
			}
			else {
				dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
			}
		}
	}

	int ret = 0;
	for (int i = 0; i < n; i++) {
		ret = max(ret, dp[n - 1][i]);
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	cout << solve();
}
