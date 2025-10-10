#include <iostream>
#include <stack>
#include <string>
using namespace std;

string s; 
string bomb; 
string result;

void checkBomb() {

    string check = "";
    int end = result.size()-1;
    int start = result.size() - bomb.length();

    for (int i = end; i >= start; i--) {
        check = result[i] + check;
    }
    if (check != bomb) return; 
    for (int i = 0; i < bomb.size(); i++) result.pop_back();
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    cin >> s;
    cin >> bomb;

    for (int i = 0; i < s.length(); i++) {
        result.push_back(s[i]);

        if (result.back() == bomb[bomb.length() - 1] 
            && result.size() >= bomb.size()) {
            checkBomb();
        }
    }
    
    if (result.empty()) cout << "FRULA";
    else cout << result;
}
