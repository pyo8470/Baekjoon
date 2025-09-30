#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 시간 계산 보조 함수
int addMinutes(int time, int add) {
    int hour = time / 100;
    int minute = time % 100;
    minute += add;
    hour += minute / 60;
    minute %= 60;
    hour %= 24; // 24시 이상이면 0시로
    return hour * 100 + minute;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    int n = schedules.size();       // 사람 수
    int d = timelogs[0].size();     // 날짜 수 (가로/세로 구조 확인 필요)
    
    cout << n << " " << d <<'\n';
    vector<bool> people(n, true);
    vector<int> limits(n, 0);
    
    // 각 사람별 마지노선 시간 계산
    for(int i=0; i<n; i++){
        limits[i] = addMinutes(schedules[i], 10);
    }
    
    // 날짜별 확인
    for(int day = 0; day < d; day++){
        int date = (day + startday) % 7;
        if(date == 0 || date == 6) continue; // 일(0), 토(6) 제외

        for(int i=0; i<n; i++){
            if(!people[i]) continue;
            
            int time = timelogs[i][day]; 
            if(time > limits[i]) {
                people[i] = false;
            }
        }
    }
    
    for(bool p : people){
        if(p) answer++;
    }
    return answer;
}
