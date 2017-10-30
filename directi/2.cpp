/*input
5
3 4 1 4 1

*/

#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;


int main()
 {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    std::vector<int> A(n);
    for (int i = 0; i < n; ++i)
    {
        cin>>A[i];
    }

       for(int i=0;i<A.size();i++)
    {
        if(A[abs(A[i])]<0)
            cout<< abs(A[i]);
        else A[abs(A[i])]=-A[abs(A[i])];
    }

    

    return 0;
 }