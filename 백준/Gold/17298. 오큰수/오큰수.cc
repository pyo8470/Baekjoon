#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <stack>

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	
	vector<int> a(n,-1);

	vector<int> result(n, -1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	// 숫자, 인덱스
	stack<pair<int,int>> st;
	st.push({a[0],0});
	for (int i = 1; i < n; i++) {

		while (!st.empty() && st.top().first < a[i]) {
			result[st.top().second] = a[i];
			st.pop();
		}
		st.push({ a[i],i });
	}

	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
}
