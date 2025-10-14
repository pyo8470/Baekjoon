#include <iostream>

using namespace std;

int solved(int a, int b, int c){
    if(a == b && b == c){
        return 10000 + a * 1000;
    }else{
        if(a==b) return 1000 + a*100;
        else if(a == c) return 1000 + a*100;
        else if(b == c) return 1000 + b*100;
        else{
            int m = max(a,b);
            m = max(m,c);
            return m*100;
        }
    }
}int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a,b,c; cin >> a >> b >> c;
    cout << solved(a, b, c);
}