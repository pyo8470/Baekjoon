#include <bits/stdc++.h>
#include <climits>
using namespace std;

int N, M;
vector<vector<pair<int, int>>> Iblock;
vector<vector<pair<int, int>>> Oblock;
vector<vector<pair<int, int>>> Lblock;
vector<vector<pair<int, int>>> Sblock;
vector<vector<pair<int, int>>> Tblock;

int find(int x, int y, vector<vector<int>> &board, vector<vector<pair<int, int>>> &block)
{
    int MAX = 0;
    for (int i = 0; i < block.size(); i++)
    {
        int sum = 0;
        bool valid = true;
        for (int j = 0; j < 4; j++)
        {

            pair<int, int> dir = block[i][j];
            int dx = dir.first, dy = dir.second;

            int nx = x + dx, ny = y + dy;

            if (nx < 0 || nx >= M || ny < 0 || ny >= N)
            {
                sum = 0;
                break;
            }
            sum += board[ny][nx];
        }
        MAX = max(sum, MAX);
    }

    return MAX;
}
int main()
{

    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }
    // I 블록 - > 시작점으로부터 아래로 1,2,3, 우로 1,2,3
    Iblock = {{{0, 0}, {0, 1}, {0, 2}, {0, 3}},
              {{0, 0}, {1, 0}, {2, 0}, {3, 0}}};
    // O 블록 -> 시작점으로 부터 (1,0) (0,1) (1,1)

    Oblock.push_back({{0, 0}, {0, 1}, {1, 0}, {1, 1}});
    // L 블록
    /*
        X O X         X   X
          O           O O O
        X O X         X   X
    */

    Lblock = {
        {{0, 0}, {0, 1}, {0, 2}, {1, 2}},  // 회전 상태 0
        {{0, 0}, {0, 1}, {0, 2}, {-1, 2}}, // 회전 상태 1
        {{0, 0}, {0, 1}, {0, 2}, {-1, 0}}, // 회전 상태 2
        {{0, 0}, {0, 1}, {0, 2}, {1, 0}},  // 회전 상태 3

        {{0, 0}, {1, 0}, {2, 0}, {0, -1}}, // 회전 상태 4
        {{0, 0}, {1, 0}, {2, 0}, {0, 1}},  // 회전 상태 5
        {{0, 0}, {1, 0}, {2, 0}, {2, -1}}, // 회전 상태 6
        {{0, 0}, {1, 0}, {2, 0}, {2, 1}}   // 회전 상태 7

    };

    // S 블록 -> 시작점으로 부터 (1,0) (0,1) (1,1)
    /*
        X K
        O O    X O K
        K X    K O X
    */

    Sblock = {
        {{0, 0}, {1, 0}, {1, -1}, {0, 1}},
        {{0, 0}, {1, 0}, {0, -1}, {1, 1}},
        {{0, 0}, {0, 1}, {1, 0}, {-1, 1}},
        {{0, 0}, {0, 1}, {1, 1}, {-1, 0}}};

    Tblock = {
        {{0, 0}, {1, 0}, {2, 0}, {1, 1}},  // ㅜ
        {{0, 0}, {1, 0}, {2, 0}, {1, -1}}, // ㅗ
        {{0, 0}, {0, 1}, {0, -1}, {1, 0}}, // ㅏ
        {{0, 0}, {1, 0}, {1, 1}, {1, -1}}  // ㅓ
    };

    int MAX = INT_MIN;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            MAX = max(MAX, find(x, y, board, Iblock));
            MAX = max(MAX, find(x, y, board, Oblock));
            MAX = max(MAX, find(x, y, board, Lblock));
            MAX = max(MAX, find(x, y, board, Sblock));
            MAX = max(MAX, find(x, y, board, Tblock));
        }
    }
    cout << MAX << endl;
}