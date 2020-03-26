#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
struct dat{
    int a,b;
}st[maxn];
int ax[maxn],ay[maxn];
int bx[maxn],by[maxn],n;
bool cmp(dat x,dat y){
    if(x.a+x.b!=y.a+y.b){
        return x.a+x.b<y.a+y.b;
    }
    return x.b<y.b;
}
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d%d",&st[i].a,&st[i].b);
    }
    int mxa=st[1].a,mxb=st[1].b,mna=st[1].a,mnb=st[1].b;
    for(int i=2;i<=n;++i){
        mxa=max(mxa,st[i].a);
        mna=min(mna,st[i].a);
        mxb=max(mxb,st[i].b);
        mnb=min(mnb,st[i].b);
    }
    ax[0]=bx[0]=mxa;ay[0]=by[0]=mxb;
    ax[n-1]=bx[n-1]=mna;ay[n-1]=by[n-1]=mnb;
    for(int i=0;i<n-2;++i){
        ax[i]=mxa;
        ay[i]=mxb;
    }
    for(int i=2;i<n;++i){
        bx[i]=mna;
        by[i]=mnb;
    }
    sort(st+1,st+n+1,cmp);
    ax[n-2]=st[n].a;
    ay[n-2]=st[n].b;
    bx[1]=st[1].a;
    by[1]=st[1].b;
    for(int i=0;i<n;++i){
        printf("%d %d %d %d\n",ax[i],ay[i],bx[i],by[i]);
    }
}
int main(){
    solve();
    return 0;
}
