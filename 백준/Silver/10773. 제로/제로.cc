#include <iostream>
using namespace std;
#include <string>
#include <stack>
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	stack<int> st;
	int K; cin >> K;
	for (int i = 0; i < K; i++) {
		int n; cin >> n;
		if (n != 0) st.push(n);
		else st.pop();
	}

	int sum = 0;
	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}
	cout << sum;
}
