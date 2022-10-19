#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q,g[100010];
int fd(int x)
{
    int l=1,r=n+1,mid,ans;
    while (l<=r) {
        mid=(l+r)>>1;
        if (g[mid]>=x) ans=mid,r=mid-1;
        else l=mid+1;
    //  printf("%d\n",mid);
    }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++)
    scanf("%d",&g[i]);
    g[n+1]=2e9;
    for (int i=1;i<=q;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        int ans=fd(b)-fd(a+1);
        if (ans<=0) printf("NO\n");
        else printf("YES %d\n",ans);
         
    }
 } 
