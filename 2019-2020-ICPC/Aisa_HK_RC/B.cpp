#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> G[10010];
int dfs(int u, int fa) {
	int cnt = 0;
	for (auto v : G[u])if (v != fa)
			cnt += dfs(v, u);
	if (cnt == 2 || cnt == 0)return 1;
	else return 0;
}
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)G[i].clear();
	for (int i = 1, u, v; i < n; ++i) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if (dfs(1, 0))puts("Alice");
	else puts("Bob");
}
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i)solve();
	return 0;
}
