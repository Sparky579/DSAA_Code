#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int stk[1001000],head=0,tail=0;
long long ans=0,now=0;
char c[100100];
typedef long long LL;
int qmi(int a,int k,int p) 
{
    int res = 1; 
    while(k)
    {
        if(k&1) res = (LL)res * a % p;
        k >>= 1;
        a = (LL)a * a % p; 
    }
    return res;
}
 
int main()
{
    scanf("%s",c+1);
    int len=strlen(c+1);
    for (int i=1;i<=len;i++) {
        if (c[i]=='(') {
            stk[++head]=1;
        }
        if (c[i]==')') {
            tail++;
            if (c[i-1]=='(') ans=(ans+qmi(2,head-tail,514329))%514329;
        }
    }
    printf("%lld\n",ans);
}
