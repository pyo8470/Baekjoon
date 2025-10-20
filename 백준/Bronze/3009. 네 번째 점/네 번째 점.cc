#include <iostream>
#include <unordered_map>
using namespace std;



void solve(){
    unordered_map<int, int> X_map;
    unordered_map<int, int> Y_map;

    int rx, ry;
    for(int i=0; i<3; i++){
        int x, y; cin >> x >> y;
        X_map[x] += 1;
        Y_map[y] += 1;
    }

    for(auto it = X_map.begin(); it != X_map.end(); it++){
        if (it->second == 1) rx = it->first;
    }

    for(auto it = Y_map.begin(); it != Y_map.end(); it++){
        if (it->second == 1) ry = it->first;
    }

    cout << rx << " " << ry;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve(); 
}