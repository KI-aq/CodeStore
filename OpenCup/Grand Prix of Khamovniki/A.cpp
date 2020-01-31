#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;

struct Info{
    int sa,sb;
};

bool pd[107];
int Num[107];
int n,s,Order[107],a[107],b[107];

bool cmp(int x,int y){
    return x>y;
}

Info dfs(int p,int x,int y,int sa,int sb){
    if (p>Order[0]){
        return (Info){sa,sb};
    }
    Info u,v;
    if (Order[p]<=n){
        u=v=(Info){-100000000,0};
        if (x<=a[0]&&Num[Order[p]]<s) 
         ++Num[Order[p]],u=dfs(p+1,x+1,y,sa+a[x],sb),--Num[Order[p]];
        if (y<=b[0]&&(!pd[Order[p]])){
            pd[Order[p]]=true;
            v=dfs(p+1,x,y+1,sa+b[y],sb);
            pd[Order[p]]=false;
        }
        //printf("u:%d %d   v:%d %d\n",u.sa,u.sb,v.sa,v.sb);
        if (u.sa-u.sb>v.sa-v.sb) return u;
        else return v;
    }
    else {
        u=v=(Info){0,-100000000};
        if (x<=a[0]&&Num[Order[p]]<s)
            ++Num[Order[p]],u=dfs(p+1,x+1,y,sa,sb+a[x]),--Num[Order[p]];
        if (y<=b[0]&&(!pd[Order[p]])){
            pd[Order[p]]=true;
            v=dfs(p+1,x,y+1,sa,sb+b[y]);
            pd[Order[p]]=false;
        }
        //printf("u:%d %d   v:%d %d\n",u.sa,u.sb,v.sa,v.sb);
        if (u.sb-u.sa>v.sb-v.sa) return u;
        else return v;
    }
}

int main(){
    scanf("%d%d",&n,&s);
    Order[0]=2*n*(s+1);
    for (int i=1;i<=Order[0];++i)
        scanf("%d",&Order[i]);
    scanf("%d",&a[0]);
    for (int i=1;i<=a[0];++i) scanf("%d",&a[i]);
    scanf("%d",&b[0]);
    for (int i=1;i<=b[0];++i) scanf("%d",&b[i]);
    sort(a+1,a+a[0]+1,cmp);
    sort(b+1,b+b[0]+1,cmp);
    Info ans=dfs(1,1,1,0,0);
    printf("%d\n",ans.sa-ans.sb);
    return 0;
}
