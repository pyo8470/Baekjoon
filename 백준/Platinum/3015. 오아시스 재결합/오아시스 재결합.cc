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

	//unordered_set <pair<int, int>> result;
	int N; cin >> N;
	long long int count = 0;
	
	// 키, 같은 키 개수
	stack<pair<int, int>> st;

	int hei;

	/*
	*	1 + 1 + 2 + 2 + 3 + 1
	*	2 4 1 2 2 5 1
	*	2 4 -> 1
	*	2 4 1 -> (2-4) (4-1) 페어
	*	2 4 1 2 -> (1-2) (4-2) 페어
	*	2 4 1 2 2 -> (2 - 2) (4-2) 페어
	* 
	*	누적식으로 더해줘야한다.
		top보다 큰 키가 오면 제거해준다.
		제거 해 줄 때, 그 top키가 몇 개 있는지도 더해준다.
	*/
	for (int i = 0; i < N; i++) {
		cin >> hei;          
		int cnt = 1;
		// top 보타 키가 크거나 같으면 stack에서 삭제
		while (!st.empty() && st.top().first <= hei) {
			count += st.top().second;
			if (st.top().first == hei) {
				cnt += st.top().second; // 같은 키 개수 올려준다.
			}
			st.pop();
		}	
		if (!st.empty()) {
			count++;
		}
		st.push({ hei,cnt});
		
	}
	cout << count;
}
