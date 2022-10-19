#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#define N 2000
#define aa(x) (((x)>0)?(x):(-(x)))
#define ll long long
using namespace std;
int primes[2010],cnt=0,st[2010],sum[2010];
void get_primes()
{
    for (int i=2;i<=N;i++){
        if (!st[i]) primes[++cnt]=i;
        for (int j=1;j<=cnt && i*primes[j] <= N;j++) {
            st[primes[j]*i]=primes[j];
            if (i % primes[j] == 0) break;
        }
    }
}
ll pw(ll a,ll b,ll mod)
{
    a%=mod;
    ll ans=1;
    while (b){
        if (b&1) {
            ans=(ans*a)%mod;
        }
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
void add(ll x,int num)
{
    while (st[x]) {sum[st[x]]+=num; x/=st[x]; }
    if (x>1) sum[x]+=num;
}
ll C(ll x,ll y,ll mod)
{
    for (int i=y;i>=y-x+1;i--) {
        add(i,1);
    }
    for (int i=1;i<=x;i++) add(i,-1);
    ll ans=1;
    for (int i=2;i<=N;i++)
    if (sum[i])
    ans=(ans*pw(i,sum[i],mod))%mod;
    return ans;
}
int main()
{
    get_primes();
    long long a,b,c,d,e;
    scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e);
    long long a1=aa(a-c);
    long long a2=aa(b-d);
    printf("%lld\n",C(a1,a1+a2,e));
}
