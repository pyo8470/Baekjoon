#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include<math.h>
using namespace std;

struct applicant {
	int coding;
	int interview;
};
vector<applicant> app;
int main() {

	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		int N; cin >> N;
		app.resize(N, { 0,0 });
		for (int i = 0; i < N; i++) {
			cin >> app[i].coding >> app[i].interview;
		}

		sort(app.begin(), app.end(), [](applicant a, applicant b) {
			return a.coding < b.coding;
			});

		/*for (int i = 0; i < N; i++) {
			cout << app[i].coding << " " << app[i].interview << '\n';
		}*/

		int result = 1;
		int top = app[0].interview;
		for (int i = 1; i < N; i++) {
			int interv = app[i].interview;

			// 이미 코테는 후달림
			// 인터뷰까지 후달리는 경우 그냥 건너뛰기
			if (top < interv) continue;
			// 안후달리는 경우(순위가 더 높음)
			// 다음 후보자는 얘보단 인터뷰 순위 높아야 됨.
			top = interv;
			result++;
		}

		cout << result << '\n';
	}
}