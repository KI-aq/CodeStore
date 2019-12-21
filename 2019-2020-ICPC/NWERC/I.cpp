#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d", &a[i]);
	}
	int wzle;
	for(wzle = 2; wzle <= n; wzle ++)
	{
		if(a[wzle] < a[wzle - 1]) break;
	}
	if(wzle == n + 1)
	{
		printf("1 1\n");
		return 0;
	}
	int wzri;
	for(wzri = wzle + 1; wzri <= n; wzri ++)
	{
		if(a[wzri] > a[wzri - 1]) break;
	}
	wzri --;
	wzle --;
	while(a[wzle - 1] == a[wzle]) wzle --;
	for(int i = wzle, j = wzri; i < j; i ++, j --)
	{
		swap(a[i], a[j]);
	}
	bool fg = 0;
	for(int i = 2; i <= n; i ++)
	{
		if(a[i] < a[i - 1])
		{
			fg = 1;
			break;
		}
	}
	if(fg)
	{
		printf("impossible\n");
	}
	else
	{
		printf("%d %d\n", wzle, wzri);
	}
	return 0; 
}
