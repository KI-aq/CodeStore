#include<bits/stdc++.h>
using namespace std;
const int N=1010,M=20005;
struct node{
    int to,next;
}e[M];
int head[N],tot=0;
inline void add(register int u,register int v)
{
    e[++tot]=(node){v,head[u]};
    head[u]=tot;
}
void init(){
    tot=0;
    memset(head,0,sizeof head);
}
int n,m,es,ans;
int dx[N],dy[N],mx[N],my[N],vis[N],dis;
inline bool bfs()
{
    queue<int> q;
    dis=1926081700;
    memset(dx,-1,sizeof(dx));
    memset(dy,-1,sizeof(dy));
    for(register int i=1;i<=n;++i)
        if(mx[i]==-1)
        {
            q.push(i);
            dx[i]=0;
        }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(dx[u]>dis)
            break;
        for(register int i=head[u];i;i=e[i].next)
        {
            int v=e[i].to;
            if(dy[v]==-1)
            {
                dy[v]=dx[u]+1;
                if(my[v]==-1)
                    dis=dy[v];
                else
                {
                    dx[my[v]]=dy[v]+1;
                    q.push(my[v]);
                        }       
            }   
        }
    }
    return dis!=1926081700;
}
inline bool dfs(register int u)
{
    for(register int i=head[u];i;i=e[i].next)
    {
        int v=e[i].to;
        if(vis[v]||(dy[v]!=dx[u]+1))
            continue;
        vis[v]=1;
        if(my[v]!=-1&&dy[v]==dis)
            continue;
        if(my[v]==-1||dfs(my[v]))
        {
            my[v]=u;
            mx[u]=v;
            return true;
        }
    }
    return false;
}

vector<int> G[N],AA,BB;
int nn,VIS[N],ib[N];

bool match(int u)
{
    memset(mx,-1,sizeof(mx));
    memset(my,-1,sizeof(my));
    while(bfs())
    {
        memset(vis,0,sizeof(vis));
        for(register int i=1;i<=n;++i)
            if(mx[i]==-1&&dfs(i))
                ++ans;
    }
    /*for(int i=1;i<=n;++i){
        if(~mx[i])cerr<<BB[mx[i]-1]<<" ";
    }
    cerr<<"   waesad"<<n<<endl;
    for(int i=1;i<=m;++i){
        if(~my[i])cerr<<AA[my[i]-1]<<" ";
    }
    cerr<<m<<endl;
    cerr<<"=========================="<<endl;*/

    for(int i=1;i<=m;++i){
        if(!~my[i]){
            return 0;
        }
    }
    puts("Yes");
    printf("%d %d\n",u,n);
    for(int i=1;i<=n;++i){
        if(~mx[i])printf("%d %d\n",AA[i-1],BB[mx[i]-1]);
        else printf("%d -1\n",AA[i-1]);
    }
    return 1;
}

void solve(){
    scanf("%d%d",&nn,&es);
    for(int i=1,u,v;i<=es;++i){
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int u=1;u<=nn;++u){
        memset(VIS,0,sizeof VIS);
        memset(ib,0,sizeof ib);
        AA.clear();
        BB.clear();
        VIS[u]=1;
        for(auto v: G[u]){
            VIS[v]=1;
            AA.push_back(v);
        }
        for(int j=1;j<=nn;++j){
            if(!VIS[j]){
                BB.push_back(j);
                ib[j]=BB.size();
            }
        }
        init();
        for(int i=0;i<AA.size();++i){
            for(auto v: G[AA[i]])
                if(ib[v]>0)add(i+1,ib[v]);
        }
        n=AA.size();
        m=BB.size();
        /*for(int j=0;j<AA.size();++j)
            cerr<<AA[j]<<"      ";
        cerr<<endl;
        for(int j=0;j<BB.size();++j)
            cerr<<BB[j]<<"      ";
        cerr<<endl;
        cerr<<tot<<endl;*/
        
        if(match(u))return;
    }
    puts("No");
}
int main(){
    solve();

    return 0;
}
