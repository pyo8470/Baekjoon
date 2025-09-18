#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<set>
using namespace std;

int N, M;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	unordered_set<string> listen;
	listen.reserve(N+5);

	for (int i = 0; i < N; i++) {
		string name; cin >> name;
		listen.insert(name);
	}

	set<string> result;
	for (int i = 0; i < M; i++) {
		string name; cin >> name;
		if (listen.find(name) != listen.end())
			result.insert(name);			
	}

	cout << result.size()<<'\n';
	for (auto it = result.begin(); it != result.end(); it++) {
		cout << *it << '\n';
	}

}