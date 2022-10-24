#include<cstdio>
#include<algorithm>
#define ll int
#include<cstring> 
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
    node *dwn;
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
            tl->dwn=tl->nx;
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
        tl->dwn=0; 
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
        delete(p);
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

int n,m;
int en=0;
int cnt = 0, fir = 1,nodes=0;
node* po[2000100]; 
ll sum=0,ans=0;
int main()
{
    int q;
    scanf("%d%d%d",&n,&m,&q);
    linklist link;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            int aa;
            scanf("%d",&aa);
			cnt++;
            link.append(aa,cnt);
            po[cnt]=link.tl;
        }
    }	
    node* nod = link.hd;
	node* nod2= link.hd;
    for (int i=1;i<=n;i++)
    nod=nod->nx;
    for (int i=1;i<=n*m-m;i++)
    {
    	po[i]->dwn=po[i+m];
	}
	int u1=cnt;
    for (int i=1;i<=n;i++){
        cnt++;
        
        link.append(-cnt,cnt);
        po[cnt]=link.tl;
    }
	link.hd->dwn=po[u1+1];

//    for (int i=1;i<=n;i++){
//    	u1++;
//    	po[u1]->nx=po[(i-1)*m+1];
//    	po[u1]->dwn=po[u1+1];
//	}
	//printf("%d\n",link.hd->nx->b);
	u1=cnt;
    for (int i=1;i<=m;i++){//printf("(%d %d)",u1,po[12]->nx->b);
        cnt++;//printf("$$$%d %d",u1,cnt);
        link.append(-cnt,cnt);
        po[cnt]=link.tl;
    }
	link.hd->nx=po[u1+1];
    for (int i=1;i<=m;i++){
    	u1++;
    	po[u1]->dwn=po[i];
    	po[u1]->nx=po[u1+1];
	}
	int vv=0;
	for (int i=n*m+1;i<=n*m+n;i++)
	{
		po[i]->dwn=po[i+1];
		po[i]->nx=po[vv*m+1];
		vv++;
	}
//	printf("%d %d\n",link.hd->nx->b,link.hd->dwn->b);
	for (int i=1;i<=cnt;i++){
	//	if (po[i]->nx) printf("%d right %d\n",i,po[i]->nx->b);
	//	if (po[i]->dwn) printf("%d down %d\n",i,po[i]->dwn->b);
	//	printf("\n");
	}//
    int h[7];
    for (int i=1;i<=q;i++){
        for (int j=1;j<=6;j++)
        scanf("%d",&h[j]);
        node* x1=link.hd,*x2=link.hd;
        for (int i=1;i<h[1];i++)
        x1=x1->dwn;
        for (int i=1;i<h[3];i++)
        x2=x2->dwn;
        for (int i=1;i<h[2];i++)
        x1=x1->nx;
        for (int i=1;i<h[4];i++)
        x2=x2->nx;
        node* x3=x1,*x4=x2;
        node* x5=x1,*x6=x2,*x7=x1,*x8=x2;
        for (int i=1;i<=h[6];i++){
        	x5=x5->nx;x6=x6->nx;
		}
        for (int i=1;i<=h[5];i++){
        	x7=x7->dwn;x8=x8->dwn;
		}
    //  printf("%d %d %dc\n",x1,x2,list[5].nxt2);
        for (int i=1;i<=h[6];i++){//0 11 -》 13 5 
            x1=x1->nx; 
            x2=x2->nx;
            swap(x1->dwn,x2->dwn);
             
        }
         
        for (int i=1;i<=h[5];i++){
            x3=x3->dwn;
            x4=x4->dwn;//printf("%d %d %d %dv\n",x3,x4,list[x3].nxt,list[x4].nxt);
            swap(x3->nx,x4->nx);
        }
         
        for (int i=1;i<=h[6];i++){
            x7=x7->nx;
            x8=x8->nx;//printf("%d %d %d %dvv\n",x7,x8,list[x7].nxt2,list[x8].nxt2);
            swap(x7->dwn,x8->dwn);
             
        }
        for (int i=1;i<=h[5];i++){
            x5=x5->dwn;
            x6=x6->dwn;//printf("%d %d %d %dvvc\n",x5,x6,list[x5].nxt2,list[x6].nxt2);
            swap(x5->nx,x6->nx);
        }//printf("%d %d$$\n",list[0].nxt,list[list[0].nxt2].nxt);
    }
    node* nn=link.hd;
    for (int i=1;i<=n;i++){
        nn=nn->dwn;
        node* nw=nn;
        for (int j=1;j<=m;j++){
            nw=nw->nx;
            printf("%d ",nw->a);
        }
        printf("\n");
    }
} 
