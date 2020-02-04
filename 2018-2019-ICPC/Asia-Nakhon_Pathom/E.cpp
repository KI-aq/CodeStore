#include<bits/stdc++.h>
using namespace std;
const int maxn=310;
int n;
int a[maxn],dp[maxn][3];
void solve(int Case){
    scanf("%d",&n);
    int mx=0;
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
        mx=max(mx,a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=0;i<=mx+1;++i)
        for(int j=0;j<=2;++j) dp[i][j] = 0;
    for(int i=1,x;i<=n;++i){
        x=a[i];
        for(int j=2;j>=1;--j)
            dp[x+1][j]=max({dp[x][j-1],dp[x-1][j-1],dp[x+1][j-1]})+1;
        for(int j=2;j>=0;--j)
            dp[x][j]=max({dp[x][j],dp[x-1][j],x>=2?dp[x-2][j]:0})+1;
        for(int j=2;j>=1;--j)
            dp[x-1][j]=max({dp[x-1][j-1],x>=2?dp[x-2][j-1]:0,x>=3?dp[x-3][j-1]:0})+1;
    }
    int ans=0;
    for(int i=1;i<=mx+1;++i)
        for(int j=0;j<=2;++j)
            ans=max(ans,dp[i][j]);
    printf("Case %d: %d\n",Case,ans);
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;++i)
        solve(i);

    return 0;
}
