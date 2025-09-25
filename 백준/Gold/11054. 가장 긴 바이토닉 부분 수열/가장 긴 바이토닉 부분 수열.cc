#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> arr;
vector<int> dp_rev;
vector<int> dp;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	arr.assign(N, 0);
	dp.assign(N, 1);
	dp_rev.assign(N, 1);

	int ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];

		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		for (int j = N - 1; j > i; j--) {
			if (arr[i] > arr[j]) {
				dp_rev[i] = max(dp_rev[i], dp_rev[j] + 1);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		ans = max(ans, dp[i] + dp_rev[i] - 1);
	}
	cout << ans;
	return 0;
}
