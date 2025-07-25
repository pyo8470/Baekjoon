#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#include<vector>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, temp,target;
	int cnt = 0;
	vector<int> v;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	cin >> target;

	sort(v.begin(), v.end());

	int start = 0;
	int end = n - 1;

	while (start != end) {

		temp = v.at(start) + v.at(end);

		if (temp == target) {
			cnt++;
			end--;
			continue;
		}
		else if (temp > target) {
			end--;
			continue;
		}
		else start++;

	}

	cout << cnt;

}
