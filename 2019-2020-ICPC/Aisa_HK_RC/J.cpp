#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5010, mod = 1e9 + 7;
int m, n;
ll f[maxn][62][62];
int t[maxn];
ll _10[maxn];
int dig(char s) {return s - '0';}
ll dfs(int id, int num1, int num2, int lm) {
	if (id < 1)return !num2;
	if (!lm && ~f[id][num1][num2])return f[id][num1][num2];

	int up = 9; if (lm)up = t[id];

	ll res = 0;
	for (int i = 0; i <= up; ++i)
		res += dfs(id - 1, (num1 + i) % m, (num2 + i * num1 - _10[id - 1] * i + m * m * m) % m, up == i && lm);
	return f[id][num1][num2] = res % mod;
}
ll solve(char *s) {
	n = strlen(s);
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j < m; ++j)
			for (int k = 0; k < m; ++k)
				f[i][j][k] = -1;
	for (int i = 0; i < n; ++i)t[i + 1] = dig(s[n - 1 - i]);
	return dfs(n, 0, 0, 1);
}
char L[maxn], R[maxn];
int main() {
	int T;
	scanf("%d", &T);
	_10[0] = 1;
	for (ll l, r, x, y; T--;) {
		scanf("%s%s", L, R);
		scanf("%d", &m);
		x = strlen(L); y = strlen(R);

		for (int i = 0; i < y; ++i)_10[i + 1] = _10[i] * 10 % m;

		--L[x - 1];
		for (int i = x - 1; ~i; --i) {
			if (L[i] - '0' < 0)L[i] += 10, L[i - 1]--;
			else break;
		}
		l = solve(L);
		r = solve(R);

		cerr << l << " " << r << endl;
		printf("%lld\n", (r - l + mod) % mod);
	}
	return 0;
}
