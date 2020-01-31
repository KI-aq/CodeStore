#include<bits/stdc++.h>
using namespace std;
const int maxn=1<<14;
int n,k,x;
int tp[maxn],w[maxn],sz[maxn];
string s;
vector<pair<int,int> > V;
void output(){
        V.clear();
        int sum=0;
        for(int i=1;i<=n;++i){
                V.push_back(make_pair(tp[i],w[i]));
                sum+=w[i];
        }
        sort(V.begin(),V.end());
        int tmp=0;
        for(auto v: V){
                tmp+=v.second;
                if(tmp*2>=sum){
                        x=v.first;
                        break;
                }
        }
        cout<<x<<endl;
}
bool input(){
        cin>>s;
        if(s[0]=='E')return 1;
        for(int i=1,t;i<=n;++i){
                cin>>t;
                if(t==0)w[i]=tp[i]=sz[i]=0;
                else if(tp[i]==x||(tp[i]<x)==(s[0]=='<')){
                        tp[i]=t;
                        w[i]>>=1;
                        --sz[i];
                }
        }
        return 0;
}
void solve(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>k;
        for(int i=1;i<=n;++i){
                cin>>tp[i];
                w[i]=1<<(sz[i]=k);
        }
        while(1){
                output();
                if(input())break;
        }
}
int main(){
        solve();
        return 0;
}
