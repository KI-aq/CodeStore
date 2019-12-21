#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[4],t;

ll read(){
	ll Num=0;char c=getchar();
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9'){
		Num=Num*10+c-'0';
		c=getchar();
	}
	if (c=='.'){
		while (c<'0'||c>'9') c=getchar();
		while (c>='0'&&c<='9'){
		Num=Num*10+c-'0';
		c=getchar();
		}
	}
	return Num;
}

void Putnum(ll Num){
	printf("%lld.%02lld",Num/100,Num%100);
}

int main(){
	for (int i=0;i<4;++i) a[i]=read();
	t=read();
	sort(a,a+4);
	if (a[3]+a[2]+a[1]<=3*t) printf("infinite");
	else if (a[0]+a[1]+a[2]>3*t) printf("impossible");
	else {
		Putnum(3*t-a[2]-a[1]);
	}
		
}
