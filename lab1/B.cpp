#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int n,q;
long long g[3030];
long long ans=0;
int main()
{
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++){
    scanf("%lld",&g[i]);
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<i;j++){
            int res=q-g[i]-g[j];
            int l=1,r=j-1,mid;
            long long an1=-1,an2=-1;
            while (l<=r){
                mid=(l+r)>>1;
                if (g[mid]<res) l=mid+1;
                else if (g[mid]>res) r=mid-1;
                else an1=mid,l=mid+1;
            }
            l=1;r=j-1;
            while (l<=r){
                mid=(l+r)>>1;
                if (g[mid]<res) l=mid+1;
                else if (g[mid]>res) r=mid-1;
                else an2=mid,r=mid-1;
            }
        //  printf("%lld %lld %lld %lld %lld\n",i,j,res,an1,an2);
            if (an1==-1) continue;
            else ans+=an1-an2+1;
        }
    }
    printf("%lld",ans);
 } 
