#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> arr;
vector<int> LIS;

int bin_search(int left, int right, int target) {
	int mid;

	while (left < right) {
		int mid = (left + right) / 2;

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
	int lis_len = 0;
	int i = 0;

	while (i < N) {
		if (LIS[lis_len] < arr[i]) {
			LIS[lis_len + 1] = arr[i];
			lis_len++;
		} else {
			int idx = bin_search(0, lis_len, arr[i]);
			LIS[idx] = arr[i];
		}
		i++;
	}
	cout << lis_len + 1;
}
