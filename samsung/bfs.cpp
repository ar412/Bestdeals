/*input
4 6
1 2
2 4
2 3
3 3
4 1 
4 2

*/

#include <iostream>
#include <string.h>
// #define ll long long int
#define mod 1000000007
using namespace std;

struct ll
{
    int val,;
    ll *next;
};

ll* newnode(int data)
{
    ll *n=(ll*)malloc(sizeof(ll));
    n->val=data;
    n->next=NULL;
}

struct que
{
    ll *front,*rear;
};

que* newque()
{
    que *q=(que*)malloc(sizeof(que));
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
    free(tmp);

    if(q->front==NULL)
        q->rear=NULL;
}
int main()
 {
    
  
    int n;
    cin>>n;
    int **arr=new int *[n+1];
    for(int i = 0; i <=n; i++)
       arr[i] = new int[n+1];
   
    memset(arr,-1,sizeof(arr));   
    int k;
    cin>>k;
    
    for (int i = 0; i < k; ++i)
    {
        int a,b;
        cin>>a>>b;
        arr[a][b]=1;
        // arr[b][a]=1;
    }
    bool *vis=new bool [n+1];
    // memset(vis,0,sizeof(vis));
    int root=4;
    que *q=newque();
    push(q,root);
    vis[root]=1;
    while(q->rear)
    {
        int u=q->front->val;
        // int d=q->front->dis;
        pop(q);
        cout<<u<<" ";
        for (int i = 1; i <=n; ++i)
        {
            if(arr[u][i]==1 && vis[i]==0)
            {
                push(q,i);
                vis[i]=1;
            }
        }
    }

    cout<<"\n";






    //   for (int i = 1; i <=n; i++)
    // {
    //     for (int j = 1; j<=n; j++)
    //     {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // } 
    return 0;
 }