#include <cstdio>
#include <algorithm>
#define  ll long long
using namespace std;
const ll Mod=998244353;

ll k_pow(ll x,ll y){
    ll ans=1;
    x%=Mod;
    for (;y;y>>=1){
        if (y&1) ans=(ans*x)%Mod;
        x=x*x%Mod;
    }
    return ans;
}

ll ans,n,p,q,a[200007];

int main(){
    scanf("%lld%lld%lld",&n,&p,&q);
    for (int i=1;i<=n;++i) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    p=p%Mod*k_pow(1e6,Mod-2)%Mod;
    q=q%Mod*k_pow(1e6,Mod-2)%Mod;
    a[0]=-1;
    for (int i=1;i<=n;++i){
        ans=(ans+1-p-q)%Mod;
        if (a[i-1]==a[i]-1&&a[i+1]==a[i]+1)
            ans=(ans+(p+q)%Mod*(1-(1-p)%Mod*(1-q)%Mod)%Mod)%Mod;
        else if (a[i-1]==a[i]-1)
            ans=(ans+(p+q)%Mod*q%Mod)%Mod;
        else if (a[i+1]==a[i]+1)
            ans=(ans+(p+q)%Mod*p%Mod)%Mod;
    }
    printf("%lld\n",(ans+Mod)%Mod);
}
