#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    deque<int> deque;
    vector<int> result;
    for (int i = 0; i < N; i++)
    {
        deque.push_back(i + 1);
    }
    int index = K - 1;
    while (!deque.empty())
    {
        for (int i = 0; i < K - 1; i++)
        {
            deque.push_back(deque.front());
            deque.pop_front();
        }

        result.push_back(deque.front());
        deque.pop_front();
    }
    cout << "<";
    for (int i = 0; i < N - 1; i++)
    {
        cout << result[i] << ", ";
    }
    cout << result[N - 1] << ">";
}