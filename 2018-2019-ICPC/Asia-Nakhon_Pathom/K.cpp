#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;

int n;
vector<pair<pair<int,int>,int> > p;
pair<pair<int,int>,int> tmp;
namespace Treap{
	struct node{
		int dat,key,sz,lc,rc;
		node(){}
		node(int dat,int key,int sz,int lc=0,int rc=0):
			dat(dat),key(key),sz(sz),lc(lc),rc(rc){}
	}tr[maxn];
	int num,rt;
	void init(int tp){
		num=0;rt=0;
		if(tp)memset(tr,0,sizeof tr);
	}
	int newnode(int u){
		tr[++num]=node(u,rand(),1);
		return num;
	}
	void pushup(int u){
		tr[u].sz=tr[tr[u].lc].sz+tr[tr[u].rc].sz+1;
	}
	void split_v(int u,int v,int &x,int &y){
		if(!u){
			x=y=0;
			return;
		}
		if(tr[u].dat<=v)x=u,split_v(tr[u].rc,v,tr[u].rc,y);
		else y=u,split_v(tr[u].lc,v,x,tr[u].lc);
		pushup(u);
	}
	int merge(int u,int v){
		if(!u||!v)return u+v;
		if(tr[u].key<tr[v].key){
			tr[u].rc=merge(tr[u].rc,v);
			pushup(u);
			return u;
		}
		else{
			tr[v].lc=merge(u,tr[v].lc);
			pushup(v);
			return v;
		}
	}
	void output(int o){
		if(!o)return;
		if(tr[o].lc)output(tr[o].lc);
		cerr<<tr[o].dat<<endl;
		if(tr[o].rc)output(tr[o].rc);
	}
	void output(){
		output(rt);
		cerr<<endl;
	}
	void push_back(int u){
		rt=merge(rt,newnode(u));
	}
	int Find_k(int k){
		int o=rt;
		while(1){
			if(k<=tr[tr[o].lc].sz)o=tr[o].lc;
			else if(k==tr[tr[o].lc].sz+1)return tr[o].dat;
			else k-=tr[tr[o].lc].sz+1,o=tr[o].rc;
		}
	}
	void Erase(int a){
		int x,y,z;
		split_v(rt,a,x,z);split_v(x,a-1,x,y);
		y=merge(tr[y].lc,tr[y].rc);
		rt=merge(merge(x,y),z);
	}
    void Insert(int a){
        int x,y;
        split_v(rt,a,x,y);
        rt=merge(merge(x,newnode(a)),y);
    }
	int size(){
		return tr[rt].sz;
	}
}
using namespace Treap;
void solve(int Case){
    scanf("%d",&n);
    init(0);
    p.clear();
    for(int i=1,op,l,r,x,k;i<=n;++i){
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d%d",&l,&x,&r);
            p.push_back(make_pair(make_pair(l,-1),x));
            p.push_back(make_pair(make_pair(r,1),x));
        }
        else{
            scanf("%d%d",&x,&k);
            p.push_back(make_pair(make_pair(x,0),k));
        }
    }
    sort(p.begin(),p.end());
    printf("Case %d:\n",Case);
    for(int i=0;i<p.size();++i){
        tmp=p[i];
        if(tmp.first.second==-1){
            Insert(tmp.second);
        }
        else if(tmp.first.second==1){
            Erase(tmp.second);
        }
        else{
            //cerr<<tmp.first.first<<" "<<size()<<" "<<tmp.second<<endl;
            if(size()<tmp.second)puts("-1");
            else printf("%d\n",Find_k(tmp.second));
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;++i)
        solve(i);
    return 0;
}
