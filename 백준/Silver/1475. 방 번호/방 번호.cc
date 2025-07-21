#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main()
{
    string number;
    cin >> number;

    int counts[10] = {
        0,
    };

    for (char ch : number)
    {
        counts[(ch - '0')]++;
    }
    int result = 0;
    int six_and_nine = ceil(double(counts[6] + counts[9]) / 2);
    counts[6] = six_and_nine;
    counts[9] = six_and_nine;

    for (int i = 0; i < 10; i++)
    {
        result = max(result, counts[i]);
    }
    cout << result;
}