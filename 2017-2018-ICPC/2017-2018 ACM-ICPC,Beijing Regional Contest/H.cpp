#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1010;
int n,m,p;
int sum[maxn],a[maxn][maxn],f[maxn];
int u[maxn],d[maxn],l[maxn],r[maxn];
void Get1(){
    memset(f,0,sizeof f);
    for(int i=1;i<=n;++i){
        memset(sum,0,sizeof sum);
        for(int j=i,res;j<=n;++j){
            res=-inf;
            for(int k=1;k<=m;++k){
                sum[k]+=a[j][k];
                f[k]=max(f[k-1],0)+sum[k];
                res=max(res,f[k]);
            }
            for(int k=j;k<=n;++k)u[k]=max(u[k],res);
            for(int k=1;k<=i;++k)d[k]=max(d[k],res);
        }
    }
}
void Get2(){
    memset(f,0,sizeof f);
    for(int i=1;i<=m;++i){
        memset(sum,0,sizeof sum);
        for(int j=i,res;j<=m;++j){
            res=-inf;
            for(int k=1;k<=n;++k){
                sum[k]+=a[k][j];
                f[k]=max(f[k-1],0)+sum[k];
                res=max(res,f[k]);
            }
            for(int k=j;k<=m;++k)l[k]=max(l[k],res);
            for(int k=1;k<=i;++k)r[k]=max(r[k],res);
        }
    }
}
void solve(){
    for(int ans;~scanf("%d%d%d",&n,&m,&p);){
        for(int i=0;i<=max(n,m)+10;++i)
            l[i]=r[i]=u[i]=d[i]=-inf;
        memset(a,0,sizeof a);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                scanf("%d",&a[i][j]);
            }
        }
        Get1();Get2();
        ans=l[m];
        //cerr<<ans<<endl;
        for(int i=1,res;i<=n;++i)
            for(int j=1;j<=m;++j){
                if(a[i][j]<=p)continue;
                res=max(u[i-1],d[i+1]);
                res=max(res,max(l[j-1],r[j+1]));
                ans=min(ans,max(res,l[m]-a[i][j]+p));
            }
        printf("%d\n",ans);
    }
}
int main(){
    solve();
    return 0;
}
