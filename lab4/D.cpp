#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int que[1001000],id[1001000],tail=0,head=1;
int g[1001000];
int now=0,ans=0;// -5 -3 -1  -9...
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    scanf("%d",&g[i]);
    que[0]=-1e9;
    for (int i=1;i<=n;i++){
    //  printf("%d: %d %d\n",i, g[i],que[tail]+now);
        now+=g[i];
        if (g[i]>que[tail]+now) {
             
            que[++tail]=g[i]-now;
            id[tail]=i;
        //  printf("%d %d +%d %d\n",i,que[tail],now, id[1]);
        }
        int l=1,r=tail,mid,tans=1e9;
        while (l<=r) {
            mid=(l+r)>>1;
        //  printf("%d %d %d %d %d\n",i, mid, id[mid], que[mid], now);
            if (que[mid]+now>0) {
                tans=id[mid];
                r=mid-1;
            }
            else l=mid+1;
        }
    //  printf("(%d)",tans);
        ans=max(ans,i-tans+1);
    }
    printf("%d\n",ans);
}
