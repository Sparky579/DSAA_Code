#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
	node()
	{
		a=b=0;
		nx=NULL;
	}
	int a;
	int b;
	node *nx;
};
class linklist
{
public:
	node *hd,*tl;
	linklist(int n=0,int *a=NULL,int *b=NULL)
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
	void append(int a,int b)
	{
		tl->nx=new node();
		tl=tl->nx;
		tl->a=a;
		tl->b=b;
	}
	void insert(int a,int b,node *p)
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
		pr->nx=pr->nx->nx;
		delete(p);
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
	void pnt()
	{
		for(node *p=hd->nx;p;p=p->nx)
		if (p->b!=0) printf("%d %d\n",p->b,p->a);
	}
};
int n,m,k,l;
int main()
{
	linklist a,b;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
	{
		scanf("%d%d",&k,&l);
		swap(k,l);
		a.append(k,l);
	}
	for(int i=0;i<m;++i)
	{
		scanf("%d%d",&k,&l);
		swap(k,l);
		b.append(k,l);
	}
	a.merge(b);
	int cc=0; 
	for (node *p=a.hd->nx;p;p=p->nx) if ((p->b) != 0) cc++;
	printf("%d\n",cc); 
	a.pnt();
	return 0;
}
