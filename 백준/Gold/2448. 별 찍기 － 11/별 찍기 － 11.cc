#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;


/*
	공백 -> N이 2배씩 늘어날빼마다 공백도 2배씩 늘어남
*/


vector<string> solve(int N) {
    if (N == 3) {
        return { "  *  ",
                 " * * ",
                 "*****" };
    }
    //cout << N << '\n';

    vector<string> star = solve(N / 2);
    vector<string> result;
    // 위쪽
    for (auto& s : star) {
        result.push_back(string(N / 2, ' ') + s + string(N / 2, ' '));
    }
    // 아래쪽
    for (auto& s : star) {
        result.push_back(s + " " + s);
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    
    //solve(N);
    for (auto& s : solve(N)) {
        cout << s << '\n';
    }
}