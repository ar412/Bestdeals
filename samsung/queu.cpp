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
    
    que *q=newque();
    push(q,5);
    push(q,10);
    push(q,15);
    while(q->rear!=NULL)
    {
        cout<<q->front->val<<" ";
        pop(q);
    }
    
    return 0;
 }