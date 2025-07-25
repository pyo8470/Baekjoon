#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
 using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int N; cin >> N;
	vector<int> arr(N);

	int K = 8001;                          // -4000 ~ 4000 총 8001개
	vector<int> countingArr(8001, 0);      // 카운팅 배열 (빈도수)
	vector<int> sorted(N);                // 정렬된 결과 저장
	double sum = 0;

	// 선택 정렬
	int maxFreq = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
		countingArr[arr[i] + 4000] += 1;   // -4000 ~ 4000 → 0 ~ 8000 인덱스로 매핑
	}
	//범위 O(K)
	int left = 0;
	for (int i = 0; i < K; i++) {
		if (countingArr[i] != 0) {
			left = i - 4000; break;
		};
	}
	int right = 0;
	for (int i = K - 1; i >= 0; i--) {
		if (countingArr[i] != 0) {
			right = i - 4000; break;
		}
	}
	// 최빈값 구하기
	for (int i = 0; i < K; i++) {
		maxFreq = max(maxFreq, countingArr[i]);
	}
	vector<int> freq;
	for (int i = 0; i < K; i++) {
		if (maxFreq == countingArr[i]) {
			freq.push_back(i -4000);
		}
	}
	// 중앙값
	for (int i = 1; i < K; i++) {
		countingArr[i] += countingArr[i - 1];
	}
	for (int i = N - 1; i >= 0; i--) {
		int val = arr[i] + 4000;
		sorted[countingArr[val] - 1] = arr[i];  // 실제 값 저장
		countingArr[val] -= 1;
	}

	/*cout << endl;

	for (int i = 0; i < freq.size(); i++) {
		cout << freq[i] << " ";
	}
	cout << endl;*/
	// 산술 평균
	double avg = round((double)(sum) / N);
	(avg == -0) ? avg = 0 : 1;
	cout << avg << '\n';
	// 중앙값 구하기
	cout << sorted[N / 2] << '\n';
	
	(freq.size() > 1) ? cout << freq[1] << '\n' : cout << freq[0] << '\n';
	// 범위
	cout << right - left << '\n';
}