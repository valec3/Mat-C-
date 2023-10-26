#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair <int, int> pii;
 
const int MOD = 1000000007;
string s;
int cnt[26];
void work() {
	cin >> s;
	LL n;
	cin >> n;
	n %= MOD;
	for (auto i : s) cnt[i - 'a'] ++;
	LL ans = 0;
	for (auto i : s) {
		for (int j = 0; j < i - 'a'; j++) {
			ans = (ans + cnt[j] * ((n * (n - 1) / 2) % MOD) % MOD) % MOD;	
		}
	}
	for (auto i : s) {
		for (int j = 0; j < i - 'a'; j++) {
			ans = (ans + cnt[j] * n) % MOD;	
		}
		cnt[i - 'a'] --;
	}
	cout << ans << endl;
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T = 1;
	for (int ca = 1; ca <= T; ca ++) {
		work();
	}
}
 