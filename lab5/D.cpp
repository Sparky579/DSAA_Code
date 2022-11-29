#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
long long p = 19260817, mod = 1e9 + 7;
char c[1000100],d[1000100];
long long hsc[1000100],hsd[1000100],hse[1000100];
long long poww[300100];
long long aa[1000100],bb[1000100];
char e[1000100];
int ANS=-1;
long long hush(long long* array, int l, int r)
{
    return (((array[r] - (array[l - 1] * poww[r - l+1])) % mod) + mod) % mod;
}
int main()
{
    scanf("%d",&ANS);
    scanf(" %s %s",c+1,d+1);
    int lenc = strlen(c+1);
    int lend = strlen(d+1);
    for (int i=1;i<=lenc;i++) {
        char cc=c[i];
        if (cc=='W') c[i]='E';
        if (cc=='E') c[i]='W';
        if (cc=='N') c[i]='S';
        if (cc=='S') c[i]='N';
    }
    for (int i=1;i<=lenc;i++) {
        e[i]=c[i];
        hsc [i] = (hsc[i-1] * p + c[i]) % mod;
    }
    reverse(e+1,e+lenc+1);
    for (int i=1;i<=lenc;i++)
    {
        hse[i]=(hse[i-1]*p+e[i]) % mod;
    }
    for (int i=1;i<=lend;i++) {
        hsd [i] = (hsd[i-1] * p + d[i]) % mod;
    }
    poww[0]=1;
    for (int i=1;i<=300000;i++)
    poww[i] = (poww[i-1] * p) % mod;
    bool oo=0;
    for (int i = 1; i <= lenc; i++) {
        if (hush(hse, 1, i) == hush(hsd, lenc-i+1, lenc)) 
        oo=1;
    }
//  printf("%s %s\n",e+1,d+1);
    if (oo) printf("NO");
    else printf("YES");
}
