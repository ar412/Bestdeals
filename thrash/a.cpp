/*input
2 3
5 10
1 2 3

5 7
10 16 12 10 13
7 17 12 10 9 6 11
*/

#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
std::vector<int> b,g;
int ff(int n,int m)
{
    cout<<n<<" "<<m<<"\n";
    if(n<0)
        return INT_MAX;

    return min(ff(n-1,m-1)+abs(b[n]-g[m]),ff(n-1,m));
}

int main()
 {
    ios_base::sync_with_stdio(0);
    
    int a[2][2]={10,12,14,16};
    int *p=*a;
    cout<<(*(p+2));
    return 0;
 }