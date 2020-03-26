#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n;

ll fpm(ll a,ll b){
    ll ret=1ll;
    for(;b;b>>=1,a=a*a%mod)
        if(b&1)ret=ret*a%mod;
    return ret;
}
void solve(){
    scanf("%d",&n);
    printf("%lld\n",fpm(2,2*n*n-2));
}
int main(){
    solve();
    return 0;
}
