#include <iostream>
#include <queue>
#include <string>

using namespace std;

int COUNT[201] = { 0, };
vector<deque<string>> names;
int SIZE = 201;

struct person {
	int age;
	string name;
};
int main() {
	ios_base::sync_with_stdio(0);

	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;
	names.resize(201, deque<string>());
	for(int i=0; i<N; i++){
		int age; string name;
		cin >> age >> name;
		COUNT[age]++;
		names[age].push_back(name);
	}

	for (int i = 1; i < SIZE; i++) {
		while (COUNT[i]--) {
			cout << i << " " << names[i].front() << '\n';
			names[i].pop_front();
		}
	}

}