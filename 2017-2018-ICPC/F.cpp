#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define ll long long
using namespace std;

typedef pair<ll,ll> Pos;

ll n,k;
Pos ans;

Pos Solve(ll n,ll k){
    if (n==2){
        if (k==1) return make_pair(1,1);
        if (k==2) return make_pair(1,2);
        if (k==3) return make_pair(2,2);
        return make_pair(2,1);
    }
    Pos ans,x;
    if (k<=(n>>1)*(n>>1)){
        x=Solve(n/2,(n>>1)*(n>>1)-k+1);
        ans.first=x.second;
        ans.second=n/2-x.first+1;
    }
    else if (k<=(n>>1)*n){
        x=Solve(n/2,k-(n>>1)*(n>>1));
        ans.first=x.first;
        ans.second=x.second+n/2;
    }
    else if (k<=(n>>1)*(n>>1)*3){
        x=Solve(n/2,k-(n)*(n>>1));
        ans.first=x.first+n/2;
        ans.second=x.second+n/2;
    }
    else {
        x=Solve(n/2,n*n-k+1);
        ans.first=n-x.second+1;
        ans.second=x.first;
    }
    return ans;
}

int main(){
    cin>>n>>k;
    ans=Solve(n,k);
    cout<<ans.first<<" "<<ans.second<<endl;
}
