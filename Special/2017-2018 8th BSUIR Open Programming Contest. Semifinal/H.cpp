#include<stdio.h>
const int maxn=100010;
typedef long long ll;
int n;
ll a[maxn];

void solve(){
    scanf("%d",&n);
    for(int i=1;i<maxn;++i){
        a[i]=a[i-1]+(i%2==1?0:i);
    }
    for(int l,r;n--;){
        scanf("%d%d",&l,&r);
        printf("%lld\n",a[r]-a[l-1]);
    }
}
int main(){
    solve();

    return 0;
}
