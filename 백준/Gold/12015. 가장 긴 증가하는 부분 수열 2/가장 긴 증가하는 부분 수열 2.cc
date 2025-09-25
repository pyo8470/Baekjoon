#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>

using namespace std;

int N;
vector<int> arr;
vector<int> LIS;
int bin_search(int left, int right, int target) {

	int mid;
	while (left < right) {
		mid = (left + right) / 2;

		if (LIS[mid] < target) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	return right;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	arr.assign(N, 0);
	LIS.assign(N, 0);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	LIS[0] = arr[0];
	int i = 1, j = 0;
	while (i < N) {
		if (LIS[j] < arr[i]) {
			LIS[j + 1] = arr[i];
			j++;
		} else {
			int idx = bin_search(0, j, arr[i]);
			LIS[idx] = arr[i];
		}
		i++;
	}
	cout << j + 1 << '\n';
//	for (i = 0; i < j + 1; i++) {
//		cout << LIS[i] << " ";
//	}
}
