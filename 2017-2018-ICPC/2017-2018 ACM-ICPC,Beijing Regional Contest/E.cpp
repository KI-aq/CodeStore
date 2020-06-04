#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>Cat[1007];

bool Eating[107];
int n,m,x,c[107],ans1,ans2;

int main(){
    while (~scanf("%d%d%d",&m,&n,&x)){
        ans1=m;ans2=0;
        for (int i=1;i<=n;++i) scanf("%d",&c[i]);
        sort(c+1,c+n+1);

        for (int i=1;i<=n;++i)
            for (int j=0;j*c[i]<=x;++j)
                Cat[c[i]*j].push_back(i);

        for (int i=0;i<=x;++i)
            for (auto p:Cat[i]){
                
                ans2-=Eating[p];
                Eating[p]=0;

                if (m>0){
                    Eating[p]=1;m--;
                    if (i!=x) ans2++,ans1--;
                }

            }
        printf("%d %d\n",ans1,ans2);
        for (int i=0;i<=x;++i) Cat[i].erase(Cat[i].begin(),Cat[i].end());
        for (int i=1;i<=n;++i) Eating[i]=0;
    }
}
