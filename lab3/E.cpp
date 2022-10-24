#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define work l^=lastans;r^=lastans;k^=lastans
using namespace std;
int g[40040],siz;
struct node{
	int val, id;
	node *nxt=0;
};
struct block{ // 290 * 290 = 84000
    int hav[292];
    int cnt[80005];
    int siz, id=0;
    block *nxt=0;
    node *go=0;
};

node *nodes[40040];
int hav0[292],rtmp[292];
block *head = new block;
block *tail = head;
node *nhead = new node;
node *ntail = nhead;
int n,m;
void split(block *x)
{
    node* end = x->nxt->go;
  //  printf("SPLITING\n");
    int cnt = 0;
    block *y = new block();
    y->nxt = x->nxt;
    x->nxt = y;
    y->siz = x->siz;
    for (int i = 0; i <= 80000; i++){
        y->cnt[i] = x->cnt[i];
    }
    for (int i = 0; i < 290; i++)
    y->hav[i] = x->hav[i];
    for (node* i = x->go; i != end ; i = i-> nxt){
        cnt++;
      //  printf("(%d\n",i->val);
    //    printf("%d %d\n",x->id, x->nxt->id);
    //    printf("%d %d %d\n",cnt, i->val, x->nxt->go->val);
        if (cnt == siz + 1){
            y->go = i;
        } 
        if (cnt > siz) {
            x->hav[(i->val)/290]--;
            x->cnt[i->val]--;
        }
    }
    x->siz = siz;
    y->siz -= siz;
}
int query(int l,int r, int k)
{
	int now=0;
	block *lb=0,*rb=0;
	block *a=head;
	node *fir,*sec;
	for (block *i=head->nxt;i;i=i->nxt) {
     //   printf("?%d\n",i->id);
		if (lb==0&&now+1>=l) {//modify to +1
        //    printf("<");
			lb=a;
		}
		if (now<l&&now+i->siz>=l) {
			fir=i->go;
          //  printf("%d %d %d\n",fir->val, now, l);
			for (int i=now+1;i<l;i++)
			fir=fir->nxt;
		}
		now+=i->siz;
		if (rb==0&&now>=r) {
        //    printf(">");
			rb=a;
			sec=i->go;
			for (int j=now-(i->siz)+1;j<r;j++)
			sec = sec -> nxt;
		}
		a=a->nxt;
	}
	for (int i=0;i<290;i++){
      //  if (i<3) printf("|%d %d\n",i, rb->hav[i]-lb->hav[i]);
		hav0[i]=(rb->hav[i])-(lb->hav[i]);
	}
    //printf("%d %d %d(LR)\n",fir->val, lb->hav[0], rb->id);
	for (node *i = fir; i != lb->nxt->go; i = i->nxt){
        hav0[(i->val)/290]++;
      //  printf("%d %d block ++\n",i->val,(i->val)/290);
        if (i == ntail) break;
    }
    if (rb != tail)
    for (node *i = rb->nxt->go;i != sec->nxt; i = i-> nxt){
        hav0[(i->val)/290]++;
//        printf("%d %d %d block ++\n",i->val,(i->val)/290, i->nxt->val);
        if (i == ntail) break;
    }
  //  printf("%d %d %d\n",hav0[0], hav0[1], hav0[2]);
    int ff=0,gg=0;
    for (ff;ff<290;ff++){
        if (gg+hav0[ff]>=k) { break;}
        gg+=hav0[ff];
    }
    memset(rtmp,0,sizeof(rtmp));
    int leas=ff*290-1;
    for (node *i = fir; i != lb->nxt->go; i = i->nxt){
        if ((i->val)>leas) rtmp[(i->val)-leas]++;
        if (i == ntail) break;
    }
    if (rb != tail)
    for (node *i = rb->nxt->go;i != sec->nxt; i = i-> nxt){
        if ((i->val)>=leas && (i->val-leas)<=290) rtmp[(i->val)-leas]++;//printf("111 %d %d\n",(i->val),leas);printf("%p\n",head->nxt);//
        if (i == ntail) break;
    }
//    printf("MESSAGE %d %d %d %d %d %d %d\n",fir->val, sec->val, lb->id, rb->id, leas, rb->hav[0], rb->hav[1]);
    for (int i=1;i<=290;i++){
    //    if ((rb->cnt[leas+i])-(lb->cnt[leas+i])) printf("%d %d TMP\n",i, (rb->cnt[leas+i])-(lb->cnt[leas+i]));
        rtmp[i]+=(rb->cnt[leas+i])-(lb->cnt[leas+i]);
    }
    if (gg >= k) return leas;
    
    for (int i=1;i<=290;i++){
        gg+=rtmp[i];
    //    if (rtmp[i]) printf("<%d %d %d\n",i,rtmp[i],leas);
        if (gg>=k) return leas+i;
    }
}
void modify(int l,int val)
{
    int now = 0;
    block *lb = 0;
    node *fir;
    for (block *i=head->nxt;i;i=i->nxt) {
        if (lb==0&&now+i->siz>=l) {
        //    printf("(%d)",i->id);
			lb=i;
		}
        if (now<l&&now+i->siz>=l) {
			fir=i->go;
        //    printf("%d %d %d\n",fir->val, now, l);
			for (int i=now+1;i<l;i++)
			fir=fir->nxt;
		}
        now+=i->siz;
     //   printf("[%d\n",now);
    }
    int preval = fir->val;
    fir->val = val;
    for (block *i = lb; i; i=i->nxt) {
      //  printf("%d\n",i->id);
        i->cnt[fir->val]++;
        i->cnt[preval]--;
        i->hav[(fir->val)/290]++;
        i->hav[preval/290]--;
    }
}
void insert(int l, int val)
{
    int now = 0;
    node *fir;
    block *lb = 0;
    for (block *i=head->nxt;i;i=i->nxt) {
        if (lb==0&&now+i->siz>=l-1) {
           // printf("(%d)",i->id);
			lb=i;
		}
        if (now<l-1&&now+i->siz>=l-1) {
			fir=i->go;
        //    printf("%d %d %d\n",fir->val, now, l);
			for (int i=now+1;i<l-1;i++)
			fir=fir->nxt;
		}
        now+=i->siz;
    }
    if (l == 1) fir = nhead;
    
    node *nod = new node();
    nod->val = val;
    nod->nxt = fir->nxt;
    fir->nxt = nod;
    lb->siz++;
    nod->id = -1;
    if (fir == ntail) ntail = nod;
    if (l == 1) lb->go = nod;
    for (block *i = lb; i; i=i->nxt){
      //  printf("(%d %d)\n",i->id, val);
        i->cnt[val]++;
        i->hav[val/290]++;
    }//printf("?%d %d\n",lb->nxt->id, siz);
    if (lb->siz > 2 * siz) split(lb);
}
int main()
{
	int lastans=0;
    memset(head->hav,0,sizeof(head->hav));
    memset(head->cnt, 0, sizeof(head->cnt));
    scanf("%d %d",&n,&m);
    siz=int(sqrt(n));
    for (int i=1;i<=n;i++){
        scanf("%d",&g[i]);
        nodes[i] = new node;
        ntail->nxt=nodes[i];
        ntail=nodes[i];
        ntail->id = i;
        ntail->val=g[i];
    }
    int cn=0;
    block *pre = head;
    for (int i=1;(i-1)*siz<n;i++){
        block *tmp = new block();
        tail->nxt = tmp;
        tmp->id=++cn;
        tail = tmp;
        tmp->go = nodes[(i-1)*siz+1];
        if ((i)*siz<n) tmp->siz = siz;
        else tmp->siz = n - (i-1)*siz;
        int ii=(i-1)*siz+1;
        for (int j=ii;j<=min(ii+siz-1,n);j++){
            tmp->cnt[g[j]]++;
            tmp->hav[g[j]/290]++;
        //    printf("(%d %d %d)",i,tmp->hav[g[j]/290],g[j]);
        }
    //    printf("%dv1\n",tmp->hav[0]);
    //    printf("%dv\n",tmp->hav[0]);
        pre = pre-> nxt;
    }
    tail->nxt = new block;
    ntail->nxt = new node;
    tail->nxt->go = ntail->nxt;
    pre = head;
    for (block *i=head->nxt;i;i=i->nxt) {
        for (int j=0;j<290;j++)
        i->hav[j]+=pre->hav[j];
        for (int j=0;j<80001;j++)
        i->cnt[j]+=pre->cnt[j];
        pre = pre->nxt;
    }
    for (int i=1;i<=m;i++){
        char c;
        int l,r,k;
        scanf(" %c",&c);
        if (c=='Q') {
            scanf("%d%d%d",&l,&r,&k);
        //    work;
        //    printf("ACTUALLY: -------------%d %d %d\n",l,r,k);
            printf("%d\n",lastans=query(l,r,k));
        //    printf("%p\n",head->nxt);
        }
        else if (c == 'M') {
            scanf("%d%d",&l,&k);
        //    work;
            modify(l, k);
        }
        else if (c == 'I') {
            scanf("%d%d",&l,&k);
        //    work;
            insert(l,k);
        }
        /*for (block *i = head->nxt; i != tail->nxt; i=i->nxt){
            printf("\nBlock: %d Size: %d\n",i->id, i->siz);
            for (node *j = i->go; j != i->nxt->go; j=j->nxt){
                printf("%d ",j->val);
            }
        }
        printf("\n"); */
    }
 //   system("pause");
}
