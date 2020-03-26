#include <iostream>
#define  ll long long
using namespace std;

bool pd[10];
ll n,a[10],Ans[10],x[10];

void dfs(int Step){
    if (Step>n){
        if (x[0]>=Ans[0]){
            Ans[0]=x[0];
            for (int i=1;i<=n;++i) Ans[i]=x[i];
        }
        return;
    }
    for (int i=1;i<=n;++i)
    if (!pd[i]){
        pd[i]=true;x[0]^=a[i];x[Step]=i;
        dfs(Step+1);
        pd[i]=false;x[0]^=a[i];
    }
}

int main() {
    cin>>n;
    for (int i=1;i<=n;++i) cin>>a[i];
    dfs(1);
    for (int i=1;i<=n;++i) cout<<Ans[i]<<" ";
    return 0;
}
