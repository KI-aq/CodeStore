#include <bits/stdc++.h>
#define N 300
using namespace std;
int head[N],t[N],i,j,n,m,k,l,o,p,T,tot,dfn[N],low[N],deep,ans,tail;
bool vise[N];
struct sl
{
	int next,id;
} e[N*N];
void add(int x,int y)
{
    e[++tot].next=head[x];
	e[tot].id=y;
	head[x]=tot;	
}
void tarjan(int u)
{
	dfn[u]=low[u]=++deep;
	t[++tail]=u;
	vise[u]=true;
	for (int i=head[u];i!=-1;i=e[i].next)
	{
		int v=e[i].id;
		if (!dfn[v]) 
		{
		tarjan(v);
		low[u]=min(low[u],low[v]);
	    } else
	    if (vise[v]) low[u]=min(low[u],dfn[v]);
	}
	if (dfn[u]==low[u])
	{
		ans++;
		while (t[tail]!=u) 
		{
			vise[t[tail--]]=false;
		}
		vise[t[tail]]=false;
		tail--;
	}
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		memset(dfn,0,sizeof dfn);
		memset(low,0,sizeof low);
		memset(head,-1,sizeof head);
		memset(vise,false,sizeof vise);
		tail=0;
		tot=0;
		ans=0;
		deep=0;
		scanf("%d",&m);
		for (i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x++;y++;
			add(x,y);
		}
		for (i=1;i<=n;i++)
		if (!dfn[i]) tarjan(i);
		printf("%d\n",ans);
	}
}
