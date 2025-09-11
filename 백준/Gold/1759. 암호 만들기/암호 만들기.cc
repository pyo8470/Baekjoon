#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#define MAX_LEN 15
using namespace std;
typedef long long ll;


int L, C;
char alphabets[MAX_LEN];
bool isValid(string &str) {
	bool Vowel = false;
	int consonant = 0;
	for (char c : str) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') Vowel = true;
		else consonant += 1;
	}
	return Vowel && consonant >= 2;
}
void combination(const int& idx, const int& depth, string &str) {
	if (depth == L) {
		if (!isValid(str)) return;
		cout << str << '\n';
		return;
	}
	for (int i = idx; i < C; i++) {
		str.push_back(alphabets[i]);
		combination(i + 1, depth + 1, str);
		str.pop_back();
	}
}
int main()
{

	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> alphabets[i];
	}

	sort(alphabets, alphabets + C);
	string s;
	combination(0, 0, s);
	//cout << Scount << '\n';

	return 0;
}

