#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // A^2 - B^2 = G

    // 구해야 하는 것 B의 목록


    int G; cin >> G;
    vector<int> ans;

    // current^2 = G + prev^2;
    
    int l = 1, r = 2;
    
    while (l < r) {
        int prev = l * l;
        int current = r * r;
        
        int diff = current - prev;
        
        if (diff <= G) {
            if (diff == G) {
                ans.push_back(r);
            }
            r++;
        }
        else {
            l++;
        }
    }
    
    if (ans.empty()) {
        cout << -1; return 0;
    }
    for (int d : ans) {
        cout << d << "\n";
    }
}
