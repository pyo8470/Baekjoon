#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<deque>
#include<unordered_map>
using namespace std;

char DNA[4] = { 'A','C','G','T' };

unordered_map<char, int> ACGT_map;
unordered_map<char, int> min_ACGT_map;
bool valid() {
	for (int i = 0; i < 4; i++) {
		if (ACGT_map[DNA[i]] < min_ACGT_map[DNA[i]]) return false;
	}
	return true;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	deque<char> dq;
	string input;
	

	int S, P; cin >> S >> P;
	cin >> input;
	int result = 0;
	
	for (int i = 0; i < 4; i++) {
		ACGT_map[DNA[i]] = 0; cin >> min_ACGT_map[DNA[i]];
	}
	
	for (int i = 0; i < P; i++) {
		dq.push_back(input[i]);
		ACGT_map[input[i]] += 1;
		
	}
	if (valid()) result += 1;
	for (int i = P; i < S; i++) {
		char dn = dq.front(); dq.pop_front();ACGT_map[dn] -= 1;
		dq.push_back(input[i]); ACGT_map[input[i]] += 1;
		if (valid()) result++;

	}

	cout << result;
	return 0;
}

