#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

char str[200007];
int n,sum[2],Count[2],del;

int main(){
    scanf("%d\n%s",&n,str+1);
    for (int i=1;i<=n/2;++i){
        if (str[i]=='?') ++Count[0];
        else sum[0]+=str[i]-'0';
    }
    for (int i=n/2+1;i<=n;++i){
        if (str[i]=='?') ++Count[1];
        else sum[1]+=str[i]-'0';
    }
    if (sum[0]<sum[1]) swap(sum[0],sum[1]),swap(Count[0],Count[1]);
    del=Count[1]-Count[0];
    if (del<0){
        puts("Monocarp");
    }
    else {
        int m=(del+1)/2,b=del/2,x=sum[0]-sum[1];
        if ((x-m*9)>=0&&(x-m*9)<=9*b&&x>=0&&x<=b*9&&(del%2==0)) puts("Bicarp");
        else puts("Monocarp");
    }
}
