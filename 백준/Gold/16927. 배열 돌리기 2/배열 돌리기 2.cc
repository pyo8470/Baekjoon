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

void rotate_by_layer(vector<vector<int>>& arr, int layer, int R) {
	
	// R번 다 도는 것은 비효율적이다.
	// 각 box당 R%boxLen만큼 돌면 된다.

	int n = N - (layer * 2);
	int m = M - (layer * 2);
	int len = 2*(n+m) -4 ;

	int r = R % len;
	// 1차원으로 바꾸자 위 오른쪽 아래 왼쪽 순
	vector<int> temp;
	int top = layer;
	for (int j = layer; j < M - layer -1 ; j++) {
		temp.push_back(arr[top][j]);
	}
	int right = M - layer - 1;
	for (int j = layer; j < N - layer -1 ; j++) {
		temp.push_back(arr[j][right]);
	}
	// bottom
	int bottom = N - layer - 1;

	for (int j = M - layer - 1; j > layer; j--) {
		temp.push_back(arr[bottom][j]);
	}
	// left
	int left = layer;
	for (int j = N-layer-1; j > layer; j--) {
		temp.push_back(arr[j][left]);
	}

	vector<int> rotated(len);
	for (int i = 0; i < len; i++) {
		rotated[i] = temp[(i + r) % len];
	}

	//for (int i = 0; i < len; i++) {
	//	cout << rotated[i] << " ";
	//}

	int index = 0;
	for (int j = layer; j < M - layer - 1; j++) {
		arr[top][j] = rotated[index++];
	}
	for (int j = layer; j < N - layer - 1; j++) {
		arr[j][right] = rotated[index++];
	}
	for (int j = M - layer - 1; j > layer; j--) {
		arr[bottom][j] = rotated[index++];
		temp.push_back(arr[bottom][j]);
	}
	for (int j = N - layer - 1; j > layer; j--) {
		arr[j][left] = rotated[index++];
	}
	// 다시 집어넣기
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

	int layers = min(N, M) / 2;
	for (int i = 0; i < layers; i++) {
		rotate_by_layer(arr, i, R);
		//cout << endl;
	}
	print(arr);
}


