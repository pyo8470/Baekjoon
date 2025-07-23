#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <climits>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int N, M, R;

void rotation(vector<vector<int>>& arr) {
	vector<vector<int>> temp = arr;
	int box = min(N, M) / 2;
	for (int i = 0; i < box; i++) {
		int dir = 0;
		// 4방향에 대해 반복
		// 가로 (상단)
		int top = i;
		for (int j = i; j < M - 1 - i; j++) {
			arr[top][j] = temp[top][j + 1];
		}
		// 가로 ((하단)
		int bottom = N - i - 1;
		for (int j = i + 1; j <= M - 1 - i; j++) {
			arr[bottom][j] = temp[bottom][j - 1];
		}
		// 세로 (우측)
		int right = M - i - 1;
		for (int j = i; j < N - 1 - i; j++) {
			arr[j][right] = temp[j + 1][right];
		}

		// 세로 (좌측)
		int left = i;
		for (int j = i + 1; j <= N - 1 - i; j++) {
			arr[j][left] = temp[j - 1][left];
		}
	}
}

void print(vector<vector<int>> arr) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> N >> M >> R;
	vector<vector<int>> arr(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			cin >> arr[i][j];
		}
	}
	for (int r = 0; r < R; r++) {
		//vector<vector<int>> temp = arr;
		rotation(arr);
	}
	print(arr);
}


