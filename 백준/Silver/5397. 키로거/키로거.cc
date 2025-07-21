#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main()
{
    int tc;
    cin >> tc;

    for (int t = 0; t < tc; t++)
    {
        string input;
        cin >> input;
        deque<char> left;
        deque<char> right;
        for (char ch : input)
        {
            if (ch == '<')
            {
                if (!left.empty())
                {
                    right.push_front(left.back());
                    left.pop_back();
                }
            }
            else if (ch == '>')
            {
                if (!right.empty())
                {
                    left.push_back(right.front());
                    right.pop_front();
                }
            }
            else if (ch == '-')
            {
                if (!left.empty())
                    left.pop_back();
            }
            else
            {
                left.push_back(ch);
            }
        }
        for (char ch : left)
        {
            cout << ch;
        }
        for (char ch : right)
        {
            cout << ch;
        }
        cout << endl;
    }
}