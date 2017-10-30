/*input
100000
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    
    int k;
    cin>>k;
    vector<int> arr;
    int a[26];
    for (int i = 0; i < 26; ++i)
    {
        a[i]=0;
    }
    a[0]=a[1]=1;
    arr.push_back(0);
    arr.push_back(1);
    int i=0;
    while(k>0)
    {
        if(a[i]<=k)
            {
                k=k-a[i];
                a[i]++;
                arr.push_back(i);
            }
        else i++;
    }

    for (int i = 0; i < arr.size(); ++i)
    {
        cout<<(char)(arr[i]+'a');
    }
   cout<<arr.size()
;    return 0;
}
