#include <bits/stdc++.h>
#include <climits>
using namespace std;

int N, L, R;

// 상하좌우
int directX[4] = {0, 0, -1, 1};
int directY[4] = {-1, 1, 0, 0};
int result = 0;

void print(vector<vector<int>> &nations)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << nations[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
bool bfs(int x, int y, vector<vector<int>> &nations, vector<vector<bool>> &visited)
{
    // x y
    deque<pair<int, int>> q;
    vector<pair<int, int>> member_cood;

    q.push_back({x, y});
    member_cood.push_back({x, y});
    int total = 0;
    while (!q.empty())
    {

        pair<int, int> cur = q.front();
        int cx = cur.first, cy = cur.second;
        total += nations[cy][cx];
        visited[cy][cx] = true;
        q.pop_front();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + directX[i];
            int ny = cy + directY[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (visited[ny][nx])
                continue;
            // 국경체크
            int pCur = nations[cy][cx], pNext = nations[ny][nx];
            int diff = abs(pCur - pNext);
            if (diff <= R && diff >= L)
            {
                q.push_back({nx, ny});
                member_cood.push_back({nx, ny});
                visited[ny][nx] = true;
            }
        }
    }

    // 연합 x
    if (member_cood.size() == 1)
        return false;

    for (pair<int, int> coord : member_cood)
    {
        int cx = coord.first, cy = coord.second;

        nations[cy][cx] = (int)(total / member_cood.size());
    }

    return true;
}
int main()
{

    cin >> N >> L >> R;
    vector<vector<int>> nations(N);
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int num;
            cin >> num;
            nations[i].push_back(num);
        }
    }

    while (true)
    {
        bool move = false;
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < N; y++)
            {
                if (!visited[y][x])
                {
                    if (bfs(x, y, nations, visited))
                    {
                        move = true;
                    }
                }
            }
        }
        if (!move)
            break;
        count++;

        // print(nations);
    }
    cout << count;
}