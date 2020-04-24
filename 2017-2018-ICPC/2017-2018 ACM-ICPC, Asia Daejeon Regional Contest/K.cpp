#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> l;
void solve(){
    scanf("%d",&n);
    l.push_back(-1);
    for(int i=1,x,y;i<=n;++i){
        scanf("%d%d",&x,&y);
        l.push_back(y);
    }
    int tot=1;
    printf("%d ",tot);
    for(int i=1;i<l.size()-1;++i){
        if(l[i]==l[i-1]){
            printf("%d ",i+1);
        }
        else{
            printf("%d ",1);
        }
    }
}
int main(){
    solve();
    return 0;
}
