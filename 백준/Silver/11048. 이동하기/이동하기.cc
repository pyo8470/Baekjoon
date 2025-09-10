#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#define MAX_LEN 1000
using namespace std;
typedef long long ll;


int N, M;
int grid[MAX_LEN][MAX_LEN] = { 0, };
int dp[MAX_LEN][MAX_LEN] = { 0, };



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> grid[i][j];
		}
	}
	dp[0][0] = grid[0][0];
	for (int i = 1; i < N; i++) {
		dp[i][0] += dp[i - 1][0] + grid[i][0];
	}
	for (int i = 1; i < M; i++) {
		dp[0][i] += dp[0][i - 1] + grid[0][i];
	}

	
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			dp[i][j] = max(dp[i - 1][j - 1] + grid[i][j], dp[i - 1][j] + grid[i][j]);
			dp[i][j] = max(dp[i][j - 1] + grid[i][j], dp[i][j]);
		}
	}

	cout << dp[N - 1][M - 1];
	return 0;
}

