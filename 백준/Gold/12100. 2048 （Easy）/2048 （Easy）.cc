#include <bits/stdc++.h>
#include <climits>
using namespace std;

enum Direction
{
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3
};
int MAX = INT_MIN;
int N;

void print(vector<vector<int>> board)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void move(vector<vector<int>> &board, Direction dir)
{

    switch (dir)
    {
    case UP:
        // 위로 이동 처리
        for (int col = 0; col < N; col++)
        {
            int index = 0; // 채워질 위치 (맨 위부터)
            for (int row = 0; row < N; row++)
            {
                if (board[row][col] != 0)
                {
                    if (row != index) // 바꿀 수 없는 위치에 있음 -> 냅두기
                    {
                        board[index][col] = board[row][col];
                        board[row][col] = 0;
                    }
                    index++;
                }
            }
        }
        break;
    case DOWN: // 아래로 이동 처리
        for (int col = 0; col < N; col++)
        {
            int index = N - 1;
            for (int row = N - 1; row >= 0; row--)
            {
                if (board[row][col] != 0)
                {
                    if (row != index) // 바꿀 수 없는 위치에 있음 -> 냅두기
                    {
                        board[index][col] = board[row][col];
                        board[row][col] = 0;
                    }
                    index--;
                }
            }
        }
        break;

    //
    case LEFT: // 왼쪽으로 이동 처리

        for (int row = 0; row < N; row++)
        {
            int index = 0;
            for (int col = 0; col < N; col++)
            {
                if (board[row][col] != 0)
                {
                    if (col != index) // 바꿀 수 없는 위치에 있음 -> 냅두기
                    {
                        board[row][index] = board[row][col];
                        board[row][col] = 0;
                    }
                    index++;
                }
            }
        }

        break;
    case RIGHT:
        // 오른쪽으로 이동 처리
        for (int row = 0; row < N; row++)
        {
            int index = N - 1;
            for (int col = N - 1; col >= 0; col--)
            {
                if (board[row][col] != 0)
                {
                    if (col != index) // 바꿀 수 없는 위치에 있음 -> 냅두기
                    {
                        board[row][index] = board[row][col];
                        board[row][col] = 0;
                    }
                    index--;
                }
            }
        }
        break;
    default:
        break;
    }
}
void merge(vector<vector<int>> &board, Direction dir)
{
    switch (dir)
    {
    case UP:
        /* code */

        for (int col = 0; col < N; col++)
        {
            int row = 0; // 채워질 위치 (맨 위부터)
            while (row < N - 1)
            {
                int currentNum = board[row][col];
                int nextNum = board[row + 1][col];
                if (currentNum != 0 && currentNum == nextNum)
                {
                    board[row][col] *= 2;
                    board[row + 1][col] = 0;
                    row += 2; // 병합된 경우는 다음 다음 칸으로
                }
                else
                {
                    row++; // 병합 불가능하면 그냥 다음 칸
                }
            }
        }

        break;
    case DOWN:
        /* code */
        for (int col = 0; col < N; col++)
        {
            int row = N - 1; // 채워질 위치 (맨 아래부터)
            while (row > 0)
            {
                int currentNum = board[row][col];
                int nextNum = board[row - 1][col];

                if (currentNum != 0 && currentNum == nextNum)
                {
                    board[row][col] *= 2;
                    board[row - 1][col] = 0;
                    row -= 2; // 병합된 경우는 다음 다음 칸으로
                }
                else
                {
                    row--; // 병합 불가능하면 그냥 다음 칸
                }
            }
        }
        break;

    case LEFT:
        /* code */
        for (int row = 0; row < N; row++)
        {
            int col = 0; // 채워질 위치 (맨 위부터)
            while (col < N - 1)
            {
                int currentNum = board[row][col];
                int nextNum = board[row][col + 1];

                if (currentNum != 0 && currentNum == nextNum)
                {
                    board[row][col] *= 2;
                    board[row][col + 1] = 0;
                    col += 2; // 병합된 경우는 다음 다음 칸으로
                }
                else
                {
                    col++; // 병합 불가능하면 그냥 다음 칸
                }
            }
        }
        break;

    case RIGHT:
        /* code */
        for (int row = 0; row < N; row++)
        {
            int col = N - 1; // 채워질 위치 (맨 위부터)
            while (col > 0)
            {
                int currentNum = board[row][col];
                int nextNum = board[row][col - 1];

                if (currentNum != 0 && currentNum == nextNum)
                {
                    board[row][col] *= 2;
                    board[row][col - 1] = 0;
                    col -= 2; // 병합된 경우는 다음 다음 칸으로
                }
                else
                {
                    col--; // 병합 불가능하면 그냥 다음 칸
                }
            }
        }
        break;

    default:
        break;
    }
}
void solve(vector<vector<int>> board, int depth)
{
    // 움직임 처리
    if (depth == 5)
    {
        int M = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                M = max(M, board[i][j]);
            }
        }

        MAX = max(M, MAX);
        return;
    }

    for (int dir = 0; dir < 4; ++dir)
    {
        Direction d = static_cast<Direction>(dir);
        vector<vector<int>> newBoard(board);
        // printf("방향 %d\n", dir);
        move(newBoard, d);
        merge(newBoard, d);
        move(newBoard, d);
        solve(newBoard, depth + 1);
    }
}
int main()
{
    cin >> N;

    vector<vector<int>> board(N, (vector<int>(N)));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    solve(board, 0);

    cout << MAX;
}