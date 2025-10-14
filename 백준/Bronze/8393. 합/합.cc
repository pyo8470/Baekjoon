#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int ans = 0;
    int n; cin >> n; 
    for(int i=0; i<n ;i++) ans += (i+1); 
    cout << ans;  
}
