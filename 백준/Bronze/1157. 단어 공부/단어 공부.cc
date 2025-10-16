#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

void solve() {
    string input; cin >> input;
    int DAT[26] = {0,};
    
    int MAX = 0;
    for(char c : input){
        c = tolower(c);
        int idx = c - 'a';
        DAT[idx]++;
        MAX = max(DAT[idx],MAX);
    }

    int count = 0;
    int m_idx;
    for(int i = 0; i < 26; i++){
        if(DAT[i] == MAX) {
            m_idx = i;
            count++;
        }
    }
    
    (count == 1) ? cout << char('A' + m_idx) : cout << "?";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}

