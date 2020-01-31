#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
#define N 310000
int a[N],i,j,n,m,k,l,o,p;
long long sum;
bool Check;
int main()
{
	scanf("%d%d%d",&k,&n,&m);
	sum=k;
	for (i=1;i<=k;i++)
	{
	 scanf("%d",&a[i]);
	 if (a[i]==-1&&i!=1) a[i]=a[i-1];else 
	 if (a[i]==-1) a[i]=1;
     if (a[i]<a[i-1]){
         Check=true;
     }
    }
    if (n<k||Check) printf("-1");else
    {
    	sum+=m-a[1];
    	for (i=2;i<=k;i++)
    	sum+=m-a[i];//+a[i-1]-1;
    	if (sum<n) printf("-1");else
    	{
    		sum=n-k;
    		for (i=1;i<=k;i++)
    		{
    			for (j=m;j>a[i]&&sum>0;j--,sum--)
    			printf("%d ",j);
    			//if (i>1)
    			//for (j=a[i-1]-1;j>=1&&sum>0;j--,sum--)
    			//printf("%d ",j);
    			printf("%d ",a[i]);	
			}
		}
	}
}
