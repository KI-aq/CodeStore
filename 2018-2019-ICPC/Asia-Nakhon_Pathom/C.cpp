#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int n,w;
int a[maxn],dp[maxn];

void solve(){
    scanf("%d%d",&n,&w);
    int pos=1;
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
        if(a[pos]<a[i])pos=i;
    }
    int ans=0;
    for(int m=n;m--;){
        for(int i=1;i<=n;i++)
		    if(a[i]<a[pos]&&abs(i-pos)<=w){
			    dp[i]=max(dp[i],dp[pos]+1);
			    ans=max(ans,dp[i]);
		    }
		a[pos]=INT_MAX;pos=0;
		for(int i=1;i<=n;++i)
		    if(a[i]!=INT_MAX&&a[i]>a[pos])pos=i;
	}
	printf("%d\n",ans);
}
int main(){
    solve();

    return 0;
}
