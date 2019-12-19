#include<bits/stdc++.h>
using namespace std;
const int maxn = 100100;
typedef long long ll;
bool chk_1(ll k) {
	if (k == 1) {
		printf("2\n1\n1 2\n");
		return 1;
	}
	return 0;
}
int n;
int f[maxn], c[maxn];
int dfs(ll k, int id) {
	if (k == 1)return c[n] = 1;
	else if (k == 2) {
		c[id] = 1;
		f[++n] = id;
		c[n] = 1;
		return 1;
	}
	else {
		if (k & 1) {
			--k;
			if (k == 2) {
				f[++n] = id;
				c[id] += dfs(k, n);
			}
			else {
				f[++n] = id;
				c[id] += dfs(k / 2, n);
				f[++n] = id;
				c[id] += dfs(2, n);
			}
		}
		else {
			f[++n] = id;
			c[id] += dfs(k - 1, n);
		}
	}
	return  c[id];
}
void solve() {
	ll k;
	scanf("%lld", &k);
	if (chk_1(k))return;
	dfs(k, ++n);
	printf("%d\n", n);
	for (int i = 2; i <= n; ++i)
		printf("%d ", f[i]);
	puts("");
	for (int i = 1; i <= n; ++i)
		printf("%d ", c[i]);
	puts("");
}
int main() {
	solve();

	return 0;
}
