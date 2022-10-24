#include<cstdio>
#include<algorithm>
#define int long long
#define ll long long
using namespace std;
struct node
{
    node()
    {
        a=b=0;
        nx=NULL;
    }
    ll a;
    ll b;
    node *nx;
};
class linklist
{
public:
    node *hd,*tl;
    linklist(int n=0,ll *a=NULL,ll *b=NULL)
    {
        hd=new node();
        tl=hd;
        for(int i=0;i<n;++i)
        {
            tl->nx=new node();
            tl=tl->nx;
            tl->a=a[i];
            tl->b=b[i];
        }
    }
    linklist(linklist &l)
    {
        hd=new node();
        tl=hd;
        for(node *p=l.hd->nx;p;p=p->nx)
        {
            hd->nx=new node();
            tl=tl->nx;
            tl->a=p->a;
            tl->b=p->b;
        }
    }
    ~linklist()
    {
        tl=hd;
        for(node *p=hd->nx;p;p=p->nx)
        {
            delete(tl);
            tl=p;
        }
    }
    void append(ll a,ll b)
    {
        tl->nx=new node();
        tl=tl->nx;
        tl->a=a;
        tl->b=b;
    }
    void insert(ll a,ll b,node *p)
    {
        node *pn=p->nx;
        p->nx=new node();
        p->nx->a=a;
        p->nx->b=b;
        p->nx->nx=pn;
    }
    void del(node *pr)
    {
        node *p=pr->nx;
        if (p !=NULL) {pr->nx=pr->nx->nx;
        }
    }
    void merge(linklist &l)
    {
        for(node *p1=hd,*p2=l.hd;p2->nx;) if((!p1->nx)||((p2->nx)&&p1->nx->a>p2->nx->a))
        {
            p2=p2->nx;
            node *p=p1->nx;
            p1->nx=new node();
            p1=p1->nx;
            p1->nx=p;
            p1->a=p2->a;
            p1->b=p2->b;
        }
        else if((p1->nx)&&p1->nx->a<p2->nx->a) p1=p1->nx;
        else
        {
            p1->nx->b+=p2->nx->b;
            p2=p2->nx;
        }
    }
};
ll n,k,l;
ll m;
ll sum,nodes,ans;
signed main()
{
    ll tp;
    linklist list;
    scanf("%lld%lld",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%lld",&tp);
        list.append(tp,0ll);
        sum+=tp;
        nodes++;
    }
    ans+=n*(m/sum);
    m%=sum;
    while (1){
        int vis=0;ll tp1=0;
    node *pr=list.hd;
    for(node *p=list.hd->nx;p;p=p->nx)
    {
        int fl=0;
        if (p->a>m) {
            fl=1;
        //  printf("del %lld\n",p->a);
            list.del(pr);
        }
        else {
            ans++;
            vis++;
            tp1+=p->a;
            m-=p->a;
        }//printf("$%lld %lld\n",pr->a,p->a);
       if (fl==0) pr=pr->nx;
    }
    if (m>=tp1&&tp1) {
    //  printf("DEL %lld\n",tp1);
            ans+=vis*(m/tp1);
            m%=tp1;
        }
    if (vis==0) break;
    }
    printf("%lld\n",ans);
} 
