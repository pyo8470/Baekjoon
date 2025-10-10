#include <iostream>
#include <stack>
using namespace std;


string solve() {
    stack<char> st;
    string input; cin >> input;

    for (char ch : input) {
        if (ch == '(') st.push(ch);
        else {
            if (st.empty()) return "NO";
            st.pop();
        }
    }

    if (!st.empty())  return "NO";
    return "YES";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cout << solve() << '\n';
    }

}
