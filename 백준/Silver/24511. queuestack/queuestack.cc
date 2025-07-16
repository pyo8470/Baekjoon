#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main()
{
    int N, M;
    cin >> N;
    deque<int> queuestack;
    vector<int> type(N);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    for (int i = 0; i < N; i++)
    {
        cin >> type[i];
    }
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (type[i] == 0) // 큐일때만 집어넣음, 스택일 때는 무시해도 되기 때문
            queuestack.push_back(num);
    }
    cin >> M;
    int n;
    for (int index = 0; index < M; index++)
    {

        int input;
        cin >> input;
        queuestack.push_front(input);
        n = queuestack.back();
        queuestack.pop_back();
        cout << n << " ";
    }
}
