#include <bits/stdc++.h>
#include <climits>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        int n;
        string p;

        cin >> p;
        cin >> n;
        deque<int> arr;
        string input;
        cin >> input;
        string num = "";
        for (char ch : input)
        {
            if (isdigit(ch))
            {
                num += ch;
            }
            else if (!num.empty())
            {
                arr.push_back(stoi(num));
                num = "";
            }
        }

        bool flag = true;
        bool reversed = false;
        for (char command : p)
        {
            // 연속적인 R 탐색
            if (command == 'R')
            {
                reversed = !reversed;
            }
            else
            {
                if (arr.size() > 0)
                {
                    if (!reversed)
                    {
                        arr.pop_front();
                    }
                    else
                    {
                        arr.pop_back();
                    }
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
        {
            cout << '[';
            if (reversed)
                reverse(arr.begin(), arr.end());
            for (int i = 0; i < arr.size(); i++)
            {
                cout << arr[i];
                if (i != (arr.size() - 1))
                {
                    cout << ',';
                }
            }
            cout << ']' << endl;
        }
        else
        {
            cout << "error" << endl;
        }
    }
}
