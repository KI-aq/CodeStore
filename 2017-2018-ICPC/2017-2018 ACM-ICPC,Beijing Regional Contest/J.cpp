#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int T[107][107];
int N,L,R,s[107],a[107],f[107][107];

bool pd[107];
bool Check(){
    memset(pd,0,sizeof pd);
    pd[1]=true;
    for (int i=2;i<=N;++i)
        for (int j=L-1;j<=R-1;++j)
            if (i-j>=1) pd[i]|=pd[i-j];
    return pd[N];
}

int Cal(int l,int r){

    for (int i=l;i<=r;++i){
        T[i][1]=f[l][i];
        if (i==r) T[i][1]=10000000;
        for (int j=2;j<=R&&j<=(i-l+1);++j){
            T[i][j]=10000000;
            for (int Last=l;Last<i;++Last)
                T[i][j]=min(T[Last][j-1]+f[Last+1][i],T[i][j]);
        }
    }

    int Ans=10000000;
    for (int i=1;i<=r-l+1&&i<=R;++i)
        Ans=min(Ans,T[r][i]);

    return min(Ans+s[r]-s[l-1],10000000);
}

void Solve(){
    for (int i=N;i;--i)
        for (int j=i+1;j<=N;++j)
            if (pd[j-i+1]) f[i][j]=Cal(i,j);
            else f[i][j]=10000000;
    printf("%d\n",f[1][N]);
}

int main(){
    while (~scanf("%d%d%d",&N,&L,&R)){
        memset(f,0,sizeof f);
        for (int i=1;i<=N;++i) scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
        if (!Check()){
            puts("0");
            continue;
        }
        Solve();
    }
}
