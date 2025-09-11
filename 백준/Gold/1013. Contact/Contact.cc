#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<regex>
#include<algorithm>
#define MAX_LEN 15
using namespace std;
typedef long long ll;

regex e1("(100+1+|01)+");

int main()
{

	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (regex_match(s, e1)) cout << "YES\n";
		else cout << "NO\n";
		//cout << it.begin()->matched << '\n';
	}


	return 0;
}

