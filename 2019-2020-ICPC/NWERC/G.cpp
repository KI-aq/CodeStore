#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
double C[maxn][maxn];
void init(){
	C[0][0]=1;
	for(int i=1;i<maxn;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j){
			C[i][j]=C[i-1][j-1]+C[i-1][j];	
		}
	}
	//cerr<<C[4][2]<<" "<<C[4][4]<<endl;
}

int n,k;
double a[maxn],ans;

double fc(int n,int m){
	if (n<0||m<0||n<m) return 0;
	return C[n][m]; 
}

void solve(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;++i) scanf("%lf",&a[i]);
	for (int i=1;i<=n;++i){
		ans=0;
		for (int j=1;j<=n;++j){
			if (j<=i)
				ans+=a[j]*fc(n-(i-j+1),k-1)/fc(n,k);
			else ans+=a[j]*fc(n-(i+(n-j+1)),k-1)/fc(n,k);
		}
		printf("%lf",ans);
		if (i<n) putchar(' ');
	}
}
int main(){
	init();
	
	solve();
	
	return 0;
}
