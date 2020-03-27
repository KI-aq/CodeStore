#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(ll a,ll b,ll c,ll n){
    //cerr<<a<<" "<<b<<" "<<c<<" "<<n<<endl;
    if(a==0)return (b/c)*n%9;
    else if(a<c&&b<c){
        ll m=(a*n+b)/c;
        return (n*m%9-f(c,c-b-1,a,m-1)+9)%9;
    }
    else{
        return (f(a%c,b%c,c,n)+(n*(n+1)>>1)%9*(a/c)%9+(n+1)*(b/c)%9)%9;
    }
}
void solve(){
    int a,b,m,k;
    scanf("%d%d%d%d",&a,&b,&m,&k);
    a%=m;
    ll res=1ll*a*k%9+(1ll*(k-1)*k>>1)%9*b%9-f(b,a,m,k-1)*m%9;
    cerr<<f(b,a,m,k-1)<<endl;
    //cerr<<res<<" "<<f(b,a,m,k-1)<<endl;
    ll ans=(res+9)%9;
    if(ans==0){
        if(a==0&&(b%m==0||k==1))ans=0;
        else ans=9;
    }
    printf("%d\n",ans);
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;++i)
        solve();
    return 0;
}
