#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    unordered_map<string, int> pokenum;
    unordered_map<int, string> numpoke;

    for (int i = 1; i <= N; ++i) {
        string name;
        cin >> name;
        pokenum[name] = i;
        numpoke[i] = name;
    }

    for (int i = 0; i < M; ++i) {
        string query;
        cin >> query;

        // 첫 글자가 숫자면 무조건 숫자
        if (isdigit(query[0])) {
            cout << numpoke[stoi(query)] << '\n';
        }
        else {
            cout << pokenum[query] << '\n';
        }
    }

    return 0;
}
