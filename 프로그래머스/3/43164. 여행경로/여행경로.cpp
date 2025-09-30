#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<string>> tickets;
vector<string> answer;
vector<bool> visited;

bool dfs(string target) {
    answer.push_back(target);

    // 모든 티켓을 다 사용했다면 성공
    if (answer.size() == tickets.size() + 1) return true;

    for (int i = 0; i < tickets.size(); i++) {
        if (!visited[i] && tickets[i][0] == target) {
            visited[i] = true;
            if (dfs(tickets[i][1])) return true;
            visited[i] = false; // 백트래킹
        }
    }

    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> inputTickets) {
    tickets = inputTickets;

    // 출발지/도착지 정렬 (사전순 우선)
    sort(tickets.begin(), tickets.end(), [](auto &lhs, auto &rhs) {
        if (lhs[0] == rhs[0]) return lhs[1] < rhs[1];
        return lhs[0] < rhs[0];
    });

    visited.assign(tickets.size(), false);

    dfs("ICN");

    return answer;
}
