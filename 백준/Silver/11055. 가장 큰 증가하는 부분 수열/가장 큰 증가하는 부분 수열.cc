#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> arr;
vector<int> dp;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	arr.assign(N, 0);
	dp.assign(N, 0);

	int ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[j] + arr[i], dp[i]);
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}
