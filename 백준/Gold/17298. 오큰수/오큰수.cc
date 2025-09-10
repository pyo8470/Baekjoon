#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stack>
#include<vector>
#define MAX_LEN 1000
using namespace std;
typedef long long ll;


int N, M;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	vector<int> arr(N,0);
	for (int i = 0; i < N; i++)cin >> arr[N - i - 1];
	vector<int> result(N,0);
	result[N - 1] = -1;


	stack<int> st;
	st.push(arr[0]);
	for (int i = 1; i < N; i++) {
		if (arr[i] < st.top()) result[N - i - 1] = st.top();
		else {
			while (!st.empty() && st.top() <= arr[i]) {
				st.pop();
			}
			result[N - i - 1] = (st.empty()) ? -1 : st.top();
		}
		st.push(arr[i]);
	}

	for (int i = 0; i < N; i++) {
		cout << result[i] << " ";
	}
	return 0;
}

