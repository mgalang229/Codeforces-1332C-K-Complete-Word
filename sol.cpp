#include <bits/stdc++.h>
using namespace std;

/*

36 9
hippopoto monstrose squippeda liophobia

hippopoto
monstrose
squippeda
liophobia (choosing the minimum letters to replace between i and n + 1 - i)
---------
423232232

= 2 * 5 + 3 * 3 + 4 * 1
= 10 + 9 + 4
= 23

aioptpoia
aioptpoia
aioptpoia
aioptpoia

ans: 23

------------------------------

21 7
wudixia oxingxi ngheclp

21 / 7 = 3 (size of string array)

wudixia
oxingxi
ngheclp
-------
2222323

= 2 * 5 + 3 * 2
= 10 + 6
= 16

ans: 16

------------------------------

*/

void test_case(int& tc) {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int g = n / k;
	string groups[g], temp = "";
	int index = 0;
	for (int i = 0; i < n; i++) {
		temp += s[i];
		if (index + 1 < g && (i + 1) % k == 0) {
			groups[index++] = temp;
			temp = "";
		}
	}
	groups[index] = temp;
	int ans = 0;
	for (int i = 0; i < k / 2; i++) {
		int mn = INT_MAX;
		for (int l = 0; l < 26; l++) {
			int cnt = 0;
			char cur = 'a' + l;
			for (int j = 0; j < g; j++) {
				cnt += (groups[j][i] != cur);
			}
			for (int j = 0; j < g; j++) {
				cnt += (groups[j][k-i-1] != cur);
			}
			mn = min(mn, cnt);
		}
		// cout << mn << "\n";
		ans += mn;
	}
	if (k % 2 == 1) {
		int mn = INT_MAX;
		for (int l = 0; l < 26; l++) {
			int cnt = 0;
			char cur = 'a' + l;
			for (int j = 0; j < g; j++) {
				cnt += (groups[j][k/2] != cur);
			}
			mn = min(mn, cnt);
		}
		ans += mn;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
		test_case(tc);
}
