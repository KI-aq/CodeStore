#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int n,m;
vector<int> G[maxn];
int deg[maxn],f[maxn],vis[maxn];
int dfs(int u){
    if(vis[u])return f[u];
    vis[u]=1;
    f[u]=1;
    for(auto v: G[u])if(deg[v]>deg[u]){
        f[u]=max(f[u],dfs(v)+1);
    }
    return f[u];
}
void solve(){
    scanf("%d%d",&n,&m);
    for(int i=1,u,v;i<=m;++i){
        scanf("%d%d",&u,&v);
        ++u,++v;
        G[u].push_back(v);
        G[v].push_back(u);
        ++deg[u];
        ++deg[v];
    }
    for(int i=1;i<=n;++i)
        if(!vis[i])dfs(i);
    int ans=0;
    for(int i=1;i<=n;++i)
        ans=max(ans,f[i]);
    printf("%d\n",ans);
}
int main(){
    solve();
    return 0;
}
