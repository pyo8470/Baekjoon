#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<regex>
#include<algorithm>
#define MAX_LEN 15
using namespace std;
typedef long long ll;

regex e1("(100+1+|01)+");


bool match(string& s) {
	int i = 0;
	int n = s.size();

	while (i < n) {
		// 01 
		//cout << i << " ";
		if (i + 1 < n && s[i] == '0' && s[i + 1] == '1') {
			// 다음으로
			i += 2; continue;
		}
		//(100+1+)
		// 100+ 먼저
		else if (i + 2 < n && s[i] == '1' && s[i + 1] == '0' && s[i + 2] == '0') {
			int j = i + 2;
			while (j < n && s[j] == '0') {
				j++;
			}if (j == n) return false;



			// 1 최소 한개 이상
			int k = j;
			while (k < n && s[k] == '1') {
				k++;
			}
			if (k == j) return false; // 1이 없음
			if (k == n) return true; // 끝


			if (k - j == 1) { // 1이 딱 한 개인 경우
				i = k;
			}
			else { // 1이 여러개
				i = k - 1; 
				// 다음 패턴이 01 패턴
				if (i + 2 < n && s[i + 1] == '0' && s[i + 2] == '1') i++;
				//else if(i+2 <n && s[i+1] == '0' && s[i+2] == '0') 
			}
			
		}
		else {
			return false;
		}
	}
	return true;
}
//regex_match(s, e1)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (match(s)) cout << "YES\n";
		else cout << "NO\n";
		//cout << it.begin()->matched << '\n';
	}


	return 0;
}

