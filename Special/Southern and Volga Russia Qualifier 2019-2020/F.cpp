#include <bits/stdc++.h>
#define N 210000
using namespace std;
int i,j,n,m,k,l,a[N];
long long x,y,z,ans1,ans2,ans3;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=1;i<=n;i++)
	{
		if (a[i]>0)
		{
			x++;
		} else if (a[i]<0)
		{
			swap(x,y);
			y++;
		} else 
		{
			z+=x+y;
			x=0;y=0;
			z++;
		}
		ans1+=x;ans2+=y;ans3+=z;
	}
	printf("%lld %lld %lld",ans2,ans3,ans1);
}
