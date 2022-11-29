#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int head=1,tail=0;
typedef long long LL;
struct st{
    int id,val;
};
struct qe{
    int id,que;
}kk[100100];
bool cmp(qe x,qe y)
{
    return x.que<y.que;
}
int g[100100];
st que[100100];
int ans[100100];
int main()
{
    int n,k,q;
    scanf("%d%d%d",&n,&k,&q);
    for (int i=1;i<=n;i++){
        scanf ("%d",&g[i]);
    }   
    for (int i=1;i<=q;i++){
        scanf("%d",&kk[i].que);
        kk[i].id=i;
    }
    int pre=1;
    sort(kk+1,kk+q+1,cmp);
    for (int i=1;i<=q;i++){
        while (que[head].id<kk[i].que&&head<=tail) head++;
        for (pre;pre<=kk[i].que+k-1;pre++){
    //      printf("(%d)",pre);
            while (que[tail].val<=g[pre]&&head<=tail) tail--;
            tail++;
            que[tail].val=g[pre];
            que[tail].id=pre;
        }
//      printf("%d %d %d\n",i,head,tail);
        ans[kk[i].id]=que[head].val;
    //  printf("%d\n",que[head].val);
    }
    for (int i=1;i<=q;i++) printf("%d\n",ans[i]);
}
