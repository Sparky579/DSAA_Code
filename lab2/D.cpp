#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long g[200010],b10[20];
long long go[2000010],tmp[2000010];
int ws[200010],cnt=0;
char dig[200010][12],dig2[200010][12];
int n,m,k;
void mergeSort(int l,int r)
{
    int mid=(l+r)>>1;
    if (l>=r) return;
    mergeSort(l,mid);
    mergeSort(mid+1,r);
    int i=l,j=mid+1;
    int pos=0;
//  printf("%d %d\n",l,r);
    while (i<=mid&&j<=r) {
    //  printf("(%d %d)",i,j);
        if (go[i]<go[j]) {
            tmp[++pos]=go[j];j++;
        }
        else {
            tmp[++pos]=go[i];i++;
        }
    }
     
    while (i<=mid) {
        tmp[++pos]=go[i++];
    }
    while (j<=r) {
        tmp[++pos]=go[j++];
    }
//  for (int i=1;i<=pos;i++) printf("(%d)",tmp[i]);
//  printf("\n");
    for (int i=1;i<=pos;i++)
    go[l+i-1]=tmp[i];
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++)
    scanf("%lld",&g[i]);
    b10[0]=1;
    for (int i=1;i<=15;i++)
    b10[i]=b10[i-1]*10ll;
    for (int i=1;i<=n;i++){
        ws[i]=0;
        long long tmp1=g[i];
        int sn=1;
        if (tmp1<0) {
            tmp1*=-1;sn*=-1;
        }
        while (tmp1>0) {//4 5 1
            dig[i][ws[i]]=sn*tmp1%10;
            dig2[i][ws[i]]=dig[i][ws[i]];//printf("(%d)",dig[i][ws[i]]);
            ws[i]++;
            tmp1/=10;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=ws[i]-1;j>=0;j--){
        //  printf("%d %d\n",i,j);
            int pos;
            char mxn=-12;
            for (int k=j;k>=0;k--){
                if (dig2[i][k]>=mxn) {
                    mxn=dig2[i][k];
                    pos=k;
                }
            }
            if (mxn>dig2[i][j]) {
                go[++cnt]=(b10[j]-b10[pos])*(mxn-dig2[i][j])-k;
                swap(dig2[i][j],dig2[i][pos]);
            }
        }
    }
    mergeSort(1,cnt);
    long long ans=0;
    for (int i=1;i<=n;i++)
    ans+=g[i];
    for (int i=1;i<=min(cnt,m);i++) {
        if (go[i]>0) ans+=go[i];
    }
    printf("%lld\n",ans);
 } 
