#include<cstring>
#include<cstdio>
using namespace std;
int t,m;
char c[111];
char d[12][12];
char tmp[12];
int xx[200],yy[200];
int lens[12];
void sustr(const char* ori, char *tm,int l, int r)
{
    if (l<0) return;
    for (int i=l;i<=r;i++)
    tm[i-l]=ori[i];
 } 
int main()
{
    scanf("%d",&t);
    while (t--) {
        scanf(" %s",c);
        scanf("%d",&m);
        for (int i=1;i<=m;i++){
        scanf(" %s",d[i]);
        lens[i]=strlen(d[i]);
        }
         
        int now=-1;
        int lenc=strlen(c);
        int ans=0;
        while (now<lenc-1) {
            int ans1=-1,ans2,ansl;
            for (int j=now+1;j<lenc;j++) {
                int id=0;
                for (int k=1;k<=m;k++) {
                    int ll=j-lens[k]+1;
                    if (ll>now+1) continue;
                    memset(tmp,0,sizeof(tmp));
                    sustr(c, tmp, ll, j);
                //  char * u1 = substr(c,ll,j);
                    if (strcmp(tmp, d[k]) == 0) id=k;
            //      printf("%d %d %s %s\n",j,ll,tmp,d[k]);
                }
                if (id) {
                    ans1=j;
                    ans2=id;
                    ansl=j-lens[id]+1;
            //      printf("# %d\n",ans1);
                }
            }
        //  printf("$$$\n");
            ans++;
            if (ans1!=-1) now=ans1;
            xx[ans]=ans2;
            yy[ans]=ansl;
        //  printf("$%d$\n",now);
            if (ans>300) break;
        }
        if (ans<300) {
            printf("%d\n",ans);
            for (int i=1;i<=ans;i++) printf("%d %d\n",xx[i],yy[i]+1);
        }
        else printf("-1\n");
    }
}
