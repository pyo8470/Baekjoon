#include <cctype>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;


void solve() {
    string input; int B;
    cin >> input >> B;
    
    int answer = 0; 

    for(int i=input.size()-1; i>=0; i--){
        char c = input[i];
        
        int num;
        int power = input.size()-1-i;

        if(isdigit(c)){
            num = c-'0';
        }else{
            num = c-'A' + 10;
        }
        
        int add = num*pow(B,power);
        answer += add;
    }
    cout << answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
