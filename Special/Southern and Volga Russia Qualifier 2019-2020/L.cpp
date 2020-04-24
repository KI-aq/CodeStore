#include <bits/stdc++.h>
using namespace std;
int n,k;
string s[2];  
void solve(){
    cin>>n>>k>>s[0]>>s[1];
    int ans=1e9+10,ansf,ansi;
    for(int i=0,mx1,mx2;i<n;++i){
        mx1=0,mx2=0;
        for(int j=0;j<n;++j){
            if(s[0][j]=='1'){
                mx1=max(mx1,abs(j-i));
                mx2=max(mx2,j+i+2+k);
            }
        }
        for(int j=0;j<n;++j){
            if(s[1][j]=='1'){
                //cerr<<"Wea"<<endl;
                mx2=max(mx2,abs(j-i));
                mx1=max(mx1,j+i+2+k);
            }
        }
        if(mx1<ans){
            ans=mx1;
            ansf=2;
            ansi=i+1;
        }
        if(mx2<ans){
            ans=mx2;
            ansf=1;
            ansi=i+1;
        }
    }
    printf("%d\n",ans);
    printf("%d %d\n",ansf,ansi);
}
int main(){
    solve();
    return 0;
}
