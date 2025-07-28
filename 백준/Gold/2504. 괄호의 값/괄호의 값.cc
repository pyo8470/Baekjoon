#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int solution(string input) {
    stack<char> stack;
    long long int result = 0;
    long long int point = 1;
    for (int i = 0; i < input.size();i++) {
        char ch = input[i];
        if (ch == '(') {
            point *= 2;
            stack.push(ch);
        }
        else if (ch == '[') {
            point *= 3;
            stack.push(ch);
        }
        else if (ch == ')') {
            if (stack.empty() || stack.top()  != '(') return 0;
            stack.pop();
            if (input[i - 1] == '(') result += point;
            point /= 2;
        }
        else if (ch == ']') {
            if (stack.empty() || stack.top() != '[') return 0;
            stack.pop();
            if(input[i-1] == '[') result += point;
            point /= 3;
        }

        //cout << ch << " " << point << " " <<result << '\n';
    }
 
    
    return !stack.empty() ? 0 : result;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

 
    string input; cin >> input;
    cout << solution(input);
}
