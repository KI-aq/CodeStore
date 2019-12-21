#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int, int>
using namespace std;
const int maxn = 1e4 + 10;
vector<int>p;
vector<pii >c;
int pd[maxn];
void ee()
{
	printf("impossible\n");
	return;
}
int main()
{
	int n, m;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		c.pb({x, y});
	}
	scanf("%d", &m);
	for(int i = 1; i <= m; i ++)
	{
		int x;
		scanf("%d", &x);
		p.pb(x);
	}
	bool fg = 0;
	int cnt = (m == 0 ? 0 : upper_bound(p.begin(), p.end(), c[0].second) - lower_bound(p.begin(), p.end(), c[0].first));
	if(cnt > 2){ee(); return 0;}
	pd[0] = cnt;
	vector<int> ans;
	for(int i = 1; i < n; i ++)
	{
		cnt = (m == 0 ? 0 :  upper_bound(p.begin(), p.end(), c[i].second) - lower_bound(p.begin(), p.end(), c[i].first));
		if(cnt > 2){ee(); return 0;}
		pd[i] = cnt;
		if(c[i].first == c[i - 1].second && pd[i - 1] < 2 && pd[i] < 2 && (m == 0 ? 1 : *lower_bound(p.begin(), p.end(), c[i].first) != c[i].first))
		{
			ans.pb(c[i].first);
			pd[i - 1] ++;
			pd[i] ++;
		}
		for(int j = c[i - 1].first + 1; j <= c[i - 1].second && pd[i - 1] < 2; j ++)
		{
			if((m == 0 ? 1 : *lower_bound(p.begin(), p.end(), j) )!= j)
			{
				ans.pb(j);
				pd[i - 1] ++;
			}
		}
	}
	for(int j = c[n - 1].first + 1; j <= c[n - 1].second && pd[n - 1] < 2; j ++)
	{
		if((m == 0 ? 1 : *lower_bound(p.begin(), p.end(), j)) != j)
		{
			ans.pb(j);
			pd[n - 1] ++;
		}
	}
	if(!ans.empty())
	{
		sort(ans.begin(), ans.end());
		printf("%d\n%d", ans.size(), ans[0]);
		for(int i = 1; i < ans.size(); i ++)
		{
			printf(" %d", ans[i]);
		}
	}
	else
	{
		printf("0\n");
	}
	return 0;
}
