#include<bits/stdc++.h>
using namespace std;
int n,a[5],b[5];
typedef long long ll;
const double EPS=1e-18;
long double tmp;
bool check(ll res){
    tmp=pow(res,1.0/3);
    return tmp*tmp*tmp-1.0*res<EPS;
}
ll lcm(ll a,ll b){
    ll g=__gcd(a,b);
    return a/g*b;
}
ll exgcd(ll a,ll b,ll &x,ll &y) {
    if(b==0){x=1;y=0;return a;}
    ll gcd=exgcd(b,a%b,x,y),tp=x;
        x=y;y=tp-a/b*y;
    return gcd;
}
ll mul(ll a,ll b,ll m){
    ll ret=0,k=a,f=1;
    if(k<0)f=-f,k=-k;
    if(b<0)f=-f,b=-b;
    for(;b;b>>=1,k=(k+k)%m)
        if(b&1)ret=(ret+k)%m;
    return ret*f;
}
ll excrt(){
    ll x,y,k;
    ll M=b[1],ans=a[1];
    for(int i=2;i<=3;++i){
        ll A=M,B=b[i],c=(a[i]-ans%B+B)%B;
        ll gcd=exgcd(A,B,x,y),bg=B/gcd;
        if(c%gcd!=0)return -1;
        
        x=mul(x,c/gcd,bg);
        
        ans+=x*M;M*=bg;
        ans=(ans%M+M)%M;
    }
    return ans;
}
void solve(){
    for(int i=1;i<=3;++i){
        scanf("%d",b+i);
    }
    for(int j=1;j<=3;++j){
        scanf("%d",a+j);
    }
    ll res=excrt();
    ll h=lcm(lcm(b[1],b[2]),b[3]);
    for(;!check(res);)res+=h;
    if((ll)pow(tmp,3)<res)printf("%lld\n",(ll)tmp+1);
    else printf("%lld\n",(ll)tmp);
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;++i)
        solve();

    return 0;
}
