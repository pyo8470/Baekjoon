#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_N 20
#define MAX_M 20

int N, M, K;
int x, y;

int MAP[MAX_N][MAX_M];
vector<int> command;

struct dice {
	int bot, top;
	int up, down, left, right;
};

dice d;
bool diceMove(const int& comm);
void init();
void solve();
void print() {
	cout << "주사위\n";
	cout << " |" << d.up << "|" << '\n';
	cout << d.left << "|" << d.bot << "|" << d.right << '\n';
	cout << " |" << d.down << "|" << '\n';
	cout << " |" << d.top << "|" << '\n';
}

void init() {
	cin >> N >> M >> y >> x >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}

	command.resize(K);
	for (int i = 0; i < K; i++) cin >> command[i];

	d = { 0,0,0,0,0,0 };
}

void solve() {

	for (int& c : command) {
		if (diceMove(c)) {
			cout << d.top << '\n';
			//print();
		}
	}
}
void draw(const int& num) {
	if (num == 0) {
		MAP[y][x] = d.bot;
	}
	else {
		d.bot = MAP[y][x];
		MAP[y][x] = 0;
	}
}
bool diceMove(const int& comm) {
	switch (comm) {
	case 1: { // 동쪽
		int nx = x + 1;
		if (nx >= M) return false;

		x = nx;
		int num = MAP[y][x];

		d = { d.right,d.left,d.up,d.down,d.bot,d.top };
		draw(num);
		break;
	}
	case 2: { // 서쪽
		int nx = x - 1;
		if (nx < 0) return false;

		x = nx;
		int num = MAP[y][x];
		d = { d.left,d.right,d.up,d.down,d.top,d.bot };
		draw(num);

		break;
	}
	case 3: { // 북쪽
		int ny = y - 1;
		if (ny < 0) return false;

		y = ny;
		int num = MAP[y][x];
		d = { d.up,d.down,d.top,d.bot,d.left,d.right };

		draw(num);

		break;
	}
	case 4: { // 남쪽
		int ny = y + 1;
		if (ny >= N) return false;

		y = ny;
		int num = MAP[y][x];
		d = { d.down,d.up,d.bot,d.top,d.left,d.right };
		draw(num);
		break;
	}
	default:break;
	}

	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();
	solve();
}
