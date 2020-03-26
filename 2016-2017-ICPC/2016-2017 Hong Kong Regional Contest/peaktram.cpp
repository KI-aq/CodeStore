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

ll g[72][72][10007],Max[72][10007];
ll ans,s[107][10007];
int k,n,h[10007],p[107],c[107];

int main(){
    memset(g,0x7f,sizeof g);
   // memset(f,0x7f,sizeof f);
    memset(Max,0x7f,sizeof Max);
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;++i){
        scanf("%d%d",&p[i],&c[i]);
        for (int t=-k;t<=k;++t)
            if (p[i]+t>0) h[++h[0]]=p[i]+t;
    }
    ans=-1;
    sort(h+1,h+h[0]+1);
    h[0]=unique(h+1,h+h[0]+1)-h-1;
    for (int i=1;i<=n;++i){
        for (int t=1;t<=h[0];++t){
            s[i][t]=s[i-1][t];
            if (p[i]>=h[t]) s[i][t]+=1ll*c[i]*(1+p[i]-h[t]);
        }
        for (int kn=min(i,k);kn;--kn){
            for (int hn=kn;hn<=h[0];++hn){
                Max[1][hn]=0;
                g[i][kn][hn]=min(Max[kn][hn]+s[i-1][hn]+1ll*abs(p[i]-h[hn])*c[i],g[i][kn][hn-1]);
                Max[kn+1][hn+1]=min(Max[kn+1][hn+1],g[i][kn][hn]-s[i][hn+1]);
                if (kn==k){
                    if (ans==-1) ans=g[i][kn][hn];
                    else ans=min(ans,g[i][kn][hn]);
                }
            }
        }
    }
    printf("%lld\n",ans);
}
