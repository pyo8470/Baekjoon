#include<iostream>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int N, X;
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		int k; cin >> k;
		(k < X) ? cout << k << " " : cout;
	}
}