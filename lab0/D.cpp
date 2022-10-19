#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#define print(x) cc[cnt]+=x;
#define aa(x) (((x)>0)?(x):(-(x)))
using namespace std;
int h[200],oo[5];
char c[200];
vector<int> y,v[5];
bool ok(vector<int> x,bool can)
{
    int hav=0;
    for (int i=1;i<=7;i++){
        if (x[i]>=3){
            hav+=x[i]/3;
            x[i]=x[i]%3;
        } 
        while (x[i]>0)
        if (x[i+1]&&x[i+2]&&can) {
            x[i]--;
            x[i+1]--;
            x[i+2]--;
            hav++;
        }
        else return 0;
    }
    if (x[8]%3||x[9]%3) return 0;
    return 1;
}
int main()
{
    h['z']=1;
    h['w']=2;
    h['b']=3;
    h['s']=4;
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf(" %s",c);
        for (int i=0;i<5;i++)
        v[i].clear();
        for (int j=0;j<5;j++)
        for (int i=0;i<10;i++)
        v[j].push_back(0);
         
    //  y.clear();
        for (int i=0;i<14;i++){
        //  printf("%d %d\n",h[c[2*i+1]],c[2*i]-'0');//
            v[h[c[2*i+1]]][c[2*i]-'0']++;
        }
        int tot=0;
        for (int i=1;i<=4;i++){
        oo[i]=ok(v[i],i!=1);
        tot+=oo[i];
    //  printf("%d\n",oo[i]);
        }
        int flag=1,flag2=0;
        if (tot!=3) flag=0;
        for (int i=1;i<=4;i++){
            if (!oo[i]) {
                for (int j=1;j<=9;j++){
                    if (v[i][j]<2) continue;
                    v[i][j]-=2;
                    flag2|=ok(v[i],i!=1);
                    v[i][j]+=2;
                }
            }
        }
        if (flag&&flag2) printf("Blessing of Heaven\n");
        else printf("Bad luck\n");
        //printf("%d ",v[4][i]);
    //  printf("\n"); 
    }
}
