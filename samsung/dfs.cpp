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
    int val;
    ll *next;
};

ll * newnode(int data)
{
    ll *tmp=(ll*)malloc(sizeof(ll));
    tmp->val=data;
    tmp->next=NULL;
    return tmp;
}
void push(ll **top,int data)
{
    ll *n=newnode(data);
    n->next=*top;
    *top=n;
}

void pop(ll **top)
{
    if(*top==NULL)
        return;

    ll *tmp=*top;
    *top=(*top)->next;
    free(tmp);
}

int main()
 {
    
    ll *top=NULL;
    // push(&top,3);
    // push(&top,5);
    // push(&top,6);
    // pop(&top);
    // cout<<top->val;
    int n;
    cin>>n;
    int **arr=new int *[n+1];
    for (int i = 0; i <=n; ++i)
        arr[i]=new int [n+1];

    memset(arr,0,sizeof(arr));
    int k;
    cin>>k;
    for (int i = 0; i < k; ++i)
    {
        int a,b;
        cin>>a>>b;
        // if(a!=b)
        arr[a][b]=1;
    }
  
    int *vis=new int [n+1];
    memset(vis,0,sizeof(vis));

    int root=4;
    push(&top,root);
    vis[root]=1;

    while(top)
    {
        int u=top->val;
        pop(&top);
        cout<<u<<" ";
        for (int i = 1; i <=n; ++i)
        {
            if(arr[u][i]==1 && vis[i]==0)
            {
                push(&top,i);
                vis[i]=1;
            }
        }
    }



    return 0;
 }