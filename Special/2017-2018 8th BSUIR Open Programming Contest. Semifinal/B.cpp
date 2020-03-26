#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int n,week,Max[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
double ans,x,y,xx,yy;

int main(){
    scanf("%d",&n);
    x=n*1.0*(3.0/365.0)*pow(362.0/365.0,n-1);
    xx=pow(362.0/365.0,n);
    y=n*1.0*(1.0/365.0)*pow(364.0/365.0,n-1);
    yy=pow(364.0/365.0,n);
    for (int i=1;i<=12;++i){
        for (int j=1;j<=Max[i];++j){
            week=(week+1)%7;
            if (!week)
                ans+=1.0-x-xx;
            else if (week<5)
                ans+=1.0-y-yy;
        }
    }
    printf("%.10lf",ans);
}
