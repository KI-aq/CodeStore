#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define ll long long
using namespace std;

int n,s[1000007],Next[1000007];

inline int read(){
    int Num=0;char c=getchar();
    while (!isdigit(c)) c=getchar();
    while (isdigit(c)){
        Num=Num*10+c-'0';
        c=getchar();
    }
    return Num;
}

void KMP(){
    for (int i=1;i<n;++i){
        int p=Next[i-1];
        while (p>0&&s[p]!=s[i])
            p=Next[p-1];
        if (s[p]==s[i]) Next[i]=p+1;
    }
}

int main(){
    n=read();
    for (int i=n-1;i>=0;--i) s[i]=read();
    KMP();
    int ans=1e9,k,p;
    for (int i=n-1;i>=0;--i){
        if ((n-1-i)+(i+1-Next[i])<=ans){
            k=n-1-i;
            p=i+1-Next[i];
            ans=k+p;
        }
    }
    printf("%d %d\n",k,p);
}
