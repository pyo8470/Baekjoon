#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    priority_queue<int,vector<int>,greater<int>> pq;
    for(string time : timetable){
        int hour = stoi(time.substr(0,2)) * 60;
        int minute = stoi(time.substr(3,2));
        int sum = hour + minute;
        pq.push(sum);
    }
    // 버스 도착 시간
    queue<int> bus;
    for(int i=0; i<n; i++){
        bus.push(60*9 + t*i);
    }
    
    vector<vector<int>> buses;
    while(!bus.empty()){
        int cur = bus.front(); bus.pop();
        vector<int> temp; // 현재 버스
        while(temp.size() < m && !pq.empty() && pq.top() <= cur){
            temp.push_back(pq.top()); pq.pop();
        }
        buses.push_back(temp);
    }
    
    int len = buses.size();
    int time = buses[len-1].size() == m ? buses[len-1][m-1]-1:540+(len-1)*t;
    
    int hour = time / 60;
    int minute = time % 60;
    
    string hour_str = to_string(hour);
    string minute_str = to_string(minute);
    
    hour_str = (hour_str.size() == 1) ? "0"+hour_str : hour_str;
    minute_str = (minute_str.size() == 1) ? "0"+minute_str : minute_str;
    answer = hour_str + ":" + minute_str;
    return answer;
}