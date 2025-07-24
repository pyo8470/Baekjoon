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

void command1(vector<vector<int>>& arr, int count);
void command2(vector<vector<int>>& arr, int count);
void command3(vector<vector<int>>& arr, int count);
void command4(vector<vector<int>>& arr, int count);
void command5(vector<vector<int>>& arr, int count);
void command6(vector<vector<int>>& arr, int count);
void print(vector<vector<int>> arr, int N, int M);

void operate(vector<vector<int>>& arr, int cCount[6]) {
	for (int i = 1; i <= 6; i++) {
		switch (i) {

		case 1: {
			if (cCount[i - 1] == cCount[i]) break;
			command1(arr, cCount[i - 1]);
			
			break;
		}
		case 2: {
			if (cCount[i - 1] == cCount[i-2]) break;
			command2(arr, cCount[i - 1]);
			break;
		}
		case 3:
			if (cCount[i - 1] == cCount[i]) break;
			command3(arr, cCount[i - 1]);
			break;
		case 4:
			if (cCount[i - 1] == cCount[i - 2]) break;
			command4(arr, cCount[i - 1]);
			break;
		case 5:
			if (cCount[i - 1] == cCount[i]) break;
			command5(arr, cCount[i - 1]);
			break;
		case 6:
			if (cCount[i - 1] == cCount[i - 2]) break;
			command6(arr, cCount[i - 1]);
			break;
		default:
			break;
		}
	}
}

void command1(vector<vector<int>>& arr, int count) {
	// 상하 반전
	if (count == 0) return;

	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < M; j++) {
			int temp = arr[i][j];
			arr[i][j] = arr[N - i - 1][j];
			arr[N - i - 1][j] = temp;
		}
	}
}
void command2(vector<vector<int>>& arr, int count) {
	if (count == 0) return;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M / 2; j++) {
			int temp = arr[i][j];
			arr[i][j] = arr[i][M - j - 1];
			arr[i][M - j - 1] = temp;
		}
	}
}
void command3(vector<vector<int>>& arr, int count) {
	if (count == 0) return;

	for (int rot = 0; rot < count; rot++) {
		vector<vector<int>> temp(M, vector<int>(N));

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				temp[i][j] = arr[N - j - 1][i];
			}
		}
		arr = temp;
		swap(N, M);
	}
}
void command4(vector<vector<int>>& arr, int count) {
	if (count == 0) return;

	for (int rot = 0; rot < count; rot++) {
		vector<vector<int>> temp(M, vector<int>(N));

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				temp[i][j] = arr[j][M - i - 1];
			}
		}
		arr = temp;
		swap(N, M);
	}
}
void command5(vector<vector<int>>& arr, int count) {
	if (count == 0) return;
	// 시계 방향
	// 1 2 3 4 순으로 저장하자
	vector<vector<vector<int>>> temp(4, vector<vector<int>>(N / 2, vector<int>(M / 2)));

	int n, m;
	n = N / 2;
	m = M / 2;
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < M / 2; j++) {
			temp[0][i][j] = arr[i][j];
			temp[1][i][j] = arr[i][j + m];
			temp[2][i][j] = arr[i + n][j + m];
			temp[3][i][j] = arr[i + n][j];
		}
	}


	vector<vector<vector<int>>> rotated(4, vector<vector<int>>(N / 2, vector<int>(M / 2)));
	for (int i = 0; i < 4; i++) {
		rotated[(i + count) % 4] = temp[(i)];
	}

	// 수정

	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < M / 2; j++) {
			arr[i][j] = rotated[0][i][j];
			arr[i][j + m] = rotated[1][i][j];
			arr[i + n][j + m] = rotated[2][i][j];
			arr[i + n][j] = rotated[3][i][j];
		}
	}
}
void command6(vector<vector<int>>& arr, int count) {
	if (count == 0) return;
	// 시계 방향
	// 1 2 3 4 순으로 저장하자
	vector<vector<vector<int>>> temp(4, vector<vector<int>>(N / 2, vector<int>(M / 2)));

	int n, m;
	n = N / 2;
	m = M / 2;
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < M / 2; j++) {
			temp[0][i][j] = arr[i][j];
			temp[1][i][j] = arr[i][j + m];
			temp[2][i][j] = arr[i + n][j + m];
			temp[3][i][j] = arr[i + n][j];
		}
	}

	vector<vector<vector<int>>> rotated(4, vector<vector<int>>(N / 2, vector<int>(M / 2)));
	for (int i = 0; i < 4; i++) {
		rotated[i] = temp[(i + count) % 4];
	}

	// 수정

	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < M / 2; j++) {
			arr[i][j] = rotated[0][i][j];
			arr[i][j + m] = rotated[1][i][j];
			arr[i + n][j + m] = rotated[2][i][j];
			arr[i + n][j] = rotated[3][i][j];
		}
	}
	// 반 시계 방향
}

void print(vector<vector<int>> arr, int N, int M) {
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
	int cCount[6] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}


	for (int i = 0; i < R; i++) {
		int num; cin >> num;
		cCount[num - 1]++;
		operate(arr, cCount);
		cCount[num - 1]--;

		// 합해서 돌리면 안될것 같다. 회전 시키는 경우엔 경우의 수가 좀 달라진다.
		/*switch (num) {
		case 1:
			cCount[num - 1] = (cCount[num - 1] + 1) % 2;
			break;
		case 2:
			cCount[num - 1] = (cCount[num - 1] + 1) % 2;
			break;
		case 3:
			cCount[num - 1] = (cCount[num - 1] + 1) % 4;
			break;
		case 4:
			cCount[num - 1] = (cCount[num - 1] + 1) % 4;
			break;
		case 5:
			cCount[num - 1] = (cCount[num - 1] + 1) % 4;
			break;
		case 6:
			cCount[num - 1] = (cCount[num - 1] + 1) % 4;
			break;
		}*/
	}

	
	print(arr, N, M);
}

