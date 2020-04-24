#include <bits/stdc++.h>
std::map<int,int>G;
int map[5][5],i,j,ans,x,y,k,len[5];
int b[12][4]={1,0,2,0,-1,0,-2,0,0,-1,0,-2,0,1,0,2,1,0,-1,0,0,1,0,-1,-1,1,-2,2,1,-1,-1,1,1,-1,2,-2,-1,-1,-2,-2,-1,-1,1,1,1,1,2,2};
bool limit(int x)
{
	if (x>=1&&x<=4) return true;else return false;
}
bool pd()
{
	int m=1,sum=0;
	for (int i=1;i<=4;i++)
	 for (int j=1;j<=4;j++)
	  sum+=map[i][j]*m,m*=3;
	if (G[sum]) return false;else
	{
		G[sum]=1;return true;
	}
}
bool check(int x,int y)
{
	int x1,y1,x2,y2;
	for (int i=0;i<12;i++)
	{
		x1=x+b[i][0];y1=y+b[i][1];
		x2=x+b[i][2];y2=y+b[i][3];
		if (limit(x1)&&limit(y1)&&limit(x2)&&limit(y2)) 
		{
			if (map[x1][y1]==map[x][y]&&map[x2][y2]==map[x][y]) return true;
		}
	} 
	return false;
}
void dfs(int n,int fx,int fy,int now)
{
	if (!pd()) return;
	if (check(fx,fy))
	{
		if (fx==x&&fy==y&&now==1) ans++;
		return;
	} else if (fx==x&&fy==y) return;
	for (int i=1;i<=4;i++)
	if (len[i]<4)
	{
		map[++len[i]][i]=now;
		dfs(n+1,len[i],i,3-now);
		map[len[i]][i]=0;
		--len[i];
	}
}
int main()
{
	scanf("%d",&k);
	scanf("%d%d",&x,&y);
	memset(map,0,sizeof map);
	map[++len[k]][k]=1;
	dfs(2,1,k,2);
	printf("%d",ans);
}
