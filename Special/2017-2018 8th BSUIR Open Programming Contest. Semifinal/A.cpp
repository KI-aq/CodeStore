#include <bits/stdc++.h>
using namespace std;
int sum[10],i,j,len,ans;
const int mo=1e9+7;
char s[1100];
char a[10];
int main()
{
	scanf("%s",s);
	strcpy(a,"BSUIROPEN");
	len=strlen(s);
	for (i=0;i<len;i++)
	{
		for (j=0;j<9;j++)
		{
			if (s[i]==a[j]) 
			{
			sum[j]++;
			break;
		    }
		}
	}
	ans=1;
	for (i=0;i<9;i++) ans=(1ll*ans*sum[i])%mo;
	printf("%d",ans);
} 
