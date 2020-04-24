#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

vector<int>e[200007],ans;

bool Color[200007];
int n,k,sum[200007];

void dfs(int u,int fa){
    bool Check=(!Color[u]);
    sum[u]+=Color[u];
    for (auto v:e[u])
    if (v!=fa){
        dfs(v,u);
        sum[u]+=sum[v];
        if (!sum[v]) Check=false;
    }
    if (k==sum[u]&&fa) Check=false;
    if (Check) ans.push_back(u);
}

int main(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<=k;++i){
        int x;scanf("%d",&x);
        Color[x]=true;
    }
    for (int i=1;i<n;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    if (!ans.empty())
        for (auto i:ans) printf("%d ",i);
}
