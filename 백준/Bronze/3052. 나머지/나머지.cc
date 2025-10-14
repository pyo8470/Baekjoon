#include <iostream>
#include <unordered_set>
using namespace std;


void solve(){
    unordered_set<int> s;
    for(int i=0; i<10; i++){
        int a; cin >> a;
        s.insert(a%42);
    }

    cout << s.size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}