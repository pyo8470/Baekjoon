#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;


void solve(){
    unordered_set<int> s;
    for(int i=1; i<=30; i++) s.insert(i);
    for(int i=0; i<28; i++){
        int stu; cin >> stu;
        s.erase(stu);
    }

    set<int> os(s.begin(),s.end());
    for(int i : os) cout << i << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
