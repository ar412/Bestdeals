/*input
6 6
4 2
4 6
5 6
5 3
2 1
3 1

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
    push(&top,3);
    push(&top,5);
    push(&top,6);
    pop(&top);
    // cout<<top->val;
    int n;
    cin>>n;
    int arr[n+1][n+1];
    memset(arr,0,sizeof(arr));
    int k;
    cin>>k;
    for (int i = 0; i < k; ++i)
    {
        int a,b;
        cin>>a>>b;
        arr[a][b]=1;
    }
    // for (int i = 1; i <=n; ++i)
    // {
    //     for (int j = 1; j<=n; ++j)
    //     {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    int vis[n+1];
    memset(vis,0,sizeof(vis));
    for (int i = 1; i <= n; ++i)
    {
        if(cycle(i,arr))
            cout<<1;
    }
    cout<<0;
    return 0;
 }