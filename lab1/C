#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const double pi = 3.14159265358979323846;
int n,q;
double g[1000100];
int main()
{
    scanf("%d%d",&n,&q);
    for (int i=1;i<=q;i++){
    scanf("%lf",&g[i]);
    g[i]=g[i]*g[i]*pi;
    }
    double l=0.0,r=5000000,mid;
    while (l<=r) {
        int hav=0;
        mid=(l+r)*0.5;
        for (int i=1;i<=q;i++){
            hav+=int(g[i]/mid);
        }
        if (hav>=n) l=mid+0.000001;
        else r=mid-0.000001;
    //  printf("%lf\n",mid);
    }
    printf("%.10lf\n",mid);
 } 
