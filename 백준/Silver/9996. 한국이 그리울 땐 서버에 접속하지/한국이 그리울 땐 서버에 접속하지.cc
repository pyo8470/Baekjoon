#include <iostream>
#include <string>
using namespace std;

string solve(const string& input, const string& front, const string &back) {
    int input_size = input.size();

    if (front.size() + back.size() > input_size) return "NE";
    for (int i = 0; i < front.size(); i++) {
        if (input[i] != front[i]) return "NE";
    }

    for (int i = 0; i < back.size(); i++) {
        if (input[input_size - i - 1] != back[i]) return "NE";
    }
    return "DA";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;

    string regex; cin >> regex;

    string front = "", back="";
    for (int i = 0; ; i++) {
        if (regex[i] == '*') break;
        front.push_back(regex[i]);
    }
    for (int i = regex.length() - 1; ; i--) {
        if (regex[i] == '*') break;
        back.push_back(regex[i]);
    }
    while (N--) {
        string input; cin >> input;

        cout << solve(input, front, back) << '\n';
    }
}
