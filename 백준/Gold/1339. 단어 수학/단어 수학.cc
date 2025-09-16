#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>
#include <cmath>
using namespace std;

int N;
vector<string> words;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unordered_map<char, long long> alpha_wei_map; // 알파벳 -> 가중치
    unordered_map<char, int> alpha_num_map;       // 알파벳 -> 숫자
    set<pair<long long, char>, greater<pair<long long, char>>> alpha_wei_set; // 가중치 정렬용

    int maxLen = 0;
    cin >> N;
    words.assign(N, "");
    for (int i = 0; i < N; i++) {
        cin >> words[i];
        maxLen = max((int)words[i].length(), maxLen);
    }

    for (string& word : words) {
        while ((int)word.length() < maxLen) {
            word = " " + word;
        }
    }

    // 가중치 부여 (10진법 자리수)
    for (string& word : words) {
        for (int idx = 0; idx < maxLen; idx++) {
            if (word[idx] == ' ') continue;
            int weight = maxLen - idx - 1; // 자리수 (0=일의 자리)
            alpha_wei_map[word[idx]] += (long long)pow(10, weight);
        }
    }

    // 가중치 정렬
    for (auto& it : alpha_wei_map) {
        alpha_wei_set.insert({ it.second, it.first });
    }

    // 숫자 배정 (가중치 높은 알파벳부터 9,8,7,...)
    int num = 9;
    for (auto& it : alpha_wei_set) {
        alpha_num_map[it.second] = num--;
    }

    // 계산
    long long total = 0;
    for (string& word : words) {
        long long val = 0;
        for (int idx = 0; idx < maxLen; idx++) {
            if (word[idx] == ' ') continue;
            char alpha = word[idx];
            val = val * 10 + alpha_num_map[alpha];
        }
        total += val;
    }

    cout  << total << '\n';
}
