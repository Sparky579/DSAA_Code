#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
struct node;
struct pnt;
int ans[2001000];
struct node{
    int val, id;
    node* nxt;
    node* pre;
};
struct pnt{
    int id, val;
};
node *head = new node(), *now, *tail = head;
bool cmp(pnt x, pnt y)
{
    return x.val < y.val;
}
void insert(int val, int id)
{
    node *nod = new node();
    tail->nxt = nod;
    nod->pre = tail;
    tail = nod;
    tail->id = id;
    tail->val = val;
}
pnt g[2001000];
int main()
{//5 3 1 4 2
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&g[i].val);
        g[i].id=i;
        ans[i]=2e9;
    }
    sort(g+1,g+n+1,cmp);
    now = head;
    int pos;
    for (int i=1;i<=n;i++){
        insert(g[i].val, g[i].id);
    //    printf("%d %d %d\n",g[i].id, pos, tail->id);
        if (now == head) {now = tail; pos = tail->id;}
        else {
        	node * u = tail->pre;
            while (u != head && tail->id > u->id) {
            //	printf("%d\n",u->id);
                ans[u->id] = min(ans[u->id], abs(u->val - tail->val));
				u=u->pre;
            }
            u->nxt = tail;
            tail->pre = u;
        }
    }
    
    tail=head;
    for (int i=n;i>=1;i--){
        insert(g[i].val, g[i].id);
    //    printf("%d %d %d\n",g[i].id, pos, tail->id);
        if (now == head) {now = tail; pos = tail->id;}
        else {
        	node * u = tail->pre;
            while (u != head && tail->id > u->id) {
            //	printf("%d\n",u->id);
                ans[u->id] = min(ans[u->id], abs(u->val - tail->val));
				u=u->pre;
            }
            u->nxt = tail;
            tail->pre = u;
        }
    }
    for (int i=1;i<n;i++)printf("%d ",ans[i]);
}
