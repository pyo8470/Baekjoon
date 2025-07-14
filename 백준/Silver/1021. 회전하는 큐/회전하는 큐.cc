#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main()
{
    deque<int> q;

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        q.push_back(i);
    }

    int result = 0;
    for (int i = 0; i < M; i++)
    {
        int target;
        cin >> target;

        int index = 0;
        for (; index < q.size(); index++)
        {
            if (q[index] == target)
                break;
        }

        if (index <= q.size() / 2)
        {
            // 왼쪽으로 이동
            while (q.front() != target)
            {
                q.push_back(q.front());
                q.pop_front();
                result++;
            }
        }
        else
        {
            while (q.front() != target)
            {
                q.push_front(q.back());
                q.pop_back();
                result++;
            }
        }

        q.pop_front();
    }
    cout << result;
}
