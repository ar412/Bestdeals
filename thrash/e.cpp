/*input
4 1 2 3 4
-1
262 91433 21544 30932 75087 88661 66097 1940 14883 22302 54993 48828 68623 20529 45656 30325 93374 5056 33388 21243 30282 25401 49400 83528 98429 5475 52352 61287 44321 36820 23207 23974 88356 7344 62137 5116 37813 54820 67654 28192 7700 16356 38798 39419 39881 18516 17152 77102 83569 81404 9313 93826 74660 84007 15995 22920 10895 36389 42023 25622 5782 67549 62918 36575 14221 42810 21657 34483 83900 70981 26311 75660 17336 66180 41254 74283 72977 73572 60482 33437 13885 2851 1471 35829 61016 66001 77072 31193 60844 5517 46130 4767 10630 55305 85719 39893 78161 58890 86345 23485 65777 23057 68667 16147 18942 64122 78634 29195 74131 71806 66866 19018 92041 98958 85402 11004 9325 96765 54149 79904 976 7574 25823 30735 27199 60519 85908 94644 88671 61554 4326 78926 89512 17732 72962 74975 14182 88195 23478 38333 55242 17041 52594 60190 59530 91311 84122 63063 19755 73281 97236 78544 51638 90512 63084 91368 28327 40964 1708 38443 88995 38481 29462 67481 17860 85175 97989 45160 2874 30190 72476 70507 6366 48291 71679 21304 79598 68310 59615 63492 15706 81115 43396 44434 2770 81019 42043 35491 50634 49868 2350 22972 53465 58869 70511 18269 87687 56522 15684 68806 63862 33492 58152 32231 60580 79507 24706 69782 61802 84697 91034 50328 9266 67200 3414 95987 38823 55819 47101 87001 1823 80662 36841 38445 14800 60389 72545 54148 34886 1966 36501 95219 70127 78348 47702 74 63043 16336 14620 16736 88846 59081 15537 85773 23813 73035 40107 41603 88854 52753 92712 28123 72660 29577 41374 45574 65475 36644 73769 44224 51370 42596 23916
-1
*/

#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;


int kthsmallest(const vector<int> &A, int k) {
    int mi=A[0],ma=A[0];
    
    for(int i=1;i<A.size();i++)
    {
        mi=min(A[i],mi);
        ma=max(A[i],ma);
    }
    int mid;
    while(mi<=ma)
    {
        mid=(mi+ma)/2;
        int c=0,l=0;
         for(int i=0;i<A.size();i++)
         {
             if(A[i]<mid)
                c++;
            if(A[i]==mid)
                l++;
         }

         cout<<mi<<" "<<mid<<" "<<ma<<" "<<c<<" "<<l<<"\n";
         if(c<k && k<=(c+l))
            { mid;
                break;
            }
        if(c<k)
        mi=mid+1;
        else ma=mid-1;
    }
    mi=-1;
     for(int i=0;i<A.size();i++)
     {
        if(A[i]<=mid && A[i]>=mi)
            mi=A[i];
     }
     return mi;
}
 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
ListNode* detectCycle(ListNode* A) {
    
    if(A==NULL)
        return NULL;
    int flag=0;
    ListNode *s=A,*f=A;
    cout<<s->val<<" "<<f->val<<"\n";
    s=s->next;
    f=f->next;
    f=f->next;
    cout<<s->val<<" "<<f->val<<"\n";
    
    while(s && f &&  f->next)
    {
        s=s->next;
        f=f->next->next;
        if(s==f)
            {flag=1;
                break;}
    }
    // if(f==NULL)
    //     return NULL;
    // if(f->next==NULL)
    //     return NULL;
    // cout<<s->val<<" "<<f->val<<"\n";
    // f=A;
    
    // if(f==s)
    //     return s;
    // while(s!=f)
    //     {
    //         s=s->next;
    //         f=f->next;
    //     }
    return s;
}   
int main()
 {
    ios_base::sync_with_stdio(0);
    

    int n,in;
    cin>>n;

         ListNode *head=NULL,*p=NULL;
           head=(ListNode*)malloc(sizeof(ListNode));
           cin>>in;
            head->val=in;
            head->next=NULL;
            p=head;
    for (int i = 1; i < n; ++i)
    {
         ListNode *a=NULL;
           a=(ListNode*)malloc(sizeof(ListNode));
           cin>>in;
            a->val=in;
            a->next=NULL;
            p->next=a;

            p=a;
    }
    cin>>in;
     ListNode *b=NULL,*c=NULL,*d=NULL,*e=NULL,*A=NULL;
    // a=(ListNode*)malloc(sizeof(ListNode));
    // b=(ListNode*)malloc(sizeof(ListNode));
    // c=(ListNode*)malloc(sizeof(ListNode));
    // d=(ListNode*)malloc(sizeof(ListNode));
    // e=(ListNode*)malloc(sizeof(ListNode));
    
    // a->val=1;
    // b->val=2;
    // c->val=3;
    // d->val=4;
    // e->val=5;
    // a->next=b;
    // b->next=a;
    // c->next=d;
    // d->next=e;
    // e->next=NULL;

    A=detectCycle(head);
    cout<<"ans == "<<A->val;
    // while(A)
    // {
    //     cout<<A->val<<" ";
    //     A=A->next;
    // }
    return 0;
 }
