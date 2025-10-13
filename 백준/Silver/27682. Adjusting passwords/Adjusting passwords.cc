#include <iostream>
#include <vector>
#include <string>
using namespace std;


int getWrongIdx(string origin, string comp) {
    if (origin.length() < comp.length()) {
        swap(origin, comp);
    }
    int i;
    for (i = 0; i < comp.length(); i++) {
        char a = comp[i], b = origin[i];
        if (a != b) return i;
    }
    return i;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; cin >> T;
 
    while (T--) {
        string answer = "";
        string correct, input;
        cin >> correct >> input;

        int c_len = correct.size();
        int i_len = input.size();
        
        // 두 가지 경우가 있다.

        // 1. 처음부터 enter로 밀어버리기
        // 2. 틀린 부분까지 backspace한다음에 옳은 문자열

        int first_idx = getWrongIdx(correct, input);

        int del_len = i_len - first_idx;
        
        // 총 입력 길이(2번 케이스)
        int total_len_with_del = del_len + (c_len - first_idx);
        int total_len_with_ent = 1 + c_len;

        //cout << total_len_with_del << " " << total_len_with_ent << '\n';
        if (total_len_with_del >= total_len_with_ent) {
            cout << "*" + correct + "*" << '\n';
        }
        else {
            while (del_len--) {
                cout << "<";
            }
            cout << correct.substr(first_idx, del_len) + "*" << '\n';
        }
    }
}
