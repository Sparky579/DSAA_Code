#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int que[100100],head=1,tail=0;
typedef long long LL;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        char c;int tmp;
        scanf(" %c %d",&c,&tmp);
        if (c=='E') {
            que[++tail]=tmp;
        }
        else {
            head+=tmp;
            printf("%d\n",que[head]);
        }
    }
}
