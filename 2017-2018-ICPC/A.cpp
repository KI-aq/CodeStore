#include<bits/stdc++.h>
using namespace std;
const int maxn=5050;
int n;
int f[maxn][maxn];
int g[maxn][maxn];
vector<int> G[maxn];
void dfs(int u,int fa){
    for(auto v: G[u])if(v!=fa){
        dfs(v,u);
        for(int i=1;i<=n;++i)g[u][i]+=g[v][i-1];
    }
    f[u][n]=n;
    for(int i=n-1;~i;--i){
        if(i==0)f[u][i]=f[u][i+1];
        else f[u][i]=min(i+g[u][i+1],f[u][i+1]);
        for(auto v: G[u])if(v!=fa)
            f[u][i]=min(f[u][i],f[v][i+1]+g[u][i+1]-g[v][i]);
    }
    g[u][0]=f[u][0];
    for(int i=1;i<=n;++i)g[u][i]=min(g[u][i],g[u][i-1]);
}
void solve(){
    scanf("%d",&n);
    for(int i=1,u,v;i<n;++i){
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    printf("%d\n",g[1][0]);
}
int main(){
    solve();
    return 0;
}
