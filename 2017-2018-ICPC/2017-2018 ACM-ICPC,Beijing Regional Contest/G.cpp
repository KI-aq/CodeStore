#include<bits/stdc++.h>
using namespace std;

const double eps=1e-9;
int dcmp(double x){return fabs(x)<eps?0:(x>0?1:-1);}
struct point{
    double x,y;
    point(double x=0,double y=0):x(x),y(y){}
    bool operator==(const point &p)const{return dcmp(x-p.x)==0&&dcmp(y-p.y)==0;}
    point operator/(double m)const{return point(x/m,y/m);}
    point operator-(point p)const{return point(x-p.x,y-p.y);}
    point operator+(point p)const{return point(x+p.x,y+p.y);}
};
double mul(point p0,point p1,point p2){return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);}
double len(point a){return sqrt(a.x*a.x+a.y*a.y);}
bool cross(point s1,point e1,point s2,point e2){
    if(max(s1.x,e1.x)<min(s2.x,e2.x))return 0;
    if(max(s2.x,e2.x)<min(s1.x,e1.x))return 0;
    if(max(s1.y,e1.y)<min(s2.y,e2.y))return 0;
    if(max(s2.y,e2.y)<min(s1.y,e1.y))return 0;
    return (mul(s1,s2,e1)*mul(s1,e1,e2)>0)&&(mul(s2,s1,e2)*mul(s2,e2,e1)>0);
}
bool edge(point p,point a,point b){
    point t1=a-p,t2=p-b;
    return (t1/len(t1)==t2/len(t2))&&dcmp(len(t1)+len(t2)-len(a-b))==0;
}
bool intri(point p,point a,point b,point c){
    if(edge(p,a,b)||edge(p,b,c)||edge(p,c,a))return 0;
    return mul(p,a,b)*mul(p,b,c)>0&&mul(p,c,a)*mul(p,b,c)>0;
}

const int N=30,dx[8]={1,-1,0,0,1,1,-1,-1},dy[8]={0,0,1,-1,1,-1,1,-1};
char ch[N][N];
bool vis[N][N];
struct node{
    int x,y,st;
    node(int x=1,int y=1,int st=0):x(x),y(y),st(st){}
};


void solve(){
    point a,b,c,d,td;
    for(int n;~scanf("%d",&n);){
        memset(vis,0,sizeof vis);
        scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
        a.x+=1.0;b.y+=1.0;b.x+=1.0;a.y+=1.0;c.x+=1.0;c.y+=1.0;
        for(int i=n;i;--i)
            scanf("%s",ch[i]+1);
        queue<node> Q;
        vis[1][1]=1;
        Q.push(node());
        for(node u;!Q.empty();){
            u=Q.front();Q.pop();
            d=point(u.x,u.y);
            for(int i=0,tx,ty;i<8;++i){
                tx=u.x+dx[i];ty=u.y+dy[i];
                td=point(tx,ty);
                if(tx<1||tx>n||ty<1||ty>n||vis[tx][ty]||ch[ty][tx]=='#')continue;
                if(cross(d,td,a,b)||cross(d,td,b,c)||cross(d,td,c,a))continue;
                if(intri(td,a,b,c)||intri(point((u.x+tx)/2.0,(u.y+ty)/2.0),a,b,c))continue;
                point dec=td-d;
                dec=(dec/len(dec))/1e7;
                if(intri(d+dec,a,b,c)||intri(td-dec,a,b,c))continue;

                vis[tx][ty]=1;
                if(tx==n&&ty==n){printf("%d\n",u.st+1);goto G;}
                Q.push(node(tx,ty,u.st+1));
            }
        }
        puts("-1");
        G:;
    }
}
int main(){
    solve();
    return 0;
}
