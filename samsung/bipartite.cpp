/*input
10 10
1 2
2 3
3 4
4 5
5 6
6 1
6 7
6 8
7 9
8 9
*/

#include <bits/stdc++.h>
#include <iostream>
#include <string.h>
// #define ll long long int
#define mod 1000000007
using namespace std;

struct ll
{
    int val;
    ll *next;
};

ll* newnode(int data)
{
    ll *n=(ll*)malloc(sizeof(ll));
    n->val=data;
    n->next=NULL;
    return n;
}

struct que
{
    ll *front,*rear;
};

que* newque()
{
    que* q=(que*)malloc(sizeof(que));
    q->front=q->rear=NULL;
    return q;
}

void push(que *q,int data)
{
    ll *n=newnode(data);

    if(q->rear==NULL)
        {
            q->front=q->rear=n;
            return;
        }

    q->rear->next=n;
    q->rear=n; 
}

void pop(que *q)
{
    if(q->rear==NULL)
        return;

    ll *tmp=q->front;
    q->front=q->front->next;
    if(q->front==NULL)
        q->rear=NULL;
    free(tmp);
}

bool util(int u,int *clr,int **g,int n)
{
    
    que *q=newque();

    push(q,u);
    // vis[u]=1;
    clr[u]=0;

    while(q->rear)
    {
        int v=q->front->val;
        pop(q);

        if(g[v][v]==1)
            return 0;
        for (int i = 1; i <=n; ++i)
        {
            if(g[v][i]==1)
            {
                if(clr[i]==-1)
                    {
                        clr[i]=1-clr[v];
                        // vis[i]=1;
                        push(q,i);}
                else
                {
                    if(clr[i]==clr[v])
                        return 0;
                }
            }
        }
    }
    return 1;
}

bool cycle(int **g,int n)
{

    int *vis=new int [n+1];
    int *clr=new int [n+1];
    // int *ans;
    memset(vis,0,sizeof(vis));
    // memset(clr,1,sizeof(clr));
    for (int i = 1; i <=n; ++i)
    {
        // vis[i]=0;
        clr[i]=-1;
        // cout<<clr[i]<<" ";
    }
    for (int i = 1; i <=n; ++i)
    {
        if(clr[i]==-1)
            if(!util(i,clr,g,n))
                return 0;

    }
    for (int i = 1; i <=n; ++i)
    {
        if(clr[i]==0)
            cout<<i<<" ";
    }
    cout<<"\n";
    for (int i = 1; i <=n; ++i)
    {
        if(clr[i]==1)
            cout<<i<<" ";
    }
    cout<<"\n";

    return 1;
}

int main()
 {
    
   
    int n;
    cin>>n;
    int **g=new int *[n+1];
    for (int i = 0; i <=n; ++i)
    {
        g[i]=new int [n+1];
    }
    memset(g,-1,sizeof(g));
    int k;
    cin>>k;
    
    for (int i = 0; i < k; ++i)
    {
        int a,b;
        cin>>a>>b;
        g[a][b]=1;
    }

    cout<<cycle(g,n);
    // for (int i = 1; i <=n; ++i)
    // {
    //     for (int j = 1; j<=n; ++j)
    //     {
    //         cout<<g[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    // cout<<0;
    return 0;
 }