#include <bits/stdc++.h>
#define N 210000
using namespace std;
int a[N],b[N],i,j,n,m,ans,len;
char s[N],t[N];
int main()
{
	scanf("%d",&len);
	scanf("%s",s+1);
	scanf("%s",t+1);
	for (i=1;i<=len;i++)
	if (s[i]!=t[i])
	{
		if (s[i]=='a') a[++n]=i;else
		b[++m]=i;
	} 
	if ((n+m)%2) printf("-1\n");else
	{
		ans=(n/2)+(m/2);
		if (n%2) ans+=2;
		printf("%d\n",ans); 
		while (n>1)
		{
			printf("%d %d\n",a[n],a[n-1]);
			n-=2;
		}
		while (m>1)
		{
			printf("%d %d\n",b[m],b[m-1]);
			m-=2;
		}
		if (n==1)
		{
			printf("%d %d\n",a[1],a[1]);
			printf("%d %d\n",a[1],b[1]);
		}
	}
}
