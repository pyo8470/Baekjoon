#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main() {
	int N; cin >> N;

	vector<int> posi, negi;
	int one = 0; int zero = 0;

	// 양수와 음수 따로 관리

	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		if (num > 1) posi.push_back(num);
		else if (num == 1) one++;
		else if (num == 0) zero++;
		else negi.push_back(num);
	}

	int result = 0;
	sort(posi.begin(), posi.end(), greater<int>());
	sort(negi.begin(), negi.end());
	int posi_size = posi.size();
	
	for (int i = 0; i < (posi_size - 1) ; i += 2) {
		result += posi[i] * posi[i + 1];
	}// 홀수 처리
	if (posi.size() % 2 == 1) result += posi.back();

	int negi_size = negi.size();
	for (int i = 0; i < negi_size -1 ; i += 2) {
		result += negi[i] * negi[i + 1];
	}// 홀수 처리

	if (negi.size() % 2 == 1) {
		// 0이 없다면
		if (zero == 0) result += negi.back();
	}

	result += one;

	cout << result;
}