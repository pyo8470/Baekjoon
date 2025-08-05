#include <iostream>
#include <queue>
using namespace std;

int COUNT[10001] = { 0, };
int C_size = 10001;
int main() {
	ios_base::sync_with_stdio(0);

	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;

	vector<int> result;
	for(int i=0; i<N; i++){
		int k; cin >> k;
		COUNT[k]++;
	}

	/*for (int i = 1; i < C_size; i++) {
		COUNT[i] += COUNT[i - 1];
	}*/

	for (int i = 0; i < C_size; i++) {
		while (COUNT[i]) {
			cout << i << '\n';
			COUNT[i]--;
		}
	}
}