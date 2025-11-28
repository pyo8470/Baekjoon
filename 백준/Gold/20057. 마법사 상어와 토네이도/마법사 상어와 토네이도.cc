#include <iostream>


using namespace std;

int N;

int sandMap[500][500];

void input() {
	cin >> N;
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			cin >> sandMap[x][y];
		}
	}
}

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int c_x;
int c_y;
int c_d;
int moveDist = 1;

int mask[4][5][5] = {
	{
		{0, 0, 2, 0, 0},
		{0, 10, 7, 1, 0},
		{5, -1, 0, 0, 0},
		{0, 10, 7, 1, 0},
		{0, 0, 2, 0, 0}
	},
	{
		{0, 0, 0, 0, 0},
		{0, 1, 0, 1, 0},
		{2, 7, 0, 7, 2},
		{0, 10, -1, 10, 0},
		{0, 0, 5, 0, 0}
	},
	{
		{0, 0, 2, 0, 0},
		{0, 1, 7, 10, 0},
		{0, 0, 0, -1, 5},
		{0, 1, 7, 10, 0},
		{0, 0, 2, 0, 0}
	},
	{
		{0, 0, 5, 0, 0},
		{0, 10, -1, 10, 0},
		{2, 7, 0, 7, 2},
		{0, 1, 0, 1, 0},
		{0, 0, 0, 0, 0}
	}
};

void move() {
	c_x += dx[c_d];
	c_y += dy[c_d];
}

int answer = 0;


// 이동 후: c_x, c_y
void moveSand() {

	int total_sand = sandMap[c_x][c_y];
	int temp = 0;
	int alpha_dx, alpha_dy;
	int ab_x, ab_y;

	for (int x = -2; x <= 2; ++x) {
		for (int y = -2; y <= 2; ++y) {

			if (mask[c_d][x + 2][y + 2] == -1) {
				alpha_dx = x;
				alpha_dy = y;
				continue;
			}

			ab_x = c_x + x;
			ab_y = c_y + y;

			int ret = total_sand * mask[c_d][x + 2][y + 2] / 100;
			temp += ret;

			// 영역 밖을 벗어남
			if (ab_x < 0 || ab_x >= N || ab_y < 0 || ab_y >= N) {
				answer += ret;
			}
			else {
				sandMap[ab_x][ab_y] += ret;
			}

			
		}
	}
	sandMap[c_x][c_y] = 0;
	
	ab_x = c_x + alpha_dx;
	ab_y = c_y + alpha_dy;
	if (ab_x < 0 || ab_x >= N || ab_y < 0 || ab_y >= N) {
		answer += total_sand - temp;
	}
	else {
		sandMap[ab_x][ab_y] += total_sand - temp;
	}
	
}


int main() {
	input();

	c_x = N / 2;
	c_y = N / 2;
	c_d = 0;
	moveDist = 1;

	while (moveDist != N - 1) {
		for (int i = 0; i < moveDist; ++i) {
			move();
			moveSand();
		}

		c_d = (c_d + 1) % 4;
		
		for (int i = 0; i < moveDist; ++i) {
			move();
			moveSand();
		}

		c_d = (c_d + 1) % 4;

		moveDist += 1;
	}

	for (int i = 0; i < moveDist; ++i) {
		move();
		moveSand();
	}

	c_d = (c_d + 1) % 4;

	for (int i = 0; i < moveDist; ++i) {
		move();
		moveSand();
	}

	c_d = (c_d + 1) % 4;

	for (int i = 0; i < moveDist; ++i) {
		move();
		moveSand();
	}

	c_d = (c_d + 1) % 4;

	cout << answer << endl;
	return 0;
}