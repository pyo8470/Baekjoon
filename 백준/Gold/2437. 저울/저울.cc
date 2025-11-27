#include <iostream>
#include <algorithm>
using namespace std;

int N;
int W[1000];

int main() {

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> W[i];
	}

	sort(W, W + N);

	int can_make = 0;
	int answer = can_make + 1;

	int i;
	for (i = 0; i < N; ++i) {
		if (can_make + 1 < W[i]) {
			answer = can_make + 1;
			break;
		}

		can_make += W[i];
	}

	if (i == N) {
		answer = can_make + 1;
	}

	cout << answer << endl;

	return 0;
}