#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;


unordered_map<string, int> algorithm;
unordered_map<string, int> person;
int N, M, Q;

string extractName(string query) {
	int i = 0;
	string name = "";
	while (i < query.size()&& query[i] != ' ') {
		name += query[i];
		i++;
	}
	return name;
}
void solve(string name) {
	vector<pair<int, string>> ordered;

	int tier = person[name];
	
	for (auto it = algorithm.begin(); it != algorithm.end(); it++) {
		int diff = abs(it->second - tier);
		ordered.push_back({ diff,it->first });
	}

	sort(ordered.begin(), ordered.end(), [](pair<int, string> a, pair<int, string> b) {
		return (a.first < b.first) ||
			(a.first == b.first && a.second < b.second);
		});
	
	cout << ordered[1].second << " yori mo " << ordered[0].second <<'\n';
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string name; int diff;
		cin >> name >> diff;
		algorithm.insert({ name,diff });
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		string name; int tier;
		cin >> name >> tier;
		person.insert({ name,tier });
	}
	cin >> Q;
	string name;
	string query;
	cin.ignore();
	for (int i = 0; i < Q; i++) {
		getline(cin, query);
		if (query == "nani ga suki?") {
			solve(name);
		}
		else{
			cout << "hai!" << '\n';
			name = extractName(query);	
		}
	}
}
