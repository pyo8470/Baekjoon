#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
	int N;
	cin >> N;
	auto compare = [](string a, string b) {
		if (a.size() == b.size()) {
			return a < b;
		}
		else return a.size() < b.size();
		};
	set<string, decltype(compare)>dict(compare);

	for (int i = 0; i < N; i++) {
		string k; cin >> k;
		dict.insert(k);
	}

	for(const auto k : dict){
		cout << k << "\n";
	}
}
