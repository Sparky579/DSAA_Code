#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
char c[100100];
int xm[100100],ym[100100];
int len;
long long xr,yr,xc,yc;
long long gox=0,goy=0,ANS=2e15;
long long posx,posy;
long long ab(long long x)
{
    return x>0?x:-x;
}
long long dis(long long x1,long long y1,long long x2,long long y2)
{
    return ab(x1-x2)+ab(y1-y2);
}
int main()
{
    scanf("%lld%lld%lld%lld%d",&xr,&yr,&xc,&yc,&len);
    scanf(" %s",c);
    bool flag=0;
    posx=xr;posy=yr;
    for (int i=0;i<len;i++){
        if (c[i]=='D') xm[i+1]=0,ym[i+1]=-1;
        if (c[i]=='U') xm[i+1]=0,ym[i+1]=1;
        if (c[i]=='L') xm[i+1]=-1,ym[i+1]=0;
        if (c[i]=='R') xm[i+1]=1,ym[i+1]=0;
        gox+=xm[i+1];
        goy+=ym[i+1];
    }
    for (int i=0;i<len;i++){
        if (i)posx+=xm[i];
        if (i)posy+=ym[i];
        long long l=0,r=2e9,mid1,mid2,ans=2e15;
        while (l<=r) {
            mid1=l+(r-l)/3;
            mid2=l+(r-l)*2/3;
            long long xa=posx+gox*mid1;
            long long ya=posy+goy*mid1;
            long long ansa=max(dis(xa,ya,xc,yc),i+mid1*len);
             
            long long xb=posx+gox*mid2;
            long long yb=posy+goy*mid2;
            long long ansb=max(dis(xb,yb,xc,yc),i+mid2*len);
        //  printf("%lld %lld\n",dis(xb,yb,xc,yc),i+mid1*len);
            if (dis(xa,ya,xc,yc)<=i+mid1*len) {
                flag=1;
            }
            else {
                l=mid1+1;
                continue;
            } 
            if (ansa>ansb) {
                ans=min(ans,ansb);
                l=mid1+1;
            }
            else {
                ans=min(ans,ansa);
                r=mid2-1;
            }
        //  printf("%lld %lld(%lld %lld %lld %lld)\n%lld %lld(%lld %lld %lld %lld)%lld %lld\n\n"
        //  ,mid1,ansa,xa,ya,xc,yc,mid2,ansb,xb,yb,xc,yc,l,r);
        }
        ANS=min(ANS,ans);
    }
    if (flag)printf("%lld\n",ANS);
    else printf("-1");
 } 
