#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
#include <set>
using namespace std;
typedef long long ll;

int N, result = INT_MAX;
vector<vector<int>> S;
vector<int> member;
vector<int> teamA;
vector<int> teamB;
// 팀을 다 꾸리기 N/2

int getPower(vector<int> team) {
	vector<pair<int, int>> pairs;
	
	for (int i = 0; i < team.size(); i++) {
		for (int j = i + 1; j < team.size(); j++) {
			pairs.push_back({ team[i],team[j] });
		}
	}
	int power = 0;
	for (pair<int, int> p : pairs) {
		power += (S[p.first][p.second] + S[p.second][p.first]);
	}
	return power;
}
void backtraking(int index,int depth) {
	
	if (depth == N / 2 ) {
	
		teamB.resize(N/2);
		auto it = set_difference(member.begin(), member.end(), teamA.begin(), teamA.end(), teamB.begin());
		//teamB.erase(it, teamB.end()); //남은공간 제거 코드
		int A = getPower(teamA);
		int B = getPower(teamB);
		result = min(result, abs(A - B));
		return;
	}
	
	for (int i = index; i < N; i++) {
		teamA.push_back(i);
		backtraking(i+1,depth + 1);
		teamA.pop_back();
	}
}
int main() {
	cin >> N; S.assign(N, vector<int>(N));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) cin >> S[i][j];

	for (int i = 0; i < N; i++) {
		member.push_back(i);
	}
	backtraking(0,0);

	cout << result;
}
