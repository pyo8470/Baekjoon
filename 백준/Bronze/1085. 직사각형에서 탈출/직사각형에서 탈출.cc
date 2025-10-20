#include <algorithm>
#include <iostream>

using namespace std;


void solve(){
    int x,y,w,h; cin >> x >> y >> w >> h;

    int mx = min(x,w-x);
    int my = min(y,h-y);
    int rst = min(mx,my);

    cout << rst;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve(); 
}