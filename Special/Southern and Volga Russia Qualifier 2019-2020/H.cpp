#include <unordered_map>
#include <cstdio>
#include <algorithm>
#define  ll long long
using namespace std;

ll x[3007];
int n,ans,f[3007][3007];

int main(){
    ans=2;
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%lld",&x[i]);
    }
    for (int i=n;i;--i) {
        int Next=i+2;
        for (int j = i + 1; j <= n; ++j) {
            f[i][j] = 2;
            while (Next<=n&&x[Next]-x[j]<x[j]-x[i]) ++Next;
            if (Next<=n&&x[Next]-x[j]==x[j]-x[i])
                f[i][j] = f[j][Next] + 1;
            ans = max(ans, f[i][j]);
        }
    }
    printf("%d\n",ans);
}
