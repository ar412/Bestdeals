/*input
5 
4 2 5 6 3
*/

#include <iostream>
#include <string.h>
// #define ll long long int
#define mod 1000000007
using namespace std;

int compare(const void *a,const void *b)
{
    return (*(int *)a > *(int *)b);
}

int main()
 {
    
   
    int n;
    cin>>n;
    int *a=new int [n];

    
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    qsort(a,n,sizeof(int),compare);
    for (int i = 0; i < n; ++i)
    {
        cout<<a[i];
    }
    return 0;
 }