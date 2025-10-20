#include <iostream>
using namespace std;



void solve(){
    int a,b,c; cin >> a >> b >> c;

    if((a+b+c) == 180){
        if( a == b && b == c){
        // 정삼각형 
            cout << "Equilateral";
        }
        else if( a != b && b != c && a != c){
        // 같은게 없음
            cout << "Scalene";
        }else{
            cout << "Isosceles";
        }
    }else{
        cout << "Error";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve(); 
}