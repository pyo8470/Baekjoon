#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;


//실제 노드 개수 33
int nodes[40];
bool visit[40];
int Dice[10];

//항상 첫번째 길로만 이동하도록(파란색을 우선할 수 있도록)
unordered_map<int, vector<int>> adjList;


void createGraph() {

	//점수 초기화
	nodes[2] = 2;
	nodes[3] = 4;
	nodes[4] = 6;
	nodes[5] = 8;
	nodes[6] = 10;
	nodes[7] = 13;
	nodes[8] = 16;
	nodes[9] = 19;
	nodes[10] = 25;
	nodes[11] = 30;
	nodes[12] = 35;
	nodes[13] = 40;
	nodes[14] = 12;
	nodes[15] = 14;
	nodes[16] = 16;
	nodes[17] = 18;
	nodes[18] = 20;
	nodes[19] = 22;
	nodes[20] = 24;
	nodes[21] = 22;
	nodes[22] = 24;
	nodes[23] = 26;
	nodes[24] = 28;
	nodes[25] = 30;
	nodes[26] = 28;
	nodes[27] = 27;
	nodes[28] = 26;
	nodes[29] = 32;
	nodes[30] = 34;
	nodes[31] = 36;
	nodes[32] = 38;


	adjList[0].push_back(2);
	adjList[2].push_back(3);
	adjList[3].push_back(4);
	adjList[4].push_back(5);
	adjList[5].push_back(6);

	adjList[6].push_back(7);
	adjList[6].push_back(14);

	adjList[7].push_back(8);
	adjList[8].push_back(9);
	adjList[9].push_back(10);

	adjList[10].push_back(11);
	adjList[11].push_back(12);
	adjList[12].push_back(13);


	adjList[14].push_back(15);
	adjList[15].push_back(16);
	adjList[16].push_back(17);
	adjList[17].push_back(18);

	adjList[18].push_back(19);
	adjList[18].push_back(21);

	adjList[19].push_back(20);
	adjList[20].push_back(10);

	adjList[21].push_back(22);
	adjList[22].push_back(23);
	adjList[23].push_back(24);
	adjList[24].push_back(25);

	adjList[25].push_back(26);
	adjList[25].push_back(29);

	adjList[26].push_back(27);
	adjList[27].push_back(28);
	adjList[28].push_back(10);

	adjList[29].push_back(30);
	adjList[30].push_back(31);
	adjList[31].push_back(32);
	adjList[32].push_back(13);

	adjList[13].push_back(1);
}

int max_score;

typedef struct {
	int cur_node;
}P;

void dfs(int cur, vector<P>& people, int score) {
	
	
	if (cur == 10) {
		max_score = max(max_score, score);
		return;
	}

	for (int i = 0; i < 4; ++i) {

		int cur_node = people[i].cur_node;

		if (cur_node == 1) continue;

		// 말을 이동 시켜 봄
		int temp = cur_node;
		for (int x = 0; x < Dice[cur]; ++x) {

			if (temp == 1) break;
			if (x == 0) {
				temp = adjList[temp][0];
			}
			else {
				if (adjList[temp].size() == 2) {
					temp = adjList[temp][1];
				}
				else
					temp = adjList[temp][0];
			}
		}

		if (temp != 1 && visit[temp]) continue; // 이미 그 자리에 누가 있으면 pass

		int pre_node = people[i].cur_node;

		
		people[i].cur_node = temp;
		visit[cur_node] = false;
		visit[temp] = true;
		dfs(cur + 1, people, score + nodes[temp]);
		visit[temp] = false;
		visit[cur_node] = true;
		people[i].cur_node = pre_node;

	}

}

int main() {

	for (int i = 0; i < 10; ++i) {
		cin >> Dice[i];
	}

	createGraph();

	vector<P> people(4, {0});

	dfs(0, people, 0);

	cout << max_score << endl;

	return 0;
}