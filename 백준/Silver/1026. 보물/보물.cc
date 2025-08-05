#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int N;
vector<int> arr1;
vector<int> arr2;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N; 
	arr1.resize(N, 0);
	arr2.resize(N, 0);
	for (int i = 0; i < N; i++) cin >> arr1[i];
	for (int i = 0; i < N; i++) cin >> arr2[i];


	sort(arr1.begin(), arr1.end(),greater<int>());
	sort(arr2.begin(), arr2.end());
	
	int result = 0;
	for (int i = 0; i < N; i++) {
		result += (arr1[i] * arr2[i]);
	}
	cout << result;
}