#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#define MAX_N 300
using namespace std;

int N;
int stair[MAX_N+1] = { 0, };
int dp[MAX_N+1] = { 0, };
int main()
{

	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> stair[i];
	dp[0] = 0;
	dp[1] = dp[0] + stair[1];
	dp[2] = dp[1] + stair[2];

	for (int i = 3; i <= N; i++) {
		dp[i] = max(dp[i - 3] + stair[i - 1] + stair[i], dp[i - 2] + stair[i]);
		//for (int i = 0; i <= N; i++) cout << dp[i] << ' ';
		//cout << '\n';
	}
	cout << dp[N];

	return 0;
}

