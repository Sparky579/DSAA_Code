#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
long long p = 19260817, mod = 1e9 + 7;
char c[300100],d[300100];
long long hsc[300100],hsd[300100],hse[300100];
long long poww[300100];
long long aa[300100],bb[300100];
char e[300100];
int ANS=-1;
long long hush(long long* array, int l, int r)
{
    return (((array[r] - (array[l - 1] * poww[r - l+1])) % mod) + mod) % mod;
}
int main()
{
    scanf(" %s %s",c+1,d+1);
    int lenc = strlen(c+1);
    int lend = strlen(d+1);
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
    int l=0,r=(min(lenc, lend)-1)/2,mid,mi;
//  printf("%lld\n",poww[1]);
//  printf("%lld %lld\n",hush(hsc, 1, 3), hush(hsd, 2, 4));
    while (l<=r) {
        mi=(l+r)>>1;
        mid=mi*2+1;
        int cnt=0,cnt2=0;
    //  printf("%s %s\n",c+1,e+1);
        for (int i=1;i+mid-1<=lenc;i++) {
        if (hush(hsc, i, i + mid - 1) == hush(hse, lenc - i - mid + 2, lenc - i + 1))
            aa[++cnt]=hush(hsc, i, i+mid-1);
        //  printf("%d %d %d %d\n",i,i+mid-1,lenc-i-mid+1,lenc-i+1);
        }
        for (int i=1;i+mid-1<=lend;i++){
            bb[++cnt2]=hush(hsd, i, i+mid-1);
        }
        sort(aa+1,aa+cnt+1);
        sort(bb+1,bb+cnt2+1);
        int p=1,flag=0;
        for (int i=1;i<=cnt;i++) {
            while (bb[p]<=aa[i]&&p<=cnt2) {
                if (bb[p]==aa[i]) flag=1;
                p++;
            }
        }
        if (flag==1) {
            ANS=max(ANS,mid);
            l=mi+1;
        }
        else {
            r=mi-1;
        }
    }
     
    l=1;r=(min(lenc, lend))/2;
    while (l<=r) {
        mi=(l+r)>>1;
        mid=mi*2;
        int cnt=0,cnt2=0;
        for (int i=1;i+mid-1<=lenc;i++) {
            if (hush(hsc, i, i + mid - 1) == hush(hse, lenc - i - mid + 2, lenc - i + 1))
            aa[++cnt]=hush(hsc, i, i+mid-1);
        //  printf("%d %d %d %d\n",i,i+mid-1,lenc-i-mid+2,lenc-i+1);
        }
        for (int i=1;i+mid-1<=lend;i++){
            bb[++cnt2]=hush(hsd, i, i+mid-1);
        }
        sort(aa+1,aa+cnt+1);
        sort(bb+1,bb+cnt2+1);
        int p=1,flag=0;
        for (int i=1;i<=cnt;i++) {
            while (bb[p]<=aa[i]&&p<=cnt2) {
                if (bb[p]==aa[i]) flag=1;
                p++;
            }
        }
        if (flag==1) {
            ANS=max(ANS,mid);
            l=mi+1;
        }
        else {
            r=mi-1;
        }
    }
    printf("%d\n",ANS);
}
