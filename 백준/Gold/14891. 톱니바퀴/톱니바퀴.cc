#include <bits/stdc++.h>
#include <climits>
using namespace std;

int N = 4;
int M = 8;
void rotation(vector<deque<char>> &wheel, int num, int dir);
void solve(vector<deque<char>> &wheel, int number, int dir);
void print(vector<deque<char>> wheel)
{
    for (int i = 0; i < N; i++)
    {
        cout << i + 1 << "번: ";
        for (int j = 0; j < M; j++)
        {
            cout << wheel[i][j] << " ";
        }
        cout
            << endl;
    }
    cout << endl;
}
int main()
{
    vector<deque<char>> wheel(N, deque<char>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> wheel[i][j];
        }
    }
    int K;
    cin >> K;
    // print(wheel);
    for (int i = 0; i < K; i++)
    {
        // 1 : 시계 방향, -1 : 반시계 방향
        int number, dir;
        cin >> number >> dir;
        number -= 1;
        solve(wheel, number, dir);
    }

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (wheel[i][0] == '1')
            sum += (1 << i);
    }
    cout << sum;
}
void solve(vector<deque<char>> &wheel, int number, int dir)
{
    // 해당 바퀴 회전
    int checkIndex[2] = {2, 6};
    vector<pair<bool, int>> RotateNubmer(N);
    RotateNubmer[number] = {true, dir};

    // print(wheel);

    // cout << number << " " << dir << endl;

    // 회전시킬지 말지 정하는 배열
    // (참,거짓/방향)

    // 오른쪽 전파(같지 않을 때 + 맨 오른쪽이 아닐 때)
    int cRightNum = number;
    int rightDir = dir;
    while (cRightNum < 3)
    {
        // 같지 않으면 회전
        bool isRotate = wheel[cRightNum][checkIndex[0]] != wheel[cRightNum + 1][checkIndex[1]];
        if (!isRotate)
        {
            break;
        }
        cRightNum++;
        rightDir *= -1;
        RotateNubmer[cRightNum] = {true, rightDir};
    }
    // 왼쪽 전파
    int cLeftNum = number;
    int leftDir = dir;
    while (cLeftNum > 0)
    {
        bool isRotate = wheel[cLeftNum][checkIndex[1]] != wheel[cLeftNum - 1][checkIndex[0]];
        if (!isRotate)
        {
            break;
        }
        cLeftNum--;
        leftDir *= -1;
        RotateNubmer[cLeftNum] = {true, leftDir};
    }

    // 전파

    for (int i = 0; i < N; i++)
    {
        pair<bool, int> k = RotateNubmer[i];
        {
            if (k.first)
            {
                rotation(wheel, i, k.second);
            }
        }
    }
}
void rotation(vector<deque<char>> &wheel, int num, int dir)
{
    if (dir == 1)
    {
        char temp = wheel[num].back();
        wheel[num].pop_back();
        wheel[num].push_front(temp);
    }
    // 반 시계 방향
    else
    {
        char temp = wheel[num].front();
        wheel[num].pop_front();
        wheel[num].push_back(temp);
    }
    // print(wheel);
}