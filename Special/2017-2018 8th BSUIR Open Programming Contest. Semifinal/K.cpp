#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010;
int n,q;
int ff[maxn][20],deg[maxn],dep[maxn];
ll F[maxn],gg[maxn];
ll f[maxn],g[maxn];
vector<int> G[maxn];

void dfs(int u,int fa){
    F[u]=deg[u];
    for(auto v: G[u])if(v!=fa){
        dfs(v,u);
        F[u]+=F[v];
    }
}
void dfs2(int u,int fa,ll res){
    gg[u]=gg[fa]+deg[fa]+res;
    ll tot=0;
    for(auto v: G[u])if(v!=fa){
        tot+=F[v];
    }
    for(auto v: G[u])if(v!=fa){
        dfs2(v,u,tot-F[v]);
    }
}
void dfs3(int u,int fa){
    g[u]=g[u]+gg[u]+g[fa];
    f[u]=f[u]+F[u]+f[fa];
    dep[u]=dep[fa]+1;
    for(int i=1;(1<<i)<=dep[u];++i){
        ff[u][i]=ff[ff[u][i-1]][i-1];
    }
    for(auto v: G[u])if(v!=fa){
        ff[v][0]=u;dfs3(v,u);
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    //cerr<<x<<" "<<y<<endl;
    for(int i=19;i>=0;--i){
        if(dep[ff[x][i]]>=dep[y])x=ff[x][i];
        if(x==y)return x;
    }
    for(int i=19;i>=0;--i){
        if(ff[x][i]!=ff[y][i]){
            x=ff[x][i];y=ff[y][i];
        } 
    } 
    return ff[x][0];
}
void solve(){
    scanf("%d%d",&n,&q);
    for(int i=1,u,v;i<n;++i){
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
        ++deg[u];
        ++deg[v];
    }
    dfs(1,0);
    dfs2(1,0,0);
    dfs3(1,0);
    //for(int i=1;i<=3;++i){
    //    cerr<<f[i]<<"   "<<g[i]<<endl;
    //}
    for(int l,u,v;q--;){
        scanf("%d%d",&u,&v);
        l=lca(u,v);
        //cerr<<g[v]<<" "<<g[l]<<endl;
        ll ans=f[u]-f[l]+g[v]-g[l];
        printf("%lld\n",ans);
    }
}
int main(){
    solve();
    return 0;
}
