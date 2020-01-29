#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353,maxn=1e5+10;
int n,K,inv_k;
ll fack[20],f[maxn],ifac[20];
ll g[maxn][20],h[maxn][20];

ll fpm(ll a,ll b){
    ll ret=1ll;
    for(;b;b>>=1,a=a*a%mod)
        if(b&1)ret=ret*a%mod;
    return ret;
}
void solve(){
    scanf("%d%d",&n,&K);
    for(int i=1;i<=n;++i)
        scanf("%lld",f+i);
    fack[0]=1;inv_k=1;
    for(int i=1;i<20;++i){
        fack[i]=fack[i-1]*(K-i+1)%mod;
        inv_k=1ll*inv_k*i%mod;
        ifac[i]=fpm(inv_k,mod-2);
    }
    h[1][0]=1;inv_k=fpm(K,mod-2);
    for(int i=2;i<=n;++i){
        for(int j=2,tmp;j<=K&&j<20;++j){
            tmp=fack[j]*h[i][j]%mod;//fuction h means to get i use j factor
            f[i]+=(mod-tmp)%mod;
            f[i]%=mod;
        }
        f[i]=f[i]*inv_k%mod;
        for(int j=1;1ll*j*i<=n;++j){
            for(ll k=1,cnt=1,now=1,y;1ll*k*j*i<=n;k*=i,++cnt){
                now=1ll*now*f[i]%mod;y=k*j*i;
                for(int l=cnt;l<20&&l<=K;++l){
                    g[y][l]+=ifac[cnt]*now%mod*h[j][l-cnt]%mod;
                    g[y][l]%=mod;
                }
            }
        }
        for(int j=1;j*i<=n;++j){
            for(ll k=1,cnt=1,now=1,y;k*j*i<=n;k*=i,++cnt){
                y=k*j*i;
                for(int l=cnt;l<20&&l<=K;++l){
                    (h[y][l]+=g[y][l])%=mod;
                    g[y][l]=0;
                }
            }
        }
    }
    for(int i=1;i<=n;++i){
        printf("%lld ",f[i]);
    }
    puts("");
}
int main(){
    solve();

    return 0;
}
