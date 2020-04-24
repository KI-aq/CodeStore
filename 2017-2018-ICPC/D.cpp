#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;

bool ans[1007],pd[1007];
ll n,x,c[1007];

bool dfs(int Num){
    if (pd[Num]) return ans[Num];
    pd[Num]=true;
    return ans[Num]=dfs(c[Num]);
}

void Init(){
    for (int i=1;i<=810;++i){
        int j=i;
        while (j) c[i]+=(j%10)*(j%10),j/=10;
    }
    pd[1]=ans[1]=true;
    for (int i=2;i<=810;++i)
        ans[i]=dfs(i);
}

int main() {
    Init();
    cin>>n;
    while (n) x+=(n%10)*(n%10),n/=10;
    if (ans[x]) puts("HAPPY");
    else puts("UNHAPPY");
    return 0;
}
