/*input
10
55 -8 43 52 8 59 -91 -79 -18 -94
*/

#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int maxSubArray(const vector<int> &A) {
    int a=0,b=0,n=A.size(),f=0,m=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(A[i]>=0)
            f=1;
        else 
        m=max(m,A[i]);
        if(b+A[i]>=0)
        {
            b+=A[i];
            if(a<b)
                a=b;
        }
        else b=0;
    }
    
    if(f==0)
        return m;
    else return a;
    
}


int main()
 {
    ios_base::sync_with_stdio(0);
   	
   	int n,m=INT_MAX,f=0;
   	cin>>n;
   	std::vector<int> v(n);
   	for (int i = 0; i < n; ++i)
   	{
   		cin>>v[i];
   	}
   	cout<<maxSubArray(v);
   

    return 0;
 }