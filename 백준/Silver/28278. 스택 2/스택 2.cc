#include <iostream>
#include <stack>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    stack<int> st;
    while (N--) {
        int cmd;
        cin >> cmd;
        int num;
        switch (cmd) {
            case 1: {
                cin >> num;
                st.push(num);
                break;
            }
            case 2: {
                if (st.empty())
                    cout << -1;
                else {
                    cout << st.top();
                    st.pop();
                }
                cout << '\n';
                break;
            }
            case 3: {
                cout << st.size();
                cout << '\n';
                break;
            }
            case 4: {
                if (st.empty())
                    cout << 1;
                else
                    cout << 0;
                cout << '\n';
                break;
            }
            case 5: {
                if (st.empty())
                    cout << -1;
                else
                    cout << st.top();
                cout << '\n';
                break;
            }
        }
    }
}