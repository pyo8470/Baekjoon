#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int cost;
    int result = -INT_MAX;
    int P[M];

    for (int i = 0; i < M; i++)
    {
        cin >> P[i];
    }

    sort(P, P + M);

    int except = 0;

    for (int p : P)
    {

        //
        int person = M - except;
        int Number = min(N, person);

        if (result < p * Number)
        {
            result = p * Number;
            cost = p;
        }
        result = max(result, p * Number);
        except++;
    }
    printf("%d %d", cost, result);
}