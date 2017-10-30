/*input
5
1 2 2 4 5


*/
#include <bits/stdc++.h>
#define ll int
using namespace std;


  struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };
 
RandomListNode* copyRandomList(RandomListNode* A) {
    
    RandomListNode *n=A,*t=new RandomListNode(A->label),*head,*c;
    	head=t;

    while(n->next)
    {
    	c=new RandomListNode(n->next->label);
    	t->next=c;

    	if(n->random)
    	t->random=n->random;
		else 
		t->random=NULL;

		n->random=t;
    	n=n->next;
    	t=c;
    }
    	if(n->random)
    	t->random=n->random;
    	else 
    	t->random=NULL;
    	n->random=t;
    	t->next=NULL;

    n=A; 
    t=head;
    while(n)
    {

    	if(t->random!=NULL)
    	t->random=n->random->random->random;
    	n=n->next;
    	t=t->next;
    }
    return head;
}

int lengthOfLongestSubstring(string A) {

    map<char,int> m;
    string s,a;
    int i=0;
    while(i<A.length())
    {
    	//cout<<i<<" s: "<<s<<" ";
        if(m[A[i]]>0)
        {
            if(s.length()>a.length())
                a=s;
            s.clear();
            i=m[A[i]];            
            m.clear();
        }
        else
        {
		    m[A[i]]=i+1;
            s+=A[i];
            i++;
        }
        //cout<<s<<" ";
    }   
     if(s.length()>a.length())
        a=s;
    return a.length();

}

int main()
{
	int n;
	cin>>n;
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
 	set<int> s;
    for(int i=0;i<v.size();i++)
    {
        s.insert(v[i]);
    }
    for(auto it:s)
    	cout<<it<<" "<<s.size();


/*
	   RandomListNode *a=NULL,*b=NULL,*c=NULL,*d=NULL,*e=NULL,*A=NULL;
    a=(RandomListNode*)malloc(sizeof(RandomListNode));
    b=(RandomListNode*)malloc(sizeof(RandomListNode));
    c=(RandomListNode*)malloc(sizeof(RandomListNode));
    d=(RandomListNode*)malloc(sizeof(RandomListNode));
    e=(RandomListNode*)malloc(sizeof(RandomListNode));
    
    a->label=1;
    b->label=2;
    c->label=3;
    // d->label=4;
    // e->label=5;
    a->next=b;
    b->next=c;
    c->next=NULL;
    // d->next=e;
    // e->next=NULL;
    a->random=c;
    b->random=NULL;
    c->random=a;
    // d->random=a;
    // e->random=b;
    A=copyRandomList(a);
    while(A)
    {
    	cout<<A<<" "<<A->label<<" ";
    	if(A->random)
    	cout<<A->random->label<<"\n";
    	else cout<<"NULL\n";
    	A=A->next;
    }
	while(a)
    {
    	cout<<a<<" "<<a->label<<" ";
    	if(a->random)
    	cout<<a->random->label<<"\n";
    	else cout<<"NULL\n";
    	a=a->next;
    }*/
	return 0;
}
