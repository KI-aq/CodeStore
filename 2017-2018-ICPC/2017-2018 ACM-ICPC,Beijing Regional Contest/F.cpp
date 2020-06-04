#include<bits/stdc++.h>
using namespace std;
char a[110][110],s[110*110],b[110][100];
int n,cnt,t;
void Dfs1(int x,int y,int t){
    s[++cnt]=a[x][y];
    if(x==n&&y==n)return;
    else if((x==1&&y!=n)||x==n){
        if(t!=0){
            Dfs1(x,y+1,0);
        }
        else{
            if(x==1)Dfs1(x+1,y-1,-1);
            else Dfs1(x-1,y+1,1);
        }
    }
    else if((y==1&&x!=n)||y==n){
        if(t!=0){
            Dfs1(x+1,y,0);
        }
        else{
            if(y==1)Dfs1(x-1,y+1,1);
            else Dfs1(x+1,y-1,-1);
        }
    }
    else{
        if(t==1)Dfs1(x-1,y+1,1);
        else Dfs1(x+1,y-1,-1);
    }
}
void Dfs2(int x,int y,int dir,int t,int turn,int lim){
    b[x][y]=s[t];++t;
    if(t>n*n)return;
    if(turn%4==0)--lim,turn++;
    //cerr<<x<<" "<<y<<endl;
    if(dir==1&&y>=lim){
        dir=3;
        turn++;
    }
    else if(dir==3&&x>=lim){
        dir=2;
        turn++;
    }
    else if(dir==2&&y<=n-lim+1){
        dir=4;
        turn++;
    }
    else if(dir==4&&x<=n-lim+1){
        dir=1;
        //turn++;
    }
    if(dir==1)Dfs2(x,y+1,dir,t,turn,lim);//you
    else if(dir==2)Dfs2(x,y-1,dir,t,turn,lim);//zuo
    else if(dir==3)Dfs2(x+1,y,dir,t,turn,lim);//xia
    else Dfs2(x-1,y,dir,t,turn,lim);//shang
}
void solve(){
    while(~scanf("%d",&n)){
        cnt=0;
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(s,0,sizeof s);
        for(int i=1;i<=n;++i)
            scanf("%s",a[i]+1);
        Dfs1(1,1,1);
        //printf("%s\n",s+1);
        Dfs2(1,1,1,1,1,n);
        for(int i=1;i<=n;++i,puts(""))
            for(int j=1;j<=n;++j)
                printf("%c",b[i][j]);
    }
}
int main(){
    solve();
    return 0;
}
