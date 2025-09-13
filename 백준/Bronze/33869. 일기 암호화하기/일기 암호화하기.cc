#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

int DAT[26];


string W;
string S;
int main(){
	cin >> W >> S;
	

	string rW = "";
	// 중복제거
	for (char& c : W) {
		int idx = c - 'A';
		if (DAT[idx]) continue;
		rW += c;
		DAT[idx]++;
	}

	for (int i = 0; i < 26; i++) {
		char al = 'A' + i;

		if (DAT[i]) continue;
		DAT[i]++;
		rW += al;
	}

	
	for (char& c : S) {
		int idx = c - 'A';
		cout << rW[idx];
	}
}