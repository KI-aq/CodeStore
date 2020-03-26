#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cstdlib>
#include<ctime>
#include<random>
#define ll long long
using namespace std;
const ll mod=1e9+7;
vector<int>Edge[100007];

int pre[6][20],suf[6][20];
int ans,Max,cnt,n,k,dp1[20][100007],dp2[20][100007];

void dfs1(int u,int fa){
    dp1[0][u]=1;
    for (int i=0;i<Edge[u].size();++i){
        int v=Edge[u][i];
        if (v==fa) continue;
        dfs1(v,u);
    }
    memset(pre,0,sizeof pre);
    for (int h=1;h<=Max;++h) pre[0][h]=1;
    for (int i=0;i<Edge[u].size();++i){
        int v=Edge[u][i];
        if (v==fa) continue;
        for (int h=1;h<=Max;++h){
            for (int s=k;s;--s)
                pre[s][h]=(pre[s][h]+1ll*pre[s-1][h]*dp1[h-1][v]%mod)%mod;
        }
    }
    for (int h=1;h<=Max;++h) dp1[h][u]=pre[k][h];
}

void dfs2(int u,int fa){
    ans=(ans+1)%mod;
    memset(pre,0,sizeof pre);
    memset(suf,0,sizeof suf);
    for (int h=1;h<=Max;++h) pre[0][h]=1,suf[0][h]=1;
    for (int i=0;i<Edge[u].size();++i){
        int v=Edge[u][i];
        if (v==fa) continue;
        for (int h=1;h<=Max;++h){
            for (int s=k;s;--s)
                suf[s][h]=(suf[s][h]+1ll*suf[s-1][h]*dp1[h-1][v]%mod)%mod;
        }        
    }
    for (int h=1;h<=Max;++h){
        for (int s=k;s;--s)
            suf[s][h]=(suf[s][h]+1ll*suf[s-1][h]*dp2[h-1][u]%mod)%mod;
        ans=(ans+suf[k][h])%mod;
    }
    for (int i=0;i<Edge[u].size();++i){
        int v=Edge[u][i];
        if (v==fa) continue;
        for (int h=1;h<=Max;++h){
            for (int s=1;s<=k;++s){
                suf[s][h]=(suf[s][h]-1ll*suf[s-1][h]*dp1[h-1][v]%mod)%mod;
            }
        }        
        for (int h=1;h<=Max;++h)
            for (int s=k;s>=0;--s)
                dp2[h][v]=(dp2[h][v]+1ll*pre[s][h]*suf[k-s][h]%mod)%mod;
        for (int h=1;h<=Max;++h){
            for (int s=k;s;--s)
                pre[s][h]=(pre[s][h]+1ll*pre[s-1][h]*dp1[h-1][v]%mod)%mod;
        }
    }       
    for (int i=0;i<Edge[u].size();++i){
        int v=Edge[u][i];
        if (v==fa) continue;
        dp2[0][v]=1;
        dfs2(v,u);
    }
}

int main(){
    scanf("%d%d",&n,&k);
    cnt=1;while (cnt<n) Max++,cnt*=k;
    for (int i=1;i<n;++i){
        int u,v;scanf("%d%d",&u,&v);
        Edge[u].push_back(v),Edge[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,0);
    printf("%lld\n",(ans+mod)%mod);
}
