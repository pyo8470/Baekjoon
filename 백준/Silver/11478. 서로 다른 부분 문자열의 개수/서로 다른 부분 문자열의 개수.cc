#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

string str; 
int length;
unordered_set<string> result; 
void solve(int start) {
	for (int len = 1; len <= length-start; len++) {
		result.insert(str.substr(start, len));
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> str;
	length = str.length();
	result.reserve(length * length);


	for (int i = 0; i < length; i++) {
		solve(i);
	}
	cout << result.size();
}