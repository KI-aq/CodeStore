#include<bits/stdc++.h>
using namespace std;
const int maxn=2000010;
int n;
int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int h[maxn];
void solve(){
    n=read();
    for(int i=1;i<=n;++i){
        h[i]=read();
    }
    if(n==0){
        puts("0");
        return;
    }
    int ans=1;
    for(int i=2,now=h[1]+20;i<=n;++i){
        if(h[i]>now){
            ++ans;
            now=h[i]+20;
        }
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
