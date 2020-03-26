#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
const int maxn=3e5+10;
int n,m,p;
vector<pair<int,int> >Seg[maxn];
vector<int> W[maxn],G[maxn],res[maxn];
int sz[maxn],deg[maxn];
int ans[maxn];
void Dfs(int u){
    ans[u]=INT_MAX;
    int sumsz=0;
    for(auto v: G[u]){
        Dfs(v);
        sumsz+=sz[v];
        ans[u]=min(ans[u],ans[v]);
    }
    //if(u==0)cerr<<G[u].size()<<"size"<<endl;
    //cerr<<sz[u]<<" "<<sumsz<<endl;
    if(ans[u]==INT_MAX||sz[u]!=sumsz)ans[u]=0;
    ans[u]+=W[u].size();
}
void dfs(int u,int l,int r){
    if(!ans[u]||l>r)return;
    for(auto v: W[u]){
        res[l++].push_back(v);
    }
    for(auto v: G[u])
        dfs(v,l,r);
}
void solve(){
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1,x;i<=m;++i){
        scanf("%d",&x);
        for(int j=1,y;j<=x;++j){
            scanf("%d",&y);
            Seg[y].push_back(mp(x,i));
        }
        sz[i]=x;
    }
    for(int i=1,x;i<=p;++i){
        scanf("%d",&x);
        W[x].push_back(i);
    }
    for(int i=1;i<=n;++i){
        sort(Seg[i].begin(),Seg[i].end());
        for(int j=1,u,v;j<Seg[i].size();++j){
            u=Seg[i][j].second;
            v=Seg[i][j-1].second;
            G[u].push_back(v);
            ++deg[v];
        }
    }
    for(int i=1;i<=m;++i){
        sort(G[i].begin(),G[i].end());
        G[i].erase(unique(G[i].begin(),G[i].end()),G[i].end());
    }
    for(int i=1;i<=m;++i){
        if(!deg[i]){
            G[0].push_back(i);
            //cerr<<"number::"<<i<<endl;
        }
        //cerr<<deg[i]<<endl;
    }
    sz[0]=n;
    Dfs(0);
    printf("%d\n",ans[0]);
    dfs(0,1,ans[0]);
    for(int i=1;i<=ans[0];++i){
        printf("%d ",res[i].size());
        for(auto v: res[i]){
            printf("%d ",v);
        }
        puts("");
    }
}
int main(){
    solve();
    return 0;
}
