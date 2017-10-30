/*input
5
1 2 3 1 1
*/

#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int main()
 {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    set<pair<int,int> > s;
    int n;
    cin>>n;
    std::vector<int> A(n);
    for (int i = 0; i < n; ++i)
    {
        cin>>A[i];
    }
    for (int i = 0; i < n; ++i)
    {
        if(s.empty())
            s.insert(make_pair(A[i],1));
        else
        {
            int c=0;
            for(auto it:s)
            {
                if(it.first==A[i])
                {
                    c=it.second;
                }
            }
            if(c>0)
            {
                s.erase(make_pair(A[i],c));
                s.insert(make_pair(A[i],c+1));
                continue;
            }
            if(s.size()<=1)
            {
                s.insert(make_pair(A[i],1));
                continue;
            }
            int j=0;
            std::vector<pair<int,int> > v(2);
            for(auto it:s)
            {
                v[j].first=it.first;
                v[j].second=it.second;
                j++;
            }
            if(v[0].second<v[1].second)
            {
                s.erase(make_pair(v[0].first,v[0].second));
            }
            else
            {
                s.erase(make_pair(v[1].first,v[1].second));   
            }
            s.insert(make_pair(A[i],1));
        }


    }
    // cout<<n/3<<"\n";
    int j=0;
    std::vector<pair<int,int> > v(2);
    for(auto it:s)
    {
        // cout<<it.first<<" "<<it.second<<"\n";
        v[j].first=it.first;
        v[j].second=it.second;
        j++;
    }
    if(v[0].second<v[1].second)
        return v[1].first;
    else return v[0].first;    // s.insert(make_pair(1,1));
    // s.insert(make_pair(2,2));
    // s.insert(make_pair(3,1));
    // cout<<s.size()<<"\n";
    //         for(auto it:s)
    //         {
    //             cout<<it.first<<" "<<it.second<<"\n";
    //         }

    return 0;
 }