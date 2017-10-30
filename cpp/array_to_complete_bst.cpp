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

node* insert(node* root,ll v)
{
    if(root==NULL)
        return newnode(v);

    if(v<=root->d)
        root->l=insert(root->l,v);
    else root->r=insert(root->r,v);

    return root;
}

void preorder(node* root)
{
    if(root!=NULL)
    {cout<<root->d<<"\n";
    preorder(root->l);
    preorder(root->r);}
}

int height(node* root)
{
    if(root==NULL)
        return 0;
    int lh=height(root->l);
    int rh=height(root->r);

    return (max(lh,rh)+1);
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

void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
       cout<< root->d<<" ";
    else if (level > 1)
    {
        printGivenLevel(root->l, level-1);
        printGivenLevel(root->r, level-1);
    }
}


void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}
 
void atb(int* a,node* root,int *i)
{
    if(root==NULL)
        return;

    atb(a,root->l,i);
    root->d=a[*i];
    (*i)++;
    atb(a,root->r,i);

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
    sort(ar,ar+n);
    int i=0;
    atb(ar,root,&i);
   
   printLevelOrder(root);


   return 0;
}  