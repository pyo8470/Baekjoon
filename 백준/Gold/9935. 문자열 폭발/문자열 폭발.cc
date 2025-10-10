#include <iostream>
#include <stack>
#include <string>
using namespace std;

string s; 
string bomb; 
string result;

void checkBomb() {

    string check = "";
    int end = result.size();
    int start = result.size() - bomb.length();

    if (start < 0 || result.empty()) return;

    for (int i = end; i > start; i--) {
        check = result.back() + check;
        result.pop_back();

    }
    if (check == bomb) return;

    for (char c : check) result.push_back(c);
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    cin >> s;
    cin >> bomb;

    for (int i = 0; i < s.length(); i++) {
        result.push_back(s[i]);

        if (result.back() == bomb[bomb.length() - 1]) {
            checkBomb();
        }
    }
    
    if (result.empty()) cout << "FRULA";
    else cout << result;
}
