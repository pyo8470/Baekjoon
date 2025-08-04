#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>;
using namespace std;



int N, K;
// w ,v 
vector<pair<int, int>> item;

// ikg에서 얻을 수 있는 가장 큰 것.

int main() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int w, v; cin >> w >> v;
		item.push_back({ w,v });
	}
	vector<vector<int>> dp(N, vector<int>(K + 1, 0));

	int result = 0;

	// 첫 번째 아이템 초기화
	for (int w = item[0].first; w <= K; w++) {
		dp[0][w] = item[0].second;
	}
	
	for (int i = 1; i < N; i++) {
		int W = item[i].first;
		int V = item[i].second;
		for (int w = 0; w <= K; w++) {
			// 가방에 넣을 수 없을 때
			if (w < W) dp[i][w] = dp[i - 1][w];
			else dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - W] + V);
		}
	}
	
	cout << dp[N - 1][K];
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < K + 1; j++) {
	//		cout << dp[i][j] << " ";
	//	}

	//	cout << '\n';
	//}

}