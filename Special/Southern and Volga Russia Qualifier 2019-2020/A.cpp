#include <iostream>
#include <algorithm>
using namespace std;

int a1,a2,k1,k2,n,Min,Max;

int main() {
    cin>>a1>>a2>>k1>>k2>>n;
    if (k1<k2) swap(k1,k2),swap(a1,a2);

    if (n>a1*(k1-1)+a2*(k2-1)){
        Min=min(n-a1*(k1-1)-a2*(k2-1),a1+a2);
    }

    Max=min(n/k2,a2)+min((n-min(n/k2,a2)*k2)/k1,a1);

    cout<<Min<<" "<<Max<<endl;
    return 0;
}
