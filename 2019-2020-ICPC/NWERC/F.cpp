#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
map<int,vector<int> > mp;
int n,m;
struct dat{
	int a,b,c;
	dat();
	dat(int a,int b,int c):
		a(a),b(b),c(c){};
};
vector<dat> ans;
int f[maxn];

int Fd(int u){
	if(!f[u])return u;
	return f[u]=Fd(f[u]);
}
int cnct(int a,int b,int c){
	int u=Fd(a),v=Fd(b);
	if(u!=v){
		ans.push_back(dat(a,b,c));
		f[v]=u;
		return 1;
	}
	return 0;
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&m);
		for(int j=1,x;j<=m;++j){
			scanf("%d",&x);
			mp[x].push_back(i);
		}
	}
	int cnt=0;
	for(auto v: mp){
		if(cnt>=n)break;
		for(int i=1;i<v.second.size();++i){
			cnt+=cnct(v.second[i],v.second[i-1],v.first);
		}
	}
	if(cnt<n-1)puts("impossible");
	else {
		for(auto v: ans){
			printf("%d %d %d\n",v.a,v.b,v.c);
		}
	}
}
int main(){
	
	solve();
	
	return 0;
} 
