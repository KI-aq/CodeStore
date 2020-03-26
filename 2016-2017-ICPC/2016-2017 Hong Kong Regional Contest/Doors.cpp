#include<bits/stdc++.h>
#define pi acos(-1.0)
using namespace std;

double R,l,w;
int main(){
    scanf("%lf%lf%lf",&R,&l,&w);
    int T;scanf("%d",&T);
    for(;T--;){
        double a,b,ans=R;
        scanf("%lf%lf",&a,&b);
        a=min(a,pi/2);
        ans=min(ans,l*sin(a)/2);
        if(b<pi/2){
            double x=l*cos(b),y=w-l*sin(b),dis=sqrt(x*x+y*y),ang;
            ang=min(atan2(y,x)+a,pi/2);
            ans=min(ans,dis*sin(ang)/2);
            ang=min(atan2(y,x)+b,pi/2);
            ans=min(ans,dis*sin(ang)/2);
        }
        else ans=min(ans,(w-l*sin(b))/2);
        printf("%.9lf\n",ans);
    }
    return 0;
}
