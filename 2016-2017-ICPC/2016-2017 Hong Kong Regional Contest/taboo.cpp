#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cstdlib>
#include<ctime>
#include<random>
#define ll long long
#define lowbit(x) (x&(-x))
using namespace std;

char s[200007];
bool pd[300007];
int ans,n,tot,ch[300007][2],fail[300007],Num[300007],mson[300007];

void Insert(){
    int len=strlen(s),cur=0;
    for (int i=0;i<len;++i){
        int p=s[i]-'0';
        if (!ch[cur][p]) ch[cur][p]=++tot;
        cur=ch[cur][p];
    }
    pd[cur]=true;
}

queue<int>q;
void Get_fail(){
    q.push(0);
    while (!q.empty()){
        int Now=q.front();q.pop();
        for (int i=0;i<2;++i){
            if (ch[Now][i]){
                fail[ch[Now][i]]=ch[fail[Now]][i];
                if (!Now) fail[ch[Now][i]]=0;
                pd[ch[Now][i]]|=pd[fail[ch[Now][i]]];
                q.push(ch[Now][i]);
            }
            else ch[Now][i]=ch[fail[Now]][i];
        }
    }
}

bool check[300007];
int dfs(int cur){
    if (pd[cur]||Num[cur]) return Num[cur];
    if (check[cur]||ans==-1){
        ans=-1;
        return 0;
    }
    check[cur]=true;
    dfs(ch[cur][0]),dfs(ch[cur][1]);
    if (Num[ch[cur][0]]>=Num[ch[cur][1]]) mson[cur]=ch[cur][0];
    else mson[cur]=ch[cur][1];
    Num[cur]=1+max(Num[ch[cur][0]],Num[ch[cur][1]]);
    check[cur]=false;
    return Num[cur];
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%s",s);
        Insert();
    }
    Get_fail();
    dfs(0);
    if (ans==-1) printf("-1");
    else {
        int cur=0;
        while (!pd[mson[cur]]){
            if (mson[cur]==ch[cur][0]) putchar('0');
            else putchar('1');
            cur=mson[cur];
        }
    }
}
