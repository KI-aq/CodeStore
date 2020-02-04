#include <bits/stdc++.h>
#define N 1100
using namespace std;
int sum[N][N],i,j,n,m,k,l,o,p,T,ans[N][N],r;
char ch;
int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    return x*f;
}
int main()
{
    T=read();
	while (T--)
	{
		n=read();
        m=read();
        for (i=1;i<=n;i++)
		{
			for (j=1;j<=m;j++)
			{
				ch=getchar();
                for(;ch!='0'&&ch!='1';ch=getchar());//continue;
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(ch^48); 
			}
		}
        int ret=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                ans[i][j]=ans[i-1][j-1]-1;
                if(ans[i][j]<1)ans[i][j]=1;
                while(i+ans[i][j]<=n&&j+ans[i][j]<=m&&
                    (sum[i+ans[i][j]][j+ans[i][j]]-sum[i-1][j+ans[i][j]]-sum[i+ans[i][j]][j-1]+sum[i-1][j-1]<=1))
                        ans[i][j]++;
                ret=max(ret,ans[i][j]);
            }
        }
		printf("%d\n",ret);
	}
}
