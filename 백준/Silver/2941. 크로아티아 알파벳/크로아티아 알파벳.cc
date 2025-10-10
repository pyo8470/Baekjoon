#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s; cin >> s;

    int ans = 0;
    int i = 0;
    while(i < s.length()){
        char cur = s[i];
        if (cur == 'c' && i + 1 < s.length()) {
            if (s[i + 1] == '=' || s[i + 1] == '-') {
                ans++;
                i += 2;
                continue;
            }
        }

        if (cur == 'd') {
            if (i + 1 < s.length() && s[i + 1] == '-') {
                ans++;
                i+=2; 
                continue;
            }

            if (i + 2 < s.length() && s[i + 1] == 'z' && s[i+2] == '=') {
                ans++;
                i+=2;
                continue;
            }
        }

        if (cur == 'j') {
            if (i - 1 >= 0 && (s[i - 1] == 'l' || s[i - 1] == 'n')) {
                i++;
                continue;
            }
        }

        if (cur == '=') {
            if (i - 1 >= 0 && (s[i - 1] == 's' || s[i - 1] == 'z')) {
                i++;
                continue;
            }
        }
        
        ans++;      
        i++;
    }
    cout << ans;
}
