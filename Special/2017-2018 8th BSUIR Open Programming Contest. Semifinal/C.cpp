#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;

deque<int>q;
bool pd[100];
int n,Count[100];

int Read(){
    int Num=0;char c=getchar();
    while (!isdigit(c)) c=getchar();
    while (isdigit(c)){
        Num=Num*10+c-'0';
        c=getchar();
    }
    return Num;
}

int main(){
    n=Read();pd[0]=true;
    for (;n>0;--n){
        char c=getchar();
        while (c!='+'&&c!='-') c=getchar();
        int x;
        if (c=='+'){
            x=Read();
            q.push_back(x);
            if (!Count[x])
                for (int i=0;i<=63;++i) pd[i^x]|=pd[i];
            ++Count[x];
        }
        else {
            x=q.front();q.pop_front();
            --Count[x];
            if (!Count[x]){
                for (int i=1;i<=63;++i) pd[i]=false;
                for (int i=1;i<=42;++i)
                    if (Count[i])
                        for (int j=0;j<=63;++j)
                            pd[i^j]|=pd[j];
            }
        }
        if (pd[42]) puts("Yes");
        else puts("No");
    }
}
