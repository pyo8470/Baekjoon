#include <cctype>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

string input;
string result = "";

bool checkValid(int flag){
    if(flag == 0) {// C++
        if(input[0] == '_' || input[input.size()-1] == '_') return false;

        // 연속된 _ 체크 , 대문자 체크
        
        for(int i=0; i<input.size();i++){
            if(i > 0 && input[i] == '_' && input[i-1] == '_') return false;
            if(isupper(input[i])) return false;
        }
    }
    else{
        if(isupper(input[0])) return false;
    }
    return true;
}
void solve(int flag){
    if(flag == 1){ // 자바
        // C++ 변환
        for(char c : input){
            if(isupper(c)){
                result += "_";
            }
            result.push_back(tolower(c));
        }
    }else{
        // Java 변환
        int is_next_upper = 0;
        for(char c : input){
            if(c == '_'){
                is_next_upper = 1;
                continue;
            }

            if(is_next_upper){
                result.push_back(toupper(c));
                is_next_upper = 0;
            }else{
                result.push_back(c);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;

    int flag;
    if(input.find('_') != string::npos){
        flag = 0;
    }else{
        flag = 1;
    }
    
    if(!checkValid(flag)){
        cout << "Error!"; return 0;
    }
    solve(flag);

    cout << result;
}