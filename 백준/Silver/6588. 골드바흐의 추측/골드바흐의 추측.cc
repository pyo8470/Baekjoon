#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

const int MAX = 1000001;
bool prime[MAX];

inline void change_bool(int start, int acc, bool flag);
void eratosthenes()
{
    fill(prime, prime + MAX, true);
    prime[0] = prime[1] = false;

    int limit = (int)(sqrt(MAX)) + 1;
    for (int i = 2; i < limit; i++)
    {
        if (prime[i])
        {
            change_bool(i*i, i, false);
        }
    }
}

inline void change_bool(int start, int acc, bool flag)
{
    for (int i = start;i < MAX; i += acc)
    {
        prime[i] = flag;
    }
}

int main()
{
    eratosthenes();

    int n;
    cin >> n;
    while (n > 0)
    {
        for (int a = 3; a <= (int)n / 2; a++)
        {
            int b = n - a;
            if (prime[a] && prime[b])
            {
                printf("%d = %d + %d\n", n, a, b);
                break;
            }
        }
        scanf("%d", &n);
    }
}