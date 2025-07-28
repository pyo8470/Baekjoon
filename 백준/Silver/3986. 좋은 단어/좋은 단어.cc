#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int isGood(string st) {
    stack<char> stack;

    for (char ch : st) {
        if (!stack.empty() && stack.top() == ch) stack.pop();
        else stack.push(ch);
    }
    return stack.empty() ? 1 : 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; 
    cin >> N;
    vector<string> st(N);
    int count = 0;
    for (int i = 0; i < N; i++) {
        cin >> st[i];
        count += isGood(st[i]);
    }
    cout << count;
    return 0;
}
