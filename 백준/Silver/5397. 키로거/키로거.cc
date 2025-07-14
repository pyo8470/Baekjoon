#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main()
{
    int T;
    cin >> T;

    stack<char> cursorLeft;
    stack<char> cursorRight;

    for (int i = 0; i < T; i++)
    {
        string input;
        cin >> input;
        for (char ch : input)
        {
            if (ch == '<')
            {
                if (!cursorLeft.empty())
                {
                    cursorRight.push(cursorLeft.top());
                    cursorLeft.pop();
                }
            }
            else if (ch == '>')
            {
                if (!cursorRight.empty())
                {
                    cursorLeft.push(cursorRight.top());
                    cursorRight.pop();
                }
            }
            else if (ch == '-')
            {
                if (!cursorLeft.empty())
                {
                    cursorLeft.pop();
                }
            }
            else
            {
                cursorLeft.push(ch);
            }
        }
        stack<char> printLeft;
        while (!cursorLeft.empty())
        {
            printLeft.push(cursorLeft.top());
            cursorLeft.pop();
        }
        while (!printLeft.empty())
        {
            cout << printLeft.top();
            printLeft.pop();
        }
        while (!cursorRight.empty())
        {
            cout << cursorRight.top();
            cursorRight.pop();
        }
        cout << endl;
    }
}