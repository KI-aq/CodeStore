#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll tot[300007],ans[300007];
int n,m,v[300007],Num[300007];

bool cmp(int a,int b){
	return v[a]>v[b];
}

void solve(int Day){
	vector<int>S;
	int cnt;
	scanf("%d",&cnt);
	for (int i=1;i<=cnt;++i){
		int x;scanf("%d",&x);
		S.push_back(x);
	}
	sort(S.begin(),S.end(),cmp);
	for (auto u:S){
		ans[u]+=tot[v[u]]-tot[v[u]+1]-1ll*Num[v[u]+1]*(m-Day+1);
		tot[v[u]]+=(m-Day+1);
		--Num[v[u]];
		++Num[++v[u]];
	}
	return;
}

int main(){
	scanf("%d%d",&n,&m);
	Num[0]=n;
	for (int i=1;i<=m;++i)
		solve(i);
	for (int i=1;i<=n;++i)
		printf("%.8lf\n",(double)(ans[i]+tot[v[i]]+m)/(double)m);
	return 0;
}
