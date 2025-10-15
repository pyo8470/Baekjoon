#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// 문자열을 구분자로 나누는 함수
vector<string> split(const string& input) {
    vector<string> ret;
    string token;
    istringstream iss(input);
    while (iss >> token) {
        ret.push_back(token);
    }
    return ret;
}

// 등급 → 점수 변환
double gradeToScore(const string& grade) {
    if (grade == "A+") return 4.5;
    if (grade == "A0") return 4.0;
    if (grade == "B+") return 3.5;
    if (grade == "B0") return 3.0;
    if (grade == "C+") return 2.5;
    if (grade == "C0") return 2.0;
    if (grade == "D+") return 1.5;
    if (grade == "D0") return 1.0;
    return 0.0;
}

// 주 로직
void solve() {
    string input;
    double totalScore = 0.0;  // 학점 × 점수의 합
    double totalCredit = 0.0; // 학점의 합

    while (getline(cin, input)) {
        vector<string> li = split(input);
        if (li.size() < 3) continue;   // 안전장치
        string subject = li[0];
        double credit = stod(li[1]);   // 학점 (예: "3.0" → 3.0)
        string grade = li[2];
        
        if (grade == "P") continue;    // Pass 과목은 계산 제외
        totalScore += credit * gradeToScore(grade);
        totalCredit += credit;
    }
    
    double gpa = totalScore / totalCredit;
    cout << fixed;
    cout.precision(6);  // 소수점 6자리까지 출력
    cout << gpa << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}

