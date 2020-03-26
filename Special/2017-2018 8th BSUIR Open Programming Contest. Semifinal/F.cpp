#include <bits/stdc++.h>
#define N 2100000
using namespace std;
struct sl
{
	int num,id;
} a[N];
int i,j,n,m,k,l,o,p,minn,ansi,ans[N];
bool cmp(sl x,sl y)
{
	return x.num<y.num;
}
int main()
{
	scanf("%d%d",&n,&k);
	p=(n+1)/2;
	for (i=1;i<=n;i++)
	 {
	 	scanf("%d",&a[i].num);
	 	a[i].id=i;
	 }
	 sort(a+1,a+n+1,cmp);
	 ansi=-1e9;
	 minn=1e9;
	 for (i=1;i<=n;i++)
	 {
	 	if (abs(a[i].num-k)<minn||(abs(a[i].num-k)==minn&&abs(i-p)<abs(ansi-p)))
	 	{
	 		ansi=i;minn=abs(a[i].num-k);
		 }
	 }
	ans[++ans[0]]=a[ansi].id;
	l=1;
	while (1)
	{
		if (ansi+l>n) break;
		ans[++ans[0]]=a[ansi+l].id;
		if (ansi-l<=0) break;
		ans[++ans[0]]=a[ansi-l].id;
		l++;
	}
	sort(ans+1,ans+ans[0]+1);
	printf("%d\n",ans[0]); 
	for (i=1;i<=ans[0];i++)
	printf("%d ",ans[i]); 
}
