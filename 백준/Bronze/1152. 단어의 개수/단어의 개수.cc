#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> arr;
    string s;
    getline(cin, s);

    int start = 0, end;
    while ((end = s.find(" ", start)) != string::npos) {
        string k = s.substr(start, end - start);
        if (!k.empty()) // 연속된 공백 방지
            arr.push_back(k);
        start = end + 1;
    }

    string last = s.substr(start);
    if (!last.empty())
        arr.push_back(last);

    cout << arr.size() << "\n";
}
