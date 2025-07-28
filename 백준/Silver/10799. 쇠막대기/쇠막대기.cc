#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //시작과 끝이 있다
    stack<char> stack;
    string input; cin >> input;
    int count = 0;
    for (int i = 0; i < input.size(); i++) {
        //레이저인 경우
        if (input[i] == ')') {
            stack.pop();
            if (input[i-1] == '(') { // 레이저인 경우입니다.
                // 막대기의 수만큼 +
                count += stack.size();
            }
            else {
                // 레이저가 아니고 막대기가 끝나는경우
                // 밑에 있는 안 끊어져 있는 막대기는 다음 레이저에서 자르는 걸로 생각한다.
                // 잘린 막대기 하나만 카운트
                count++;
            }
        }
        else {
            stack.push(input[i]);
        }
    }
    // 마지막 막대기 조각 하나

    cout << count;
}
