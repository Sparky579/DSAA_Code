#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#define print(x) cc[cnt]+=x;
#define aa(x) (((x)>0)?(x):(-(x)))
using namespace std;
long long g[2010][2010];
int main()
{
    long long a,b,c,d,e;
    scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e);
    long long a1=aa(a-c);
    long long a2=aa(b-d);
    g[0][0]=1;
//  printf("%lld %lld\n",a1,a1+a2);
    for (int i=1;i<=2000;i++){
        g[i][0]=1;
        for (int j=1;j<=i;j++)
        g[i][j]=(g[i-1][j-1]+g[i-1][j])%e;
    }
    printf("%lld\n",g[a1+a2][a1]);
}
