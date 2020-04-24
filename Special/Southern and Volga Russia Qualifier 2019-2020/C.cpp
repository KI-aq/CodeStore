#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=(1<<20)+10;
ll dp[maxn];
vector<int> t[30];
ll val[30][30];

int n;
void init(){
    for(int i=0;i<20;++i){
        for(int j=0;j<20;++j){
            if(i==j||t[j].size()==0)continue;
            for(auto u: t[i]){
                if(t[j][0]>u)continue;
                int l=0,r=t[j].size();
                for(int mid;l<r;){
                    mid=(l+r)/2;
                    if(t[j][mid]<u)l=mid+1;
                    else r=mid;
                }
                val[i][j]+=l;
            }
        }
    }
}
void solve(){
    scanf("%d",&n);
    for(int i=0,x;i<n;++i){
        scanf("%d",&x);
        t[x-1].push_back(i);
    }
    init();
    int S=(1<<20)-1;
    ll res=0;
    for(int i=1;i<=S;++i)dp[i]=1.5e18;
    for(int i=0;i<=S;++i){
        for(int j=0;j<20;++j){
            if((i&(1<<j))==0){
                res=0;
                //cerr<<"wea"<<endl;
                for(int k=0;k<20;++k)
                    if(i&(1<<k))res+=val[k][j];
                dp[i|(1<<j)]=min(dp[i|(1<<j)],dp[i]+res);
            }
        }
    }
    printf("%lld\n",dp[S]);
}
int main(){
    solve();
    return 0;
}
