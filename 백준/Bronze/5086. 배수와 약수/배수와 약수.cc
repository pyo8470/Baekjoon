#include <cmath>
#include <iostream>

using namespace std;


string decide(const int& a, const int& b){
    if(a > b && a % b == 0) return "multiple";
    if(a < b && b % a == 0) return "factor";
    return "neither";
}

void solve() {
   while(1){
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0) break;

        cout << decide(a,b) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}

