#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define mp make_pair
const int maxn=2010;
const ll INF=(ll)1e15;
vector<pll> G[maxn];
int n,m;
ll dis[maxn][maxn];

void init(){
	cin>>n>>m;
	for(int i=1,u,v,w;i<=m;++i){
		//scanf("%d%d%d",&u,&v,&w);
		cin>>u>>v>>w;
		G[u].push_back(mp(v,w));	
		G[v].push_back(mp(u,w));
	}
	queue<pll> Q;
	while(!Q.empty())Q.pop();
	Q.push(mp(1,0));
	for(int i=1;i<=n;++i)
		for(int j=0;j<=n;++j)
			dis[i][j]=INF;
	
	dis[1][0]=0;
	for(ll x,y,v,w;!Q.empty();){
		x=Q.front().first;
		y=Q.front().second;
		Q.pop();
		if(y==n)continue;
		for(auto t: G[x]){
			v=t.first;w=t.second;
			if(dis[v][y+1]>dis[x][y]+w){
				if(dis[v][y+1]==INF)
					Q.push(mp(v,y+1));
				dis[v][y+1]=dis[x][y]+w;
			}
		}
	}
}
bool chk(pll a,pll b,pll c){
	return (c.second-a.second)*(a.first-b.first)<
			(b.second-a.second)*(a.first-c.first);
}
bool vis[maxn],vd[maxn][maxn];
void dfs(int u,int v){
	vis[u]=1;vd[u][v]=1;
	//cerr<<u<<endl;
	if(u==1)return;
	for(auto t: G[u])
		if(dis[u][v]==dis[t.first][v-1]+t.second&&!vd[t.first][v-1])
			dfs(t.first,v-1);
}
void solve(){
	vector<pll> hl;
	pll tmp;
	for(int i=n,sz=0;i>=1;--i){
		if(dis[n][i]==INF)continue;
		tmp=mp(i,dis[n][i]);
		for(;sz>=2&&chk(hl[sz-2],hl[sz-1],tmp);--sz)hl.pop_back();
		++sz;hl.push_back(tmp);
	}

	int sz=hl.size(),pos=0;
	while(pos+1<sz&&hl[pos].second>hl[pos+1].second)++pos;
	for(int i=pos;i<sz;++i){
		dfs(n,hl[i].first);
		//cerr<<hl[i].first<<"   eawe"<<endl;
	}

	vector<int> ans;
	for(int i=1;i<=n;++i)
		if(!vis[i])ans.push_back(i);

	cout<<ans.size()<<endl;
	for(auto v: ans)cout<<v<<" ";
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	init();
	solve();
	
	return 0;
}
