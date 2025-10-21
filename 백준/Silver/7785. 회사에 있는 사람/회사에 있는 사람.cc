#include <bits/stdc++.h>

#include <functional>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    set<string, greater<string>> entered;
    for (int i = 0; i < n; i++) {
        string name, log;
        cin >> name >> log;

        if (log == "enter")
            entered.insert(name);
        else {
            if (entered.find(name) == entered.end())
                continue;
            entered.erase(name);
        }
    }

    for (auto it = entered.begin(); it != entered.end(); it++) {
        cout << *it << '\n';
    }
}