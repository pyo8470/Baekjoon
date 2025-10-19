#include <cmath>
#include <iostream>
#include <vector>

using namespace std;


void solve() {
    int T;
    while(1){
        cin >> T; 
        if(T == -1) break;
        
        int sum = 0;
        vector<int> nums;
        for(int i=1; i<= T/2; i++){
            if(T % i == 0) {
                sum += i;
                nums.push_back(i);
            }        
        }
        if(sum == T){
            cout << T << " = ";
            for(int i = 0; i<nums.size() - 1; i++){
                cout << nums[i] << " + ";
            }
            cout << nums[nums.size()-1] << '\n';
        } else{
            cout << T << " is NOT perfect." << '\n'; 
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}

