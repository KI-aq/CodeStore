#include<bits/stdc++.h>
using namespace std;
const int maxn=200010,inf=1<<25;
int n;
int vis[maxn],lab[maxn],used[maxn];
int u[maxn],v[maxn];
int deg[maxn];
vector<int> p;
void output(){
    printf("%d\n",n);
    for(int i=1;i<n;++i){
        printf("%d %d\n",lab[u[i]],lab[v[i]]);
    }
}
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",vis+i);
    }
    for(int i=1;i<=n;++i){
        lab[i]=i;
        used[i]=1;
    }
    for(int i=1;i<n;++i){
        scanf("%d%d",u+i,v+i);
        ++deg[u[i]];
        ++deg[v[i]];
    }
    int chk=n;
    for(int i=1;i<=n;++i){
        if(deg[i]&1){
            chk^=i;
            if(vis[i])p.push_back(i);
        }
    }
    used[0]=1;
    if(chk==0){
        output();
    }
    else{
        if(p.size()==0){
            puts("-1");
            return;
        }
        else if(p.size()==2){
            int a,b,tmp=chk^(p[0])^(p[1]);
            if(tmp!=0){
                a=p[0];
                b=p[1];
            }
            else{
                puts("-1");
                return;
            }
            lab[a]=inf;
            lab[b]=inf^tmp;
            output();
        }
        else if(p.size()>2){
            int a,b,tmp=chk^(p[0])^(p[1]);
            if(tmp==0){
                a=p[0];
                b=p[2];
                tmp=chk^a^b;
            }
            else{
                a=p[0];
                b=p[1];
            }
            lab[a]=inf;
            lab[b]=inf^tmp;
            output();
        }
        else{
            int tmp=chk^p[0];
            if(!used[tmp]){
                lab[p[0]]=tmp;
                output();
            }
            else if(used[tmp]&&vis[tmp]==1&&deg[tmp]%2==0){
                lab[tmp]=inf;
                lab[p[0]]=tmp;
                output();
            }
            else{
                puts("-1");
                return;
            }
        }
    }
}
int main(){
    solve();
    return 0;
}
/*
5
0 1 0 1 0
1 3
1 4
2 5
3 5

*/
