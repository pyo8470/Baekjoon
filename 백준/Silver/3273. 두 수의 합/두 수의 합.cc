#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int x;
    cin >> x;

    int l = 0, r = n - 1;
    int count = 0;
    int result = 0;
    while (l < r)
    {
        count = a[l] + a[r];

        // 작다면 왼쪽 포인터를 오른쪽으로
        if (count < x)
            l++;
        // 크다면 오른쪽 포인터를 왼쪽으로
        else if (count > x)
            r--;
        else
        {
            result++;
            l++;
        }
    }
    cout << result;
}