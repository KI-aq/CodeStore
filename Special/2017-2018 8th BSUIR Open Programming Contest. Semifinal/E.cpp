#include <bits/stdc++.h>
using namespace std;
int f[1600],i,j,n,m,k,a[27],sum[5],len,ans,b[27];
char s[1100];
bool flag;
const int mo=1e9+7;
void pd(char x)
{
	int p;
	if (!flag) p=-1;else p=1;
	if (x=='2') sum[1]+=1*p;
	if (x=='3') sum[2]+=1*p;
	if (x=='4') sum[1]+=2*p;
	if (x=='5') sum[3]+=1*p;
	if (x=='6') sum[1]+=1*p,sum[2]+=1*p;
	if (x=='7') sum[4]+=1*p;
	if (x=='8') sum[1]+=3*p;
	if (x=='9') sum[2]+=2*p;
}
int solve(int m)
{
	if (m==0) return 1;
	memset(f,0,sizeof f);
	f[0]=1;
	int i,j,k;
	for (i=1;i<=n;i++)
	 for (j=0;j<=m;j++)
	   if (j-b[i]>=0) f[j]=(f[j]+f[j-b[i]])%mo;
	return f[m];
}
int main()
{
	scanf("%s",s);
	len=strlen(s);
	for (i=0;i<len;i++)
	{
		if (s[i]=='*') continue;
		if (s[i]>='a'&&s[i]<='z') a[s[i]-'a'+1]++;
		else if (s[i]=='=') flag=true;else
		pd(s[i]);
	}
	for (i=1;i<=4;i++)
	if (sum[i]<0)
	{
		printf("0");return 0;
	}
	for (i=1;i<=26;i++)
	if (a[i]>0) b[++n]=a[i];
	ans=1;
	for (i=1;i<=4;i++)
	ans=1ll*ans*solve(sum[i])%mo;
	printf("%d",ans);
}
