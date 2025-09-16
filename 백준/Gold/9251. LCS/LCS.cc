#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#define MAX_LEN 1001
using namespace std;


string s1, s2;
int M, N;
int dp[MAX_LEN][MAX_LEN];
int LCS(const int& m,const int& n) {
	
	if (m == 0 || n == 0) {
		return 0;
	}
	if (s1[m - 1] == s2[n - 1]) return 1 + LCS(m - 1, n - 1);
	return max(LCS(m, n - 1), LCS(m - 1, n));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> s1 >> s2;
	
	M = s1.length();
	N = s2.length();
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[M][N];
}
