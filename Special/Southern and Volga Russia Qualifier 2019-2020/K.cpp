#include <bits/stdc++.h>
using namespace std;
int i,j,n,m,k,x,y;
int main()
{
	scanf("%d",&n);
	printf("%d\n",n*n/4*3);
	x=y=1;
	while (x<=n-1)
	{
		while (y<=n-1)
		{
		printf("%d %d %d %d\n",1,x,y+1,2);
		printf("%d %d %d %d\n",1,x+1,y,2);
		printf("%d %d %d %d\n",2,x,y,1);
		y+=2;
	    }
	    x+=2;y=1;
	}
}
