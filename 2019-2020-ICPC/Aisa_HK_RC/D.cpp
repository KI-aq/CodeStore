#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<int> a;
void solve() {
	scanf("%d%d", &k, &n);
	a.clear();
	for (; n; n /= k) {
		--n;
		a.push_back(((10 - k) + n % k));
	}
	reverse(a.begin(), a.end());
	for (auto v : a) {
		printf("%d", v);
	}
	puts("");
}
int main() {
	int T;
	scanf("%d", &T);
	for (; T--;)
		solve();
	return 0;
}
