#include<bits/stdc++.h>
using namespace std;
int n,m;
void solve(){
    double ans=0;
    while(~scanf("%d%d",&n,&m)&&(n||m)){
        ans=0;
        for(int i=n;i<=m;++i)
            ans+=pow(1.0*i*i,-1.0/3);
        ans=ans*(1.0/3)*(1e-15);
        printf("%.5E\n",ans);
    }
}
int main(){
    solve();

    return 0;
}
