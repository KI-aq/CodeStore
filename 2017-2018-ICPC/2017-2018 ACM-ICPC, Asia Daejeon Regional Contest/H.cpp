#include<bits/stdc++.h>
using namespace std;
typedef complex<double> cd;
const int maxn=(1<<20)|10;
const double PI=acos(-1.0);
int rev[maxn];
cd a[maxn],b[maxn];
void getrev(int N){
    int S=N,T=N>>1;
    for(int i=0;i<S;++i)
        rev[i]=(rev[i>>1]>>1)|((i&1)==0?0:T);
}
void fft(cd *a,int n,int on){
    for(int i=0;i<n;++i)
        if(i<rev[i])swap(a[i],a[rev[i]]);
    for(int h=1;h<n;h<<=1){
        cd wn=exp(cd(0,on*PI/h));
        for(int j=0;j<n;j+=h<<1){
            cd wnk(1,0);
            for(int k=j;k<j+h;++k){
                cd x=a[k],y=wnk*a[k+h];
                a[k]=x+y;
                a[k+h]=x-y;
                wnk*=wn;
            }
        }
    }
    if(on==-1){
        for(int i=0;i<n;++i){
            a[i]/=n;
        }
    }
}
int n,m,N,ans[maxn];
char s1[maxn],s2[maxn];
void solver(char now,char los){
    reverse(s1,s1+m);
    for(int i=0;i<N;++i){
        a[i]=b[i]=0;
    }
    for(int i=0;i<m;++i){
        if(s1[i]==now)a[i]=1;
        else a[i]=0;
    }
    for(int i=0;i<n;++i){
        if(s2[i]==los)b[i]=1;
        else b[i]=0;
    }
    reverse(s1,s1+m);
    fft(a,N,1);
    fft(b,N,1);
    for(int i=0;i<N;++i)a[i]=a[i]*b[i];
    fft(a,N,-1);
    for(int i=m;i<=n+m-1;++i){
        ans[i-m]+=(int)(a[i-1].real()+0.01);
    }
}
void solve(){
    scanf("%d%d",&n,&m);
    for(N=1;N<=(m+n+m);N<<=1);
    getrev(N);
    scanf("%s%s",s2,s1);
    solver('R','S');//R -> S
    solver('S','P');
    solver('P','R');
    int tot=0;
    for(int i=0;i<n;++i)tot=max(ans[i],tot);
    printf("%d\n",tot);
}
int main(){
    solve();
    return 0;
}
