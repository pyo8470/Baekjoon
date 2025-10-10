#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int N;
vector<string> str;

void init() {
    cin >> N; str.assign(N, "");
    for (int i = 0; i < N; i++) cin >> str[i];
}
int solve() {
    int ret = 0;
    for (string st : str) {
        unordered_set<char> s;

        s.insert(st[0]);

        bool flag = true;
        for (int i = 1; i < st.length(); i++) {
            char cur = st[i];
            char prev = st[i - 1];

            if (cur == prev) continue;
            if (s.find(cur) != s.end()) {
                flag = false;
                break;
            }
            s.insert(cur);

        }
        if (flag) ret++;
   }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    init();
    cout << solve();

}
