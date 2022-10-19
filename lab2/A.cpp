#include<cstdio>
#include<cstring>
long long g[100010],tmp[100010];
void mergeSort(int l,int r)
{
    int mid=(l+r)>>1;
    if (l==r) return;
    mergeSort(l,mid);
    mergeSort(mid+1,r);
    int i=l,j=mid+1;
    int pos=0;
//  printf("%d %d\n",l,r);
    while (i<=mid&&j<=r) {
    //  printf("(%d %d)",i,j);
        if (g[i]>g[j]) {
            tmp[++pos]=g[j];j++;
        }
        else {
            tmp[++pos]=g[i];i++;
        }
    }
     
    while (i<=mid) {
        tmp[++pos]=g[i++];
    }
    while (j<=r) {
        tmp[++pos]=g[j++];
    }
//  for (int i=1;i<=pos;i++) printf("(%d)",tmp[i]);
//  printf("\n");
    for (int i=1;i<=pos;i++)
    g[l+i-1]=tmp[i];
}
int main()
{
    int t=1;
    while (t--) {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%lld",&g[i]);
        long long ans=0;
        mergeSort(1,n);
        for (int i=1;i<=n/2;i++) ans+=g[i]*g[n-i+1];
        printf("%lld\n",ans);
    }
}
