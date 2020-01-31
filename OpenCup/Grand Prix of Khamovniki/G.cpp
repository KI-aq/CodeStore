#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=101010;
const double eps=1e-12;
int n;
int x[maxn],y[maxn];
void solve(){
    scanf("%d",&n);
    for(int i=0;i<=n;++i){
        scanf("%d%d",x+i,y+i);
    }
    ll lf=1ll*(y[0]-y[1])*(x[n]-x[n-1]);
    ll rf=-1ll*(y[n]-y[n-1])*(x[0]-x[1]);
    if(lf==rf){
        lf=(y[0]*x[1]-y[1]*x[0])*(x[n]-x[n-1]);
        rf=(y[n]*x[n-1]-y[n-1]*x[n])*(x[0]-x[1]);
        if(lf==-rf)puts("Yes");
        else puts("No");
    }
    else{
        puts("No");
    }
}
int main(){
    solve();

    return 0;
}
