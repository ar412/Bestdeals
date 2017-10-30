/*input
5
1 2 3 4 5
*/
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

typedef struct node
{
    ll d;
    node* l;
    node* r;
} node;



node* newnode(ll v)
{
    node* n=(node*)malloc(sizeof(node));
    n->d=v;
    n->r=n->l=NULL;
    return n; 
}


typedef struct que
{
    int front,back,size;
    node* *a;
} que;

que* createque(int n)
{
    que* tmp = (que*)malloc(sizeof(que));
    tmp->size=n;
    tmp->front=tmp->back=-1;
    tmp->a=(node**)malloc(sizeof(node*) * n);
    for (int i = 0; i < n; ++i)
    {
        tmp->a[i]=NULL;
    }
    return tmp;
}

void deq(que* q)
{
    if(q->front==-1)
        return;
    if(q->front==q->back)
        q->front=q->back=-1;
    else
        q->front++;
}

void enque(node* tmp,que* q)
{
    if(q->back==q->size-1)
        return;
    q->back++;
    q->a[q->back]=tmp;
    if(q->front==-1)
        q->front++;
}

void insertbt(node** root,int data,que* q)
{
    node* tmp=newnode(data);

    if(*root==NULL)
        *root=tmp;
    else{
        node* f=q->a[q->front];

        if(f->l==NULL)
            f->l=tmp;
        else if(f->r==NULL)
            f->r=tmp;
        if(f->l && f->r && f)
            deq(q);
    }
    enque(tmp,q);
}


void storein(int* a,node* root,int* i)
{
    if(root==NULL)
        return;
    storein(a,root->l,i);
    a[*i]=root->d;
    (*i)++;
    storein(a,root->r,i);
}

int minSwaps(int a[],int n)
{
    vector<pair<int,int> > v(n);
    vector<int> vis(n);
    int ans=0;
    for (int i = 0; i < n; ++i)
    {
        v[i].first=a[i];
        v[i].second=i;
        vis[i]=0;
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; ++i)
    {
        if(vis[i] || v[i].second==i)
            continue;

        int j=i,c=0;
        while(!vis[j])
        {
            vis[j]=1;
            j=v[j].second;
            c++;
        }
        ans+=c-1;
    }
    return ans;
}

int main()
{
    int n;   
    cin>>n;  
    int ar[n];
    for (int i = 0; i < n; ++i)
        cin>>ar[i];
    node* root=NULL;
    que* q = createque(n);    
    for (int i = 0; i < n; ++i)
    {
        insertbt(&root,ar[i],q);
    }
    int i=0,a[n];
    storein(a,root,&i);
  
 
   cout<<minSwaps(a,n);
  // printLevelOrder(root);


   return 0;
}  