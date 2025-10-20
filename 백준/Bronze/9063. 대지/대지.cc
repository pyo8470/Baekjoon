#include <iostream>
using namespace std;



void solve(){
    int N;
    int lx = 2e9,rx = -2e9;
    int ly = 2e9,ry = -2e9;

    cin >> N;
    for(int i=0; i<N; i++){
        int x,y; cin >> x >> y;
        lx = min(x,lx); rx = max(x,rx);
        ly = min(y,ly); ry = max(y,ry);
    }

    int rst = (rx-lx) * (ry-ly);
    cout << rst;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve(); 
}