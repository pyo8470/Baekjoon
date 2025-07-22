#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <stack>
#include <unordered_set>


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	int M; cin >> M;

	deque<int> dq(N);
	for (int i = 1; i <= N; i++) {
		dq[i - 1] = i;
	}

	int result = 0;
	for (int i = 0; i < M; i++) {
		int target; cin >> target;

		int index = 0;

		for (; index < dq.size(); index++) {
			if (dq[index] == target) {
				break;
			}
		}

		// 오른쪽 이동
		if (index > (dq.size() / 2)) {
			while (dq.front() != target) {
				result++;
				dq.push_front(dq.back());
				dq.pop_back();
			}
			dq.pop_front();
		}
		// 왼쪽 이동
		else {
			while (dq.front() != target) {
				result++;
				dq.push_back(dq.front());
				dq.pop_front();
			}
			dq.pop_front();
		}
		
	}
	cout << result;
}